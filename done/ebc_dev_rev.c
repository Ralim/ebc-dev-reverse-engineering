#include "ebc_dev.h"

// Reverse engineered functions from the ebc_dev_v8 blob

struct ebc ebc_global;

ssize_t pmic_vcom_write(struct device *device, struct device_attribute *attr,
			char *buf, size_t count)
{
	int return_value;
	uint new_value_mv;
	count = 0;
	return_value = kstrtouint(buf, 0, &new_value_mv);
	if (return_value == 0)
	{
		return_value = ebc_pmic_set_vcom(ebc_global.pmic, new_value_mv);
		if (return_value != 0)
		{
			count = -1;
			dev_err(ebc_global.dev, "set vcom value failed\n");
		}
	}
	else
	{
		count = -1;
		dev_err(ebc_global.dev, "invalid value = %s\n", buf);
	}
	return count;
}

ssize_t waveform_version_read(struct device *device,
			      struct device_attribute *attr, char *buf)

{
	int res;
	char *waveform_version;

	waveform_version = epd_lut_get_wf_version();
	res = sprintf(buf, "%s\n", waveform_version);
	return (long)res;
}

/*
 * ebc system ioctl command
 *
 * Seems like GET_OSD_BUFFER and SEND_OSD_BUFFER aren't implemented
 */
				     //ulong argp, probably a pointer to a struct
long ebc_io_ctl(file *file, uint cmd, unsigned long buf_addr)
{
	void *tmp_stackpointer;
	bool bVar2;
	long ret;
	// Some kind of struct pointer
	// struct s_buf_base *buf_base = (struct s_buf_base*) buf_addr;
	ulong buf_base; // maybe this is actually signed (it probably shouldn't be though)
	struct ebc_buf_s *ebc_buf_s_ptr;
	size_t __n;
	ulong ebc_buf_phy_addr;
	struct wait_queue_entry __wq_entry;
	struct ebc_buf_info buf_info;

	if (cmd < EBC_ENABLE_OVERLAY && !buf_addr) {
		dev_err(ebc_global.info.dev, "%s: buf NULL\n", __func__);
		return -14; // EFAULT
	}

	switch (cmd)
	{
		case EBC_GET_BUFFER: //0x7000
			ebc_buf_s_ptr = ebc_empty_buf_get();

			if (!ebc_buf_s_ptr)
			{
				ret = -1; // EPERM (probably just EBC_ERROR though)
				return ret;
			}

			ebc_buf_phy_addr = ebc_buf_s_ptr->phy_addr;
			buf_base = ebc_phy_buf_base_get();
			// Read address in stack pointer and store it
			tmp_stackpointer = (void *)cRead_8(sp_el0);

			buf_info.offset = (int)ebc_buf_phy_addr - (int)buf_base;
			buf_info.panel_color = ebc_global.panel.panel_color;
			buf_info.width = ebc_global.panel.width;
			buf_info.height = ebc_global.panel.height;

			// Maybe accessing struct properties
			if (((*(uint *)((long)tmp_stackpointer + 0x34) >> 0x15 & 1) != 0) ||
				(buf_base = buf_addr, ((uint)*tmp_stackpointer >> 0x1a & 1) != 0))
			{
				// This seems to just be a cast, the bit magic is weird
				buf_base = (long)(buf_addr << 8) >> 8 & buf_addr;
				//buf_base = (long)buf_addr;
			}
				     //0xff - 0x2c
			// buf_base > -45 ??
			bVar2 = 0xffffffffffffffd3 < buf_base;
			buf_base += 0x2c; // -44
			ebc_buf_phy_addr = 0;

			if (!bVar2 || buf_base == 0)
			{
				// Is tmp_stackpointer[1] just the previous pointer to ebc_buf_phy_addr on the stack?? (from line 71)
				ebc_buf_phy_addr = tmp_stackpointer[1];
			}
			if (bVar2)
			{
				buf_base = 0xffffffffffffffff; // -1
			}
			// carry8 checks for overflow in unsigned addition (can only check for 8 bits of overflow???)
			if (!CARRY8(buf_base, ~ebc_buf_phy_addr) &&
				!CARRY8(buf_base + ~ebc_buf_phy_addr, (ulong)bVar2) ||
				buf_base == ebc_buf_phy_addr + !bVar2)
			{
				ret = cRead_8(sp_el0);
				if (((long)buf_addr &
					(*(ulong *)(ret + 8) ^ 0xffffffffffffffff)) != 0)
				{
					buf_addr = 0;
				}
				buf_base = __arch_copy_to_user((void *)buf_addr, &buf_info, 0x2c);
				if ((int)buf_base == 0)
				{
					ret = 0;
					return ret;
				}
			}

			ebc_buf_release(ebc_buf_s_ptr);
			ret = -14; // EFAULT
			return ret;
		case EBC_SEND_BUFFER: //0x7001
			tmp_stackpointer = (void *)cRead_8(sp_el0);
			if (((*(uint *)((long)tmp_stackpointer + 0x34) >> 0x15 & 1) != 0) ||
			    (buf_base = buf_addr, ((uint)*tmp_stackpointer >> 0x1a & 1) != 0))
			{
				buf_base = (long)(buf_addr << 8) >> 8 & buf_addr;
			}
			bVar2 = 0xffffffffffffffd3 < buf_base;
			buf_base += 0x2c;
			ebc_buf_phy_addr = 0;
			if (!bVar2 || buf_base == 0)
			{
				ebc_buf_phy_addr = tmp_stackpointer[1];
			}
			if (bVar2)
			{
				buf_base = 0xffffffffffffffff;
			}
			// NULL check?
			if (!CARRY8(buf_base, ~ebc_buf_phy_addr) &&
				!CARRY8(buf_base + ~ebc_buf_phy_addr, (ulong)bVar2) ||
			    buf_base == ebc_buf_phy_addr + !bVar2)
			{
				ret = cRead_8(sp_el0);
				if (((long)(buf_addr << 8) >> 8 & buf_addr &
				     (*(ulong *)(ret + 8) ^ 0xffffffffffffffff)) != 0)
				{
					buf_addr = 0;
				}
				// Fetch struct from userspace				      //size
				buf_base = __arch_copy_from_user(&buf_info, (void *)buf_addr, 0x2c);
				if (buf_base == 0)
				{
					buf_base = ebc_phy_buf_base_get();
					ebc_buf_s_ptr =
					    ebc_find_buf_by_phy_addr((long)buf_info.offset + buf_base);
					//
					if (ebc_buf_s_ptr)
					{
						// Send buffer to DSP
						ebc_buf_s_ptr->buf_mode = buf_info.epd_mode;
						ebc_buf_s_ptr->win_x1 = buf_info.win_x1;
						ebc_buf_s_ptr->win_y1 = buf_info.win_y1;
						ebc_buf_s_ptr->win_x2 = buf_info.win_x2;
						ebc_buf_s_ptr->win_y2 = buf_info.win_y2;
						ebc_add_to_dsp_buf_list(ebc_buf_s_ptr);
						// If DSP is asleep, wake it up
						if (ebc_global.info.ebc_dsp_buf_status == 0)
						{
							ebc_global.info.ebc_dsp_buf_status = 1;
							__wake_up_sync(&ebc_thread_wq, 1, 1);
						}
						if ((ebc_buf_s_ptr->buf_mode == 0xf && ebc_global.info.is_early_suspend == 0) ||ebc_buf_s_ptr->buf_mode == 0x11)
						{
							// Wait for DSP to finish
							ebc_global.info.ebc_last_display = 1;
							init_wait_entry(&__wq_entry, 0);
							while (true)
							{
								ret =
								    prepare_to_wait_event(&ebc_poweroff_wq, &__wq_entry, 1);
								if (ebc_global.info.ebc_last_display == 0)
									break;
								if (ret != 0)
									return 0; //why?
								schedule();
							}
							finish_wait(&ebc_poweroff_wq, &__wq_entry);
							ret = 0;
							return ret;
						}
					}
				}
			}
			ret = -14; // -EFAULT
			return ret;
		case EBC_GET_BUFFER_INFO:
			tmp_stackpointer = (void *)cRead_8(sp_el0);
			buf_info.width_mm = ebc_global.panel.width_mm;
			buf_info.height_mm = ebc_global.panel.height_mm;
			buf_info.width = ebc_global.panel.width;
			buf_info.height = ebc_global.panel.height;
			buf_info.panel_color = ebc_global.panel.panel_color;

			if (((*(uint *)((long)tmp_stackpointer + 0x34) >> 0x15 & 1) != 0) ||
			(buf_base = buf_addr, ((uint)*tmp_stackpointer >> 0x1a & 1) != 0))
			{
				buf_base = (long)(buf_addr << 8) >> 8 & buf_addr;
			}
			bVar2 = 0xffffffffffffffd3 < buf_base;
			buf_base += 0x2c;
			ebc_buf_phy_addr = 0;
			if (!bVar2 || buf_base == 0)
			{
				ebc_buf_phy_addr = tmp_stackpointer[1];
			}
			if (bVar2)
			{
				buf_base = 0xffffffffffffffff;
			}

			if (!CARRY8(buf_base, ~ebc_buf_phy_addr) && !CARRY8(buf_base + ~ebc_buf_phy_addr, (ulong)bVar2) ||
			buf_base == ebc_buf_phy_addr + !bVar2)
			{
				ret = cRead_8(sp_el0);
				if (((long)(buf_addr << 8) >> 8 & buf_addr &
				(*(ulong *)(ret + 8) ^ 0xffffffffffffffff)) != 0)
				{
					buf_addr = 0;
				}
				buf_base = __arch_copy_to_user((void *)buf_addr, &buf_info, 0x2c);
				if (buf_base == 0)
				{
					ret = 0;
					return ret;
				}
			}
			dev_err(ebc_global.info.dev, "EBC_GET_BUFFER_INFO failed\n");
			ret = -14; // EFAULT
			return ret;
		case EBC_SET_FULL_MODE_NUM:
			tmp_stackpointer = (void *)cRead_8(sp_el0);
			if (((*(uint *)((long)tmp_stackpointer + 0x34) >> 0x15 & 1) != 0) ||
			    (buf_base = buf_addr, ((uint)*tmp_stackpointer >> 0x1a & 1) != 0))
			{
				buf_base = (long)(buf_addr << 8) >> 8 & buf_addr;
			}
			// 0b1111111111111111111111111111111111111111111111111111111111010011
			bVar2 = 0xfffffffffffffffb < buf_base;
			buf_base += 4;
			ebc_buf_phy_addr = 0;
			if (!bVar2 || buf_base == 0)
			{
				ebc_buf_phy_addr = tmp_stackpointer[1];
			}
			if (bVar2)
			{
				buf_base = 0xffffffffffffffff;
			}
			buf_base = (ulong)(!CARRY8(buf_base, ~ebc_buf_phy_addr) &&
					       !CARRY8(buf_base + ~ebc_buf_phy_addr, (ulong)bVar2) ||
					   buf_base == ebc_buf_phy_addr + !bVar2);
			if (buf_base == 0)
			{
				__n = 4;
			}
			else
			{
				ret = cRead_8(sp_el0);
				if (((long)(buf_addr << 8) >> 8 & buf_addr &
				     (*(ulong *)(ret + 8) ^ 0xffffffffffffffff)) != 0)
				{
					buf_addr = 0;
				}
				__n = __arch_copy_from_user(&ebc_global.info.full_mode_num,
							    (void *)buf_addr, 4);
				if (__n == 0)
				{
					dev_info(ebc_global.info.dev, "full_mode_num = %d\n",
						  (ulong)(uint)ebc_global.info.full_mode_num);
					ret = 0;
					return ret;
				}
				buf_base = 4 - __n;
			}
			memset((void *)((long)ebc_global.info.direct_buffer + (buf_base - 0x7c)),
			       0, __n);
			dev_err(ebc_global.info.dev, "EBC_SET_FULL_MODE_NUM failed\n");
			ret = -14; // EFAULT
			return ret;
		case EBC_ENABLE_OVERLAY:
			ebc_global.info.overlay_enable = 1;
			dev_info(ebc_global.info.dev,
				  "enable ebc overlay, you can use auto_overlay mode to show "
				  "somthing over the system display\n");
			ret = 0;
			return ret;
		case EBC_DISABLE_OVERLAY:
			ebc_global.info.overlay_enable = 0;
			ebc_global.info.overlay_start = 0;
			dev_info(ebc_global.info.dev, "disable ebc overlay\n");
			ret = 0;
			return ret;
	}
	dev_err(ebc_global.info.dev, "%s: unknow cmd\n", "ebc_io_ctl");
	ret = 0;
	return ret;
}

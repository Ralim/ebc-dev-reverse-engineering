#include "ebc_dev.h"
#include "ebc_pmic.h"
#include <kernel.h>
#include <stdint.h>
#include <string.h>

typedev byte uint8_t

    struct ebc_info {
  ulong ebc_buffer_phy_addr;
  char *ebc_buffer_vir;
  int ebc_buffer_size;
  int ebc_buf_real_size;
  int direct_buf_real_size;
  int is_busy_now;
  int task_restart;
  int auto_refresh_done;
  char frame_total;
  char frame_bw_total;
  char field_0x2a;
  char field_0x2b;
  int auto_need_refresh0;
  int auto_need_refresh1;
  int frame_left;
  int part_mode_count;
  int full_mode_num;
  int height;
  int width;
  int *lut_addr;
  int buffer_need_check;
  int ebc_irq_status;
  int ebc_dsp_buf_status;
  u32 field_0x5c;
  struct device *dev;
  struct epd_lut_data lut_data;
  struct task_struct *ebc_task;
  int *auto_image_new;
  int *auto_image_old;
  int *auto_image_bg;
  int *auto_image_cur;
  u8 *auto_frames;
  int *auto_image_fb;
  void *direct_buffer[2];
  int ebc_power_status;
  int ebc_last_display;
  char *lut_ddr_vir;
  struct ebc_buf_s *prev_dsp_buf;
  struct ebc_buf_s *curr_dsp_buf;
  struct wake_lock suspend_lock;
  int wake_lock_is_set;
  int first_in;
  struct timer_list vdd_timer;
  struct timer_list frame_timer;
  struct work_struct auto_buffer_work;
  int is_early_suspend;
  int is_deep_sleep;
  int is_power_off;
  int overlay_enable;
  int overlay_start;
  u32 field_0x274;
};

struct ebc { // Must be 0x328 bytes
  struct device *dev;
  struct ebc_tcon *tcon;
  struct ebc_pmic *pmic;
  struct ebc_panel panel;
  struct ebc_info info;
};

// open() handler
int ebc_open(inode *inode, file *file) {
  file->f_pos = 0;
  return 0;
}

// Resume from being in suspension
int ebc_resume(device *dev) {
  struct ebc *driver_data_ebc;

  driver_data_ebc = dev->driver_data;
  (*driver_data_ebc->pmic->pmic_pm_resume)(driver_data_ebc->pmic);
  (driver_data_ebc->info).is_deep_sleep = 0;
  _dev_info((driver_data_ebc->info).dev, "device resume\n");
  return 0;
}

void ebc_vdd_power_timeout(timer_list *t) {
  if (ebc_global.info.wake_lock_is_set == 0) {
    return;
  }
  ebc_global.info.wake_lock_is_set = 0;
  __pm_relax((wakeup_source *)&ebc_global.info.suspend_lock);
  return;
}

// remove() -> deregisters the misc object
int ebc_remove(platform_device *pdev) {
  misc_deregister(&ebc_misc);
  return 0;
}

// WARNING: Type propagation algorithm not settling

int ebc_mmap(file *file, vm_area_struct *vma) {
  int res;
  ulong phy_buffer_base_addr;
  ulong vm_end;
  pgprot_t prot;
  ulong vm_flags;

  phy_buffer_base_addr = ebc_phy_buf_base_get();
  vm_flags = vma->vm_flags;
  vm_end = vma->vm_end;
  prot = (pgprot_t)((vma->vm_page_prot).pgprot & 0xff9fffffffffffe3 |
                    0x60000000000000);
  (vma->vm_page_prot).pgprot = (pteval_t)prot;
  vma->vm_flags = vm_flags | 0x4044000;
  res = remap_pfn_range(vma, vma->vm_start, phy_buffer_base_addr >> 0xc,
                        vm_end - vma->vm_start, prot);
  if (res != 0) {
    res = -11;
  }
  return res;
}

long ebc_io_ctl(file *file, uint cmd, ulong argp)

{
  void *puVar1;
  bool bVar2;
  long return_val;
  ulong buf_base;
  struct ebc_buf_s *ebc_buf_s_ptr;
  size_t __n;
  ulong uVar3;
  struct wait_queue_entry __wq_entry;
  struct ebc_buf_info buf_info;

  if ((cmd - 0x7000 < 4) && (argp == 0)) {
    _dev_err(ebc_global.info.dev, "%s: argp NULL\n", "ebc_io_ctl");
    return_val = -0xe;
    goto LAB_001001ac_exit;
  }
  if (cmd == 0x7002) {
    puVar1 = (void *)cRead_8(sp_el0);
    buf_info.width_mm = ebc_global.panel.width_mm;
    buf_info.height_mm = ebc_global.panel.height_mm;
    buf_info.width = ebc_global.panel.width;
    buf_info.height = ebc_global.panel.height;
    buf_info.panel_color = ebc_global.panel.panel_color;
    if (((*(uint *)((long)puVar1 + 0x34) >> 0x15 & 1) != 0) ||
        (buf_base = argp, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
      buf_base = (long)(argp << 8) >> 8 & argp;
    }
    bVar2 = 0xffffffffffffffd3 < buf_base;
    buf_base += 0x2c;
    uVar3 = 0;
    if (!bVar2 || buf_base == 0) {
      uVar3 = puVar1[1];
    }
    if (bVar2) {
      buf_base = 0xffffffffffffffff;
    }
    if (!CARRY8(buf_base, ~uVar3) && !CARRY8(buf_base + ~uVar3, (ulong)bVar2) ||
        buf_base == uVar3 + !bVar2) {
      return_val = cRead_8(sp_el0);
      if (((long)(argp << 8) >> 8 & argp &
           (*(ulong *)(return_val + 8) ^ 0xffffffffffffffff)) != 0) {
        argp = 0;
      }
      buf_base = __arch_copy_to_user((void *)argp, &buf_info, 0x2c);
      if (buf_base == 0) {
        return_val = 0;
        goto LAB_001001ac_exit;
      }
    }
    _dev_err(ebc_global.info.dev, "EBC_GET_BUFFER_INFO failed\n");
    return_val = -0xe;
    goto LAB_001001ac_exit;
  }
  if (cmd < 0x7003) {
    if (cmd == 0x7000) {
      ebc_buf_s_ptr = ebc_empty_buf_get();
      if (ebc_buf_s_ptr == (struct ebc_buf_s *)0x0) {
        return_val = -1;
      } else {
        uVar3 = ebc_buf_s_ptr->phy_addr;
        buf_base = ebc_phy_buf_base_get();
        puVar1 = (void *)cRead_8(sp_el0);
        buf_info.offset = (int)uVar3 - (int)buf_base;
        buf_info.panel_color = ebc_global.panel.panel_color;
        buf_info.width = ebc_global.panel.width;
        buf_info.height = ebc_global.panel.height;
        if (((*(uint *)((long)puVar1 + 0x34) >> 0x15 & 1) != 0) ||
            (buf_base = argp, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
          buf_base = (long)(argp << 8) >> 8 & argp;
        }
        bVar2 = 0xffffffffffffffd3 < buf_base;
        buf_base += 0x2c;
        uVar3 = 0;
        if (!bVar2 || buf_base == 0) {
          uVar3 = puVar1[1];
        }
        if (bVar2) {
          buf_base = 0xffffffffffffffff;
        }
        if (!CARRY8(buf_base, ~uVar3) &&
                !CARRY8(buf_base + ~uVar3, (ulong)bVar2) ||
            buf_base == uVar3 + !bVar2) {
          return_val = cRead_8(sp_el0);
          if (((long)(argp << 8) >> 8 & argp &
               (*(ulong *)(return_val + 8) ^ 0xffffffffffffffff)) != 0) {
            argp = 0;
          }
          buf_base = __arch_copy_to_user((void *)argp, &buf_info, 0x2c);
          if ((int)buf_base == 0) {
            return_val = 0;
            goto LAB_001001ac_exit;
          }
        }
        ebc_buf_release(ebc_buf_s_ptr);
        return_val = -14;
      }
      goto LAB_001001ac_exit;
    }
    if (cmd == 0x7001) {
      puVar1 = (void *)cRead_8(sp_el0);
      if (((*(uint *)((long)puVar1 + 0x34) >> 0x15 & 1) != 0) ||
          (buf_base = argp, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
        buf_base = (long)(argp << 8) >> 8 & argp;
      }
      bVar2 = 0xffffffffffffffd3 < buf_base;
      buf_base += 0x2c;
      uVar3 = 0;
      if (!bVar2 || buf_base == 0) {
        uVar3 = puVar1[1];
      }
      if (bVar2) {
        buf_base = 0xffffffffffffffff;
      }
      if (!CARRY8(buf_base, ~uVar3) &&
              !CARRY8(buf_base + ~uVar3, (ulong)bVar2) ||
          buf_base == uVar3 + !bVar2) {
        return_val = cRead_8(sp_el0);
        if (((long)(argp << 8) >> 8 & argp &
             (*(ulong *)(return_val + 8) ^ 0xffffffffffffffff)) != 0) {
          argp = 0;
        }
        buf_base = __arch_copy_from_user(&buf_info, (void *)argp, 0x2c);
        if (buf_base == 0) {
          buf_base = ebc_phy_buf_base_get();
          ebc_buf_s_ptr =
              ebc_find_buf_by_phy_addr((long)buf_info.offset + buf_base);
          if (ebc_buf_s_ptr != (struct ebc_buf_s *)0x0) {
            ebc_buf_s_ptr->buf_mode = buf_info.epd_mode;
            ebc_buf_s_ptr->win_x1 = buf_info.win_x1;
            ebc_buf_s_ptr->win_y1 = buf_info.win_y1;
            ebc_buf_s_ptr->win_x2 = buf_info.win_x2;
            ebc_buf_s_ptr->win_y2 = buf_info.win_y2;
            ebc_add_to_dsp_buf_list(ebc_buf_s_ptr);
            if (ebc_global.info.ebc_dsp_buf_status == 0) {
              ebc_global.info.ebc_dsp_buf_status = 1;
              __wake_up_sync(&ebc_thread_wq, 1, 1);
            }
            if (ebc_buf_s_ptr->buf_mode == 0xf) {
              if (ebc_global.info.is_early_suspend == 0)
                goto LAB_00100490;
            } else if (ebc_buf_s_ptr->buf_mode == 0x11) {
            LAB_00100490:
              ebc_global.info.ebc_last_display = 1;
              init_wait_entry(&__wq_entry, 0);
              while (true) {
                return_val =
                    prepare_to_wait_event(&ebc_poweroff_wq, &__wq_entry, 1);
                if (ebc_global.info.ebc_last_display == 0)
                  break;
                if (return_val != 0)
                  goto LAB_001002a0;
                schedule();
              }
              finish_wait(&ebc_poweroff_wq, &__wq_entry);
              return_val = 0;
              goto LAB_001001ac_exit;
            }
          }
        LAB_001002a0:
          return_val = 0;
          goto LAB_001001ac_exit;
        }
      }
    LAB_001005a4:
      return_val = -0xe;
      goto LAB_001001ac_exit;
    }
  } else {
    if (cmd == 0x7004) {
      ebc_global.info.overlay_enable = 1;
      _dev_info(ebc_global.info.dev,
                "enable ebc overlay, you can use auto_overlay mode to show "
                "somthing over the system display\n");
      return_val = 0;
      goto LAB_001001ac_exit;
    }
    if (cmd < 0x7004) {
      puVar1 = (void *)cRead_8(sp_el0);
      if (((*(uint *)((long)puVar1 + 0x34) >> 0x15 & 1) != 0) ||
          (buf_base = argp, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
        buf_base = (long)(argp << 8) >> 8 & argp;
      }
      bVar2 = 0xfffffffffffffffb < buf_base;
      buf_base += 4;
      uVar3 = 0;
      if (!bVar2 || buf_base == 0) {
        uVar3 = puVar1[1];
      }
      if (bVar2) {
        buf_base = 0xffffffffffffffff;
      }
      buf_base = (ulong)(!CARRY8(buf_base, ~uVar3) &&
                             !CARRY8(buf_base + ~uVar3, (ulong)bVar2) ||
                         buf_base == uVar3 + !bVar2);
      if (buf_base == 0) {
        __n = 4;
      } else {
        return_val = cRead_8(sp_el0);
        if (((long)(argp << 8) >> 8 & argp &
             (*(ulong *)(return_val + 8) ^ 0xffffffffffffffff)) != 0) {
          argp = 0;
        }
        __n = __arch_copy_from_user(&ebc_global.info.full_mode_num,
                                    (void *)argp, 4);
        if (__n == 0) {
          _dev_info(ebc_global.info.dev, "full_mode_num = %d\n",
                    (ulong)(uint)ebc_global.info.full_mode_num);
          return_val = 0;
          goto LAB_001001ac_exit;
        }
        buf_base = 4 - __n;
      }
      memset((void *)((long)ebc_global.info.direct_buffer + (buf_base - 0x7c)),
             0, __n);
      _dev_err(ebc_global.info.dev, "EBC_SET_FULL_MODE_NUM failed\n");
      goto LAB_001005a4;
    }
    if (cmd == 0x7005) {
      ebc_global.info.overlay_enable = 0;
      ebc_global.info.overlay_start = 0;
      _dev_info(ebc_global.info.dev, "disable ebc overlay\n");
      return_val = 0;
      goto LAB_001001ac_exit;
    }
  }
  _dev_err(ebc_global.info.dev, "%s: unknow cmd\n", "ebc_io_ctl");
  return_val = 0;
LAB_001001ac_exit:
  return return_val;
}

void frame_done_callback(struct timer_list *timer_maybe)

{
  if (1 < (uint)(ebc_global.info.curr_dsp_buf)->buf_mode) {
    if (ebc_global.info.frame_left != 0) {
      ebc_global.info.is_busy_now = 1;
      wake_up_process(ebc_auto_task);
      return;
    }
    ebc_global.info.is_busy_now = 0;
    ebc_global.info.ebc_irq_status = 1;
    _dev_info(ebc_global.info.dev, "frame done\n");
  LAB_00100674:
    __wake_up_sync(&ebc_wq, 1, 1);
    __wake_up_sync(&ebc_thread_wq, 1, 1);
    return;
  }
  if ((ebc_global.info.auto_need_refresh0 == 0) &&
      (ebc_global.info.auto_need_refresh1 == 0)) {
    if (ebc_global.info.task_restart == 0) {
      _dev_info(ebc_global.info.dev, "auto frame done\n");
      memset(ebc_global.info.auto_frames, 0,
             (long)ebc_global.info.ebc_buf_real_size);
      mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 0x18000000);
      ebc_global.info.is_busy_now = 0;
      ebc_global.info.ebc_irq_status = 1;
      goto LAB_00100674;
    }
  } else if (ebc_global.info.task_restart == 0)
    goto LAB_00100624;
  mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 0x18000000);
  ebc_global.info.task_restart = 0;
LAB_00100624:
  wake_up_process(ebc_auto_task);
  return;
}

void ebc_frame_timeout(timer_list *t) {
  frame_done_callback(t);
  return;
}

int ebc_lut_update(struct ebc *ebc) {
  struct epd_lut_data *out;
  long lVar1;
  ulong uVar2;
  int res;
  u8 *wf_table_ptr;
  uint uVar3;
  ulong uVar4;
  ulong pmic_temp_c_2;
  long lVar5;
  uint pmic_temp_c;
  byte frame_num;

  (*ebc->pmic->pmic_read_temperature)(ebc->pmic, (int *)&pmic_temp_c);
  pmic_temp_c_2 = (ulong)pmic_temp_c;
  if (0x32 < pmic_temp_c) {
    _dev_err((ebc->info).dev, "temperature = %d, out of range0~50 ,use 25 \n",
             pmic_temp_c);
    pmic_temp_c_2 = 0x19;
    pmic_temp_c = 0x19;
  }
  _dev_info((ebc->info).dev, "temperature = %d\n", pmic_temp_c_2);
  out = &(ebc->info).lut_data;
  switch (((ebc->info).curr_dsp_buf)->buf_mode) {
  case 0:
  case 1:
    res = epd_lut_get(out, WF_TYPE_AUTO, pmic_temp_c);
    break;
  default:
    res = epd_lut_get(&(ebc->info).lut_data, WF_TYPE_GC16, pmic_temp_c);
    break;
  case 3:
  case 8:
    res = epd_lut_get(out, WF_TYPE_GL16, pmic_temp_c);
    break;
  case 4:
  case 9:
    res = epd_lut_get(out, WF_TYPE_GLR16, pmic_temp_c);
    break;
  case 5:
  case 10:
    res = epd_lut_get(out, WF_TYPE_GLD16, pmic_temp_c);
    break;
  case 6:
  case 0xb:
    res = epd_lut_get(out, WF_TYPE_GCC16, pmic_temp_c);
    break;
  case 0xc:
    res = epd_lut_get(out, WF_TYPE_A2, pmic_temp_c);
    break;
  case 0xd:
    res = epd_lut_get(out, WF_TYPE_GRAY2, pmic_temp_c);
    break;
  case 0xe:
    res = epd_lut_get(out, WF_TYPE_RESET, pmic_temp_c);
  }
  if (res == 0) {
    // If same mode and similar temp, skip update
    if ((((ebc->info).curr_dsp_buf)->buf_mode == ebc_lut_update::last_mode) &&
        (ebc_lut_update::last_temperature / 3 == (int)pmic_temp_c / 3)) {
      res = 0;
    } else {
      wf_table_ptr = (ebc->info).lut_data.wf_table;
      frame_num = *(byte *)&(ebc->info).lut_data.frame_num;
      if (wf_table_ptr != (u8 *)0x0) {
        kfree(wf_table_ptr);
        (ebc->info).lut_data.wf_table = (u8 *)0x0;
      }
      wf_table_ptr = (u8 *)__kmalloc((ulong)frame_num << 0x10, 0x6080c0);
      (ebc->info).lut_data.wf_table = wf_table_ptr;
      if (wf_table_ptr == (u8 *)0x0) {
        res = printk("\x013No memory for ebc wavform table, need %d byte\n",
                     (ulong)((ebc->info).lut_data.frame_num << 0x10));
        // There was a breakpoint here, @smaeul pointed out this is the bug call
        BUG();
        return res;
      }
      if (frame_num != 0) {
        lVar5 = 0;
        while (true) {
          res = (int)lVar5 << 10;
          pmic_temp_c_2 = 0;
          lVar1 = (long)(ebc->info).lut_data.data + lVar5;
          while (true) {
            uVar4 = 0;
            while (true) {
              uVar2 = uVar4 >> 3;
              uVar3 = (uint)uVar4;
              uVar4 = (ulong)(uVar3 + 1);
              wf_table_ptr[res + uVar3] =
                  (byte)((*(uint *)(lVar1 + (pmic_temp_c_2 >> 4) * 4) >>
                              (ulong)((uint)uVar2 & 0x1e) &
                          3)
                         << 2) |
                  (byte)(*(uint *)(lVar1 + (pmic_temp_c_2 & 0xf) * 4) >>
                         (ulong)((uVar3 & 0xf) << 1)) &
                      3;
              if (uVar3 + 1 == 0x100)
                break;
              wf_table_ptr = (ebc->info).lut_data.wf_table;
            }
            uVar3 = (int)pmic_temp_c_2 + 1;
            pmic_temp_c_2 = (ulong)uVar3;
            res += 0x100;
            if (uVar3 == 0x100)
              break;
            wf_table_ptr = (ebc->info).lut_data.wf_table;
          }
          if ((ulong)(frame_num - 1) * 0x40 - lVar5 == 0)
            break;
          lVar5 += 0x40;
          wf_table_ptr = (ebc->info).lut_data.wf_table;
        }
      }
      ebc_lut_update::last_temperature = pmic_temp_c;
      res = 0;
      ebc_lut_update::last_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
    }
  } else {
    _dev_err((ebc->info).dev, "get lut data failed\n");
    res = -1;
  }
  return res;
}

ssize_t ebc_state_read(device *device, device_attribute *attr, char *buf) {
  int ret;
  ret = sprintf(buf, "%d\n", (ulong)(uint)ebc_global.info.wake_lock_is_set);
  return (long)ret;
}

ssize_t ebc_version_read(device *device, device_attribute *attr, char *buf) {
  int iVar1;

  iVar1 = sprintf(buf, "%s\n", "1.01");
  return (long)iVar1;
}

ssize_t pmic_vcom_read(device *device, device_attribute *attr, char *buf) {
  int vcom_mv;

  vcom_mv = (*(ebc_global.pmic)->pmic_get_vcom)(ebc_global.pmic);
  vcom_mv = sprintf(buf, "%d\n", vcom_mv);
  return (long)vcom_mv;
}

ssize_t pmic_temp_read(device *device, device_attribute *attr, char *buf) {
  int len;
  int t;
  uint temp_in_c;

  (*(ebc_global.pmic)->pmic_read_temperature)(ebc_global.pmic,
                                              (int *)&temp_in_c);
  len = sprintf(buf, "%d\n", (ulong)temp_in_c);
  return (long)len;
}

ssize_t pmic_name_read(device *device, device_attribute *attr, char *buf) {
  int res;

  res = sprintf(buf, "%s\n", (ebc_global.pmic)->pmic_name);
  return (long)res;
}

ssize_t pmic_vcom_write(device *device, struct device_attribute *attr,
                        char *buf, size_t count) {
  int res;
  uint new_value_mv;

  res = kstrtouint(buf, 0, &new_value_mv);
  if (res == 0) {
    res = ebc_pmic_set_vcom(ebc_global.pmic, new_value_mv);
    if (res != 0) {
      count = -1;
      _dev_err(ebc_global.dev, "set vcom value failed\n");
    }
  } else {
    count = -1;
    _dev_err(ebc_global.dev, "invalid value = %s\n", buf);
  }
  return count;
}

ssize_t waveform_version_read(struct device *device,
                              struct device_attribute *attr, char *buf) {
  int res;
  char *waveform_version;
  waveform_version = epd_lut_get_wf_version();
  res = sprintf(buf, "%s\n", waveform_version);
  return (long)res;
}

// Sends the current buffer by DMA, and swaps to the other buffer being in use

void flip(ebc_panel *panel, int buffer_length) {
  struct device *panel_device_handle;
  struct dma_map_ops *pdVar1;
  int current_buffer_num;

  current_buffer_num = panel->current_buffer;
  panel_device_handle = panel->dev;
  if (panel_device_handle == (device *)0x0) {
    pdVar1 = (dma_map_ops *)0x105108;
  } else {
    pdVar1 = (dma_map_ops *)0x105108;
    if (panel_device_handle->dma_ops != (dma_map_ops *)0x0) {
      pdVar1 = panel_device_handle->dma_ops;
    }
  }
  if (pdVar1->sync_single_for_device != 0x0) {
    (*pdVar1->sync_single_for_device)(panel_device_handle,
                                      panel->fb[current_buffer_num].phy_addr,
                                      (long)buffer_length, DMA_TO_DEVICE);
  }
  (*panel->tcon->dsp_mode_set)(panel->tcon, 0, 0, 0, 0);
  (*panel->tcon->image_addr_set)(
      panel->tcon, *(u32 *)&panel->fb[current_buffer_num].phy_addr, 0);
  (*panel->tcon->frame_start)(panel->tcon, 1);
  panel->current_buffer = 1 - panel->current_buffer;
  return;
}

// Powewr down the pmic / tcon

int ebc_power_set_off(ebc *ebc, int power_status) {
  struct device *pdVar1;

  (ebc->info).ebc_power_status = power_status;
  (*ebc->pmic->pmic_power_req)(ebc->pmic, false);
  (*ebc->tcon->disable)(ebc->tcon);
  if ((ebc->info).wake_lock_is_set == 0) {
    pdVar1 = ebc->dev;
    _dev_info(pdVar1, "ebc hw power off\n");
    return (int)pdVar1;
  }
  (ebc->info).wake_lock_is_set = 0;
  __pm_relax((struct wakeup_source *)&(ebc->info).suspend_lock);
  pdVar1 = ebc->dev;
  _dev_info(pdVar1, "ebc hw power off\n");
  return (int)pdVar1;
}

// Suspend device for sleep

int ebc_suspend(device *dev) {
  struct ebc *ebc;

  ebc = dev->driver_data;
  if ((ebc->info).ebc_power_status == 1) {
    _dev_info((ebc->info).dev, "%s: device is busy now...\n", "ebc_suspend");
    ebc_power_set_off(ebc, 0);
  }
  (ebc->info).is_deep_sleep = 1;
  (*ebc->pmic->pmic_pm_suspend)(ebc->pmic);
  _dev_info((ebc->info).dev, "device suspend\n");
  return 0;
}

// Appears to be inner loop for transforming data across the virtual buffers
// into the direct buffer using waveform data.
//
// Seems to be for partial screen updates

void direct_mode_data_change_part(void *direct_buffer,
                                  char *curr_dsp_buf_virt_addr,
                                  char *prev_dsp_buf_virt_addr,
                                  byte frame_total, byte frame_left,
                                  u8 *waveform_table)

{
  undefined4 *puVar1;
  byte bVar13;
  uint uint_virt_addr_curr_dsp_buf_pos;
  ulong virt_addr_curr_dsp_buf_pos;
  uint uint_virt_addr_prev_dsp_buf_pos;
  ulong virt_addr_prev_dsp_buf_pos;
  int int_remainder;
  ulong remainder;
  long stepping_across_strip_count;
  byte bVar18;
  undefined4 *pointer_to_buffer_pos;
  int iterator_over_height;
  byte bVar19;
  byte bVar3;
  byte bVar4;
  uint buffer_offset;
  ushort data_at_prev_buff;
  ushort data_att_curr_buff;
  int iVar5;
  long lVar2;
  u32 panel_height;
  u32 panel_mirror;
  uint panel_width_stripes_16px_wide;
  undefined4 *puffer_pos_maybe_ptr;
  uint uVar6;
  ushort *ushort_curr_dsp_buff;
  ushort *ushort_prev_dsp_buff;
  u8 *waveform_table_data_ptr;

  panel_mirror = ebc_global.panel.mirror;
  panel_height = ebc_global.panel.height;
  waveform_table_data_ptr =
      waveform_table + (int)(((uint)frame_total - (uint)frame_left) * 0x10000);
  if ((int)ebc_global.panel.height < 1) {
    return;
  }
  // Panel is probably 16 pixel aligned
  panel_width_stripes_16px_wide = ebc_global.panel.width >> 4;
  // Remainder after stripes are made
  remainder = (ulong)(ebc_global.panel.width & 0xf);
  lVar2 = (ulong)(panel_width_stripes_16px_wide - 1) + 1;
  iterator_over_height = 0;
  if (ebc_global.panel.mirror == 0)
    goto LAB_00101148_no_mirror;
  do {
    buffer_offset = ((ebc_global.panel.height - 1) - iterator_over_height) *
                    ebc_global.panel.width;
    while (true) {
      pointer_to_buffer_pos =
          (undefined4 *)((long)direct_buffer + (ulong)(buffer_offset >> 2));
      if (panel_width_stripes_16px_wide != 0) {
        stepping_across_strip_count = 0;
        puffer_pos_maybe_ptr = pointer_to_buffer_pos;
        do {
          virt_addr_curr_dsp_buf_pos =
              *(ulong *)((long)curr_dsp_buf_virt_addr +
                         stepping_across_strip_count * 4 * 2);
          virt_addr_prev_dsp_buf_pos =
              *(ulong *)((long)prev_dsp_buf_virt_addr +
                         stepping_across_strip_count * 4 * 2);
          // If same location, skip
          if (virt_addr_curr_dsp_buf_pos == virt_addr_prev_dsp_buf_pos) {
            *puffer_pos_maybe_ptr = 0;
          } else {
            uint_virt_addr_prev_dsp_buf_pos = (uint)virt_addr_prev_dsp_buf_pos;
            uint_virt_addr_curr_dsp_buf_pos = (uint)virt_addr_curr_dsp_buf_pos;
            buffer_offset = uint_virt_addr_curr_dsp_buf_pos & 0xffff;
            bVar13 = 0;
            bVar19 = 3;
            bVar18 = 3;
            if ((uint_virt_addr_prev_dsp_buf_pos & 0xffff) != buffer_offset) {
              uVar6 = uint_virt_addr_prev_dsp_buf_pos & 0xffff ^ buffer_offset;
              bVar13 = bVar18;
              if ((uVar6 & 0xf) == 0) {
                bVar13 = 0;
              }
              bVar3 = bVar13 | 0xc;
              if ((uVar6 & 0xf0) == 0) {
                bVar3 = bVar13;
              }
              bVar4 = bVar3 | 0x30;
              if ((uVar6 & 0xf00) == 0) {
                bVar4 = bVar3;
              }
              bVar13 = bVar4 | 0xc0;
              if ((uVar6 & 0xf000) == 0) {
                bVar13 = bVar4;
              }
              bVar13 =
                  (waveform_table_data_ptr[(
                       int)((uint_virt_addr_prev_dsp_buf_pos & 0xff) * 0x100 +
                            (uint_virt_addr_curr_dsp_buf_pos & 0xff))] |
                   waveform_table_data_ptr[(
                       int)((uint_virt_addr_prev_dsp_buf_pos & 0xff00) +
                            (buffer_offset >> 8))]
                       << 4) &
                  bVar13;
            }
            *(byte *)puffer_pos_maybe_ptr = bVar13;
            buffer_offset = uint_virt_addr_prev_dsp_buf_pos >> 16;
            bVar13 = 0;
            if (buffer_offset != uint_virt_addr_curr_dsp_buf_pos >> 16) {
              uint_virt_addr_prev_dsp_buf_pos =
                  (uint_virt_addr_prev_dsp_buf_pos ^
                   uint_virt_addr_curr_dsp_buf_pos) >>
                  16;
              bVar13 = bVar18;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf) == 0) {
                bVar13 = 0;
              }
              bVar3 = bVar13 | 0xc;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf0) == 0) {
                bVar3 = bVar13;
              }
              bVar4 = bVar3 | 0x30;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf00) == 0) {
                bVar4 = bVar3;
              }
              bVar13 = bVar4 | 0xc0;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf000) == 0) {
                bVar13 = bVar4;
              }
              bVar13 =
                  (waveform_table_data_ptr[(
                       int)((buffer_offset & 0xff) * 0x100 +
                            (uint_virt_addr_curr_dsp_buf_pos >> 16 & 0xff))] |
                   waveform_table_data_ptr[(
                       int)((buffer_offset & 0xff00) +
                            (uint_virt_addr_curr_dsp_buf_pos >> 0x18))]
                       << 4) &
                  bVar13;
            }
            *(byte *)((long)puffer_pos_maybe_ptr + 1) = bVar13;
            buffer_offset = (uint)(virt_addr_prev_dsp_buf_pos >> 0x20);
            virt_addr_prev_dsp_buf_pos =
                virt_addr_curr_dsp_buf_pos >> 0x20 & 0xffff;
            bVar13 = 0;
            uint_virt_addr_curr_dsp_buf_pos = (uint)virt_addr_prev_dsp_buf_pos;
            if ((buffer_offset & 0xffff) != uint_virt_addr_curr_dsp_buf_pos) {
              uint_virt_addr_prev_dsp_buf_pos =
                  buffer_offset & 0xffff ^ uint_virt_addr_curr_dsp_buf_pos;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf) == 0) {
                bVar19 = 0;
              }
              bVar13 = bVar19 | 0xc;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf0) == 0) {
                bVar13 = bVar19;
              }
              bVar19 = bVar13 | 0x30;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf00) == 0) {
                bVar19 = bVar13;
              }
              bVar13 = bVar19 | 0xc0;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf000) == 0) {
                bVar13 = bVar19;
              }
              bVar13 = (waveform_table_data_ptr[(
                            int)((buffer_offset & 0xff) * 0x100 +
                                 (uint)(byte)virt_addr_prev_dsp_buf_pos)] |
                        waveform_table_data_ptr[(
                            int)((buffer_offset & 0xff00) +
                                 (uint_virt_addr_curr_dsp_buf_pos >> 8))]
                            << 4) &
                       bVar13;
            }
            *(byte *)((long)puffer_pos_maybe_ptr + 2) = bVar13;
            bVar13 = 0;
            uint_virt_addr_curr_dsp_buf_pos =
                (uint)(virt_addr_curr_dsp_buf_pos >> 0x20);
            if (buffer_offset >> 0x10 !=
                uint_virt_addr_curr_dsp_buf_pos >> 0x10) {
              uint_virt_addr_prev_dsp_buf_pos =
                  (buffer_offset ^ uint_virt_addr_curr_dsp_buf_pos) >> 0x10;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf) == 0) {
                bVar18 = 0;
              }
              bVar13 = bVar18 | 0xc;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf0) == 0) {
                bVar13 = bVar18;
              }
              bVar19 = bVar13 | 0x30;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf00) == 0) {
                bVar19 = bVar13;
              }
              bVar13 = bVar19 | 0xc0;
              if ((uint_virt_addr_prev_dsp_buf_pos & 0xf000) == 0) {
                bVar13 = bVar19;
              }
              bVar13 =
                  (waveform_table_data_ptr[(
                       int)((buffer_offset >> 0x10 & 0xff) * 0x100 +
                            (uint)(byte)(virt_addr_curr_dsp_buf_pos >> 0x30))] |
                   waveform_table_data_ptr[(
                       int)((buffer_offset >> 0x10 & 0xff00) +
                            (uint_virt_addr_curr_dsp_buf_pos >> 0x18))]
                       << 4) &
                  bVar13;
            }
            *(byte *)((long)puffer_pos_maybe_ptr + 3) = bVar13;
          }
          stepping_across_strip_count += 1;
          puffer_pos_maybe_ptr = puffer_pos_maybe_ptr + 1;
        } while ((int)stepping_across_strip_count <
                 (int)panel_width_stripes_16px_wide);
        curr_dsp_buf_virt_addr =
            (char *)((long)curr_dsp_buf_virt_addr + lVar2 * 4 * 2);
        prev_dsp_buf_virt_addr =
            (char *)((long)prev_dsp_buf_virt_addr + lVar2 * 4 * 2);
        pointer_to_buffer_pos = pointer_to_buffer_pos + lVar2;
      }
      int_remainder = (int)remainder;
      if (int_remainder != 0) {
        printk("width[%d], left pixels [%d] when aligned in 16 pixels\n",
               panel_width_stripes_16px_wide, remainder);
        iVar5 = int_remainder + 3;
        if (-1 < int_remainder) {
          iVar5 = int_remainder;
        }
        ushort_curr_dsp_buff = (ushort *)curr_dsp_buf_virt_addr;
        ushort_prev_dsp_buff = (ushort *)prev_dsp_buf_virt_addr;
        puffer_pos_maybe_ptr = pointer_to_buffer_pos;
        while (puVar1 = (undefined4 *)((long)puffer_pos_maybe_ptr + 1),
               puVar1 != (undefined4 *)((long)pointer_to_buffer_pos +
                                        (long)(iVar5 >> 2) + 1)) {
          data_at_prev_buff = *ushort_prev_dsp_buff;
          data_att_curr_buff = *ushort_curr_dsp_buff;
          if ((uint)data_att_curr_buff == (uint)data_at_prev_buff) {
            *(undefined *)puffer_pos_maybe_ptr = 0;
            puffer_pos_maybe_ptr = puVar1;
          } else {
            ushort_prev_dsp_buff = ushort_prev_dsp_buff + 1;
            ushort_curr_dsp_buff = ushort_curr_dsp_buff + 1;
            *(u8 *)puffer_pos_maybe_ptr =
                waveform_table_data_ptr[(int)((data_at_prev_buff & 0xff) *
                                                  0x100 +
                                              (uint)(byte)data_att_curr_buff)] |
                waveform_table_data_ptr[(int)((data_at_prev_buff & 0xff00) +
                                              (uint)(data_att_curr_buff >> 8))]
                    << 4;
            puffer_pos_maybe_ptr = puVar1;
          }
        }
        remainder = 0xffffffff;
      }
      if (panel_height == iterator_over_height + 1U) {
        return;
      }
      iterator_over_height += 1;
      if (panel_mirror != 0)
        break;
    LAB_00101148_no_mirror:
      buffer_offset = iterator_over_height * ebc_global.panel.width;
    }
  } while (true);
}

void direct_mode_data_change(void *direct_buffer, char *curr_dsp_buf_virt_addr,
                             char *prev_dsp_buf_virt_addr, byte frame_total,
                             byte frame_left, u8 *waveform_table)

{
  undefined8 *puVar1;
  u8 *puVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  u32 uVar6;
  u32 uVar7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  byte *pbVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  byte *pbVar15;
  int iVar16;
  uint uVar17;

  uVar7 = ebc_global.panel.mirror;
  uVar6 = ebc_global.panel.height;
  puVar2 =
      waveform_table + (int)(((uint)frame_total - (uint)frame_left) * 0x10000);
  if ((int)ebc_global.panel.height < 1) {
    return;
  }
  uVar5 = ebc_global.panel.width >> 4;
  uVar17 = ebc_global.panel.width & 0xf;
  lVar3 = (ulong)(uVar5 - 1) + 1;
  lVar14 = lVar3 * 8;
  iVar16 = 0;
  if (ebc_global.panel.mirror == 0)
    goto LAB_001013bc;
  do {
    uVar4 = ((ebc_global.panel.height - 1) - iVar16) * ebc_global.panel.width;
    while (true) {
      pbVar15 = (byte *)((long)direct_buffer + (ulong)(uVar4 >> 2));
      if (uVar5 != 0) {
        lVar12 = 0;
        pbVar11 = pbVar15;
        do {
          puVar1 = (undefined8 *)(prev_dsp_buf_virt_addr + lVar12);
          uVar9 = *(ulong *)(curr_dsp_buf_virt_addr + lVar12);
          lVar12 += 8;
          uVar10 = (uint)*puVar1;
          uVar8 = (uint)uVar9;
          uVar4 = (uint)((ulong)*puVar1 >> 0x20);
          uVar13 = uVar9 >> 0x20 & 0xffff;
          *pbVar11 = puVar2[(int)((uVar10 & 0xff) * 0x100 + (uVar8 & 0xff))] |
                     puVar2[(int)((uVar10 & 0xff00) + ((uVar8 & 0xffff) >> 8))]
                         << 4;
          pbVar11[1] =
              puVar2[(int)((uVar10 >> 0x10 & 0xff) * 0x100 +
                           (uVar8 >> 0x10 & 0xff))] |
              puVar2[(int)((uVar10 >> 0x10 & 0xff00) + (uVar8 >> 0x18))] << 4;
          pbVar11[2] =
              puVar2[(int)((uVar4 & 0xff) * 0x100 + (uint)(byte)uVar13)] |
              puVar2[(int)((uVar4 & 0xff00) + ((uint)uVar13 >> 8))] << 4;
          pbVar11[3] =
              puVar2[(int)((uVar4 >> 0x10 & 0xff) * 0x100 +
                           (uint)(byte)(uVar9 >> 0x30))] |
              puVar2[(int)((uVar4 >> 0x10 & 0xff00) + (uint)(uVar9 >> 0x38))]
                  << 4;
          pbVar11 = pbVar11 + 4;
        } while (lVar14 - lVar12 != 0);
        curr_dsp_buf_virt_addr = curr_dsp_buf_virt_addr + lVar14;
        prev_dsp_buf_virt_addr = prev_dsp_buf_virt_addr + lVar14;
        pbVar15 = pbVar15 + lVar3 * 4;
      }
      if (uVar17 != 0) {
        printk("width[%d], left pixels [%d] when aligned in 16 pixels\n", uVar5,
               (ulong)uVar17);
        uVar4 = uVar17 + 3;
        if (-1 < (int)uVar17) {
          uVar4 = uVar17;
        }
        if ((int)uVar4 >> 2 != 0) {
          lVar12 = 0;
          do {
            pbVar15[lVar12] =
                puVar2[(int)((*(ushort *)(prev_dsp_buf_virt_addr + lVar12 * 2) &
                              0xff) *
                                 0x100 +
                             (uint)(byte) * (ushort *)(curr_dsp_buf_virt_addr +
                                                       lVar12 * 2))] |
                puVar2[(int)((*(ushort *)(prev_dsp_buf_virt_addr + lVar12 * 2) &
                              0xff00) +
                             (uint)(*(ushort *)(curr_dsp_buf_virt_addr +
                                                lVar12 * 2) >>
                                    8))]
                    << 4;
            lVar12 += 1;
          } while ((ulong)(((int)uVar4 >> 2) - 1) + 1 != lVar12);
        }
        uVar17 = 0xffffffff;
      }
      if (uVar6 == iVar16 + 1U) {
        return;
      }
      iVar16 += 1;
      if (uVar7 != 0)
        break;
    LAB_001013bc:
      uVar4 = iVar16 * ebc_global.panel.width;
    }
  } while (true);
}

// WARNING: Globals starting with '_' overlap smaller symbols at the same
// address

int ebc_auto_tast_function(ebc_info *ebc_info)

{
  long lVar1;
  u8 *puVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  u32 uVar10;
  u32 uVar11;
  char cVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  u8 *puVar19;
  byte bVar20;
  long lVar21;
  byte bVar22;
  int *piVar23;
  int *piVar24;
  u32 uVar25;
  u8 *puVar26;
  void *pvVar27;

  lVar9 = cRead_8(sp_el0);
  do {
    down(&ebc_auto_thread_sem);
    *(undefined8 *)(lVar9 + 0x20) = 2;
    DataMemoryBarrier(2, 3);
    iVar6 = (ebc_global.info.curr_dsp_buf)->buf_mode;
    if (iVar6 < 0) {
    LAB_0010184c:
      ebc_global.info.frame_left += -1;
      flip(&ebc_global.panel, ebc_global.info.direct_buf_real_size);
      if (ebc_global.info.frame_left == 0)
        goto LAB_0010150c;
      direct_mode_data_change(
          ebc_global.info.direct_buffer[ebc_global.panel.current_buffer],
          (ebc_global.info.curr_dsp_buf)->virt_addr,
          (ebc_global.info.prev_dsp_buf)->virt_addr,
          ebc_global.info.frame_total, (byte)ebc_global.info.frame_left,
          ebc_global.info.lut_data.wf_table);
      uVar7 = (ebc_global.info.curr_dsp_buf)->buf_mode;
    } else {
      if (iVar6 < 2) {
        if (ebc_global.info.task_restart == 0) {
          flip(&ebc_global.panel, ebc_global.info.direct_buf_real_size);
        } else {
          mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 4);
        }
        cVar12 = ebc_global.info.frame_total;
        uVar11 = ebc_global.panel.mirror;
        uVar10 = ebc_global.panel.height;
        pvVar27 =
            ebc_global.info.direct_buffer[ebc_global.panel.current_buffer];
        ebc_global.info.auto_need_refresh0 = 0;
        uVar7 = ebc_global.panel.width >> 4;
        if (0 < (int)ebc_global.panel.height) {
          uVar25 = 0;
          lVar1 = (ulong)(uVar7 - 1) + 1;
          piVar23 = ebc_global.info.auto_image_old;
          piVar24 = ebc_global.info.auto_image_new;
          puVar26 = ebc_global.info.auto_frames;
          if (ebc_global.panel.mirror == 0)
            goto LAB_0010182c;
        LAB_001015c4:
          uVar8 =
              ((ebc_global.panel.height - 1) - uVar25) * ebc_global.panel.width;
          do {
            if (uVar7 != 0) {
              lVar17 = (long)pvVar27 + (ulong)(uVar8 >> 2) + 4;
              puVar19 = puVar26 + 8;
              lVar18 = 0;
              do {
                while (true) {
                  uVar14 = *(ulong *)(piVar24 + lVar18 * 2);
                  uVar16 = *(ulong *)(piVar23 + lVar18 * 2);
                  if (uVar14 != uVar16)
                    break;
                  *(undefined4 *)(lVar17 + -4) = 0;
                  lVar18 += 1;
                  lVar17 += 4;
                  puVar19 = puVar19 + 8;
                  if ((int)uVar7 <= (int)lVar18)
                    goto LAB_00101810;
                }
                ebc_global.info.auto_need_refresh0 = 1;
                lVar21 = *(ulong *)(puVar19 + -8) + 0x101010101010101;
                puVar2 = ebc_global.info.lut_data.wf_table +
                         (*(ulong *)(puVar19 + -8) & 0xff) * 0x10000;
                if (cVar12 == (char)lVar21) {
                  *(ulong *)(piVar23 + lVar18 * 2) = uVar14;
                  lVar21 = 0;
                }
                uVar15 = (uint)uVar16;
                uVar13 = (uint)uVar14;
                uVar8 = uVar13 & 0xffff;
                bVar20 = 0;
                bVar22 = 3;
                if ((uVar15 & 0xffff) != uVar8) {
                  uVar5 = uVar15 & 0xffff ^ uVar8;
                  bVar20 = 0;
                  if ((uVar5 & 0xf) != 0) {
                    bVar20 = bVar22;
                  }
                  bVar3 = bVar20 | 0xc;
                  if ((uVar5 & 0xf0) == 0) {
                    bVar3 = bVar20;
                  }
                  bVar4 = bVar3 | 0x30;
                  if ((uVar5 & 0xf00) == 0) {
                    bVar4 = bVar3;
                  }
                  bVar20 = bVar4 | 0xc0;
                  if ((uVar5 & 0xf000) == 0) {
                    bVar20 = bVar4;
                  }
                  bVar20 =
                      (puVar2[(int)((uVar15 & 0xff) * 0x100 +
                                    (uVar13 & 0xff))] |
                       puVar2[(int)((uVar15 & 0xff00) + (uVar8 >> 8))] << 4) &
                      bVar20;
                }
                *(byte *)(lVar17 + -4) = bVar20;
                uVar8 = uVar15 >> 0x10;
                bVar20 = 0;
                if (uVar8 != uVar13 >> 0x10) {
                  uVar15 = (uVar15 ^ uVar13) >> 0x10;
                  bVar20 = 0;
                  if ((uVar15 & 0xf) != 0) {
                    bVar20 = bVar22;
                  }
                  bVar3 = bVar20 | 0xc;
                  if ((uVar15 & 0xf0) == 0) {
                    bVar3 = bVar20;
                  }
                  bVar4 = bVar3 | 0x30;
                  if ((uVar15 & 0xf00) == 0) {
                    bVar4 = bVar3;
                  }
                  bVar20 = bVar4 | 0xc0;
                  if ((uVar15 & 0xf000) == 0) {
                    bVar20 = bVar4;
                  }
                  bVar20 = (puVar2[(int)((uVar8 & 0xff) * 0x100 +
                                         (uVar13 >> 0x10 & 0xff))] |
                            puVar2[(int)((uVar8 & 0xff00) + (uVar13 >> 0x18))]
                                << 4) &
                           bVar20;
                }
                *(byte *)(lVar17 + -3) = bVar20;
                uVar8 = (uint)(uVar16 >> 0x20);
                uVar16 = uVar14 >> 0x20 & 0xffff;
                bVar20 = 0;
                uVar13 = (uint)uVar16;
                if ((uVar8 & 0xffff) != uVar13) {
                  uVar15 = uVar8 & 0xffff ^ uVar13;
                  bVar20 = 0;
                  if ((uVar15 & 0xf) != 0) {
                    bVar20 = bVar22;
                  }
                  bVar3 = bVar20 | 0xc;
                  if ((uVar15 & 0xf0) == 0) {
                    bVar3 = bVar20;
                  }
                  bVar4 = bVar3 | 0x30;
                  if ((uVar15 & 0xf00) == 0) {
                    bVar4 = bVar3;
                  }
                  bVar20 = bVar4 | 0xc0;
                  if ((uVar15 & 0xf000) == 0) {
                    bVar20 = bVar4;
                  }
                  bVar20 =
                      (puVar2[(int)((uVar8 & 0xff) * 0x100 +
                                    (uint)(byte)uVar16)] |
                       puVar2[(int)((uVar8 & 0xff00) + (uVar13 >> 8))] << 4) &
                      bVar20;
                }
                *(byte *)(lVar17 + -2) = bVar20;
                bVar20 = 0;
                uVar13 = (uint)(uVar14 >> 0x20);
                if (uVar8 >> 0x10 != uVar13 >> 0x10) {
                  uVar15 = (uVar8 ^ uVar13) >> 0x10;
                  bVar20 = 0;
                  if ((uVar15 & 0xf) != 0) {
                    bVar20 = bVar22;
                  }
                  bVar22 = bVar20 | 0xc;
                  if ((uVar15 & 0xf0) == 0) {
                    bVar22 = bVar20;
                  }
                  bVar3 = bVar22 | 0x30;
                  if ((uVar15 & 0xf00) == 0) {
                    bVar3 = bVar22;
                  }
                  bVar20 = bVar3 | 0xc0;
                  if ((uVar15 & 0xf000) == 0) {
                    bVar20 = bVar3;
                  }
                  bVar20 = (puVar2[(int)((uVar8 >> 0x10 & 0xff) * 0x100 +
                                         (uint)(byte)(uVar14 >> 0x30))] |
                            puVar2[(int)((uVar8 >> 0x10 & 0xff00) +
                                         (uVar13 >> 0x18))]
                                << 4) &
                           bVar20;
                }
                *(byte *)(lVar17 + -1) = bVar20;
                lVar18 += 1;
                *(long *)(puVar19 + -8) = lVar21;
                lVar17 += 4;
                puVar19 = puVar19 + 8;
              } while ((int)lVar18 < (int)uVar7);
            LAB_00101810:
              piVar23 = piVar23 + lVar1 * 2;
              piVar24 = piVar24 + lVar1 * 2;
              puVar26 = puVar26 + lVar1 * 8;
            }
            uVar25 += 1;
            if (uVar10 == uVar25)
              break;
            if (uVar11 != 0)
              goto LAB_001015c4;
          LAB_0010182c:
            uVar8 = uVar25 * ebc_global.panel.width;
          } while (true);
        }
      } else {
        if (4 < iVar6 - 7U)
          goto LAB_0010184c;
        ebc_global.info.frame_left += -1;
        flip(&ebc_global.panel, ebc_global.info.direct_buf_real_size);
        if (ebc_global.info.frame_left != 0) {
          direct_mode_data_change_part(
              ebc_global.info.direct_buffer[ebc_global.panel.current_buffer],
              (ebc_global.info.curr_dsp_buf)->virt_addr,
              (ebc_global.info.prev_dsp_buf)->virt_addr,
              ebc_global.info.frame_total, (byte)ebc_global.info.frame_left,
              ebc_global.info.lut_data.wf_table);
        }
      }
    LAB_0010150c:
      uVar7 = (ebc_global.info.curr_dsp_buf)->buf_mode;
    }
    if (uVar7 < 2) {
      queue_work_on(8, _DAT_00105240, &ebc_global.info.auto_buffer_work);
    }
    up(&ebc_auto_thread_sem);
    schedule();
  } while (true);
}

// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same
// address

int ebc_probe(platform_device *pdev)

{
  struct list_head *plVar1;
  struct ebc_pmic *peVar2;
  struct ebc_pmic *peVar3;
  int iVar6;
  struct ebc *ebc_buf_ptr;
  struct device_node *platform_device_node;
  struct platform_device *platform_device_ptr;
  struct ebc_tcon *tcon_handle;
  struct i2c_client *pmic_i2c_client_ptr;
  struct ebc_pmic *pmic_ptr;
  int return_value;
  char *pcVar7;
  u8 *puVar8;
  struct task_struct *task;
  char *__s;
  struct ebc_buf_s *peVar9;
  ulong uVar10;
  int iVar11;
  struct device *device_ptr;
  void *__dest;
  void *__dest_00;
  uint local_6c;
  struct resource resource_obj;
  bool bVar5;
  struct device *device_ptr_base_device;
  struct ebc_info *ebc_info_ptr;
  uint uVar4;

  device_ptr_base_device = &pdev->dev;
  ebc_buf_ptr = (ebc *)devm_kmalloc(device_ptr_base_device, 0x328, 0x6080c0);
  if (ebc_buf_ptr == (ebc *)0x0) {
    return_value = -0xc;
    goto LAB_00101df0;
  }
  // WARNING: Read-only address (ram,0x00103ab0) is written
  platform_device_node = (pdev->dev).of_node;
  str_get_buffer_info_failed._8_8_ = ebc_buf_ptr;
  ebc_buf_ptr->dev = device_ptr_base_device;
  platform_device_node = of_parse_phandle(platform_device_node, "ebc_tcon", 0);
  if (platform_device_node == (device_node *)0x0) {
    return_value = -0x13;
    _dev_err(device_ptr_base_device, "not find ebc tcon\n");
    goto LAB_00101df0;
  }
  platform_device_ptr = of_find_device_by_node(platform_device_node);
  if (platform_device_ptr != (platform_device *)0x0) {
    tcon_handle = (ebc_tcon *)(platform_device_ptr->dev).driver_data;
    ebc_buf_ptr->tcon = tcon_handle;
    if (tcon_handle != (ebc_tcon *)0x0) {
      tcon_handle->dsp_end_callback = frame_done_callback;
      platform_device_node = of_parse_phandle((pdev->dev).of_node, "pmic", 0);
      if (platform_device_node == (device_node *)0x0) {
        return_value = -0x13;
        _dev_err(device_ptr_base_device, "not find pmic node\n");
        goto LAB_00101df0;
      }
      pmic_i2c_client_ptr = of_find_i2c_device_by_node(platform_device_node);
      if (pmic_i2c_client_ptr == (i2c_client *)0x0) {
        return_value = -0x205;
        _dev_err(device_ptr_base_device, "not find pmic i2c client\n");
        goto LAB_00101df0;
      }
      pmic_ptr = (ebc_pmic *)(pmic_i2c_client_ptr->dev).driver_data;
      ebc_buf_ptr->pmic = pmic_ptr;
      if (pmic_ptr == (ebc_pmic *)0x0) {
        return_value = -0x205;
        _dev_err(device_ptr_base_device,
                 "get drvdata from pmic client failed\n");
        goto LAB_00101df0;
      }
      ebc_info_ptr = &ebc_buf_ptr->info;
      *(device **)((int *)&ebc_buf_ptr->info + 0x14) = device_ptr_base_device;
      (&ebc_buf_ptr->pmic)[1] = (ebc_pmic *)device_ptr_base_device;
      (&ebc_buf_ptr->pmic)[2] = (ebc_pmic *)ebc_buf_ptr->tcon;
      (&ebc_buf_ptr->pmic)[3] = pmic_ptr;
      return_value = of_property_read_variable_u32_array(
          (pdev->dev).of_node, "panel,width",
          (u32 *)((long)&ebc_buf_ptr->pmic + 0x54), 1, 0);
      if ((((((return_value < 0) ||
              (return_value = of_property_read_variable_u32_array(
                   (pdev->dev).of_node, "panel,height",
                   (u32 *)(&ebc_buf_ptr->pmic + 0xb), 1, 0),
               return_value < 0)) ||
             (return_value = of_property_read_variable_u32_array(
                  (pdev->dev).of_node, "panel,sdck", (u32 *)&ebc_buf_ptr->panel,
                  1, 0),
              return_value < 0)) ||
            ((return_value = of_property_read_variable_u32_array(
                  (pdev->dev).of_node, "panel,lsl",
                  (u32 *)&ebc_buf_ptr->panel + 1, 1, 0),
              return_value < 0 ||
                  (return_value = of_property_read_variable_u32_array(
                       (pdev->dev).of_node, "panel,lbl",
                       (u32 *)&ebc_buf_ptr->panel, 1, 0),
                   return_value < 0)))) ||
           ((return_value = of_property_read_variable_u32_array(
                 (pdev->dev).of_node, "panel,ldl",
                 (u32 *)&ebc_buf_ptr->panel + 1, 1, 0),
             return_value < 0 ||
                 ((return_value = of_property_read_variable_u32_array(
                       (pdev->dev).of_node, "panel,lel",
                       (u32 *)&ebc_buf_ptr->panel + 2, 1, 0),
                   return_value < 0 ||
                       (return_value = of_property_read_variable_u32_array(
                            (pdev->dev).of_node, "panel,gdck-sta",
                            (u32 *)&ebc_buf_ptr->panel + 3, 1, 0),
                        return_value < 0)))))) ||
          ((return_value = of_property_read_variable_u32_array(
                (pdev->dev).of_node, "panel,lgonl",
                (u32 *)&ebc_buf_ptr->panel + 4, 1, 0),
            return_value < 0 ||
                ((((return_value = of_property_read_variable_u32_array(
                        (pdev->dev).of_node, "panel,fsl",
                        (u32 *)&ebc_buf_ptr->panel + 5, 1, 0),
                    return_value < 0 ||
                        (return_value = of_property_read_variable_u32_array(
                             (pdev->dev).of_node, "panel,fbl",
                             (u32 *)&ebc_buf_ptr->panel + 6, 1, 0),
                         return_value < 0)) ||
                   (return_value = of_property_read_variable_u32_array(
                        (pdev->dev).of_node, "panel,fdl",
                        (u32 *)&ebc_buf_ptr->panel + 7, 1, 0),
                    return_value < 0)) ||
                  (return_value = of_property_read_variable_u32_array(
                       (pdev->dev).of_node, "panel,fel",
                       (u32 *)&ebc_buf_ptr->panel, 1, 0),
                   return_value < 0)))))) {
        return_value = -0x16;
        _dev_err(device_ptr_base_device, "failed to probe panel: %d\n",
                 0xffffffea);
        goto LAB_00101df0;
      }
      return_value = of_property_read_variable_u32_array(
          (pdev->dev).of_node, "panel,panel_16bit",
          (u32 *)&ebc_buf_ptr->panel + 1, 1, 0);
      if (return_value < 0) {
        platform_device_node = (pdev->dev).of_node;
        ((u32 *)&ebc_buf_ptr->panel)[1] = 0;
        return_value = of_property_read_variable_u32_array(
            platform_device_node, "panel,panel_color",
            (u32 *)&ebc_buf_ptr->panel, 1, 0);
        if (return_value < 0)
          goto LAB_00101ea8;
      LAB_00101ba8:
        return_value = of_property_read_variable_u32_array(
            (pdev->dev).of_node, "panel,mirror", (u32 *)&ebc_buf_ptr->panel + 1,
            1, 0);
        if (-1 < return_value)
          goto LAB_00101bc8;
      LAB_00101e80:
        platform_device_node = (pdev->dev).of_node;
        ((u32 *)&ebc_buf_ptr->panel)[1] = 0;
        return_value = of_property_read_variable_u32_array(
            platform_device_node, "panel,width-mm",
            (u32 *)((long)&ebc_buf_ptr->pmic + 0x5c), 1, 0);
        if (return_value < 0)
          goto LAB_00101e58;
      LAB_00101be8:
        return_value = of_property_read_variable_u32_array(
            (pdev->dev).of_node, "panel,height-mm", (u32 *)&ebc_buf_ptr->panel,
            1, 0);
      } else {
        return_value = of_property_read_variable_u32_array(
            (pdev->dev).of_node, "panel,panel_color",
            (u32 *)&ebc_buf_ptr->panel, 1, 0);
        if (-1 < return_value)
          goto LAB_00101ba8;
      LAB_00101ea8:
        platform_device_node = (pdev->dev).of_node;
        *(u32 *)&ebc_buf_ptr->panel = 0;
        return_value = of_property_read_variable_u32_array(
            platform_device_node, "panel,mirror",
            (u32 *)&ebc_buf_ptr->panel + 1, 1, 0);
        if (return_value < 0)
          goto LAB_00101e80;
      LAB_00101bc8:
        return_value = of_property_read_variable_u32_array(
            (pdev->dev).of_node, "panel,width-mm",
            (u32 *)((long)&ebc_buf_ptr->pmic + 0x5c), 1, 0);
        if (-1 < return_value)
          goto LAB_00101be8;
      LAB_00101e58:
        platform_device_node = (pdev->dev).of_node;
        *(undefined4 *)((long)&ebc_buf_ptr->pmic + 0x5c) = 0;
        return_value = of_property_read_variable_u32_array(
            platform_device_node, "panel,height-mm", (u32 *)&ebc_buf_ptr->panel,
            1, 0);
      }
      if (return_value < 0) {
        *(u32 *)&ebc_buf_ptr->panel = 0;
      }
      return_value = *(int *)(&ebc_buf_ptr->pmic + 0xb);
      ((int *)&ebc_buf_ptr->info)[0xc] = return_value;
      iVar11 = *(int *)((long)&ebc_buf_ptr->pmic + 0x54);
      ((int *)&ebc_buf_ptr->info)[0xd] = iVar11;
      uVar4 = return_value * iVar11;
      ((int *)&ebc_buf_ptr->info)[1] = uVar4 >> 1;
      ((int *)&ebc_buf_ptr->info)[2] = uVar4 >> 2;
      device_ptr = ebc_buf_ptr->dev;
      platform_device_node =
          of_parse_phandle(device_ptr->of_node, "memory-region", 0);
      if (platform_device_node == (device_node *)0x0) {
        return_value = -0x13;
      } else {
        return_value =
            of_address_to_resource(platform_device_node, 0, &resource_obj);
        if (return_value == 0) {
          (ebc_buf_ptr->info).ebc_buffer_phy_addr =
              CONCAT44(resource_obj.start._4_4_, (uint)resource_obj.start);
          return_value = ((int)resource_obj.end + 1) - (uint)resource_obj.start;
          *(int *)&ebc_buf_ptr->info = return_value;
          pcVar7 = (char *)devm_memremap(
              device_ptr,
              CONCAT44(resource_obj.start._4_4_, (uint)resource_obj.start),
              (long)return_value, 1);
          *(char **)&ebc_buf_ptr->info = pcVar7;
          if ((pcVar7 != (char *)0x0) &&
              (return_value =
                   ebc_buf_init((ebc_buf_ptr->info).ebc_buffer_phy_addr, pcVar7,
                                *(int *)&ebc_buf_ptr->info, 0x200000, 4),
               return_value == 0)) {
            pcVar7 = *(char **)&ebc_buf_ptr->info;
            (&ebc_buf_ptr->pmic)[6] = (ebc_pmic *)ebc_open;
            peVar2 = (ebc_pmic *)(pcVar7 + 0x800000);
            (&ebc_buf_ptr->pmic)[4] = peVar2;
            peVar3 = (ebc_pmic *)(pcVar7 + 0x900000);
            uVar10 = (ebc_buf_ptr->info).ebc_buffer_phy_addr;
            (&ebc_buf_ptr->pmic)[5] = (ebc_pmic *)(uVar10 + 0x800000);
            ((u8 **)&ebc_buf_ptr->info)[8] = (u8 *)peVar2;
            (&ebc_buf_ptr->pmic)[9] = (ebc_pmic *)0x100000;
            (&ebc_buf_ptr->pmic)[7] = peVar3;
            (&ebc_buf_ptr->pmic)[8] = (ebc_pmic *)(uVar10 + 0x900000);
            ((u8 **)&ebc_buf_ptr->info)[9] = (u8 *)peVar3;
            puVar8 = (u8 *)devm_kmalloc(
                device_ptr, (long)((int *)&ebc_buf_ptr->info)[1], 0x6080c0);
            ((u8 **)&ebc_buf_ptr->info)[2] = puVar8;
            if (puVar8 != (u8 *)0x0) {
              puVar8 = (u8 *)devm_kmalloc(
                  device_ptr, (long)((int *)&ebc_buf_ptr->info)[1], 0x6080c0);
              ((u8 **)&ebc_buf_ptr->info)[3] = puVar8;
              if (((u8 **)&ebc_buf_ptr->info)[2] != (u8 *)0x0) {
                puVar8 = (u8 *)devm_kmalloc(
                    device_ptr, (long)((int *)&ebc_buf_ptr->info)[1], 0x6080c0);
                ((u8 **)&ebc_buf_ptr->info)[4] = puVar8;
                if (((u8 **)&ebc_buf_ptr->info)[2] != (u8 *)0x0) {
                  puVar8 = (u8 *)devm_kmalloc(
                      device_ptr, (long)((int *)&ebc_buf_ptr->info)[1],
                      0x6080c0);
                  ((u8 **)&ebc_buf_ptr->info)[5] = puVar8;
                  if (((u8 **)&ebc_buf_ptr->info)[2] != (u8 *)0x0) {
                    puVar8 = (u8 *)devm_kmalloc(
                        device_ptr, (long)((int *)&ebc_buf_ptr->info)[1],
                        0x6080c0);
                    ((u8 **)&ebc_buf_ptr->info)[6] = puVar8;
                    if (((u8 **)&ebc_buf_ptr->info)[2] != (u8 *)0x0) {
                      return_value = ((int *)&ebc_buf_ptr->info)[1];
                      memset(puVar8, 0, (long)return_value);
                      memset(((u8 **)&ebc_buf_ptr->info)[4], 0xff,
                             (long)return_value);
                      device_ptr =
                          *(device **)((int *)&ebc_buf_ptr->info + 0x14);
                      platform_device_node = of_parse_phandle(
                          device_ptr->of_node, "waveform-region", 0);
                      if (platform_device_node == (device_node *)0x0) {
                        return_value = -0x13;
                      } else {
                        return_value = of_address_to_resource(
                            platform_device_node, 0, &resource_obj);
                        if (return_value == 0) {
                          iVar11 = ((int)resource_obj.end + 1) -
                                   (uint)resource_obj.start;
                          puVar8 = (u8 *)devm_memremap(
                              device_ptr,
                              CONCAT44(resource_obj.start._4_4_,
                                       (uint)resource_obj.start),
                              (long)iVar11, 1);
                          ((u8 **)&ebc_buf_ptr->info)[0xb] = puVar8;
                          if (puVar8 != (u8 *)0x0) {
                            iVar6 = epd_lut_from_mem_init(puVar8);
                            if (iVar6 < 0) {
                              _dev_err(
                                  *(device **)((int *)&ebc_buf_ptr->info +
                                               0x14),
                                  "Failed to read waveform from mem, we use "
                                  "waveform file from kernel file instead\n");
                              iVar11 = epd_lut_from_file_init(
                                  *(device **)((int *)&ebc_buf_ptr->info +
                                               0x14),
                                  ((u8 **)&ebc_buf_ptr->info)[0xb], iVar11);
                              if (iVar11 < 0) {
                                return_value = -1;
                                _dev_err(
                                    *(device **)((int *)&ebc_buf_ptr->info +
                                                 0x14),
                                    "Failed to read waveform file from kernel, "
                                    "no waveform!!!\n");
                                goto LAB_00101dc4;
                              }
                            }
                            plVar1 =
                                &((work_struct *)&ebc_buf_ptr->info)->entry;
                            (((work_struct *)&ebc_buf_ptr->info)->data)
                                .counter = 0xfffffffe0;
                            (((work_struct *)&ebc_buf_ptr->info)->entry).next =
                                plVar1;
                            *(list_head **)&ebc_buf_ptr->info = plVar1;
                            *(code **)&ebc_buf_ptr->info = new_buffer_refresh;
                            resource_obj.start._0_4_ = 99;
                            ebc_auto_task = kthread_create_on_node(
                                ebc_auto_tast_function, ebc_info_ptr, -1,
                                "ebc_task");
                            if (ebc_auto_task <
                                (task_struct *)0xfffffffffffff001) {
                              sched_setscheduler_nocheck(
                                  ebc_auto_task, 1,
                                  (sched_param *)&resource_obj);
                              __ll_sc_atomic_add(1,
                                                 (long *)&ebc_auto_task->usage);
                              ebc_refresh_task = kthread_create_on_node(
                                  ebc_refresh_tast_function, ebc_info_ptr, -1,
                                  "ebc_refresh_task");
                              if (ebc_refresh_task <
                                  (task_struct *)0xfffffffffffff001) {
                                sched_setscheduler_nocheck(
                                    ebc_refresh_task, 1,
                                    (sched_param *)&resource_obj);
                                __ll_sc_atomic_add(
                                    1, (long *)&ebc_refresh_task->usage);
                                resource_obj.start._0_4_ = 99;
                                task = kthread_create_on_node(
                                    ebc_thread, ebc_info_ptr, -1, "ebc_thread");
                                if (task < (task_struct *)0xfffffffffffff001) {
                                  wake_up_process(task);
                                  ((u8 **)&ebc_buf_ptr->info)[1] = (u8 *)task;
                                  sched_setscheduler_nocheck(
                                      task, 1, (sched_param *)&resource_obj);
                                  __ll_sc_atomic_add(
                                      1,
                                      (long *)(((u8 **)&ebc_buf_ptr->info)[1] +
                                               0x30));
                                  ((int *)&ebc_buf_ptr->info)[0xb] = -1;
                                  ((int *)&ebc_buf_ptr->info)[3] = 0;
                                  ((int *)&ebc_buf_ptr->info)[5] = 0;
                                  ((int *)&ebc_buf_ptr->info)[0x12] = 0;
                                  *(undefined4 *)((u8 **)&ebc_buf_ptr->info +
                                                  10) = 0;
                                  *(int *)&ebc_buf_ptr->info = 0;
                                  ((int *)&ebc_buf_ptr->info)[1] = 0;
                                  ((wakeup_source *)((u8 **)&ebc_buf_ptr->info +
                                                     0xe))
                                      ->name = (char *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0xf] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x10] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x11] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x12] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x13] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x14] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x15] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x16] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x17] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x18] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x19] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1a] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1b] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1c] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1d] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1e] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x1f] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x20] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x21] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x22] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x23] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x24] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x25] = (u8 *)0x0;
                                  ((u8 **)&ebc_buf_ptr->info)[0x26] = (u8 *)0x0;
                                  *(undefined8 *)&ebc_buf_ptr->info = 0;
                                  ((u8 **)&ebc_buf_ptr->info)[0xe] = "ebc";
                                  wakeup_source_add(
                                      (wakeup_source
                                           *)((u8 **)&ebc_buf_ptr->info + 0xe));
                                  *(int *)&ebc_buf_ptr->info = 0;
                                  init_timer_key(
                                      (timer_list *)&ebc_buf_ptr->info,
                                      ebc_vdd_power_timeout, 0, (char *)0x0,
                                      (lock_class_key *)0x0);
                                  mod_timer((timer_list *)&ebc_buf_ptr->info,
                                            _devm_memremap + 0xfffffff);
                                  init_timer_key(
                                      (timer_list *)&ebc_buf_ptr->info,
                                      ebc_frame_timeout, 0, (char *)0x0,
                                      (lock_class_key *)0x0);
                                  mod_timer((timer_list *)&ebc_buf_ptr->info,
                                            _devm_memremap + 0xfffffff);
                                  pcVar7 = _DAT_00105340;
                                  local_6c = 0;
                                  resource_obj.start._0_4_ = 0;
                                  __s = strstr(_DAT_00105340, "ulogo_addr=");
                                  pcVar7 = strstr(pcVar7, "klogo_addr=");
                                  if ((__s == (char *)0x0) ||
                                      (sscanf(__s, "ulogo_addr=0x%x",
                                              &local_6c),
                                       (ulong)local_6c <
                                           (ebc_buf_ptr->info)
                                               .ebc_buffer_phy_addr)) {
                                    bVar5 = false;
                                    __dest_00 = (void *)0x0;
                                    __dest = (void *)0x0;
                                    if (pcVar7 != (char *)0x0) {
                                    LAB_0010216c:
                                      sscanf(pcVar7, "klogo_addr=0x%x",
                                             &resource_obj);
                                      pcVar7 = (char *)0x0;
                                      __dest = (void *)0x0;
                                      if ((ebc_buf_ptr->info)
                                              .ebc_buffer_phy_addr <=
                                          (ulong)(uint)resource_obj.start) {
                                        _dev_info(
                                            *(device **)((int *)&ebc_buf_ptr
                                                             ->info +
                                                         0x14),
                                            "need show klogo, klogo addr = "
                                            "0x%x\n");
                                        __dest = __kmalloc(
                                            (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                        ->pmic +
                                                                    0x54) *
                                                           *(int *)(&ebc_buf_ptr
                                                                         ->pmic +
                                                                    0xb)) >>
                                                    1),
                                            0x6080c0);
                                        if (__dest == (void *)0x0) {
                                          _dev_err(
                                              *(device **)((int *)&ebc_buf_ptr
                                                               ->info +
                                                           0x14),
                                              "malloc klogo buffer failed\n");
                                          goto LAB_00102220;
                                        }
                                        pcVar7 = (char *)0x1;
                                        memcpy(
                                            __dest,
                                            *(char **)&ebc_buf_ptr->info +
                                                ((ulong)(uint)
                                                     resource_obj.start -
                                                 (ebc_buf_ptr->info)
                                                     .ebc_buffer_phy_addr),
                                            (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                        ->pmic +
                                                                    0x54) *
                                                           *(int *)(&ebc_buf_ptr
                                                                         ->pmic +
                                                                    0xb)) >>
                                                    1));
                                      }
                                      iVar11 = (int)pcVar7;
                                      if (bVar5)
                                        goto LAB_001022f8;
                                    }
                                    iVar11 = (int)pcVar7;
                                    _dev_info(
                                        *(device **)((int *)&ebc_buf_ptr->info +
                                                     0x14),
                                        "no uboot logo, panel init\n");
                                    ebc_pmic_verity_vcom(ebc_buf_ptr->pmic);
                                    peVar9 = ebc_empty_buf_get();
                                    memset(
                                        peVar9->virt_addr, 0xff,
                                        (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                    ->pmic +
                                                                0x54) *
                                                       *(int *)(&ebc_buf_ptr
                                                                     ->pmic +
                                                                0xb)) >>
                                                1));
                                    peVar9->win_x1 = 0;
                                    peVar9->win_y1 = 0;
                                    peVar9->buf_mode = 0xe;
                                    peVar9->win_x2 = *(
                                        int *)((long)&ebc_buf_ptr->pmic + 0x54);
                                    peVar9->win_y2 =
                                        *(int *)(&ebc_buf_ptr->pmic + 0xb);
                                    ebc_add_to_dsp_buf_list(peVar9);
                                  LAB_001021f8:
                                    if ((iVar11 != 0) &&
                                        (peVar9 = ebc_empty_buf_get(),
                                         peVar9 != (struct ebc_buf_s *)0x0)) {
                                      memcpy(
                                          peVar9->virt_addr, __dest,
                                          (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                      ->pmic +
                                                                  0x54) *
                                                         *(int *)(&ebc_buf_ptr
                                                                       ->pmic +
                                                                  0xb)) >>
                                                  1));
                                      peVar9->win_x1 = 0;
                                      peVar9->win_y1 = 0;
                                      peVar9->buf_mode = 7;
                                      peVar9->win_x2 =
                                          *(int *)((long)&ebc_buf_ptr->pmic +
                                                   0x54);
                                      peVar9->win_y2 =
                                          *(int *)(&ebc_buf_ptr->pmic + 0xb);
                                      ebc_add_to_dsp_buf_list(peVar9);
                                    }
                                    if (((int *)&ebc_buf_ptr->info)[0x12] ==
                                        0) {
                                      ((int *)&ebc_buf_ptr->info)[0x12] = 1;
                                      __wake_up_sync(&ebc_thread_wq, 1, 1);
                                    }
                                    if (__dest_00 != (void *)0x0) {
                                      kfree(__dest_00);
                                    }
                                    if (__dest != (void *)0x0) {
                                      kfree(__dest);
                                    }
                                  } else {
                                    _dev_info(
                                        *(device **)((int *)&ebc_buf_ptr->info +
                                                     0x14),
                                        "have ulogo display, ulogo addr = "
                                        "0x%x\n");
                                    __dest_00 = __kmalloc(
                                        (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                    ->pmic +
                                                                0x54) *
                                                       *(int *)(&ebc_buf_ptr
                                                                     ->pmic +
                                                                0xb)) >>
                                                1),
                                        0x6080c0);
                                    if (__dest_00 != (void *)0x0) {
                                      memcpy(
                                          __dest_00,
                                          *(char **)&ebc_buf_ptr->info +
                                              ((ulong)local_6c -
                                               (ebc_buf_ptr->info)
                                                   .ebc_buffer_phy_addr),
                                          (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                      ->pmic +
                                                                  0x54) *
                                                         *(int *)(&ebc_buf_ptr
                                                                       ->pmic +
                                                                  0xb)) >>
                                                  1));
                                      if (pcVar7 != (char *)0x0) {
                                        bVar5 = true;
                                        goto LAB_0010216c;
                                      }
                                      iVar11 = 0;
                                      __dest = (void *)0x0;
                                    LAB_001022f8:
                                      peVar9 = ebc_empty_buf_get();
                                      if (peVar9 != (struct ebc_buf_s *)0x0) {
                                        memcpy(
                                            peVar9->virt_addr, __dest_00,
                                            (ulong)((uint)(*(int *)((long)&ebc_buf_ptr
                                                                        ->pmic +
                                                                    0x54) *
                                                           *(int *)(&ebc_buf_ptr
                                                                         ->pmic +
                                                                    0xb)) >>
                                                    1));
                                        peVar9->win_x1 = 0;
                                        peVar9->win_y1 = 0;
                                        peVar9->buf_mode = 7;
                                        peVar9->win_x2 =
                                            *(int *)((long)&ebc_buf_ptr->pmic +
                                                     0x54);
                                        peVar9->win_y2 =
                                            *(int *)(&ebc_buf_ptr->pmic + 0xb);
                                        ebc_add_to_dsp_buf_list(peVar9);
                                      }
                                      goto LAB_001021f8;
                                    }
                                    _dev_err(
                                        *(device **)((int *)&ebc_buf_ptr->info +
                                                     0x14),
                                        "malloc ulogo buffer failed\n");
                                  }
                                LAB_00102220:
                                  (pdev->dev).driver_data = ebc_buf_ptr;
                                  misc_register(&ebc_misc);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_waveform_version);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_pmic_name);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_pmic_temp);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_pmic_vcom);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_ebc_version);
                                  device_create_file(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      &dev_attr_ebc_state);
                                  _dev_info(
                                      *(device **)((int *)&ebc_buf_ptr->info +
                                                   0x14),
                                      "rockchip ebc driver %s probe success\n",
                                      "1.01");
                                  goto LAB_00101df0;
                                }
                                device_ptr =
                                    *(device **)((int *)&ebc_buf_ptr->info +
                                                 0x14);
                                ((u8 **)&ebc_buf_ptr->info)[1] = (u8 *)task;
                                _dev_err(device_ptr,
                                         "failed to run ebc thread\n");
                              } else {
                                _dev_err(
                                    *(device **)((int *)&ebc_buf_ptr->info +
                                                 0x14),
                                    "failed to create ebc_refresh_task "
                                    "thread\n");
                              }
                            } else {
                              _dev_err(*(device **)((int *)&ebc_buf_ptr->info +
                                                    0x14),
                                       "failed to create ebc_task thread\n");
                            }
                            return_value = -1;
                            _dev_err(device_ptr_base_device,
                                     "task init failed\n");
                            goto LAB_00101df0;
                          }
                          return_value = -0xc;
                          _dev_err(
                              *(device **)((int *)&ebc_buf_ptr->info + 0x14),
                              "%s:%d: failed to get mem from reserved\n",
                              "ebc_lut_table_init", 0x5f8);
                        }
                      }
                    LAB_00101dc4:
                      _dev_err(device_ptr_base_device,
                               "lut table init failed\n");
                      goto LAB_00101df0;
                    }
                  }
                }
              }
            }
          }
          return_value = -0xc;
        } else {
          _dev_err(device_ptr,
                   "Couldn\'t address to resource for reserved memory\n");
        }
      }
      _dev_err(device_ptr_base_device, "buffer manage init failed\n");
      goto LAB_00101df0;
    }
  }
  return_value = -0x205;
LAB_00101df0:
  return return_value;
}

// Turn device power on

int ebc_power_set_on(ebc *ebc, int power_status)

{
  if ((ebc->info).wake_lock_is_set == 0) {
    (ebc->info).wake_lock_is_set = 1;
    __pm_stay_awake((wakeup_source *)&(ebc->info).suspend_lock);
  }
  (ebc->info).ebc_power_status = 1;
  (*ebc->tcon->enable)(ebc->tcon, &ebc->panel);
  (*ebc->pmic->pmic_power_req)(ebc->pmic, true);
  _dev_info(ebc->dev, "ebc hw power on\n");
  return 0;
}

void refresh_new_image2(u32 *image_new, u32 *image_fb, u32 *image_bg,
                        u32 *frame_count, ebc_info *ebc_info, int buf_mode)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;

  iVar3 = ebc_info->height;
  iVar6 = ebc_info->width;
  iVar2 = iVar6 + 0xf;
  if (-1 < iVar6) {
    iVar2 = iVar6;
  }
  iVar2 >>= 4;
  if (0 < iVar3) {
    iVar6 = 0;
    lVar1 = (ulong)(iVar2 - 1) + 1;
    do {
      lVar4 = 0;
      if (0 < iVar2) {
        do {
          uVar5 = 0xffffffffffffffff;
          if (buf_mode != 0) {
            uVar5 = *(ulong *)image_bg;
            image_bg = (u32 *)((long)image_bg + 8);
          }
          uVar5 = uVar5 & *(ulong *)(image_fb + lVar4 * 2);
          if (*(long *)(frame_count + lVar4 * 2) != 0) {
            uVar5 = *(ulong *)(image_new + lVar4 * 2);
          }
          *(ulong *)(image_new + lVar4 * 2) = uVar5;
          lVar4 += 1;
        } while ((int)lVar4 < iVar2);
        frame_count = frame_count + lVar1 * 2;
        image_fb = image_fb + lVar1 * 2;
        image_new = image_new + lVar1 * 2;
      }
      iVar6 += 1;
    } while (iVar3 != iVar6);
  }
  return;
}

void new_buffer_refresh(work_struct *work)

{
  down(&auto_sem);
  refresh_new_image2((u32 *)ebc_global.info.auto_image_new,
                     (u32 *)ebc_global.info.auto_image_cur,
                     (u32 *)ebc_global.info.auto_image_bg,
                     (u32 *)ebc_global.info.auto_frames, &ebc_global.info,
                     (ebc_global.info.curr_dsp_buf)->buf_mode);
  up(&auto_sem);
  return;
}

// WARNING: Globals starting with '_' overlap smaller symbols at the same
// address

int ebc_thread(void *ptr)

{
  int **ppiVar1;
  int iVar6;
  struct ebc_buf_s *esp_dsp_buf_ptr;
  long ebc_wq_ptr;
  uint buf_mode_temp;
  ulong uVar10;
  int *temp;
  char *virt_addr;
  struct wait_queue_entry *pwVar12;
  ulong uVar13;
  int **ppiVar14;
  int **ppiVar15;
  int full_mode_num_iterator;
  struct wait_queue_entry __wq_entry;
  u8 *auto_frames;
  int *auto_image_bg;
  int *auto_image_cur;
  int buf_mode;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  struct ebc_buf_s *prev_disp_buff_ptr;
  int win_x1;
  int win_x2;

  iVar6 = 0;
  full_mode_num_iterator = 0;
joined_r0x00102770:
  while (true) {
    if (ebc_global.info.is_power_off != 0) {
      if (ebc_global.info.ebc_power_status == 1) {
        ebc_power_set_off(&ebc_global, 0);
      }
      return 0;
    }
    esp_dsp_buf_ptr = ebc_dsp_buf_get();
    if ((esp_dsp_buf_ptr == (struct ebc_buf_s *)0x0) ||
        (esp_dsp_buf_ptr->phy_addr == 0))
      break;
    buf_mode = esp_dsp_buf_ptr->buf_mode;
    if (buf_mode == 0x11) {
      ebc_global.info.overlay_enable = 0;
      ebc_global.info.overlay_start = 0;
    LAB_00102904:
      mod_timer(&ebc_global.info.vdd_timer, _devm_memremap + 0x18000000);
      prev_disp_buff_ptr = esp_dsp_buf_ptr;
      if (ebc_global.info.first_in != 0) {
        prev_disp_buff_ptr = ebc_global.info.prev_dsp_buf;
      }
      ebc_global.info.prev_dsp_buf = prev_disp_buff_ptr;
      buf_mode = (ebc_global.info.prev_dsp_buf)->buf_mode;
      if (esp_dsp_buf_ptr->buf_mode != buf_mode) {
        _dev_info(ebc_global.info.dev, "change display mode from %d to %d\n",
                  buf_mode, esp_dsp_buf_ptr->buf_mode);
        buf_mode = esp_dsp_buf_ptr->buf_mode;
      }
      if (buf_mode < 7) {
        if (buf_mode < 2) {
          if (buf_mode == 0) {
            down(&auto_sem);
            ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
            memcpy(ebc_global.info.auto_image_cur, esp_dsp_buf_ptr->virt_addr,
                   (long)ebc_global.info.ebc_buf_real_size);
            if (((ebc_global.info.prev_dsp_buf)->buf_mode == 0) ||
                (memset(ebc_global.info.auto_image_bg, 0xff,
                        (long)ebc_global.info.ebc_buf_real_size),
                 (uint)(ebc_global.info.prev_dsp_buf)->buf_mode < 2)) {
              temp = ebc_global.info.auto_image_cur;
              refresh_new_image2((u32 *)ebc_global.info.auto_image_new,
                                 (u32 *)ebc_global.info.auto_image_cur,
                                 (u32 *)ebc_global.info.auto_image_bg,
                                 (u32 *)ebc_global.info.auto_frames,
                                 &ebc_global.info,
                                 (ebc_global.info.curr_dsp_buf)->buf_mode);
              buf_mode = (int)temp;
            } else {
              memcpy(ebc_global.info.auto_image_new,
                     (ebc_global.info.curr_dsp_buf)->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              virt_addr = (ebc_global.info.prev_dsp_buf)->virt_addr;
              memcpy(ebc_global.info.auto_image_old, virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              buf_mode = (int)virt_addr;
            }
            up(&auto_sem);
            if (ebc_global.info.is_busy_now == 0) {
              ebc_global.info.is_busy_now = 1;
              ebc_global.info.ebc_irq_status = 0;
              if (ebc_global.info.ebc_power_status == 0) {
                ebc_power_set_on(&ebc_global, buf_mode);
              }
              buf_mode = ebc_lut_update(&ebc_global);
              if (buf_mode == -1) {
                _dev_err(ebc_global.info.dev, "ebc_lut_update err\n");
              } else {
                ebc_global.info.frame_total =
                    (char)(ebc_global.info.lut_data.frame_num & 0xff);
                ebc_global.info.frame_bw_total = ebc_global.info.frame_total;
                _dev_info(ebc_global.info.dev,
                          "auto mode start, frame_total=%d\n",
                          (ulong)(ebc_global.info.lut_data.frame_num & 0xff));
                ebc_global.info.task_restart = 1;
                wake_up_process(ebc_auto_task);
              }
            }
          } else {
            if (buf_mode != 1)
              goto LAB_00102b28;
            if (ebc_global.info.overlay_enable != 0) {
              ebc_global.info.overlay_start = 1;
            }
            if ((ebc_global.info.prev_dsp_buf)->buf_mode == 1) {
              memcpy(ebc_global.info.auto_image_cur, esp_dsp_buf_ptr->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
            } else {
              down(&auto_sem);
              memcpy(ebc_global.info.auto_image_bg,
                     (ebc_global.info.prev_dsp_buf)->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              memcpy(ebc_global.info.auto_image_cur, esp_dsp_buf_ptr->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
              up(&auto_sem);
            }
            if (1 < (uint)(ebc_global.info.prev_dsp_buf)->buf_mode) {
              memcpy(ebc_global.info.auto_image_new,
                     (ebc_global.info.prev_dsp_buf)->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
              memcpy(ebc_global.info.auto_image_old,
                     (ebc_global.info.prev_dsp_buf)->virt_addr,
                     (long)ebc_global.info.ebc_buf_real_size);
            }
            auto_frames = ebc_global.info.auto_frames;
            auto_image_cur = ebc_global.info.auto_image_cur;
            auto_image_bg = ebc_global.info.auto_image_bg;
            temp = ebc_global.info.auto_image_new;
            win_x1 = (ebc_global.info.curr_dsp_buf)->win_x1;
            buf_mode = (ebc_global.info.curr_dsp_buf)->win_y1;
            win_x2 = (ebc_global.info.curr_dsp_buf)->win_x2;
            iVar2 = win_x1 + 0xf;
            if (-1 < win_x1) {
              iVar2 = win_x1;
            }
            iVar4 = (ebc_global.info.curr_dsp_buf)->buf_mode;
            win_x1 = win_x2 + 0xf;
            if (-1 < win_x2) {
              win_x1 = win_x2;
            }
            win_x2 = ebc_global.info.width + 0xf;
            if (-1 < ebc_global.info.width) {
              win_x2 = ebc_global.info.width;
            }
            win_x1 = (win_x1 >> 4) + 1;
            iVar3 = (win_x2 >> 4) + -1;
            if (win_x1 < win_x2 >> 4) {
              iVar3 = win_x1;
            }
            win_x1 = ebc_global.info.height + -1;
            if ((ebc_global.info.curr_dsp_buf)->win_y2 <
                ebc_global.info.height) {
              win_x1 = (ebc_global.info.curr_dsp_buf)->win_y2;
            }
            prev_disp_buff_ptr = ebc_global.info.curr_dsp_buf;
            if (buf_mode <= win_x1) {
              do {
                iVar5 = buf_mode * ebc_global.info.width;
                win_x2 = iVar2 >> 4;
              joined_r0x00102a84:
                if (win_x2 <= iVar3) {
                  do {
                    ebc_wq_ptr = (long)(iVar5 / 2) + (long)win_x2 * 8;
                    uVar13 = 0xffffffffffffffff;
                    uVar10 = *(ulong *)((long)auto_image_cur + ebc_wq_ptr);
                    if (iVar4 != 0) {
                      uVar13 = *(ulong *)((long)auto_image_bg + ebc_wq_ptr);
                    }
                    if (*(long *)(auto_frames + ebc_wq_ptr) == 0) {
                      *(ulong *)((long)temp + ebc_wq_ptr) = uVar10 & uVar13;
                    } else {
                      prev_disp_buff_ptr =
                          (struct ebc_buf_s *)(uVar10 & uVar13);
                      if (*(struct ebc_buf_s **)((long)temp + ebc_wq_ptr) !=
                          prev_disp_buff_ptr)
                        goto code_r0x00102ad0;
                    }
                    prev_disp_buff_ptr = (struct ebc_buf_s *)(uVar10 & uVar13);
                    win_x2 += 1;
                    if (iVar3 < win_x2)
                      break;
                  } while (true);
                }
                buf_mode += 1;
                if (win_x1 < buf_mode)
                  break;
              } while (true);
            }
            if (ebc_global.info.is_busy_now == 0) {
              ebc_global.info.is_busy_now = 1;
              ebc_global.info.task_restart = 1;
              ebc_global.info.ebc_irq_status = 0;
              if (ebc_global.info.ebc_power_status == 0) {
                ebc_power_set_on(&ebc_global, (int)prev_disp_buff_ptr);
              }
              buf_mode = ebc_lut_update(&ebc_global);
              if (buf_mode != -1) {
                ebc_global.info.frame_total =
                    (char)(ebc_global.info.lut_data.frame_num & 0xff);
                ebc_global.info.frame_bw_total = ebc_global.info.frame_total;
                _dev_info(ebc_global.info.dev,
                          "overlay mode start, frame_total=%d\n",
                          (ulong)(ebc_global.info.lut_data.frame_num & 0xff));
                wake_up_process(ebc_auto_task);
              }
            }
          }
          goto one_buffer_end;
        }
      LAB_00102b70:
        iVar6 = 1;
      LAB_00102b74:
        if (ebc_global.info.is_busy_now == 1) {
          _dev_info(ebc_global.info.dev,
                    "ebc is busy now, waiting prev refresh mode end...\n");
          if (ebc_global.info.ebc_irq_status == 0) {
            init_wait_entry(&__wq_entry, 0);
            while (ebc_wq_ptr = prepare_to_wait_event(&ebc_wq, &__wq_entry, 1),
                   ebc_global.info.ebc_irq_status == 0) {
              if (ebc_wq_ptr != 0)
                goto __out;
              schedule();
            }
            finish_wait(&ebc_wq, &__wq_entry);
          }
        __out:
          _dev_info(ebc_global.info.dev, "prev refresh mode end\n");
          buf_mode_temp = (ebc_global.info.prev_dsp_buf)->buf_mode;
          temp = ebc_global.info.auto_image_old;
        } else {
          buf_mode_temp = (ebc_global.info.prev_dsp_buf)->buf_mode;
          temp = ebc_global.info.auto_image_old;
        }
        auto_image_bg = (int *)(ulong)buf_mode_temp;
        ebc_global.info.auto_image_old = temp;
        if (buf_mode_temp < 2) {
          memcpy((ebc_global.info.prev_dsp_buf)->virt_addr, temp,
                 (long)ebc_global.info.ebc_buf_real_size);
          auto_image_bg = temp;
        }
        iVar2 = ebc_global.info.full_mode_num;
        ebc_global.info.ebc_irq_status = 0;
        buf_mode = esp_dsp_buf_ptr->buf_mode;
        if (buf_mode - 7U < 5) {
          ppiVar14 = (int **)esp_dsp_buf_ptr->virt_addr;
          buf_mode_temp = ebc_global.panel.width * ebc_global.panel.height >> 1;
          ppiVar15 = (int **)(ebc_global.info.prev_dsp_buf)->virt_addr;
          win_x1 = (int)buf_mode_temp >> 3;
          if (win_x1 == 0) {
          LAB_00102f18:
            buf_mode_temp &= 7;
            if (buf_mode_temp != 0) {
              temp = (int *)0x0;
              auto_image_bg = (int *)(((ulong)(buf_mode_temp - 1) + 1) * 4);
              do {
                if (*(char *)((long)ppiVar14 + (long)temp) !=
                    *(char *)((long)ppiVar15 + (long)temp))
                  goto LAB_00102ba8;
                temp = temp + 1;
              } while (temp != auto_image_bg);
            }
            ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
            _dev_info(ebc_global.info.dev,
                      "check_part_mode==0, no need refresh\n");
            goto one_buffer_end;
          }
          auto_image_bg = *ppiVar14;
          if (*ppiVar15 == auto_image_bg) {
            ebc_wq_ptr = 8;
            do {
              if (((ulong)(win_x1 - 1) + 1) * 8 - ebc_wq_ptr == 0)
                goto LAB_00102f18;
              ppiVar1 = (int **)((long)ppiVar14 + ebc_wq_ptr);
              auto_image_bg = *(int **)((long)ppiVar15 + ebc_wq_ptr);
              ebc_wq_ptr = ebc_wq_ptr + 8;
            } while (*ppiVar1 == auto_image_bg);
          }
        }
      LAB_00102ba8:
        buf_mode_temp = (uint)auto_image_bg;
        if (iVar6 == 0) {
          ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
          if ((0 < ebc_global.info.full_mode_num) &&
              (full_mode_num_iterator += 1,
               ebc_global.info.full_mode_num <= full_mode_num_iterator)) {
            esp_dsp_buf_ptr->buf_mode = 2;
            full_mode_num_iterator = 0;
            buf_mode = (ebc_global.info.curr_dsp_buf)->buf_mode;
          }
          buf_mode_temp = iVar2;
          if (buf_mode != 0xc)
            goto LAB_00102bf0;
        LAB_00102da0:
          buf_mode_temp = (ebc_global.info.prev_dsp_buf)->buf_mode - 0xc;
          if (buf_mode_temp < 2)
            goto LAB_00102bf0;
          buf_mode_temp = 0xd;
          (ebc_global.info.curr_dsp_buf)->buf_mode = 0xd;
          if (ebc_global.info.ebc_power_status == 0)
            goto LAB_00102dc4;
        LAB_00102bf8:
          iVar6 = ebc_lut_update(&ebc_global);
        } else {
          full_mode_num_iterator = 0;
          ebc_global.info.curr_dsp_buf = esp_dsp_buf_ptr;
          if (buf_mode == 0xc)
            goto LAB_00102da0;
        LAB_00102bf0:
          if (ebc_global.info.ebc_power_status != 0)
            goto LAB_00102bf8;
        LAB_00102dc4:
          ebc_power_set_on(&ebc_global, buf_mode_temp);
          iVar6 = ebc_lut_update(&ebc_global);
        }
        if (iVar6 == 0) {
          ebc_global.info.frame_total =
              (char)ebc_global.info.lut_data.frame_num;
          _dev_info(ebc_global.info.dev,
                    "frame start, mode = %d, framecount = %d\n",
                    (ulong)(uint)(ebc_global.info.curr_dsp_buf)->buf_mode,
                    (ulong)(ebc_global.info.lut_data.frame_num & 0xff));
          ebc_global.info.is_busy_now = 1;
          ebc_global.info.frame_left =
              ZEXT14((byte)ebc_global.info.frame_total);
          if ((ebc_global.info.curr_dsp_buf)->buf_mode - 7U < 5) {
            direct_mode_data_change_part(
                ebc_global.info.direct_buffer[0],
                (ebc_global.info.curr_dsp_buf)->virt_addr,
                (ebc_global.info.prev_dsp_buf)->virt_addr,
                ebc_global.info.frame_total, ebc_global.info.frame_total,
                ebc_global.info.lut_data.wf_table);
            ebc_global.info.frame_left += -1;
            direct_mode_data_change_part(
                ebc_global.info.direct_buffer[1],
                (ebc_global.info.curr_dsp_buf)->virt_addr,
                (ebc_global.info.prev_dsp_buf)->virt_addr,
                ebc_global.info.frame_total, (byte)ebc_global.info.frame_left,
                ebc_global.info.lut_data.wf_table);
            ebc_global.panel.current_buffer = 0;
            flip(&ebc_global.panel, ebc_global.info.direct_buf_real_size);
            mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 900);
          } else {
            direct_mode_data_change(ebc_global.info.direct_buffer[0],
                                    (ebc_global.info.curr_dsp_buf)->virt_addr,
                                    (ebc_global.info.prev_dsp_buf)->virt_addr,
                                    ebc_global.info.frame_total,
                                    ebc_global.info.frame_total,
                                    ebc_global.info.lut_data.wf_table);
            ebc_global.info.frame_left += -1;
            direct_mode_data_change(ebc_global.info.direct_buffer[1],
                                    (ebc_global.info.curr_dsp_buf)->virt_addr,
                                    (ebc_global.info.prev_dsp_buf)->virt_addr,
                                    ebc_global.info.frame_total,
                                    (byte)ebc_global.info.frame_left,
                                    ebc_global.info.lut_data.wf_table);
            ebc_global.panel.current_buffer = 0;
            flip(&ebc_global.panel, ebc_global.info.direct_buf_real_size);
            mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 900);
          }
          if (ebc_global.info.ebc_irq_status == 0) {
            init_wait_entry(&__wq_entry, 0);
            while (ebc_wq_ptr = prepare_to_wait_event(&ebc_wq, &__wq_entry, 1),
                   ebc_global.info.ebc_irq_status == 0) {
              if (ebc_wq_ptr != 0)
                goto __out;
              schedule();
            }
            finish_wait(&ebc_wq, &__wq_entry);
          }
        __out:
          mod_timer(&ebc_global.info.frame_timer, _devm_memremap + 0x18000000);
          ebc_global.info.ebc_irq_status = 0;
          goto one_buffer_end;
        }
        iVar6 = 0;
        _dev_err(ebc_global.info.dev, "ebc_lut_update err\n");
        buf_mode = (ebc_global.info.curr_dsp_buf)->buf_mode;
        if (buf_mode != 0x11)
          goto LAB_00102b48;
      LAB_00102c2c:
        ebc_global.info.ebc_last_display = 0;
        ebc_global.info.is_power_off = 1;
        _dev_info(ebc_global.info.dev, "power off\n");
        __wake_up_sync(&ebc_poweroff_wq, 1, 1);
        ebc_remove_from_dsp_buf_list(esp_dsp_buf_ptr);
      } else {
        if (buf_mode < 0xe)
          goto LAB_00102b74;
        if (buf_mode < 0x12)
          goto LAB_00102b70;
      LAB_00102b28:
        _dev_err(ebc_global.info.dev, "ebc buffer mode error!\n");
      one_buffer_end:
        buf_mode = (ebc_global.info.curr_dsp_buf)->buf_mode;
        if (buf_mode == 0x11)
          goto LAB_00102c2c;
      LAB_00102b48:
        if (buf_mode == 0xf) {
          ebc_global.info.ebc_last_display = 0;
          ebc_global.info.is_early_suspend = 1;
          ebc_global.info.overlay_start = 0;
          _dev_info(ebc_global.info.dev, "early suspend\n");
          ebc_notify(2);
          __wake_up_sync(&ebc_poweroff_wq, 1, 1);
        }
        ebc_remove_from_dsp_buf_list(esp_dsp_buf_ptr);
      }
      if (ebc_global.info.first_in == 0) {
        ebc_global.info.first_in = 1;
      } else {
        ebc_buf_release(ebc_global.info.prev_dsp_buf);
      }
      ebc_global.info.prev_dsp_buf = ebc_global.info.curr_dsp_buf;
    } else if (CONCAT44(ebc_global.info.is_deep_sleep,
                        ebc_global.info.is_early_suspend) == 0) {
      if (buf_mode == 0xf) {
        ebc_global.info.overlay_start = 0;
        goto LAB_00102904;
      }
      if (ebc_global.info.overlay_start == 0 || buf_mode == 1)
        goto LAB_00102904;
      virt_addr = esp_dsp_buf_ptr->virt_addr;
      memcpy(ebc_global.info.auto_image_bg, virt_addr,
             (long)ebc_global.info.ebc_buf_real_size);
      buf_mode = (int)virt_addr;
      ebc_remove_from_dsp_buf_list(esp_dsp_buf_ptr);
      ebc_buf_release(esp_dsp_buf_ptr);
      wake_up_process(ebc_refresh_task);
      if (ebc_global.info.auto_refresh_done == 0) {
        init_wait_entry(&__wq_entry, 0);
        while (ebc_wq_ptr = prepare_to_wait_event(&ebc_wq, &__wq_entry, 1),
               ebc_global.info.auto_refresh_done == 0) {
          buf_mode = ebc_global.info.auto_refresh_done;
          if (ebc_wq_ptr != 0)
            goto __out;
          schedule();
        }
        pwVar12 = &__wq_entry;
        finish_wait(&ebc_wq, pwVar12);
        buf_mode = (int)pwVar12;
      }
    __out:
      ebc_global.info.auto_refresh_done = 0;
      if (ebc_global.info.is_busy_now == 0) {
        ebc_global.info.is_busy_now = 1;
        ebc_global.info.task_restart = 1;
        ebc_global.info.ebc_irq_status = 0;
        if (ebc_global.info.ebc_power_status == 0) {
          ebc_power_set_on(&ebc_global, buf_mode);
        }
        wake_up_process(ebc_auto_task);
      }
    } else {
      if (buf_mode == 0x10) {
        ebc_global.info.is_early_suspend = 0;
        ebc_notify(3);
        _dev_info(ebc_global.info.dev, "early resume\n");
        goto LAB_00102904;
      }
      ebc_remove_from_dsp_buf_list(esp_dsp_buf_ptr);
      ebc_buf_release(esp_dsp_buf_ptr);
    }
  }
  if (ebc_global.info.is_busy_now == 1) {
    if (ebc_global.info.ebc_dsp_buf_status == 0) {
      init_wait_entry(&__wq_entry, 0);
      while (
          (ebc_wq_ptr = prepare_to_wait_event(&ebc_thread_wq, &__wq_entry, 1),
           ebc_global.info.is_busy_now != 0 &&
               (ebc_global.info.ebc_dsp_buf_status == 0))) {
        if (ebc_wq_ptr != 0)
          goto LAB_00102810;
        schedule();
      }
      finish_wait(&ebc_thread_wq, &__wq_entry);
      if (ebc_global.info.is_busy_now == 0)
        goto joined_r0x00102ccc;
      goto LAB_00102810;
    }
  } else {
  joined_r0x00102ccc:
    if (ebc_global.info.ebc_power_status == 1) {
      ebc_power_set_off(&ebc_global, 0);
    }
  LAB_00102810:
    if (ebc_global.info.ebc_dsp_buf_status == 0) {
      init_wait_entry(&__wq_entry, 0);
      while (ebc_wq_ptr = prepare_to_wait_event(&ebc_thread_wq, &__wq_entry, 1),
             ebc_global.info.ebc_dsp_buf_status == 0) {
        if (ebc_wq_ptr != 0)
          goto __out;
        schedule();
      }
      finish_wait(&ebc_thread_wq, &__wq_entry);
      ebc_global.info.ebc_dsp_buf_status = 0;
      goto joined_r0x00102770;
    }
  }
__out:
  ebc_global.info.ebc_dsp_buf_status = 0;
  goto joined_r0x00102770;
code_r0x00102ad0:
  *(struct ebc_buf_s **)((long)temp + ebc_wq_ptr) = prev_disp_buff_ptr;
  win_x2 += 1;
  *(undefined8 *)(auto_frames + ebc_wq_ptr) = 0x101010101010101;
  goto joined_r0x00102a84;
}

int ebc_refresh_tast_function(void *data) {
  long lVar1;
  lVar1 = cRead_8(sp_el0);
  do {
    down(&ebc_refresh_thread_sem);
    *(undefined8 *)(lVar1 + 0x20) = 2;
    DataMemoryBarrier(2, 3);
    refresh_new_image2((u32 *)ebc_global.info.auto_image_new,
                       (u32 *)ebc_global.info.auto_image_cur,
                       (u32 *)ebc_global.info.auto_image_bg,
                       (u32 *)ebc_global.info.auto_frames, &ebc_global.info,
                       (ebc_global.info.curr_dsp_buf)->buf_mode);
    ebc_global.info.auto_refresh_done = 1;
    __wake_up_sync(&ebc_wq, 1, 1);
    up(&ebc_refresh_thread_sem);
    schedule();
  } while (true);
}

void ebc_exit(void) {
  platform_driver_unregister(&ebc_driver);
  return;
}

int ebc_init(void) {
  int iVar1;

  iVar1 = __platform_driver_register(&ebc_driver, (module *)0x0);
  return iVar1;
}

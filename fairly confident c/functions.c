#include "structs.h"


// Swaps the two buffers in the panel driver struct.. I think

void flip(ebc_panel *panel,ebc_info *ebc_info)

{
  int iVar1;
  device *pdVar2;
  dma_map_ops *pdVar3;
  
  iVar1 = panel->current_buffer;
  pdVar2 = panel->dev;
  if (pdVar2 == (device *)0x0) {
    pdVar3 = (dma_map_ops *)0x5108;
  }
  else {
    pdVar3 = (dma_map_ops *)0x5108;
    if (pdVar2->dma_ops != (dma_map_ops *)0x0) {
      pdVar3 = pdVar2->dma_ops;
    }
  }
  if (pdVar3->sync_single_for_device != ebc_open) {
    (*pdVar3->sync_single_for_device)
              (pdVar2,panel->fb[iVar1].phy_addr,(long)(int)ebc_info,DMA_TO_DEVICE);
  }
  (*panel->tcon->dsp_mode_set)(panel->tcon,0,0,0,0);
  (*panel->tcon->image_addr_set)(panel->tcon,*(u32 *)&panel->fb[iVar1].phy_addr,0);
  (*panel->tcon->frame_start)(panel->tcon,1);
  panel->current_buffer = 1 - panel->current_buffer;
  return;
}





// Suspends the device if its not busy and sleeps the pmic

int ebc_suspend(device *dev)

{
  struct_driver_data_wip *ebc;
  
  ebc = dev->driver_data;
  if (ebc->is_busy == 1) {
    _dev_info(ebc->device_handle,"%s: device is busy now...\n","ebc_suspend");
    ebc_power_set((ebc *)ebc,0);
  }
  ebc->is_suspended = 1;
  (*ebc->pmic_handle->pmic_pm_suspend)(ebc->pmic_handle);
  _dev_info(ebc->device_handle,"device suspend\n");
  return 0;
}



void new_buffer_refresh(work_struct *work)

{
  down(&ebc_buffer_sem);
  refresh_new_image2((u32 *)ebc_global.info.auto_image_new,(u32 *)ebc_global.info.auto_image_cur,
                     (u32 *)ebc_global.info.auto_image_bg,(u32 *)ebc_global.info.auto_frame_count,
                     &ebc_global.info,(ebc_global.info.curr_dsp_buf)->buf_mode);
  up(&ebc_buffer_sem);
  return;
}



int ebc_refresh_tast_function(void *data)

{
  long lVar1;
  
  lVar1 = cRead_8(sp_el0);
  do {
    down(&ebc_refresh_thread_sem);
    *(undefined8 *)(lVar1 + 0x20) = 2;
    DataMemoryBarrier(2,3);
    refresh_new_image2((u32 *)ebc_global.info.auto_image_new,(u32 *)ebc_global.info.auto_image_cur,
                       (u32 *)ebc_global.info.auto_image_bg,(u32 *)ebc_global.info.auto_frame_count,
                       &ebc_global.info,(ebc_global.info.curr_dsp_buf)->buf_mode);
    ebc_global.info.auto_refresh_done = 1;
    __wake_up_sync(&ebc_wq,1,1);
    up(&ebc_refresh_thread_sem);
    schedule();
  } while( true );
}



void ebc_exit(void)

{
  platform_driver_unregister(&ebc_driver);
  return;
}



int ebc_init(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&ebc_driver,(module *)0x0);
  return iVar1;
}





// Prints if the wake lock is set into provided string

ssize_t ebc_state_printf(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%d\n",(ulong)(uint)ebc_global.info.wake_lock_is_set);
  return (long)iVar1;
}



// Prints the current version number of the driver into the string

ssize_t ebc_version_print(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%s\n","1.01");
  return (long)iVar1;
}



// Prints the vcom in mV into the string

ssize_t pmic_vcom_sprintf(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = (*(ebc_global.pmic)->pmic_get_vcom)(ebc_global.pmic);
  iVar1 = sprintf(buf,"%d\n",iVar1);
  return (long)iVar1;
}



// Prints the pmic temp in C into the string

ssize_t pmic_temp_sprintf(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  int t;
  uint local_c;
  long local_8;
  
  local_8 = __stack_chk_guard;
  (*(ebc_global.pmic)->pmic_read_temperature)(ebc_global.pmic,(int *)&local_c);
  iVar1 = sprintf(buf,"%d\n",(ulong)local_c);
  if (local_8 == __stack_chk_guard) {
    return (long)iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// Prints the pmic drivers name into the string

ssize_t pmic_name_sprintf(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%s\n",(ebc_global.pmic)->pmic_name);
  return (long)iVar1;
}



// Sets the pmic vcomm to a value in millivolts based on the string provided.
// String is the millivolt value eg "150"

ssize_t pmic_vcom_write(device *device,device_attribute *attr,char *buf,size_t count)

{
  int iVar1;
  uint local_c;
  long local_8;
  
  local_8 = __stack_chk_guard;
  iVar1 = kstrtouint(buf,0,&local_c);
  if (iVar1 == 0) {
    iVar1 = ebc_pmic_set_vcom(ebc_global.pmic,local_c);
    if (iVar1 != 0) {
      count = 0xffffffffffffffff;
      _dev_err(ebc_global.dev,"set vcom value failed\n");
    }
  }
  else {
    count = 0xffffffffffffffff;
    _dev_err(ebc_global.dev,"invalid value = %s\n",buf);
  }
  if (local_8 == __stack_chk_guard) {
    return count;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// Prings the waveforms name into the string

ssize_t waveform_version_sprintf(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = epd_lut_get_wf_version();
  iVar1 = sprintf(buf,"%s\n",pcVar2);
  return (long)iVar1;
}



void ebc_frame_timeout(timer_list *t)

{
  frame_done_callback();
  return;
}
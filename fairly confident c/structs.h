#include <stdint.h>

#include "../ebc public c/ebc_panel.h"
#include "../ebc public c/epdlut/epd_lut.h"
#ifndef STRUCTS_GUESS_H_
#define STRUCTS_GUESS_H_
typedef unsigned char undefined;

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int dword;
typedef long long longlong;
typedef unsigned long qword;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned long undefined8;
typedef unsigned short ushort;
typedef unsigned short word;

struct ebc_info {
  ulong ebc_buffer_phy;
  char *ebc_buffer_vir;
  int ebc_buffer_size;
  int ebc_buf_real_size;
  int direct_buf_real_size;
  int is_busy_now;
  int task_restart;
  int auto_refresh_done;
  char frame_total;
  char frame_bw_total;
  undefined field_0x2a;
  undefined field_0x2b;
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
  undefined field_0x5c;
  undefined field_0x5d;
  undefined field_0x5e;
  undefined field_0x5f;
  struct device *dev;
  struct epd_lut_data lut_data;
  struct task_struct *ebc_task;
  int *auto_image_new;
  int *auto_image_old;
  int *auto_image_bg;
  int *auto_image_cur;
  u8 *auto_frame_count;
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
  undefined field_0x274;
  undefined field_0x275;
  undefined field_0x276;
  undefined field_0x277;
};
#endif
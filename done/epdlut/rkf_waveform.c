#include "epd_lut.h"
#include <kernel.h>
#include <stdint.h>
#include <string.h>

static void *global_ptr_waveform_file;
static uint32_t crc_table[256]; // CRC working table generated at runtime

// Returns pointer to best waveform from file in memory based on type and
// current temp

uint8_t *get_wf_buf(int temp, int mode) {
  uint64_t iterator;
  uint8_t *temp_table;
  uint64_t position;
  long data_table;

  if (mode == 3) {
    temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x114);
    data_table = (long)global_ptr_waveform_file + 0x454;
  } else if (mode < 4) {
    if (mode == 1) {
      temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x1d4);
      data_table = (long)global_ptr_waveform_file + 0x754;
    } else if (mode < 2) {
      temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x94);
      data_table = (long)global_ptr_waveform_file + 0x254;
      if (mode != 0) {
        return (uint8_t *)0x0;
      }
    } else {
      temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0xd4);
      data_table = (long)global_ptr_waveform_file + 0x354;
    }
  } else if (mode == 5) {
    temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x194);
    data_table = (long)global_ptr_waveform_file + 0x654;
  } else if (mode < 5) {
    temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x154);
    data_table = (long)global_ptr_waveform_file + 0x554;
  } else {
    temp_table = (uint8_t *)((long)global_ptr_waveform_file + 0x214);
    data_table = (long)global_ptr_waveform_file + 0x854;
    if (mode != 6) {
      return (uint8_t *)0x0;
    }
  }
  if (temp < 0) {
    temp = 0;
  }
  iterator = 0;
  position = 0;
  if (49 < temp) {
    temp = 49;
  }
  while (
      ((int)(uint32_t)temp_table[iterator] < temp ||
       (position = iterator & 0xffffffff, temp_table[iterator + 1] != '\0'))) {
    iterator += 1;
    if (iterator == 50) {
      return (uint8_t *)((long)global_ptr_waveform_file +
                         (uint64_t) * (uint32_t *)(data_table +
                                                   (long)(int)position * 4));
    }
  }
  return (uint8_t *)((long)global_ptr_waveform_file +
                     (uint64_t) * (uint32_t *)(data_table + iterator * 4));
}

uint32_t *copy_wf_data(uint8_t *pbuf, uint32_t length) {
  uint32_t *buffer;

  buffer = (uint32_t *)__kmalloc((uint64_t)length, 0x6080c0);
  if (buffer != (uint32_t *)0x0) {
    memcpy(buffer, pbuf + 4, (uint64_t)length);
  }
  return buffer;
}

int parse_wf_gray16(struct epd_lut_data *output, void *data, int temp_c,
                    int mode1) {
  int iVar2;
  uint8_t *pbuf;
  uint *puVar3;
  uint *extraout_x8;
  uint8_t bVar1;

  pbuf = get_wf_buf(temp_c, mode1);
  bVar1 = *pbuf;
  *extraout_x8 = (uint)bVar1;
  puVar3 = copy_wf_data(pbuf, (uint)bVar1 << 6);
  *(uint **)data = puVar3;
  iVar2 = -0x16;
  if (puVar3 != (uint *)0x0) {
    iVar2 = 0;
  }
  return iVar2;
}

int rkf_wf_input(void *waveform_file) {
  uint8_t *pbVar1;
  uint bit_position;
  uint iterator_as_MSB;
  uint file_computed_crc32;
  long iterator;
  int return_val;
  int file_length;
  uint file_read_crc;
  uint this_bit;
  uint uVar3;

  return_val = -16;
  // If nothing has been loaded thus far
  if (global_ptr_waveform_file == (void *)0x0) {
    return_val =
        strncmp((char *)((long)waveform_file + 4), "rkf waveform", 0xc);
    if (return_val == 0) {
      // WARNING: Load size is inaccurate
      file_length = *waveform_file;
      if (file_length < 0x40001) {
        file_read_crc = *(uint *)((long)waveform_file + (long)file_length);
        memset(crc32_table, 0, 0x400);
        // Compute CRC32 Table
        iterator = 0;
        do {
          iterator_as_MSB = (int)iterator << 0x16;
          file_computed_crc32 = 8;
          bit_position = 0;
          do {
            uVar3 = iterator_as_MSB ^ bit_position;
            this_bit = bit_position << 1;
            bit_position = bit_position << 1;
            if ((int)uVar3 < 0) {
              bit_position = this_bit ^ 0x4c10db7;
            }
            iterator_as_MSB <<= 1;
            file_computed_crc32 -= 1;
          } while (file_computed_crc32 != 0);
          *(uint *)((long)crc32_table + iterator) = bit_position;
          iterator += 4;
        } while (iterator != 0x400);
        if (file_length != 0) {
          // Compute file CRC
          iterator = 0;
          do {
            pbVar1 = (uint8_t *)((long)waveform_file + iterator);
            iterator += 1;
            file_computed_crc32 =
                crc32_table[(uint)*pbVar1 ^ file_computed_crc32 >> 0x18] ^
                file_computed_crc32 << 8;
          } while ((uint)iterator < (uint)file_length);
        }
        if (file_read_crc == file_computed_crc32) {
          printk("rkf file version: %s\n",
                 (char *)((long)waveform_file + 0x14));
          global_ptr_waveform_file = waveform_file;
          return 0;
        }
        printk("[EINK]: waveform crc err readcrc = %x crccheck = %x\n",
               file_read_crc, file_computed_crc32);
      }
      printk("rkf: failed to check crc RKF waveform\n");
      return -1;
    }
    printk("rkf: check format failed\n");
    return_val = -1;
    printk("rkf: failed to check RKF file format\n");
  }
  return return_val;
}

char *rkf_wf_get_version(void)

{
  char *pcVar1;

  pcVar1 = (char *)((long)global_ptr_waveform_file + 0x54);
  if (global_ptr_waveform_file == (void *)0x0) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

int rkf_wf_get_lut(struct epd_lut_data *output, struct epd_lut_type lut_type,
                   int temperture)

{
  uint uVar1;
  uint uVar2;
  uint8_t *wf_buf;
  uint *ptr_wf_data;
  uint *return_data_buffer2;
  uint inner_inner_iterator;
  uint uVar3;
  uint *ptr_output_data;
  uint inner_iterator;
  long outer_iterator;
  uint8_t frame_num;
  int innter_iteration_end;
  int internal_mode_type;
  uint wf_data_item;
  uint wf_len;

  if (global_ptr_waveform_file == (void *)0x0) {
    return -19;
  }
  if (output == (epd_lut_data *)0x0) {
    return -22;
  }
  // If same temp and type leave old data alone and exit
  if ((rkf_wf_get_lut::last_lut_temp_c == temperture) &&
      (rkf_wf_get_lut::last_lut_type == lut_type)) {
    return 0;
  }
  // Free old data
  rkf_wf_get_lut::last_lut_temp_c = temperture;
  rkf_wf_get_lut::last_lut_type = lut_type;
  if (output->data != (uint *)0x0) {
    kfree(output->data);
    output->data = (uint *)0x0;
  }
  internal_mode_type = rkf_wf_get_lut::last_lut_temp_c;
  if (lut_type != WF_TYPE_GRAY16) {
    if (lut_type == WF_TYPE_GCC16) {
    LAB_001004a4:
      internal_mode_type = 4;
      goto LAB_Parse_Grey16;
    }
    if (lut_type == WF_TYPE_A2) {
      wf_buf = get_wf_buf(rkf_wf_get_lut::last_lut_temp_c, 6);
      frame_num = *wf_buf;
      output->frame_num = (uint)frame_num;
      ptr_wf_data = copy_wf_data(wf_buf, (uint)frame_num << 6);
      output->data = ptr_wf_data;
      return (int)-(uint)(ptr_wf_data == (uint *)0x0);
    }
    if (lut_type < WF_TYPE_GC16) {
      if (lut_type != WF_TYPE_GRAY4) {
        if (lut_type < WF_TYPE_GRAY2) {
          if (lut_type == WF_TYPE_RESET) {
            wf_buf = get_wf_buf(rkf_wf_get_lut::last_lut_temp_c, 0);
            frame_num = *wf_buf;
            wf_len = frame_num + 0xf >> 4;
            ptr_wf_data = copy_wf_data(wf_buf, wf_len << 2);
            if (ptr_wf_data != (uint *)0x0) {
              output->frame_num = (uint)frame_num;
              return_data_buffer2 =
                  (uint *)__kmalloc((uint64_t)wf_len << 10, 0x6080c0);
              if (return_data_buffer2 != (uint *)0x0) {
                if (wf_len != 0) {
                  // This appears to be doing some form of descrambling or
                  // re-arranging magic before returning
                  outer_iterator = 0;
                  do {
                    wf_data_item = ptr_wf_data[outer_iterator];
                    internal_mode_type = (int)outer_iterator << 8;
                    inner_iterator = 0;
                    do {
                      uVar1 = (int)wf_data_item >> (inner_iterator & 0x1f) & 3;
                      inner_inner_iterator = 0;
                      uVar3 = uVar1;
                      do {
                        uVar2 = inner_inner_iterator & 0x1f;
                        inner_inner_iterator += 2;
                        uVar3 |= uVar1 << (uint64_t)uVar2;
                      } while (inner_inner_iterator != 32);
                      innter_iteration_end = internal_mode_type + 0x10;
                      do {
                        return_data_buffer2[internal_mode_type] = uVar3;
                        internal_mode_type += 1;
                      } while (internal_mode_type != innter_iteration_end);
                      inner_iterator += 2;
                    } while (inner_iterator != 32);
                    outer_iterator += 1;
                  } while ((int)outer_iterator < (int)wf_len);
                }
                output->data = return_data_buffer2;
                kfree(ptr_wf_data);
                return 0;
              }
              output->data = (uint *)0x0;
              kfree(ptr_wf_data);
            }
          }
        } else if (lut_type == WF_TYPE_GRAY2) {
          wf_buf = get_wf_buf(rkf_wf_get_lut::last_lut_temp_c, 1);
          frame_num = *wf_buf;
          ptr_wf_data = copy_wf_data(wf_buf, (uint)frame_num << 6);
          output->data = ptr_wf_data;
          if (ptr_wf_data != (uint *)0x0) {
            output->frame_num = (uint)frame_num;
            return 0;
          }
        } else if (lut_type == WF_TYPE_AUTO) {
          wf_buf = get_wf_buf(rkf_wf_get_lut::last_lut_temp_c, 2);
          frame_num = *wf_buf;
          output->frame_num = (uint)frame_num;
          ptr_wf_data = copy_wf_data(wf_buf, (uint)frame_num << 6);
          output->data = ptr_wf_data;
          if (ptr_wf_data != (uint *)0x0) {
            wf_buf = get_wf_buf(internal_mode_type, 1);
            frame_num = *wf_buf;
            output->frame_num = output->frame_num | (uint)frame_num << 8;
            ptr_wf_data = copy_wf_data(wf_buf, (uint)frame_num << 6);
            if (ptr_wf_data != (uint *)0x0) {
              wf_len = 0;
              ptr_output_data = output->data;
              return_data_buffer2 = ptr_wf_data;
              if (frame_num != 0) {
                do {
                  outer_iterator = 0;
                  do {
                    *(uint *)((long)ptr_output_data + outer_iterator) =
                        *(uint *)((long)return_data_buffer2 + outer_iterator) &
                            0xc0000003 |
                        *(uint *)((long)ptr_output_data + outer_iterator) &
                            0x3ffffffc;
                    outer_iterator += 4;
                  } while (outer_iterator != 64);
                  wf_len += 1;
                  return_data_buffer2 = return_data_buffer2 + 16;
                  ptr_output_data = ptr_output_data + 16;
                } while (frame_num != wf_len);
              }
              kfree(ptr_wf_data);
              return 0;
            }
          }
        }
        return -1;
      }
    } else {
      if (lut_type == WF_TYPE_GL16) {
        internal_mode_type = 3;
        goto LAB_Parse_Grey16;
      }
      if (WF_TYPE_GC16 < lut_type) {
        if (lut_type != WF_TYPE_GLR16) {
          if (lut_type != WF_TYPE_GLD16) {
            return -1;
          }
          internal_mode_type = 5;
          goto LAB_Parse_Grey16;
        }
        goto LAB_001004a4;
      }
    }
  }
  internal_mode_type = 2;
LAB_Parse_Grey16:
  internal_mode_type =
      parse_wf_gray16(output, &output->data, rkf_wf_get_lut::last_lut_temp_c,
                      internal_mode_type);
  return (int)-(uint)(internal_mode_type != 0);
}

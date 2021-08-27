#include "epd_lut.h"
#include <kernel.h>
#include <stdint.h>
#include <string.h>

struct pvi_waveform {
  uint32_t checksum;
  uint32_t file_length;
  uint32_t serial;
  uint8_t run_type;
  uint8_t fpl_platform;
  uint16_t fpl_lot;
  uint8_t mode_version;
  uint8_t wf_version;
  uint8_t wf_subversion;
  uint8_t wf_type;
  uint8_t panel_size;
  uint8_t amepd_part_number;
  uint8_t wfm_rev;
  uint8_t frame_rate;
  uint32_t reserved;
  uint8_t vcom_offset;
  uint8_t xwia[3];
  uint8_t sc1;
  uint8_t unknown1[4];
  uint8_t modenumber;
  uint8_t temperaturenumber;
  uint8_t unknown2[9];
};

struct struct_waveforms_waveform { // Length is 0x400
  u8 waveformdata[32];
  u8 waveformdata2[32];
  u8 waveformdata3[32];
  u8 largeLookup[928];
};

struct struct_waveforms { // Size is 0x80000
  struct struct_waveforms_waveform waveformData[510];
  u8 field_0x7f800[2048];
};

struct struct_global_data {
  uint gray_2_data_2d_array[300][2];
  int pvi_modes[9];
  struct pvi_waveform *global_waveform;
  uint reset_data[300];
  char spi_id_buffer_aka_name[32];
  u32 gray32_data[300][64];
  uint gray_data[4800];
  struct struct_waveforms waveforms;
};

struct struct_global_data GlobalStruct;

// Returns the waveform lut to use for frame X of transition for 16 level of
// grey

void get_lut_gray16_data(uint *dst, int frame_num)

{
  struct struct_waveforms_waveform *psVar1;
  uint *puVar2;
  uint *puVar3;
  struct struct_waveforms *waveform_ptr;
  uint uVar5;
  uint *iterate_over_gray_table_ptr;
  struct struct_waveforms *iterate_over_waveform_data_ptr;
  struct struct_waveforms *ptr_waveform_data;

  memset(GlobalStruct.gray_data, 0, 0x4b00);
  ptr_waveform_data = &GlobalStruct.waveforms;
  uVar5 = 0;
  do {
    iterate_over_gray_table_ptr = GlobalStruct.gray_data;
    iterate_over_waveform_data_ptr = ptr_waveform_data;
    do {
      if (0 < frame_num) {
        puVar2 = iterate_over_gray_table_ptr;
        waveform_ptr = iterate_over_waveform_data_ptr;
        do {
          psVar1 = waveform_ptr->waveformData;
          waveform_ptr = (struct_waveforms *)(waveform_ptr->waveformData + 1);
          puVar3 = puVar2 + 0x10;
          *puVar2 = *puVar2 | (uint)psVar1->waveformdata[0]
                                  << (ulong)(uVar5 & 0x1f);
          puVar2 = puVar3;
        } while (puVar3 != iterate_over_gray_table_ptr +
                               (ulong)(frame_num - 1) * 0x10 + 0x10);
      }
      iterate_over_gray_table_ptr = iterate_over_gray_table_ptr + 1;
      iterate_over_waveform_data_ptr =
          (struct struct_waveforms *)iterate_over_waveform_data_ptr
              ->waveformData[0]
              .waveformdata2;
    } while (iterate_over_gray_table_ptr != GlobalStruct.gray_data + 0x10);
    ptr_waveform_data =
        (struct struct_waveforms
             *)(ptr_waveform_data->waveformData[0].waveformdata + 1);
    uVar5 += 2;
  } while (ptr_waveform_data !=
           (struct struct_waveforms
                *)(GlobalStruct.waveforms.waveformData[0].waveformdata + 0x10));
  memcpy(dst, GlobalStruct.gray_data, (long)(frame_num << 6));
  return;
}

// Get the lookup table for waveforms for frame N of 2 levels of grey

void get_lut_gray2_data(uint *dst, int frame_num)

{
  uint uVar1;
  uint uVar2;
  uint8_t *pbVar1;
  uint uVar4;
  struct struct_global_data *ptr_to_global;
  uint8_t *ptr_grey_2_data_lookup;

  ptr_to_global = &GlobalStruct;
  memset(&GlobalStruct, 0, 0x960);
  if (0 < frame_num) {
    ptr_grey_2_data_lookup =
        GlobalStruct.waveforms.waveformData[0].waveformdata + 0xf;
    uVar4 = 0;
    while (true) {
      uVar1 = 0;
      pbVar1 = ptr_grey_2_data_lookup + -0xf;
      do {
        uVar2 = uVar1 & 0x1f;
        uVar1 += 2;
        uVar4 |= (uint)*pbVar1 << (ulong)uVar2;
        pbVar1 = pbVar1 + 0x20;
      } while (uVar1 != 0x20);
      uVar2 = ptr_to_global->gray_2_data_2d_array[1];
      uVar1 = 0;
      ptr_to_global->gray_2_data_2d_array[0] = uVar4;
      pbVar1 = ptr_grey_2_data_lookup;
      do {
        uVar4 = uVar1 & 0x1f;
        uVar1 += 2;
        uVar2 |= (uint)*pbVar1 << (ulong)uVar4;
        pbVar1 = pbVar1 + 0x20;
      } while (uVar1 != 0x20);
      ptr_to_global->gray_2_data_2d_array[1] = uVar2;
      ptr_to_global =
          (struct struct_global_data *)ptr_to_global->gray_2_data_2d_array[1];
      ptr_grey_2_data_lookup = ptr_grey_2_data_lookup + 0x400;
      if (ptr_to_global ==
          (struct struct_global_data *)
              GlobalStruct.gray_2_data_2d_array[(ulong)(frame_num - 1) + 1])
        break;
      uVar4 = ptr_to_global->gray_2_data_2d_array[0];
    }
  }
  memcpy(dst, &GlobalStruct, (long)(frame_num << 3));
  return;
}

// Lookup waveform mode index from type; updates the pvi modes global

int get_wf_mode_index(epd_lut_type lut_type)

{
  int retVal;
  uint8_t mode_version;

  mode_version = (GlobalStruct.global_waveform)->mode_version;
  if (mode_version == 0x19) {
    GlobalStruct.pvi_modes[0] = 0;
    GlobalStruct.pvi_modes[1] = 1;
    GlobalStruct.pvi_modes[2] = 7;
    GlobalStruct.pvi_modes[3] = 2;
    GlobalStruct.pvi_modes[4] = 3;
    GlobalStruct.pvi_modes[5] = 4;
    GlobalStruct.pvi_modes[6] = 5;
    GlobalStruct.pvi_modes[8] = 4;
    GlobalStruct.pvi_modes[7] = 6;
  } else if (mode_version < 0x1a) {
    if (mode_version == 0x12) {
      GlobalStruct.pvi_modes[0] = 0;
      GlobalStruct.pvi_modes[1] = 1;
      GlobalStruct.pvi_modes[2] = 7;
      GlobalStruct.pvi_modes[3] = 3;
      GlobalStruct.pvi_modes[4] = 3;
      GlobalStruct.pvi_modes[5] = 5;
      GlobalStruct.pvi_modes[6] = 6;
      GlobalStruct.pvi_modes[7] = 4;
      GlobalStruct.pvi_modes[8] = 5;
    } else {
      if (mode_version != 0x18)
        goto LAB_00100318;
    LAB_00100378:
      GlobalStruct.pvi_modes[0] = 0;
      GlobalStruct.pvi_modes[1] = 1;
      GlobalStruct.pvi_modes[2] = 1;
      GlobalStruct.pvi_modes[3] = 2;
      GlobalStruct.pvi_modes[4] = 3;
      GlobalStruct.pvi_modes[5] = 4;
      GlobalStruct.pvi_modes[6] = 5;
      GlobalStruct.pvi_modes[7] = 6;
      GlobalStruct.pvi_modes[8] = 4;
    }
  } else if (mode_version == 0x23) {
    GlobalStruct.pvi_modes[0] = 0;
    GlobalStruct.pvi_modes[1] = 1;
    GlobalStruct.pvi_modes[2] = 5;
    GlobalStruct.pvi_modes[3] = 2;
    GlobalStruct.pvi_modes[4] = 3;
    GlobalStruct.pvi_modes[5] = 3;
    GlobalStruct.pvi_modes[6] = 3;
    GlobalStruct.pvi_modes[7] = 4;
    GlobalStruct.pvi_modes[8] = 3;
  } else if (mode_version == 0x54) {
    GlobalStruct.pvi_modes[0] = 0;
    GlobalStruct.pvi_modes[1] = 1;
    GlobalStruct.pvi_modes[2] = 1;
    GlobalStruct.pvi_modes[3] = 2;
    GlobalStruct.pvi_modes[4] = 3;
    GlobalStruct.pvi_modes[5] = 4;
    GlobalStruct.pvi_modes[6] = 4;
    GlobalStruct.pvi_modes[7] = 5;
    GlobalStruct.pvi_modes[8] = 4;
  } else {
    if (mode_version == 0x20)
      goto LAB_00100378;
  LAB_00100318:
    GlobalStruct.pvi_modes[0] = 0;
    GlobalStruct.pvi_modes[1] = 1;
    GlobalStruct.pvi_modes[2] = 1;
    GlobalStruct.pvi_modes[3] = 2;
    GlobalStruct.pvi_modes[4] = 3;
    GlobalStruct.pvi_modes[5] = 4;
    GlobalStruct.pvi_modes[8] = 4;
    GlobalStruct.pvi_modes[6] = 5;
    GlobalStruct.pvi_modes[7] = 6;
    printk("pvi : Unknow waveform version %x,%x\n",
           (ulong)(GlobalStruct.global_waveform)->mode_version,
           (ulong)(GlobalStruct.global_waveform)->wfm_rev);
  }
  retVal = GlobalStruct.pvi_modes[3];
  if (((lut_type != WF_TYPE_AUTO) && (lut_type != WF_TYPE_GRAY16)) &&
      (retVal = GlobalStruct.pvi_modes[7], lut_type != WF_TYPE_A2)) {
    if (lut_type < WF_TYPE_GC16) {
      retVal = GlobalStruct.pvi_modes[2];
      if (((lut_type != WF_TYPE_GRAY4) &&
           (retVal = GlobalStruct.pvi_modes[1], lut_type != WF_TYPE_GRAY2)) &&
          (retVal = GlobalStruct.pvi_modes[0], lut_type != WF_TYPE_RESET))
        goto LAB_001002b8;
    } else {
      retVal = GlobalStruct.pvi_modes[4];
      if (((lut_type != WF_TYPE_GL16) &&
           (retVal = GlobalStruct.pvi_modes[3], WF_TYPE_GC16 < lut_type)) &&
          ((retVal = GlobalStruct.pvi_modes[5],
            lut_type != WF_TYPE_GLR16 && (retVal = GlobalStruct.pvi_modes[6],
                                          lut_type != WF_TYPE_GLD16)))) {
      LAB_001002b8:
        printk("pvi: unspport PVI waveform type");
        return -1;
      }
    }
  }
  return retVal;
}

// Decodes provided data into the waveformdata global

int decodewaveform(uint8_t *data, int maxpic, int want_pic)

{
  uint uVar1;
  uint uVar2;
  uint8_t bVar3;
  uint8_t uVar4;
  long lVar5;
  ulong uVar6;
  uint8_t bVar7;
  uint8_t bVar8;
  uint uVar9;
  ulong uVar10;
  struct struct_waveforms_waveform *waveform_ptr1;
  ulong uVar11;
  struct struct_waveforms_waveform *waveform_ptr2;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  int iVar15;
  ulong uVar16;

  if (((maxpic - 0x10U & 0xffffffef) != 0) &&
      ((want_pic - 0x10U & 0xffffffef) != 0)) {
    return (int)0xffffffea;
  }
  memset(&GlobalStruct.waveforms, 0, 0x80000);
  uVar16 = 0;
  uVar12 = 1;
  uVar14 = 0;
  uVar9 = 0;
  uVar11 = 0;
  do {
    uVar13 = (uint)uVar14;
    bVar3 = data[uVar14];
    iVar15 = (int)uVar16;
    if (bVar3 == 0xff) {
      if ((maxpic != 0x20 || want_pic != 0x10) || (iVar15 == 0))
        goto LAB_returnnow;
      goto LAB_dataheader_ff;
    }
    if (bVar3 == 0xfc) {
      uVar13 += 1;
      uVar12 ^= 1;
      bVar3 = data[uVar13];
    }
    lVar5 = uVar16 * 0x20;
    if (uVar12 == 0) {
      *(uint8_t *)((lVar5 + (ulong)uVar9) * 0x20 + 0x119700 + uVar11) =
          bVar3 & 3;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 1)) * 0x20 + 0x119700 + uVar11) =
          bVar3 >> 2 & 3;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 2)) * 0x20 + 0x119700 + uVar11) =
          bVar3 >> 4 & 3;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 3)) * 0x20 + 0x119700 + uVar11) =
          bVar3 >> 6;
      uVar9 += 4;
      uVar14 = (ulong)(uVar13 + 1);
      if ((uint)maxpic <= uVar9) {
        uVar13 = (int)uVar11 + 1;
        uVar11 = (ulong)uVar13;
        uVar9 = 0;
        if ((uint)maxpic <= uVar13) {
          uVar16 = (ulong)(iVar15 + 1);
          uVar11 = 0;
          uVar9 = uVar12;
        }
      }
    } else {
      *(uint8_t *)((lVar5 + (ulong)uVar9) * 0x20 + 0x119700 + uVar11) =
          bVar3 & 3;
      bVar7 = bVar3 >> 2 & 3;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 1)) * 0x20 + 0x119700 + uVar11) =
          bVar7;
      bVar8 = bVar3 >> 4 & 3;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 2)) * 0x20 + 0x119700 + uVar11) =
          bVar8;
      *(uint8_t *)((lVar5 + (ulong)(uVar9 + 3)) * 0x20 + 0x119700 + uVar11) =
          bVar3 >> 6;
      uVar9 += 4;
      if ((uint)maxpic <= uVar9) {
        uVar12 = (int)uVar11 + 1;
        uVar11 = (ulong)uVar12;
        uVar9 = 0;
        if ((uint)maxpic <= uVar12) {
          uVar16 = (ulong)(iVar15 + 1);
          uVar11 = 0;
        }
      }
      uVar4 = data[uVar13 + 1];
      while (uVar4 != 0) {
        lVar5 = uVar16 * 0x20;
        uVar12 = uVar9 + 1;
        uVar1 = uVar9 + 2;
        uVar2 = uVar9 + 3;
        *(uint8_t *)((lVar5 + (ulong)uVar9) * 0x20 + 0x119700 + uVar11) =
            bVar3 & 3;
        uVar9 += 4;
        *(uint8_t *)((lVar5 + (ulong)uVar12) * 0x20 + 0x119700 + uVar11) =
            bVar7;
        uVar4 += 0xff;
        *(uint8_t *)((lVar5 + (ulong)uVar1) * 0x20 + 0x119700 + uVar11) = bVar8;
        *(uint8_t *)((lVar5 + (ulong)uVar2) * 0x20 + 0x119700 + uVar11) =
            bVar3 >> 6;
        if ((uint)maxpic <= uVar9) {
          uVar12 = (int)uVar11 + 1;
          uVar11 = (ulong)uVar12;
          uVar9 = 0;
          if ((uint)maxpic <= uVar12) {
            uVar16 = (ulong)((int)uVar16 + 1);
            uVar11 = 0;
          }
        }
      }
      uVar14 = (ulong)(uVar13 + 2);
      uVar12 = 1;
    }
  } while ((uint)uVar16 < 0x200);
  printk("pvi: decodec waveform 19 error\n");
  if (maxpic != 0x20 || want_pic != 0x10) {
  LAB_returnnow:
    return (int)uVar16;
  }
LAB_dataheader_ff:
  uVar11 = 0;
  do {
    waveform_ptr2 = GlobalStruct.waveforms.waveformData + uVar11;
    uVar14 = 0;
    do {
      uVar10 = 0;
      waveform_ptr1 = waveform_ptr2;
      do {
        uVar6 = uVar10 >> 1;
        uVar9 = (int)uVar10 + 2;
        uVar10 = (ulong)uVar9;
        *(u8 *)((uVar11 * 0x20 + (uVar14 >> 1)) * 0x20 + 0x119700 + uVar6) =
            waveform_ptr1->waveformdata[0];
        waveform_ptr1 =
            (struct_waveforms_waveform *)(waveform_ptr1->waveformdata + 2);
      } while (uVar9 != 0x20);
      uVar9 = (int)uVar14 + 2;
      uVar14 = (ulong)uVar9;
      waveform_ptr2 = (struct_waveforms_waveform *)waveform_ptr2->waveformdata3;
    } while (uVar9 != 0x20);
    uVar9 = (int)uVar11 + 1U & 0xff;
    uVar11 = (ulong)uVar9;
  } while (uVar9 < (uint)uVar16);
  return (uint)uVar16;
}

// Lookup the waveform number to use based on mode/temp/want_pic

int get_wf_frm_num(int mode, int temp_index, int want_pic)

{
  long lVar1;
  uint8_t bVar2;
  int return_val;
  ulong uVar3;
  uint uVar4;

  return_val = (uint) * (uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + 0x20) +
               mode * 4;
  lVar1 = GlobalStruct.gray32_data[6]._80_8_ + return_val;
  uVar4 = (uint) * (uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + return_val);
  if ((uint) * (uint8_t *)(lVar1 + 3) ==
      ((uint) * (uint8_t *)(lVar1 + 1) + (uint) * (uint8_t *)(lVar1 + 2) +
           uVar4 &
       0xff)) {
    return_val = ((uint) * (uint8_t *)(lVar1 + 2) << 0x10 |
                  (uint) * (uint8_t *)(lVar1 + 1) << 8 | uVar4) +
                 temp_index * 4;
    lVar1 = GlobalStruct.gray32_data[6]._80_8_ + return_val;
    uVar4 =
        (uint) * (uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + return_val);
    if ((uint) * (uint8_t *)(lVar1 + 3) ==
        ((uint) * (uint8_t *)(lVar1 + 1) + (uint) * (uint8_t *)(lVar1 + 2) +
             uVar4 &
         0xff)) {
      bVar2 = *(uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + 0x10);
      uVar3 = (ulong)((uint) * (uint8_t *)(lVar1 + 2) << 0x10 |
                      (uint) * (uint8_t *)(lVar1 + 1) << 8 | uVar4);
      if ((0x17 < bVar2) && ((bVar2 < 0x1a || (bVar2 == 0x20)))) {
        return_val = decodewaveform(
            (uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + uVar3), 0x20,
            want_pic);
        return return_val;
      }
      if (want_pic == 0x20) {
        return_val = -0x16;
      } else {
        return_val = decodewaveform(
            (uint8_t *)(GlobalStruct.gray32_data[6]._80_8_ + uVar3), 0x10,
            0x10);
      }
    } else {
      printk("pvi: %s %d check error\n", "get_wf_frm_num", 0x150);
      return_val = -0x16;
    }
  } else {
    printk("pvi: %s %d check error\n", "get_wf_frm_num", 0x142);
    return_val = -0x16;
  }
  return return_val;
}

// Parse waveform grey16 data using lut type field

int parse_wf_gray16_with_lut_type(epd_lut_data *lut_data, uint **data,
                                  uint wf_data, uint lut_type)

{
  int wf_mode;
  uint frame_num;
  uint *dst;

  wf_mode = get_wf_mode_index(lut_type);
  frame_num = get_wf_frm_num(wf_mode, wf_data, 0x10);
  lut_data->frame_num = frame_num;
  dst = (uint *)__kmalloc((long)(int)(frame_num << 6), 0x6080c0);
  *data = dst;
  if (dst == (uint *)0x0) {
    wf_mode = -0xc;
  } else {
    get_lut_gray16_data(dst, frame_num);
    wf_mode = 0;
  }
  return wf_mode;
}

// Parse and interpret the grey2 waveform data

int parse_wf_gray2(epd_lut_data *lut_data, uint **data,
                   uint temperatureNumberLessOne, uint lut_type)

{
  uint frame_num;
  int returnValue;
  uint *temp_working_buf;
  uint *return_buffer;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;

  returnValue = get_wf_mode_index(WF_TYPE_GRAY2);
  frame_num = get_wf_frm_num(returnValue, temperatureNumberLessOne, 0x10);
  lut_data->frame_num = frame_num;
  temp_working_buf = (uint *)__kmalloc((long)(int)(frame_num << 3), 0x6080c0);
  if (temp_working_buf == (uint *)0x0) {
    returnValue = -0xc;
  } else {
    get_lut_gray2_data(temp_working_buf, frame_num);
    lut_data->frame_num = frame_num;
    return_buffer = (uint *)__kmalloc((ulong)(frame_num << 6), 0x6080c0);
    if (return_buffer == (uint *)0x0) {
      return_buffer = (uint *)0x0;
    } else if (0 < (int)frame_num) {
      returnValue = 0;
      puVar7 = temp_working_buf;
      do {
        puVar8 = puVar7 + 2;
        uVar4 = *puVar7;
        uVar5 = 0;
        uVar3 = puVar7[1];
        iVar6 = returnValue;
        do {
          uVar1 = uVar5 & 0x1f;
          uVar2 = uVar5 & 0x1f;
          uVar5 += 2;
          return_buffer[iVar6] =
              (int)uVar4 >> uVar1 & 3U | ((int)uVar3 >> uVar2) << 0x1e;
          iVar6 += 1;
        } while (uVar5 != 0x20);
        returnValue += 0x10;
        puVar7 = puVar8;
      } while (puVar8 != temp_working_buf + ((ulong)(frame_num - 1) + 1) * 2);
    }
    *data = return_buffer;
    kfree(temp_working_buf);
    returnValue = 0;
  }
  return returnValue;
}

// WARNING: Type propagation algorithm not settling
// Public:
// Get the waveform lut based on the lut_type and current temp in C

int pvi_wf_get_lut(epd_lut_data *output, epd_lut_type lut_type, int temperature)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint8_t bVar4;
  uint8_t *pbVar5;
  int mode_index;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint wf_data;
  uint *output_buffer;
  void *__dest;
  uint *puVar9;
  struct struct_waveforms_waveform *psVar10;
  struct struct_waveforms *psVar11;
  uint uVar12;
  struct struct_waveforms_waveform *psVar13;
  uint *puVar14;
  long lVar15;
  long lVar16;
  struct struct_waveforms_waveform *psVar17;
  uint unaff_w22;
  uint unaff_w23;
  uint8_t tempNumber;
  uint temp_less_one;

  if (GlobalStruct.global_waveform == (pvi_waveform *)0x0) {
    return -0x13;
  }
  if (output == (epd_lut_data *)0x0) {
    return -0x16;
  }
  if ((temperature / 3 == pvi_wf_get_lut::sftemp / 3) &&
      (pvi_wf_get_lut::stype == lut_type)) {
    return 0;
  }
  tempNumber = (GlobalStruct.global_waveform)->temperaturenumber;
  if (tempNumber == 0) {
  LAB_Handled_temp_match:
    temp_less_one = tempNumber - 1;
  } else {
    bVar4 = *(uint8_t *)&GlobalStruct.global_waveform[1].checksum;
    temp_less_one = 0;
    while ((int)(uint)bVar4 <= temperature) {
      if ((uint)tempNumber == temp_less_one + 1)
        goto LAB_Handled_temp_match;
      bVar4 = (GlobalStruct.global_waveform)
                  ->xwia[(long)(int)(temp_less_one + 49) + -29];
      temp_less_one = temp_less_one + 1;
    }
  }
  pvi_wf_get_lut::sftemp = temperature;
  pvi_wf_get_lut::stype = lut_type;
  if (output->data != (uint *)0x0) {
    kfree(output->data);
    output->data = (uint *)0x0;
  }
  if (lut_type == WF_TYPE_A2) {
    mode_index = get_wf_mode_index(WF_TYPE_A2);
    wf_data = get_wf_frm_num(mode_index, temp_less_one, 0x10);
    if ((int)wf_data < 1) {
    LAB_Handle_Gray2:
      mode_index =
          parse_wf_gray2(output, &output->data, temp_less_one, lut_type);
      return (int)-(uint)(mode_index != 0);
    }
    output->frame_num = wf_data;
    output_buffer = (uint *)__kmalloc((long)(int)(wf_data << 6), 0x6080c0);
    output->data = output_buffer;
    if (output_buffer != (uint *)0x0) {
      get_lut_gray16_data(output_buffer, wf_data);
      return 0;
    }
  } else {
    if (WF_TYPE_A2 < lut_type) {
      if (lut_type != WF_TYPE_GLR16) {
        if (lut_type < WF_TYPE_GLD16) {
          if ((lut_type != WF_TYPE_GC16) && (lut_type != WF_TYPE_GL16)) {
            return -1;
          }
        } else if (lut_type != WF_TYPE_GCC16) {
          if (WF_TYPE_GLD16 < lut_type) {
            if (lut_type != WF_TYPE_GRAY32) {
              return -1;
            }
            mode_index = get_wf_mode_index(WF_TYPE_GC16);
            temp_less_one = get_wf_frm_num(mode_index, temp_less_one, 0x20);
            output->frame_num = temp_less_one;
            output_buffer =
                (uint *)__kmalloc((long)(int)(temp_less_one << 8), 0x6080c0);
            output->data = output_buffer;
            if (output_buffer == (uint *)0x0) {
              return -1;
            }
            memset(GlobalStruct.gray32_data, 0, 0x12c00);
            psVar17 = GlobalStruct.waveforms.waveformData +
                      (ulong)(temp_less_one - 1) + 1;
            uVar6 = 0;
            wf_data = 0;
            do {
              puVar14 = GlobalStruct.gray32_data + 1;
              lVar16 = 1;
              lVar15 = 0;
              psVar13 = psVar17;
              do {
                if (0 < (int)temp_less_one) {
                  psVar10 = psVar13 + (-1 - (ulong)(temp_less_one - 1));
                  puVar8 = puVar14;
                  do {
                    while (pbVar5 = psVar10->waveformdata,
                           (int)wf_data < 0x10) {
                      psVar10 = psVar10 + 1;
                      puVar8[lVar15 - lVar16] =
                          puVar8[lVar15 - lVar16] |
                          (uint)*pbVar5 << (ulong)((wf_data & 0xf) << 1);
                      puVar8 = puVar8 + 0x40;
                      if (psVar10 == psVar13)
                        goto LAB_loopexit;
                    }
                    psVar10 = psVar10 + 1;
                    *puVar8 = *puVar8 | (uint)*pbVar5 << (ulong)(uVar6 & 0x1f);
                    puVar8 = puVar8 + 0x40;
                  } while (psVar10 != psVar13);
                }
              LAB_loopexit:
                lVar15 += 2;
                psVar13 = (struct_waveforms_waveform *)psVar13->waveformdata2;
                lVar16 += 2;
                puVar14 = puVar14 + 2;
              } while (lVar15 != 0x40);
              wf_data += 1;
              psVar17 =
                  (struct_waveforms_waveform *)(psVar17->waveformdata + 1);
              uVar6 += 2;
              if (wf_data == 0x20) {
                memcpy(output_buffer, GlobalStruct.gray32_data,
                       (long)(int)(temp_less_one << 8));
                return 0;
              }
            } while (true);
          }
          lut_type = WF_TYPE_GLD16;
        }
      }
      mode_index = parse_wf_gray16_with_lut_type(output, &output->data,
                                                 temp_less_one, lut_type);
      return (int)-(uint)(mode_index != 0);
    }
    if (lut_type == WF_TYPE_GRAY4) {
      printk("pvi: unsupport WF GRAY4n");
      return 0;
    }
    if (lut_type < WF_TYPE_GRAY2) {
      if (lut_type == WF_TYPE_RESET) {
        mode_index = get_wf_mode_index(WF_TYPE_RESET);
        uVar6 = get_wf_frm_num(mode_index, temp_less_one, 0x10);
        temp_less_one = uVar6 + 3;
        wf_data = uVar6 + 6;
        if (-1 < (int)temp_less_one) {
          wf_data = temp_less_one;
        }
        __dest = __kmalloc((long)((int)wf_data >> 2), 0x6080c0);
        if (__dest != (void *)0x0) {
          memset(GlobalStruct.reset_data, 0, 0x4b0);
          if (0 < (int)uVar6) {
            uVar12 = 0;
            psVar11 = &GlobalStruct.waveforms;
            uVar7 = 0;
            while (true) {
              uVar1 = uVar7 + 1;
              GlobalStruct.reset_data[(int)uVar7 >> 4] =
                  (uint)psVar11->waveformData[0].waveformdata[0]
                      << (ulong)((uVar7 & 0xf) << 1) |
                  uVar12;
              psVar11 = (struct_waveforms *)(psVar11->waveformData + 1);
              if (uVar6 == uVar1)
                break;
              uVar12 = uVar7 + 0x10;
              if (-1 < (int)uVar1) {
                uVar12 = uVar1;
              }
              uVar12 = GlobalStruct.reset_data[(int)uVar12 >> 4];
              uVar7 = uVar1;
            }
          }
          memcpy(__dest, GlobalStruct.reset_data, (long)((int)wf_data >> 2));
          output->frame_num = uVar6;
          output_buffer = (uint *)__kmalloc((ulong)(uVar6 << 10), 0x6080c0);
          if (output_buffer == (uint *)0x0) {
            output_buffer = (uint *)0x0;
          } else if (temp_less_one >> 2 != 0) {
            lVar15 = 0;
            do {
              iVar3 = *(int *)((long)__dest + lVar15 * 4);
              mode_index = (int)lVar15 << 8;
              wf_data = 0;
              do {
                uVar12 = iVar3 >> (wf_data & 0x1f) & 3;
                uVar6 = 0;
                uVar7 = uVar12;
                do {
                  uVar1 = uVar6 & 0x1f;
                  uVar6 += 2;
                  uVar7 |= uVar12 << (ulong)uVar1;
                } while (uVar6 != 0x20);
                iVar2 = mode_index + 0x10;
                do {
                  output_buffer[mode_index] = uVar7;
                  mode_index += 1;
                } while (mode_index != iVar2);
                wf_data += 2;
              } while (wf_data != 0x20);
              lVar15 += 1;
            } while ((int)lVar15 < (int)(temp_less_one >> 2));
          }
          output->data = output_buffer;
          kfree(__dest);
          return 0;
        }
      } else if (lut_type == WF_TYPE_GRAY16) {
        mode_index = get_wf_mode_index(WF_TYPE_GRAY16);
        temp_less_one = get_wf_frm_num(mode_index, temp_less_one, 0x10);
        output->frame_num = temp_less_one;
        output_buffer =
            (uint *)__kmalloc((long)(int)(temp_less_one << 6), 0x6080c0);
        output->data = output_buffer;
        if (output_buffer != (uint *)0x0) {
          get_lut_gray16_data(output_buffer, temp_less_one);
          return 0;
        }
      }
    } else {
      if (lut_type == WF_TYPE_GRAY2)
        goto LAB_Handle_Gray2;
      if (lut_type == WF_TYPE_AUTO) {
        mode_index = get_wf_mode_index(WF_TYPE_AUTO);
        wf_data = get_wf_frm_num(mode_index, temp_less_one, 0x10);
        output->frame_num = wf_data;
        output_buffer = (uint *)__kmalloc((long)(int)(wf_data << 6), 0x6080c0);
        output->data = output_buffer;
        if (output_buffer != (uint *)0x0) {
          get_lut_gray16_data(output_buffer, wf_data);
          mode_index = get_wf_mode_index(WF_TYPE_GRAY2);
          temp_less_one = get_wf_frm_num(mode_index, temp_less_one, 0x10);
          output_buffer =
              (uint *)__kmalloc((long)(int)(temp_less_one << 3), 0x6080c0);
          if (output_buffer != (uint *)0x0) {
            get_lut_gray2_data(output_buffer, temp_less_one);
            wf_data = 0;
            puVar14 = output->data;
            puVar8 = output_buffer;
            if (output->frame_num != 0) {
              do {
                puVar9 = puVar8;
                if (wf_data < temp_less_one) {
                  unaff_w23 = puVar8[1];
                  puVar9 = puVar8 + 2;
                  unaff_w22 = *puVar8;
                }
                uVar6 = 0;
                puVar8 = puVar14;
                do {
                  uVar7 = uVar6 & 0x1f;
                  uVar1 = uVar6 & 0x1f;
                  uVar6 += 2;
                  uVar12 = *puVar8 & 0x3ffffffc;
                  if (wf_data < temp_less_one) {
                    uVar12 |= (int)unaff_w22 >> uVar7 & 3U |
                              ((int)unaff_w23 >> uVar1) << 0x1e;
                  }
                  *puVar8 = uVar12;
                  puVar8 = puVar8 + 1;
                } while (uVar6 != 0x20);
                wf_data += 1;
                puVar14 = puVar14 + 0x10;
                puVar8 = puVar9;
              } while (wf_data < output->frame_num);
            }
            kfree(output_buffer);
            return 0;
          }
        }
      }
    }
  }
  return -1;
}

// Load provided waveform data into the ram struct used for later lookups

int pvi_wf_input(void *waveform_file)

{
  uint8_t version;

  if (GlobalStruct.global_waveform != (struct pvi_waveform *)0x0) {
    return -0x10;
  }
  version = *(uint8_t *)((long)waveform_file + 0x10);
  if (version < 0x1a) {
    if (0x17 < version) {
      GlobalStruct.global_waveform = (struct pvi_waveform *)waveform_file;
      return 0;
    }
    if (version == 0x12) {
      GlobalStruct.global_waveform = (struct pvi_waveform *)waveform_file;
      return 0;
    }
  } else if (((version == 0x23) || (version == 0x54)) || (version == 0x20)) {
    GlobalStruct.global_waveform = (struct pvi_waveform *)waveform_file;
    return 0;
  }
  printk("pvi : Unknow waveform version %x,%x, may be wrong waveform file\n",
         (ulong)version, (ulong) * (uint8_t *)((long)waveform_file + 0x16));
  return -8;
}

// Get version name text from the loaded global waveform

char *pvi_wf_get_version(void)

{
  long iterator;
  struct pvi_waveform *ptr_global_waveform;

  ptr_global_waveform = GlobalStruct.global_waveform;
  if (GlobalStruct.global_waveform != (pvi_waveform *)0x0) {
    iterator = 0;
    do {
      GlobalStruct.spi_id_buffer_aka_name[iterator] =
          ptr_global_waveform[1].xwia[iterator + -0xc];
      iterator += 1;
    } while (iterator != 31);
    GlobalStruct.spi_id_buffer_aka_name[31] = '\0';
    return GlobalStruct.spi_id_buffer_aka_name;
  }
  return (char *)0x0;
}

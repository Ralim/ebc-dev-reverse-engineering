#include "ebc_dev_v8.h"



void get_auto_image(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,u8 *frame_count,ebc_info *ebc_info)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  u32 uVar5;
  u32 uVar6;
  uint uVar7;
  byte bVar8;
  byte *pbVar9;
  ebc *peVar10;
  uint uVar11;
  long lVar12;
  byte *pbVar13;
  uint uVar14;
  u32 uVar15;
  byte bVar16;
  byte bVar17;
  
  peVar10 = global_ebc;
  bVar8 = ebc_info->frame_total;
  uVar6 = (global_ebc->panel).mirror;
  uVar4 = (global_ebc->panel).vir_width;
  uVar5 = (global_ebc->panel).vir_height;
  ebc_info->auto_need_refresh = 0;
  if (0 < (int)uVar5) {
    uVar4 = uVar4 >> 3;
    uVar15 = 0;
    lVar1 = (ulong)(uVar4 - 1) + 1;
    do {
      if (uVar6 == 0) {
        uVar11 = uVar15 * (peVar10->panel).vir_width;
      }
      else {
        uVar11 = (((peVar10->panel).vir_height - 1) - uVar15) * (peVar10->panel).vir_width;
      }
      lVar12 = 0;
      pbVar9 = frame_count;
      pbVar13 = data_buf + (uVar11 >> 2);
      if (uVar4 != 0) {
        do {
          uVar7 = buffer_new[lVar12];
          uVar11 = buffer_old[lVar12];
          if (uVar7 == uVar11) {
            *pbVar13 = 0;
            pbVar13[1] = 0;
          }
          else {
            uVar3 = uVar7 ^ uVar11;
            ebc_info->auto_need_refresh = 1;
            bVar16 = 0;
            uVar14 = (uint)bVar8;
            if ((uVar3 & 0xf) != 0) {
              uVar2 = *pbVar9 + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (ebc_info->lut_data).wf_table
                       [(long)(int)((uint)*pbVar9 << 0x10) +
                        (ulong)((uVar11 & 0xff) * 0x100 + (uVar7 & 0xff))] & 3;
              if (uVar14 == uVar2) {
                uVar11 = uVar11 & 0xfffffff0 | uVar7 & 0xf;
                bVar17 = 0;
              }
              *pbVar9 = bVar17;
            }
            if ((uVar3 & 0xf0) != 0) {
              uVar2 = pbVar9[1] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[1] << 0x10) +
                                (ulong)((uVar11 >> 4 & 0xff) * 0x100 + (uVar7 >> 4 & 0xff))] & 3) <<
                             2) | bVar16;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf0 | uVar11 & 0xffffff0f;
                bVar17 = 0;
              }
              pbVar9[1] = bVar17;
            }
            if ((uVar3 & 0xf00) != 0) {
              uVar2 = pbVar9[2] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[2] << 0x10) +
                                (ulong)((ushort)(uVar7 >> 8) & 0xff | (ushort)uVar11 & 0xff00)] & 3)
                             << 4) | bVar16;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf00 | uVar11 & 0xfffff0ff;
                bVar17 = 0;
              }
              pbVar9[2] = bVar17;
            }
            if ((uVar3 & 0xf000) != 0) {
              uVar2 = pbVar9[3] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[3] << 0x10) +
                                (ulong)((uVar11 >> 0xc & 0xff) * 0x100 + (uVar7 >> 0xc & 0xff))] & 3
                              ) << 6) | bVar16;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf000 | uVar11 & 0xffff0fff;
                bVar17 = 0;
              }
              pbVar9[3] = bVar17;
            }
            *pbVar13 = bVar16;
            bVar16 = 0;
            if ((uVar3 & 0xf0000) != 0) {
              uVar2 = pbVar9[4] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (ebc_info->lut_data).wf_table
                       [(long)(int)((uint)pbVar9[4] << 0x10) +
                        (ulong)((uVar11 >> 0x10 & 0xff) * 0x100 + (uVar7 >> 0x10 & 0xff))] & 3;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf0000 | uVar11 & 0xfff0ffff;
                bVar17 = 0;
              }
              pbVar9[4] = bVar17;
            }
            if ((uVar3 & 0xf00000) != 0) {
              uVar2 = pbVar9[5] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[5] << 0x10) +
                                (ulong)((uVar11 >> 0x14 & 0xff) * 0x100 + (uVar7 >> 0x14 & 0xff))] &
                              3) << 2) | bVar16;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf00000 | uVar11 & 0xff0fffff;
                bVar17 = 0;
              }
              pbVar9[5] = bVar17;
            }
            if ((uVar3 & 0xf000000) != 0) {
              uVar2 = pbVar9[6] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[6] << 0x10) +
                                (ulong)((uVar7 >> 0x18) + (uVar11 >> 0x18) * 0x100)] & 3) << 4) |
                       bVar16;
              if (uVar14 == uVar2) {
                uVar11 = uVar7 & 0xf000000 | uVar11 & 0xf0ffffff;
                bVar17 = 0;
              }
              pbVar9[6] = bVar17;
            }
            if ((uVar3 & 0xf0000000) != 0) {
              uVar3 = pbVar9[7] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar9[7] << 0x10) +
                                (ulong)((uVar7 >> 0x1c) + (uVar11 >> 0x1c) * 0x100)] & 3) << 6) |
                       bVar16;
              if (uVar14 == uVar3) {
                uVar11 = uVar7 & 0xf0000000 | uVar11 & 0xfffffff;
                bVar17 = 0;
              }
              pbVar9[7] = bVar17;
            }
            buffer_old[lVar12] = uVar11;
            pbVar13[1] = bVar16;
          }
          lVar12 = lVar12 + 1;
          pbVar9 = pbVar9 + 8;
          pbVar13 = pbVar13 + 2;
        } while ((int)lVar12 < (int)uVar4);
        frame_count = frame_count + lVar1 * 8;
        buffer_old = buffer_old + lVar1;
        buffer_new = buffer_new + lVar1;
      }
      uVar15 = uVar15 + 1;
    } while (uVar5 != uVar15);
    return;
  }
  return;
}



void get_overlay_image(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,u8 *frame_count,
                      ebc_info *ebc_info)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  u32 uVar6;
  u32 uVar7;
  uint uVar8;
  byte bVar9;
  byte *pbVar10;
  ebc *peVar11;
  uint uVar12;
  long lVar13;
  byte *pbVar14;
  u32 uVar15;
  byte bVar16;
  byte bVar17;
  
  peVar11 = global_ebc;
  uVar5 = (global_ebc->panel).vir_width;
  uVar6 = (global_ebc->panel).vir_height;
  uVar7 = (global_ebc->panel).mirror;
  ebc_info->auto_need_refresh = 0;
  if (0 < (int)uVar6) {
    uVar5 = uVar5 >> 3;
    uVar15 = 0;
    lVar1 = (ulong)(uVar5 - 1) + 1;
    do {
      if (uVar7 == 0) {
        uVar12 = uVar15 * (peVar11->panel).vir_width;
      }
      else {
        uVar12 = (((peVar11->panel).vir_height - 1) - uVar15) * (peVar11->panel).vir_width;
      }
      lVar13 = 0;
      pbVar10 = frame_count;
      pbVar14 = data_buf + (uVar12 >> 2);
      if (uVar5 != 0) {
        do {
          uVar8 = buffer_new[lVar13];
          uVar12 = buffer_old[lVar13];
          if (uVar8 == uVar12) {
            *pbVar14 = 0;
            pbVar14[1] = 0;
          }
          else {
            uVar4 = uVar8 ^ uVar12;
            ebc_info->auto_need_refresh = 1;
            bVar16 = 0;
            if ((uVar4 & 0xf) != 0) {
              uVar2 = *pbVar10 + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar9 = ebc_info->frame_total;
              if ((uVar8 & 0xf) == 0 || (uVar8 & 0xf) == 0xf) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (ebc_info->lut_data).wf_table
                       [(long)(int)((uint)*pbVar10 << 0x10) +
                        (ulong)((uVar12 & 0xff) * 0x100 + (uVar8 & 0xff))] & 3;
              if (bVar9 == uVar2) {
                uVar12 = uVar12 & 0xfffffff0 | uVar8 & 0xf;
                bVar17 = 0;
              }
              *pbVar10 = bVar17;
            }
            if ((uVar4 & 0xf0) != 0) {
              uVar2 = uVar8 & 0xf0;
              uVar3 = pbVar10[1] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar9 = ebc_info->frame_total;
              if (uVar2 == 0xf0 || uVar2 == 0) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[1] << 0x10) +
                                (ulong)((uVar12 >> 4 & 0xff) * 0x100 + (uVar8 >> 4 & 0xff))] & 3) <<
                             2) | bVar16;
              if (bVar9 == uVar3) {
                bVar17 = 0;
                uVar12 = uVar2 | uVar12 & 0xffffff0f;
              }
              pbVar10[1] = bVar17;
            }
            if ((uVar4 & 0xf00) != 0) {
              uVar2 = uVar8 & 0xf00;
              uVar3 = pbVar10[2] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar9 = ebc_info->frame_total;
              if (uVar2 == 0xf00 || uVar2 == 0) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[2] << 0x10) +
                                (ulong)((ushort)(uVar8 >> 8) & 0xff | (ushort)uVar12 & 0xff00)] & 3)
                             << 4) | bVar16;
              if (bVar9 == uVar3) {
                bVar17 = 0;
                uVar12 = uVar2 | uVar12 & 0xfffff0ff;
              }
              pbVar10[2] = bVar17;
            }
            if ((uVar4 & 0xf000) != 0) {
              uVar2 = uVar8 & 0xf000;
              uVar3 = pbVar10[3] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar9 = ebc_info->frame_total;
              if (uVar2 == 0xf000 || uVar2 == 0) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[3] << 0x10) +
                                (ulong)((uVar12 >> 0xc & 0xff) * 0x100 + (uVar8 >> 0xc & 0xff))] & 3
                              ) << 6) | bVar16;
              if (bVar9 == uVar3) {
                bVar17 = 0;
                uVar12 = uVar2 | uVar12 & 0xffff0fff;
              }
              pbVar10[3] = bVar17;
            }
            *pbVar14 = bVar16;
            bVar16 = 0;
            if ((uVar4 & 0xf0000) != 0) {
              uVar2 = uVar8 & 0xf0000;
              uVar3 = pbVar10[4] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar9 = ebc_info->frame_total;
              if (uVar2 == 0xf0000 || uVar2 == 0) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (ebc_info->lut_data).wf_table
                       [(long)(int)((uint)pbVar10[4] << 0x10) +
                        (ulong)((uVar12 >> 0x10 & 0xff) * 0x100 + (uVar8 >> 0x10 & 0xff))] & 3;
              if (bVar9 == uVar3) {
                bVar17 = 0;
                uVar12 = uVar2 | uVar12 & 0xfff0ffff;
              }
              pbVar10[4] = bVar17;
            }
            if ((uVar4 & 0xf00000) != 0) {
              uVar2 = uVar8 & 0xf00000;
              uVar3 = pbVar10[5] + 1 & 0xff;
              bVar17 = (byte)uVar3;
              bVar9 = ebc_info->frame_total;
              if (uVar2 == 0xf00000 || uVar2 == 0) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[5] << 0x10) +
                                (ulong)((uVar12 >> 0x14 & 0xff) * 0x100 + (uVar8 >> 0x14 & 0xff))] &
                              3) << 2) | bVar16;
              if (bVar9 == uVar3) {
                bVar17 = 0;
                uVar12 = uVar2 | uVar12 & 0xff0fffff;
              }
              pbVar10[5] = bVar17;
            }
            if ((uVar4 & 0xf000000) != 0) {
              uVar3 = uVar8 & 0xf000000;
              uVar2 = pbVar10[6] + 1 & 0xff;
              bVar17 = (byte)uVar2;
              bVar9 = ebc_info->frame_total;
              if (uVar3 == 0 || uVar3 == 0xf000000) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[6] << 0x10) +
                                (ulong)((uVar8 >> 0x18) + (uVar12 >> 0x18) * 0x100)] & 3) << 4) |
                       bVar16;
              if (bVar9 == uVar2) {
                bVar17 = 0;
                uVar12 = uVar3 | uVar12 & 0xf0ffffff;
              }
              pbVar10[6] = bVar17;
            }
            if ((uVar4 & 0xf0000000) != 0) {
              uVar4 = pbVar10[7] + 1 & 0xff;
              bVar17 = (byte)uVar4;
              bVar9 = ebc_info->frame_total;
              if ((uVar8 & 0xf0000000) == 0 || (uVar8 & 0xf0000000) == 0xf0000000) {
                bVar9 = ebc_info->frame_bw_total;
              }
              bVar16 = (byte)(((ebc_info->lut_data).wf_table
                               [(long)(int)((uint)pbVar10[7] << 0x10) +
                                (ulong)((uVar8 >> 0x1c) + (uVar12 >> 0x1c) * 0x100)] & 3) << 6) |
                       bVar16;
              if (bVar9 == uVar4) {
                bVar17 = 0;
                uVar12 = uVar8 & 0xf0000000 | uVar12 & 0xfffffff;
              }
              pbVar10[7] = bVar17;
            }
            buffer_old[lVar13] = uVar12;
            pbVar14[1] = bVar16;
          }
          lVar13 = lVar13 + 1;
          pbVar10 = pbVar10 + 8;
          pbVar14 = pbVar14 + 2;
        } while ((int)lVar13 < (int)uVar5);
        frame_count = frame_count + lVar1 * 8;
        buffer_old = buffer_old + lVar1;
        buffer_new = buffer_new + lVar1;
      }
      uVar15 = uVar15 + 1;
    } while (uVar6 != uVar15);
  }
  return;
}



int ebc_open(undefined *inode,file *file)

{
  file->f_pos = 0;
  return 0;
}



int ebc_resume(device *dev)

{
  ebc *ebc;
  
  ebc = (ebc *)dev->driver_data;
  (*ebc->pmic->pmic_pm_resume)(ebc->pmic);
  (ebc->info).is_deep_sleep = 0;
  _dev_info((ebc->info).dev,"device resume\n");
  return 0;
}



void ebc_vdd_power_timeout(timer_list *t)

{
  if ((global_ebc->info).wake_lock_is_set == 0) {
    return;
  }
  (global_ebc->info).wake_lock_is_set = 0;
  __pm_relax();
  return;
}



void FUN_001008f0(long param_1)

{
  *(undefined4 *)(param_1 + 0x260) = 0;
  __pm_relax();
  return;
}



int ebc_remove(platform_device *pdev)

{
  misc_deregister(&ebc_misc);
  return 0;
}



int ebc_mmap(file *file,vm_area_struct *vma)

{
  int iVar1;
  ulong uVar2;
  pteval_t pVar3;
  
  uVar2 = ebc_phy_buf_base_get();
  pVar3 = (vma->vm_page_prot).pgprot;
  vma->vm_flags = vma->vm_flags | 0x4044000;
  iVar1 = remap_pfn_range(vma,vma->vm_start,uVar2 >> 0xc,vma->vm_end - vma->vm_start,pVar3);
  if (iVar1 != 0) {
    iVar1 = -0xb;
  }
  return iVar1;
}



long ebc_io_ctl(file *file,uint cmd,ulong arg)

{
  ulong uVar1;
  ebc_info *peVar2;
  ebc *peVar3;
  long lVar4;
  bool bVar5;
  int iVar6;
  ebc_buf_s *peVar7;
  char *__dest;
  ulong uVar8;
  size_t __n;
  device *dev;
  int *piVar9;
  uint uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  wait_queue_entry __wq_entry;
  ebc_buf_info buf_info;
  
  lVar4 = __stack_chk_guard;
  peVar3 = global_ebc;
  if ((0x6fff < cmd) && (((cmd < 0x7004 || (cmd - 0x7006 < 2)) && (arg == 0)))) {
    lVar13 = -0xe;
    _dev_err((global_ebc->info).dev,"%s: argp NULL\n","ebc_io_ctl",0);
    goto LAB_00100b24;
  }
  if (cmd == 0x7005) {
    dev = (global_ebc->info).dev;
    (global_ebc->info).overlay_enable = 0;
    lVar13 = 0;
    (peVar3->info).overlay_start = 0;
    _dev_info(dev,"disable ebc overlay\n");
    goto LAB_00100b24;
  }
  if (cmd < 0x7006) {
    if (cmd == 0x7002) {
      puVar11 = (undefined8 *)cRead_8(sp_el0);
      buf_info.width_mm = (global_ebc->panel).width_mm;
      buf_info.height_mm = (global_ebc->panel).height_mm;
      buf_info.width = (global_ebc->panel).vir_width;
      buf_info.height = (global_ebc->panel).vir_height;
      buf_info.panel_color = (global_ebc->panel).panel_color;
      if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
         (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
        uVar12 = (long)(arg << 8) >> 8 & arg;
      }
      bVar5 = 0xffffffffffffffd3 < uVar12;
      uVar12 = uVar12 + 0x2c;
      uVar8 = 0;
      if (!bVar5 || uVar12 == 0) {
        uVar8 = puVar11[1];
      }
      if (bVar5) {
        uVar12 = 0xffffffffffffffff;
      }
      if (!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
          uVar12 == uVar8 + !bVar5) {
        lVar13 = cRead_8(sp_el0);
        if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
          arg = 0;
        }
        lVar13 = __arch_copy_to_user(arg,&buf_info,0x2c);
        if (lVar13 == 0) {
          lVar13 = 0;
          goto LAB_00100b24;
        }
      }
      lVar13 = -0xe;
      _dev_err((peVar3->info).dev,"EBC_GET_BUFFER_INFO failed\n");
      goto LAB_00100b24;
    }
    if (cmd < 0x7003) {
      if (cmd == 0x7000) {
        peVar7 = ebc_empty_buf_get();
        if (peVar7 != (ebc_buf_s *)0x0) {
          uVar12 = peVar7->phy_addr;
          iVar6 = ebc_phy_buf_base_get();
          puVar11 = (undefined8 *)cRead_8(sp_el0);
          buf_info.offset = (int)uVar12 - iVar6;
          buf_info.panel_color = (peVar3->panel).panel_color;
          buf_info.width = (peVar3->panel).vir_width;
          buf_info.height = (peVar3->panel).vir_height;
          if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
             (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
            uVar12 = (long)(arg << 8) >> 8 & arg;
          }
          bVar5 = 0xffffffffffffffd3 < uVar12;
          uVar12 = uVar12 + 0x2c;
          uVar8 = 0;
          if (!bVar5 || uVar12 == 0) {
            uVar8 = puVar11[1];
          }
          if (bVar5) {
            uVar12 = 0xffffffffffffffff;
          }
          if (!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
              uVar12 == uVar8 + !bVar5) {
            lVar13 = cRead_8(sp_el0);
            if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0)
            {
              arg = 0;
            }
            iVar6 = __arch_copy_to_user(arg,&buf_info,0x2c);
            if (iVar6 == 0) {
              lVar13 = 0;
              goto LAB_00100b24;
            }
          }
          lVar13 = -0xe;
          ebc_buf_release(peVar7);
          goto LAB_00100b24;
        }
        goto LAB_00101148;
      }
      if (cmd == 0x7001) {
        puVar11 = (undefined8 *)cRead_8(sp_el0);
        if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
           (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
          uVar12 = (long)(arg << 8) >> 8 & arg;
        }
        bVar5 = 0xffffffffffffffd3 < uVar12;
        uVar12 = uVar12 + 0x2c;
        uVar8 = 0;
        if (!bVar5 || uVar12 == 0) {
          uVar8 = puVar11[1];
        }
        if (bVar5) {
          uVar12 = 0xffffffffffffffff;
        }
        if (!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
            uVar12 == uVar8 + !bVar5) {
          lVar13 = cRead_8(sp_el0);
          if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
            arg = 0;
          }
          lVar13 = __arch_copy_from_user(&buf_info,arg,0x2c);
          if (lVar13 == 0) {
            lVar13 = ebc_phy_buf_base_get();
            peVar7 = (ebc_buf_s *)ebc_find_buf_by_phy_addr(buf_info.offset + lVar13);
            if (peVar7 != (ebc_buf_s *)0x0) {
              peVar7->buf_mode = buf_info.epd_mode;
              peVar7->win_x1 = buf_info.win_x1;
              peVar7->win_y1 = buf_info.win_y1;
              peVar7->win_x2 = buf_info.win_x2;
              peVar7->win_y2 = buf_info.win_y2;
              ebc_add_to_dsp_buf_list(peVar7);
              if ((peVar3->info).ebc_dsp_buf_status == 0) {
                (peVar3->info).ebc_dsp_buf_status = 1;
                __wake_up_sync(&ebc_thread_wq,1);
              }
              if (peVar7->buf_mode == EPD_SUSPEND) {
                if ((peVar3->info).is_early_suspend != 0) {
                  lVar13 = 0;
                  goto LAB_00100b24;
                }
              }
              else if (peVar7->buf_mode != EPD_POWER_OFF) goto __out;
              (peVar3->info).ebc_last_display = 1;
              init_wait_entry(&__wq_entry,0);
              while (lVar13 = prepare_to_wait_event(&ebc_poweroff_wq,&__wq_entry,1),
                    (peVar3->info).ebc_last_display != 0) {
                if (lVar13 != 0) goto __out;
                schedule();
              }
              finish_wait(&ebc_poweroff_wq,&__wq_entry);
            }
__out:
            lVar13 = 0;
            goto LAB_00100b24;
          }
        }
LAB_00101110:
        lVar13 = -0xe;
        goto LAB_00100b24;
      }
    }
    else {
      if (cmd == 0x7003) {
        puVar11 = (undefined8 *)cRead_8(sp_el0);
        piVar9 = &(global_ebc->info).full_mode_num;
        if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
           (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
          uVar12 = (long)(arg << 8) >> 8 & arg;
        }
        bVar5 = 0xfffffffffffffffb < uVar12;
        uVar12 = uVar12 + 4;
        uVar8 = 0;
        if (!bVar5 || uVar12 == 0) {
          uVar8 = puVar11[1];
        }
        if (bVar5) {
          uVar12 = 0xffffffffffffffff;
        }
        uVar12 = (ulong)(!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
                        uVar12 == uVar8 + !bVar5);
        if (uVar12 == 0) {
          __n = 4;
        }
        else {
          lVar13 = cRead_8(sp_el0);
          if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
            arg = 0;
          }
          __n = __arch_copy_from_user(piVar9,arg,4);
          if (__n == 0) {
            lVar13 = 0;
            _dev_info((peVar3->info).dev,"full_mode_num = %d\n",
                      (ulong)(uint)(peVar3->info).full_mode_num);
            goto LAB_00100b24;
          }
          uVar12 = 4 - __n;
        }
        memset((void *)((long)piVar9 + uVar12),0,__n);
        lVar13 = -0xe;
        _dev_err((peVar3->info).dev,"EBC_SET_FULL_MODE_NUM failed\n");
        goto LAB_00100b24;
      }
      if (cmd == 0x7004) {
        peVar2 = &global_ebc->info;
        (global_ebc->info).overlay_enable = 1;
        lVar13 = 0;
        _dev_info(peVar2->dev,
                  "enable ebc overlay, you can use auto_overlay mode to show somthing over the system display\n"
                 );
        goto LAB_00100b24;
      }
    }
LAB_00100fb0:
    lVar13 = 0;
    _dev_err((global_ebc->info).dev,"%s: unknow cmd\n","ebc_io_ctl",0);
    goto LAB_00100b24;
  }
  if (cmd == 0x7008) {
    peVar7 = ebc_empty_buf_get();
    if (peVar7 != (ebc_buf_s *)0x0) {
      piVar9 = (peVar3->info).auto_image_old;
      __dest = peVar7->virt_addr;
      uVar10 = (peVar3->panel).vir_width * (peVar3->panel).vir_height;
LAB_00100a48:
      memcpy(__dest,piVar9,(ulong)(uVar10 >> 1));
      uVar12 = peVar7->phy_addr;
      iVar6 = ebc_phy_buf_base_get();
      buf_info.offset = (int)uVar12 - iVar6;
      puVar11 = (undefined8 *)cRead_8(sp_el0);
      buf_info.width = (peVar3->panel).vir_width;
      buf_info.height = (peVar3->panel).vir_height;
      uVar12 = puVar11[1];
      if ((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) == 0) {
LAB_00100a78:
        uVar8 = arg;
        if (((uint)*puVar11 >> 0x1a & 1) != 0) goto LAB_00100a84;
      }
      else {
LAB_00100a84:
        uVar8 = (long)(arg << 8) >> 8 & arg;
      }
      bVar5 = 0xffffffffffffffd3 < uVar8;
      uVar8 = uVar8 + 0x2c;
      uVar1 = 0;
      if (!bVar5 || uVar8 == 0) {
        uVar1 = uVar12;
      }
      if (bVar5) {
        uVar8 = 0xffffffffffffffff;
      }
      lVar13 = 0x2c;
      if (!CARRY8(uVar8,~uVar1) && !CARRY8(uVar8 + ~uVar1,(ulong)bVar5) || uVar8 == uVar1 + !bVar5)
      {
        lVar13 = cRead_8(sp_el0);
        if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
          arg = 0;
        }
        iVar6 = __arch_copy_to_user(arg,&buf_info,0x2c);
        lVar13 = (long)iVar6;
      }
      ebc_buf_release(peVar7);
      goto LAB_00100b24;
    }
  }
  else if (cmd < 0x7009) {
    if (cmd != 0x7006) {
      if (cmd == 0x7007) {
        puVar11 = (undefined8 *)cRead_8(sp_el0);
        if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
           (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
          uVar12 = (long)(arg << 8) >> 8 & arg;
        }
        bVar5 = 0xffffffffffffffd3 < uVar12;
        uVar12 = uVar12 + 0x2c;
        uVar8 = 0;
        if (!bVar5 || uVar12 == 0) {
          uVar8 = puVar11[1];
        }
        if (bVar5) {
          uVar12 = 0xffffffffffffffff;
        }
        if (!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
            uVar12 == uVar8 + !bVar5) {
          lVar13 = cRead_8(sp_el0);
          if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
            arg = 0;
          }
          lVar13 = __arch_copy_from_user(&buf_info,arg,0x2c);
          if (lVar13 == 0) {
            peVar7 = (ebc_buf_s *)ebc_osd_buf_clone();
            if (peVar7 != (ebc_buf_s *)0x0) {
              peVar7->buf_mode = buf_info.epd_mode;
              peVar7->win_x1 = buf_info.win_x1;
              peVar7->win_y1 = buf_info.win_y1;
              peVar7->win_x2 = buf_info.win_x2;
              peVar7->win_y2 = buf_info.win_y2;
              ebc_add_to_dsp_buf_list(peVar7);
              if ((peVar3->info).ebc_dsp_buf_status == 0) {
                (peVar3->info).ebc_dsp_buf_status = 1;
                lVar13 = 0;
                __wake_up_sync(&ebc_thread_wq,1);
                goto LAB_00100b24;
              }
            }
            goto __out;
          }
        }
        goto LAB_00101110;
      }
      goto LAB_00100fb0;
    }
    lVar13 = ebc_osd_buf_get();
    if (lVar13 != 0) {
      uVar14 = *(undefined8 *)(lVar13 + 8);
      iVar6 = ebc_phy_buf_base_get();
      puVar11 = (undefined8 *)cRead_8(sp_el0);
      buf_info.offset = (int)uVar14 - iVar6;
      buf_info.panel_color = (peVar3->panel).panel_color;
      buf_info.width = (peVar3->panel).vir_width;
      buf_info.height = (peVar3->panel).vir_height;
      if (((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) != 0) ||
         (uVar12 = arg, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
        uVar12 = (long)(arg << 8) >> 8 & arg;
      }
      bVar5 = 0xffffffffffffffd3 < uVar12;
      uVar12 = uVar12 + 0x2c;
      uVar8 = 0;
      if (!bVar5 || uVar12 == 0) {
        uVar8 = puVar11[1];
      }
      if (bVar5) {
        uVar12 = 0xffffffffffffffff;
      }
      lVar13 = 0x2c;
      if (!CARRY8(uVar12,~uVar8) && !CARRY8(uVar12 + ~uVar8,(ulong)bVar5) ||
          uVar12 == uVar8 + !bVar5) {
        lVar13 = cRead_8(sp_el0);
        if (((long)(arg << 8) >> 8 & arg & (*(ulong *)(lVar13 + 8) ^ 0xffffffffffffffff)) != 0) {
          arg = 0;
        }
        iVar6 = __arch_copy_to_user(arg,&buf_info,0x2c);
        lVar13 = (long)iVar6;
      }
      goto LAB_00100b24;
    }
  }
  else if (cmd == 0x700a) {
    peVar7 = ebc_empty_buf_get();
    if (peVar7 != (ebc_buf_s *)0x0) {
      piVar9 = (peVar3->info).auto_image_bg;
      __dest = peVar7->virt_addr;
      uVar10 = (peVar3->panel).vir_width * (peVar3->panel).vir_height;
      goto LAB_00100a48;
    }
  }
  else if (cmd < 0x700a) {
    peVar7 = ebc_empty_buf_get();
    if (peVar7 != (ebc_buf_s *)0x0) {
      memcpy(peVar7->virt_addr,(peVar3->info).auto_image_new,
             (ulong)((peVar3->panel).vir_width * (peVar3->panel).vir_height >> 1));
      uVar12 = peVar7->phy_addr;
      iVar6 = ebc_phy_buf_base_get();
      buf_info.offset = (int)uVar12 - iVar6;
      puVar11 = (undefined8 *)cRead_8(sp_el0);
      buf_info.width = (peVar3->panel).vir_width;
      buf_info.height = (peVar3->panel).vir_height;
      uVar12 = puVar11[1];
      if ((*(uint *)((long)puVar11 + 0x34) >> 0x15 & 1) == 0) goto LAB_00100a78;
      goto LAB_00100a84;
    }
  }
  else {
    if (cmd != 0x700b) goto LAB_00100fb0;
    peVar7 = ebc_empty_buf_get();
    if (peVar7 != (ebc_buf_s *)0x0) {
      __dest = peVar7->virt_addr;
      uVar10 = (peVar3->panel).vir_width * (peVar3->panel).vir_height;
      piVar9 = (int *)((peVar3->info).curr_dsp_buf)->virt_addr;
      goto LAB_00100a48;
    }
  }
LAB_00101148:
  lVar13 = -1;
LAB_00100b24:
  if (lVar4 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return lVar13;
}



void frame_done_callback(void)

{
  ebc *peVar1;
  undefined *tsk;
  device *dev;
  
  tsk = ebc_auto_task;
  peVar1 = global_ebc;
  if (EPD_OVERLAY < ((global_ebc->info).curr_dsp_buf)->buf_mode) {
    if ((global_ebc->info).frame_left == 0) {
      dev = (global_ebc->info).dev;
      (global_ebc->info).is_busy_now = 0;
      (peVar1->info).ebc_irq_status = 1;
      _dev_info(dev,"frame done\n");
      __wake_up_sync(&ebc_wq,1,1);
      __wake_up_sync(&ebc_thread_wq,1,1);
      return;
    }
    (global_ebc->info).is_busy_now = 1;
    wake_up_process((task_struct *)tsk);
    return;
  }
  if ((global_ebc->info).auto_need_refresh != 0) {
    wake_up_process((task_struct *)ebc_auto_task);
    return;
  }
  _dev_info((global_ebc->info).dev,"auto frame done\n");
  memset((peVar1->info).auto_frame_count,0,
         (ulong)((peVar1->panel).vir_width * (peVar1->panel).vir_height));
  mod_timer(&(peVar1->info).frame_timer,jiffies + 0x18000000);
  (peVar1->info).ebc_irq_status = 1;
  (peVar1->info).is_busy_now = 0;
  __wake_up_sync(&ebc_wq,1,1);
  __wake_up_sync(&ebc_thread_wq,1,1);
  return;
}



void ebc_frame_timeout(timer_list *t)

{
  frame_done_callback();
  return;
}



// WARNING: Type propagation algorithm not settling

int ebc_lut_update(ebc *ebc)

{
  uint ret;
  int iVar1;
  ulong uVar2;
  uint temperature;
  long local_8;
  
  temperature = 0x19;
  local_8 = __stack_chk_guard;
  ret = (*ebc->pmic->pmic_read_temperature)(ebc->pmic,(int *)&temperature);
  if (ret == 0) {
    uVar2 = (ulong)temperature;
    if ((int)temperature < 0) {
      _dev_info((ebc->info).dev,"temperature = %d, out of range0~50 ,use 0 \n");
      temperature = 0;
      uVar2 = 0;
    }
    else if (0x32 < (int)temperature) {
      _dev_info((ebc->info).dev,"temperature = %d, out of range0~50 ,use 50 \n");
      uVar2 = 0x32;
      temperature = 0x32;
    }
  }
  else {
    _dev_err((ebc->info).dev,"ebc_pmic_read_temp failed, ret = %d\n",(ulong)ret);
    uVar2 = (ulong)temperature;
  }
  _dev_info((ebc->info).dev,"lut update use temperature = %d\n",uVar2);
  switch(((ebc->info).curr_dsp_buf)->buf_mode) {
  default:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GC16,temperature);
    break;
  case EPD_OVERLAY:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_AUTO,temperature);
    break;
  case EPD_FULL_GL16:
  case EPD_PART_GL16:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GL16,temperature);
    break;
  case EPD_FULL_GLR16:
  case EPD_PART_GLR16:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GLR16,temperature);
    break;
  case EPD_FULL_GLD16:
  case EPD_PART_GLD16:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GLD16,temperature);
    break;
  case EPD_FULL_GCC16:
  case EPD_PART_GCC16:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GCC16,temperature);
    break;
  case EPD_A2:
  case EPD_A2_DITHER:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_A2,temperature);
    break;
  case EPD_DU:
  case EPD_A2_ENTER:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GRAY2,temperature);
    break;
  case EPD_DU4:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_GRAY4,temperature);
    break;
  case EPD_RESET:
    iVar1 = epd_lut_get(&(ebc->info).lut_data,WF_TYPE_RESET,temperature);
  }
  if (iVar1 == 0) {
    if (ret == 0) goto LAB_00101390;
  }
  else {
    ret = 0xffffffff;
  }
  _dev_err((ebc->info).dev,"get lut data failed\n");
LAB_00101390:
  if (local_8 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return ret;
}



ssize_t ebc_buf_state_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = ebc_buf_state_show(buf);
  return (long)iVar1;
}



ssize_t ebc_state_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%d\n",(ulong)(uint)(global_ebc->info).wake_lock_is_set);
  return (long)iVar1;
}



ssize_t ebc_version_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%s\n",&DAT_00104868);
  return (long)iVar1;
}



ssize_t pmic_vcom_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = (*global_ebc->pmic->pmic_get_vcom)(global_ebc->pmic);
  iVar1 = sprintf(buf,"%d\n",iVar1);
  return (long)iVar1;
}



ssize_t pmic_temp_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  int t;
  uint local_c;
  long local_8;
  
  local_8 = __stack_chk_guard;
  (*global_ebc->pmic->pmic_read_temperature)(global_ebc->pmic,(int *)&local_c);
  iVar1 = sprintf(buf,"%d\n",(ulong)local_c);
  if (local_8 == __stack_chk_guard) {
    return (long)iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



ssize_t pmic_name_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  
  iVar1 = sprintf(buf,"%s\n",global_ebc->pmic->pmic_name);
  return (long)iVar1;
}



ssize_t pmic_vcom_write(device *device,device_attribute *attr,char *buf,size_t count)

{
  ebc *peVar1;
  int iVar2;
  undefined4 local_c;
  long local_8;
  
  peVar1 = global_ebc;
  local_8 = __stack_chk_guard;
  iVar2 = kstrtouint(buf,0,&local_c);
  if (iVar2 == 0) {
    iVar2 = ebc_pmic_set_vcom(peVar1->pmic,local_c);
    if (iVar2 != 0) {
      count = 0xffffffffffffffff;
      _dev_err(peVar1->dev,"set vcom value failed\n");
    }
  }
  else {
    count = 0xffffffffffffffff;
    _dev_err(peVar1->dev,"invalid value = %s\n",buf);
  }
  if (local_8 == __stack_chk_guard) {
    return count;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



ssize_t waveform_version_read(device *device,device_attribute *attr,char *buf)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = epd_lut_get_wf_version();
  iVar1 = sprintf(buf,"%s\n",uVar2);
  return (long)iVar1;
}



void direct_mode_data_change(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,ebc_info *ebc_info)

{
  undefined8 *puVar1;
  long lVar2;
  u32 uVar3;
  u32 uVar4;
  uint uVar5;
  int iVar6;
  ebc *peVar7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  u8 *puVar12;
  byte *pbVar13;
  long lVar14;
  ulong uVar15;
  u32 uVar16;
  u32 uVar17;
  
  peVar7 = global_ebc;
  uVar17 = ebc_info->buf_align16;
  if (uVar17 == 0) {
    puVar12 = (ebc_info->lut_data).wf_table;
    iVar6 = (uint)(byte)ebc_info->frame_total - ebc_info->frame_left;
    uVar3 = (global_ebc->panel).vir_height;
    uVar11 = (global_ebc->panel).vir_width;
    uVar16 = (global_ebc->panel).mirror;
    uVar5 = uVar11 >> 3;
    if (0 < (int)uVar3) {
      lVar2 = (ulong)(uVar5 - 1) + 1;
      if (uVar16 == 0) goto LAB_00101888;
      do {
        uVar11 = (((peVar7->panel).vir_height - 1) - uVar17) * uVar11;
        while( true ) {
          if (uVar5 != 0) {
            lVar14 = 0;
            pbVar13 = data_buf + (uVar11 >> 2);
            do {
              uVar11 = buffer_old[lVar14];
              uVar8 = buffer_new[lVar14];
              lVar14 = lVar14 + 1;
              *pbVar13 = puVar12[(long)(int)((uVar11 & 0xff) * 0x100 + (uVar8 & 0xff)) +
                                 (long)(iVar6 * 0x10000)] |
                         puVar12[(long)(int)((uVar11 & 0xff00) + ((uVar8 & 0xffff) >> 8)) +
                                 (long)(iVar6 * 0x10000)] << 4;
              pbVar13[1] = puVar12[(long)(int)((uVar11 >> 0x10 & 0xff) * 0x100 +
                                              (uVar8 >> 0x10 & 0xff)) + (long)(iVar6 * 0x10000)] |
                           puVar12[(long)(int)((uVar11 >> 0x10 & 0xff00) + (uVar8 >> 0x18)) +
                                   (long)(iVar6 * 0x10000)] << 4;
              pbVar13 = pbVar13 + 2;
            } while ((int)lVar14 < (int)uVar5);
            buffer_new = buffer_new + lVar2;
            buffer_old = buffer_old + lVar2;
          }
          uVar17 = uVar17 + 1;
          if (uVar3 == uVar17) {
            return;
          }
          uVar11 = (peVar7->panel).vir_width;
          if (uVar16 != 0) break;
LAB_00101888:
          uVar11 = uVar17 * uVar11;
        }
      } while( true );
    }
  }
  else {
    puVar12 = (ebc_info->lut_data).wf_table;
    iVar6 = (uint)(byte)ebc_info->frame_total - ebc_info->frame_left;
    uVar17 = (global_ebc->panel).vir_height;
    uVar11 = (global_ebc->panel).vir_width;
    uVar3 = (global_ebc->panel).mirror;
    uVar5 = uVar11 >> 4;
    if (0 < (int)uVar17) {
      lVar2 = (ulong)(uVar5 - 1) + 1;
      uVar16 = 0;
      if (uVar3 == 0) goto LAB_00101a1c;
      do {
        uVar11 = (((global_ebc->panel).vir_height - 1) - uVar16) * uVar11;
        while( true ) {
          pbVar13 = data_buf + (uVar11 >> 2);
          if (uVar5 != 0) goto LAB_00101914;
          uVar16 = uVar16 + 1;
          if (uVar17 == uVar16) {
            return;
          }
          uVar11 = (global_ebc->panel).vir_width;
          if (uVar3 != 0) break;
LAB_00101a1c:
          uVar11 = uVar16 * uVar11;
        }
      } while( true );
    }
  }
  return;
LAB_00101914:
  lVar14 = 0;
  do {
    puVar1 = (undefined8 *)((long)buffer_old + lVar14);
    uVar9 = *(ulong *)((long)buffer_new + lVar14);
    lVar14 = lVar14 + 8;
    uVar10 = (uint)*puVar1;
    uVar8 = (uint)uVar9;
    uVar11 = (uint)((ulong)*puVar1 >> 0x20);
    uVar15 = uVar9 >> 0x20 & 0xffff;
    *pbVar13 = puVar12[(long)(int)((uVar10 & 0xff) * 0x100 + (uVar8 & 0xff)) +
                       (long)(iVar6 * 0x10000)] |
               puVar12[(long)(int)((uVar10 & 0xff00) + ((uVar8 & 0xffff) >> 8)) +
                       (long)(iVar6 * 0x10000)] << 4;
    pbVar13[1] = puVar12[(long)(int)((uVar10 >> 0x10 & 0xff) * 0x100 + (uVar8 >> 0x10 & 0xff)) +
                         (long)(iVar6 * 0x10000)] |
                 puVar12[(long)(int)((uVar10 >> 0x10 & 0xff00) + (uVar8 >> 0x18)) +
                         (long)(iVar6 * 0x10000)] << 4;
    pbVar13[2] = puVar12[(long)(int)((uVar11 & 0xff) * 0x100 + (uint)(byte)uVar15) +
                         (long)(iVar6 * 0x10000)] |
                 puVar12[(long)(int)((uVar11 & 0xff00) + ((uint)uVar15 >> 8)) +
                         (long)(iVar6 * 0x10000)] << 4;
    pbVar13[3] = puVar12[(long)(int)((uVar11 >> 0x10 & 0xff) * 0x100 + (uint)(byte)(uVar9 >> 0x30))
                         + (long)(iVar6 * 0x10000)] |
                 puVar12[(long)(int)((uVar11 >> 0x10 & 0xff00) + (uint)(uVar9 >> 0x38)) +
                         (long)(iVar6 * 0x10000)] << 4;
    pbVar13 = pbVar13 + 4;
  } while (lVar2 * 8 - lVar14 != 0);
  buffer_new = buffer_new + lVar2 * 2;
  buffer_old = buffer_old + lVar2 * 2;
  do {
    while( true ) {
      uVar16 = uVar16 + 1;
      if (uVar17 == uVar16) {
        return;
      }
      uVar4 = (peVar7->panel).vir_width;
      if (uVar3 == 0) break;
      pbVar13 = data_buf + ((((peVar7->panel).vir_height - 1) - uVar16) * uVar4 >> 2);
      if (uVar5 != 0) goto LAB_00101914;
    }
    pbVar13 = data_buf + (uVar16 * uVar4 >> 2);
  } while (uVar5 == 0);
  goto LAB_00101914;
}



void direct_mode_data_change_part(u8 *data_buf,u32 *buffer_new,u32 *buffer_old,ebc_info *ebc_info)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  u32 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ebc *peVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  u8 *puVar16;
  undefined4 *puVar17;
  byte bVar18;
  byte bVar19;
  long lVar20;
  u32 uVar21;
  undefined2 *puVar22;
  byte bVar23;
  u32 uVar24;
  
  peVar10 = global_ebc;
  uVar24 = ebc_info->buf_align16;
  if (uVar24 == 0) {
    puVar16 = (ebc_info->lut_data).wf_table;
    iVar9 = (uint)(byte)ebc_info->frame_total - ebc_info->frame_left;
    uVar4 = (global_ebc->panel).vir_height;
    uVar21 = (global_ebc->panel).mirror;
    uVar15 = (global_ebc->panel).vir_width;
    uVar7 = uVar15 >> 3;
    if (0 < (int)uVar4) {
      lVar1 = (ulong)(uVar7 - 1) + 1;
      if (uVar21 == 0) goto LAB_00101c1c;
      do {
        uVar15 = (((peVar10->panel).vir_height - 1) - uVar24) * uVar15;
        while( true ) {
          if (uVar7 != 0) {
            lVar20 = 0;
            puVar22 = (undefined2 *)(data_buf + (uVar15 >> 2));
            do {
              uVar5 = buffer_old[lVar20];
              bVar18 = 0;
              uVar6 = buffer_new[lVar20];
              bVar19 = 0;
              uVar15 = uVar6 & 0xffff;
              uVar8 = uVar5 >> 0x10;
              uVar11 = uVar5 & 0xffff ^ uVar15;
              uVar13 = (uVar5 ^ uVar6) >> 0x10;
              if (uVar6 == uVar5) {
                *puVar22 = 0;
              }
              else {
                bVar23 = 3;
                if ((uVar5 & 0xffff) != uVar15) {
                  bVar18 = bVar23;
                  if ((uVar11 & 0xf) == 0) {
                    bVar18 = 0;
                  }
                  bVar2 = bVar18 | 0xc;
                  if ((uVar11 & 0xf0) == 0) {
                    bVar2 = bVar18;
                  }
                  bVar3 = bVar2 | 0x30;
                  if ((uVar11 & 0xf00) == 0) {
                    bVar3 = bVar2;
                  }
                  bVar18 = bVar3 | 0xc0;
                  if ((uVar11 & 0xf000) == 0) {
                    bVar18 = bVar3;
                  }
                  bVar18 = (puVar16[(long)(int)((uVar5 & 0xff) * 0x100 + (uVar6 & 0xff)) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar5 & 0xff00) + (uVar15 >> 8)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar18;
                }
                *(byte *)puVar22 = bVar18;
                if (uVar8 != uVar6 >> 0x10) {
                  if ((uVar13 & 0xf) == 0) {
                    bVar23 = 0;
                  }
                  bVar18 = bVar23 | 0xc;
                  if ((uVar13 & 0xf0) == 0) {
                    bVar18 = bVar23;
                  }
                  bVar23 = bVar18 | 0x30;
                  if ((uVar13 & 0xf00) == 0) {
                    bVar23 = bVar18;
                  }
                  bVar19 = bVar23 | 0xc0;
                  if ((uVar13 & 0xf000) == 0) {
                    bVar19 = bVar23;
                  }
                  bVar19 = (puVar16[(long)(int)((uVar8 & 0xff) * 0x100 + (uVar6 >> 0x10 & 0xff)) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar8 & 0xff00) + (uVar6 >> 0x18)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar19;
                }
                *(byte *)((long)puVar22 + 1) = bVar19;
              }
              lVar20 = lVar20 + 1;
              puVar22 = puVar22 + 1;
            } while ((int)lVar20 < (int)uVar7);
            buffer_new = buffer_new + lVar1;
            buffer_old = buffer_old + lVar1;
          }
          uVar24 = uVar24 + 1;
          if (uVar4 == uVar24) {
            return;
          }
          uVar15 = (peVar10->panel).vir_width;
          if (uVar21 != 0) break;
LAB_00101c1c:
          uVar15 = uVar24 * uVar15;
        }
      } while( true );
    }
  }
  else {
    puVar16 = (ebc_info->lut_data).wf_table;
    iVar9 = (uint)(byte)ebc_info->frame_total - ebc_info->frame_left;
    uVar24 = (global_ebc->panel).vir_height;
    uVar4 = (global_ebc->panel).mirror;
    uVar15 = (global_ebc->panel).vir_width;
    uVar7 = uVar15 >> 4;
    if (0 < (int)uVar24) {
      lVar1 = (ulong)(uVar7 - 1) + 1;
      uVar21 = 0;
      if (uVar4 == 0) goto LAB_00101ec8;
      do {
        uVar15 = (((peVar10->panel).vir_height - 1) - uVar21) * uVar15;
        while( true ) {
          if (uVar7 != 0) {
            lVar20 = 0;
            puVar17 = (undefined4 *)(data_buf + (uVar15 >> 2));
            do {
              uVar12 = *(ulong *)(buffer_new + lVar20 * 2);
              uVar14 = *(ulong *)(buffer_old + lVar20 * 2);
              if (uVar12 == uVar14) {
                *puVar17 = 0;
              }
              else {
                uVar13 = (uint)uVar14;
                uVar11 = (uint)uVar12;
                uVar15 = uVar11 & 0xffff;
                bVar18 = 0;
                bVar19 = 3;
                if ((uVar13 & 0xffff) != uVar15) {
                  uVar5 = uVar13 & 0xffff ^ uVar15;
                  bVar18 = bVar19;
                  if ((uVar5 & 0xf) == 0) {
                    bVar18 = 0;
                  }
                  bVar23 = bVar18 | 0xc;
                  if ((uVar5 & 0xf0) == 0) {
                    bVar23 = bVar18;
                  }
                  bVar2 = bVar23 | 0x30;
                  if ((uVar5 & 0xf00) == 0) {
                    bVar2 = bVar23;
                  }
                  bVar18 = bVar2 | 0xc0;
                  if ((uVar5 & 0xf000) == 0) {
                    bVar18 = bVar2;
                  }
                  bVar18 = (puVar16[(long)(int)((uVar13 & 0xff) * 0x100 + (uVar11 & 0xff)) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar13 & 0xff00) + (uVar15 >> 8)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar18;
                }
                *(byte *)puVar17 = bVar18;
                uVar15 = uVar13 >> 0x10;
                bVar18 = 0;
                if (uVar15 != uVar11 >> 0x10) {
                  uVar13 = (uVar13 ^ uVar11) >> 0x10;
                  bVar18 = bVar19;
                  if ((uVar13 & 0xf) == 0) {
                    bVar18 = 0;
                  }
                  bVar23 = bVar18 | 0xc;
                  if ((uVar13 & 0xf0) == 0) {
                    bVar23 = bVar18;
                  }
                  bVar2 = bVar23 | 0x30;
                  if ((uVar13 & 0xf00) == 0) {
                    bVar2 = bVar23;
                  }
                  bVar18 = bVar2 | 0xc0;
                  if ((uVar13 & 0xf000) == 0) {
                    bVar18 = bVar2;
                  }
                  bVar18 = (puVar16[(long)(int)((uVar15 & 0xff) * 0x100 + (uVar11 >> 0x10 & 0xff)) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar15 & 0xff00) + (uVar11 >> 0x18)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar18;
                }
                *(byte *)((long)puVar17 + 1) = bVar18;
                uVar15 = (uint)(uVar14 >> 0x20);
                uVar14 = uVar12 >> 0x20 & 0xffff;
                bVar18 = 0;
                uVar11 = (uint)uVar14;
                if ((uVar15 & 0xffff) != uVar11) {
                  uVar13 = uVar15 & 0xffff ^ uVar11;
                  bVar18 = bVar19;
                  if ((uVar13 & 0xf) == 0) {
                    bVar18 = 0;
                  }
                  bVar23 = bVar18 | 0xc;
                  if ((uVar13 & 0xf0) == 0) {
                    bVar23 = bVar18;
                  }
                  bVar2 = bVar23 | 0x30;
                  if ((uVar13 & 0xf00) == 0) {
                    bVar2 = bVar23;
                  }
                  bVar18 = bVar2 | 0xc0;
                  if ((uVar13 & 0xf000) == 0) {
                    bVar18 = bVar2;
                  }
                  bVar18 = (puVar16[(long)(int)((uVar15 & 0xff) * 0x100 + (uint)(byte)uVar14) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar15 & 0xff00) + (uVar11 >> 8)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar18;
                }
                *(byte *)((long)puVar17 + 2) = bVar18;
                bVar18 = 0;
                uVar11 = (uint)(uVar12 >> 0x20);
                if (uVar15 >> 0x10 != uVar11 >> 0x10) {
                  uVar13 = (uVar15 ^ uVar11) >> 0x10;
                  if ((uVar13 & 0xf) == 0) {
                    bVar19 = 0;
                  }
                  bVar18 = bVar19 | 0xc;
                  if ((uVar13 & 0xf0) == 0) {
                    bVar18 = bVar19;
                  }
                  bVar19 = bVar18 | 0x30;
                  if ((uVar13 & 0xf00) == 0) {
                    bVar19 = bVar18;
                  }
                  bVar18 = bVar19 | 0xc0;
                  if ((uVar13 & 0xf000) == 0) {
                    bVar18 = bVar19;
                  }
                  bVar18 = (puVar16[(long)(int)((uVar15 >> 0x10 & 0xff) * 0x100 +
                                               (uint)(byte)(uVar12 >> 0x30)) +
                                    (long)(iVar9 * 0x10000)] |
                           puVar16[(long)(int)((uVar15 >> 0x10 & 0xff00) + (uVar11 >> 0x18)) +
                                   (long)(iVar9 * 0x10000)] << 4) & bVar18;
                }
                *(byte *)((long)puVar17 + 3) = bVar18;
              }
              lVar20 = lVar20 + 1;
              puVar17 = puVar17 + 1;
            } while ((int)lVar20 < (int)uVar7);
            buffer_new = buffer_new + lVar1 * 2;
            buffer_old = buffer_old + lVar1 * 2;
          }
          uVar21 = uVar21 + 1;
          if (uVar24 == uVar21) {
            return;
          }
          uVar15 = (peVar10->panel).vir_width;
          if (uVar4 != 0) break;
LAB_00101ec8:
          uVar15 = uVar21 * uVar15;
        }
      } while( true );
    }
  }
  return;
}



void flip(ebc_panel *panel,uint buf_size)

{
  device *dev;
  dma_map_ops *dma_ops;
  int current_buffer;
  
  current_buffer = panel->current_buffer;
  dev = panel->dev;
  if (dev == (device *)0x0) {
    dma_ops = (dma_map_ops *)&dummy_dma_ops;
  }
  else {
    dma_ops = (dma_map_ops *)&dummy_dma_ops;
    if (dev->dma_ops != (dma_map_ops *)0x0) {
      dma_ops = dev->dma_ops;
    }
  }
  if (dma_ops->sync_single_for_device !=
      (anon_subr_void_device_ptr_dma_addr_t_size_t_dma_data_direction_for_sync_single_for_device *)
      0x0) {
    (*dma_ops->sync_single_for_device)
              (dev,panel->fb[current_buffer].phy_addr,(long)(int)buf_size,DMA_TO_DEVICE);
  }
  (*panel->tcon->dsp_mode_set)(panel->tcon,0,0,0,0);
  (*panel->tcon->image_addr_set)(panel->tcon,*(u32 *)&panel->fb[current_buffer].phy_addr,0);
  (*panel->tcon->frame_start)(panel->tcon,1);
  panel->current_buffer = 1 - panel->current_buffer;
  return;
}



void ebc_frame_start(ebc *ebc)

{
  ebc_info *ebc_info;
  ebc_panel *panel;
  ebc_buf_s *curr_dsp_buf;
  panel_refresh_mode buf_mode;
  
  ebc_info = &ebc->info;
  panel = &ebc->panel;
  curr_dsp_buf = (ebc->info).curr_dsp_buf;
  buf_mode = curr_dsp_buf->buf_mode;
  if (buf_mode == EPD_OVERLAY) {
    get_overlay_image((u8 *)(ebc->info).direct_buffer[0],(u32 *)(ebc->info).auto_image_new,
                      (u32 *)(ebc->info).auto_image_old,(ebc->info).auto_frame_count,ebc_info);
    if ((ebc->info).auto_need_refresh != 0) {
      (ebc->panel).current_buffer = 0;
      flip(panel,(ebc->info).direct_buf_real_size);
      get_overlay_image((u8 *)(ebc->info).direct_buffer[1],(u32 *)(ebc->info).auto_image_new,
                        (u32 *)(ebc->info).auto_image_old,(ebc->info).auto_frame_count,ebc_info);
      return;
    }
    _dev_info((ebc->info).dev,"%s: overlay no need to update\n","ebc_frame_start");
    (ebc->info).is_busy_now = 0;
    return;
  }
  if ((int)buf_mode < 2) {
    if (buf_mode == EPD_AUTO) {
      get_auto_image((u8 *)(ebc->info).direct_buffer[0],(u32 *)(ebc->info).auto_image_new,
                     (u32 *)(ebc->info).auto_image_old,(ebc->info).auto_frame_count,ebc_info);
      if ((ebc->info).auto_need_refresh != 0) {
        (ebc->panel).current_buffer = 0;
        flip(panel,(ebc->info).direct_buf_real_size);
        get_auto_image((u8 *)(ebc->info).direct_buffer[1],(u32 *)(ebc->info).auto_image_new,
                       (u32 *)(ebc->info).auto_image_old,(ebc->info).auto_frame_count,ebc_info);
        return;
      }
      _dev_info((ebc->info).dev,"%s: auto no need to update\n","ebc_frame_start");
      (ebc->info).is_busy_now = 0;
      return;
    }
  }
  else if (buf_mode + ~EPD_FULL_GCC16 < 10) {
    (ebc->info).frame_left = (uint)(byte)(ebc->info).frame_total;
    direct_mode_data_change_part
              ((u8 *)(ebc->info).direct_buffer[0],(u32 *)curr_dsp_buf->virt_addr,
               (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
    (ebc->panel).current_buffer = 0;
    flip(panel,(ebc->info).direct_buf_real_size);
    (ebc->info).frame_left = (ebc->info).frame_left + -1;
    direct_mode_data_change_part
              ((u8 *)(ebc->info).direct_buffer[1],(u32 *)((ebc->info).curr_dsp_buf)->virt_addr,
               (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
    return;
  }
  (ebc->info).frame_left = (uint)(byte)(ebc->info).frame_total;
  direct_mode_data_change
            ((u8 *)(ebc->info).direct_buffer[0],(u32 *)curr_dsp_buf->virt_addr,
             (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
  (ebc->panel).current_buffer = 0;
  flip(panel,(ebc->info).direct_buf_real_size);
  (ebc->info).frame_left = (ebc->info).frame_left + -1;
  direct_mode_data_change
            ((u8 *)(ebc->info).direct_buffer[1],(u32 *)((ebc->info).curr_dsp_buf)->virt_addr,
             (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
  return;
}



int ebc_auto_tast_function(void *data)

{
  ebc_panel *panel;
  ebc_info *ebc_info;
  long lVar1;
  work_struct *auto_buffer_work;
  panel_refresh_mode buf_mode;
  ebc *ebc;
  
  ebc = global_ebc;
  panel = &global_ebc->panel;
  ebc_info = &global_ebc->info;
  auto_buffer_work = &(global_ebc->info).auto_buffer_work;
  lVar1 = cRead_8(sp_el0);
  do {
    down(&ebc_auto_thread_sem);
    *(undefined8 *)(lVar1 + 0x20) = 2;
    DataMemoryBarrier(2,3);
    buf_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
    if (buf_mode == EPD_OVERLAY) {
      flip(panel,(ebc->info).direct_buf_real_size);
      get_overlay_image((u8 *)ebc_info->direct_buffer[(ebc->panel).current_buffer],
                        (u32 *)(ebc->info).auto_image_new,(u32 *)(ebc->info).auto_image_old,
                        (ebc->info).auto_frame_count,ebc_info);
LAB_00102254:
      buf_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
      if (buf_mode == EPD_AUTO) goto LAB_001022f0;
LAB_00102260:
      if (((buf_mode == EPD_OVERLAY) && ((ebc->info).overlay_enable != 0)) &&
         ((ebc->info).overlay_start != 0)) {
        queue_work_on(8,system_wq,auto_buffer_work);
      }
    }
    else {
      if ((int)buf_mode < 2) {
        if (buf_mode != EPD_AUTO) goto LAB_00102308;
        flip(panel,(ebc->info).direct_buf_real_size);
        get_auto_image((u8 *)ebc_info->direct_buffer[(ebc->panel).current_buffer],
                       (u32 *)(ebc->info).auto_image_new,(u32 *)(ebc->info).auto_image_old,
                       (ebc->info).auto_frame_count,ebc_info);
        goto LAB_00102254;
      }
      if (9 < buf_mode + ~EPD_FULL_GCC16) {
LAB_00102308:
        (ebc->info).frame_left = (ebc->info).frame_left + -1;
        flip(panel,(ebc->info).direct_buf_real_size);
        if ((ebc->info).frame_left != 0) {
          direct_mode_data_change
                    ((u8 *)ebc_info->direct_buffer[(ebc->panel).current_buffer],
                     (u32 *)((ebc->info).curr_dsp_buf)->virt_addr,
                     (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
        }
        goto LAB_00102254;
      }
      (ebc->info).frame_left = (ebc->info).frame_left + -1;
      flip(panel,(ebc->info).direct_buf_real_size);
      if ((ebc->info).frame_left == 0) goto LAB_00102254;
      direct_mode_data_change_part
                ((u8 *)ebc_info->direct_buffer[(ebc->panel).current_buffer],
                 (u32 *)((ebc->info).curr_dsp_buf)->virt_addr,
                 (u32 *)((ebc->info).prev_dsp_buf)->virt_addr,ebc_info);
      buf_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
      if (buf_mode != EPD_AUTO) goto LAB_00102260;
LAB_001022f0:
      queue_work_on(8,system_wq,auto_buffer_work);
    }
    up(&ebc_auto_thread_sem);
    schedule();
  } while( true );
}



int ebc_power_set(ebc *ebc,int power_status)

{
  int iVar1;
  
  (ebc->info).ebc_power_status = power_status;
  (*ebc->tcon->disable)(ebc->tcon);
  (*ebc->pmic->pmic_power_req)(ebc->pmic,false);
  if ((ebc->info).wake_lock_is_set == 0) {
    iVar1 = _dev_info(ebc->dev,"ebc hw power off\n");
    return iVar1;
  }
  (ebc->info).wake_lock_is_set = 0;
  __pm_relax(&(ebc->info).suspend_lock);
  iVar1 = _dev_info(ebc->dev,"ebc hw power off\n");
  return iVar1;
}



int ebc_suspend(device *dev)

{
  ebc *ebc;
  
  ebc = (ebc *)dev->driver_data;
  if ((ebc->info).ebc_power_status == 1) {
    _dev_info((ebc->info).dev,"%s: device is busy now...\n","ebc_suspend");
    ebc_power_set(ebc,0);
  }
  (ebc->info).is_deep_sleep = 1;
  (*ebc->pmic->pmic_pm_suspend)(ebc->pmic);
  _dev_info((ebc->info).dev,"device suspend\n");
  return 0;
}



// WARNING: Type propagation algorithm not settling
// WARNING: Could not reconcile some variable overlaps

int ebc_probe(platform_device *pdev)

{
  device *dev;
  list_head *plVar1;
  wake_lock *ws;
  timer_list *ptVar2;
  timer_list *ptVar3;
  u32 uVar4;
  uint uVar5;
  bool bVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  ebc *ebc;
  device_node *tcon_np;
  platform_device *tcon_dev;
  ebc_tcon *tcon;
  uint *puVar10;
  long lVar11;
  ebc_pmic *pmic;
  long mem_region_np;
  char *pcVar12;
  int *piVar13;
  u8 *__s;
  device_node *wf_region_np;
  task_struct *ebc_task;
  char *__s_00;
  ebc_buf_s *buf;
  ulong uVar14;
  uint uVar15;
  int iVar16;
  device *pdVar17;
  void *__dest;
  void *__dest_00;
  int local_70;
  uint local_6c;
  resource r;
  
  lVar7 = __stack_chk_guard;
  dev = &pdev->dev;
  ebc = (ebc *)devm_kmalloc(dev,800,0x6080c0);
  if (ebc == (ebc *)0x0) {
    iVar8 = -0xc;
    goto LAB_001025d0;
  }
  tcon_np = (pdev->dev).of_node;
  global_ebc = ebc;
  ebc->dev = dev;
  tcon_np = of_parse_phandle(tcon_np,"ebc_tcon",0);
  if (tcon_np == (device_node *)0x0) {
    iVar8 = -0x13;
    _dev_err(dev,"not find ebc tcon\n");
    goto LAB_001025d0;
  }
  tcon_dev = of_find_device_by_node(tcon_np);
  if (tcon_dev != (platform_device *)0x0) {
    tcon = (ebc_tcon *)(tcon_dev->dev).driver_data;
    ebc->tcon = tcon;
    if (tcon != (ebc_tcon *)0x0) {
      *(code **)(&tcon->len + 0x16) = frame_done_callback;
      puVar10 = (uint *)of_get_property((pdev->dev).of_node,"pmic",&local_70);
      local_70 = (int)((ulong)(long)local_70 >> 2);
      if (local_70 == 0) {
        iVar8 = -0x16;
        _dev_err(dev,"wrong pmics number\n");
        goto LAB_001025d0;
      }
      uVar15 = 0;
      if (local_70 < 1) {
LAB_0010261c:
        pmic = ebc->pmic;
        if (pmic != (ebc_pmic *)0x0) {
          (ebc->info).dev = dev;
          (ebc->panel).dev = dev;
          (ebc->panel).tcon = ebc->tcon;
          (ebc->panel).pmic = pmic;
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,width",&(ebc->panel).width,1,0);
          if ((((((iVar8 < 0) ||
                 (iVar8 = of_property_read_variable_u32_array
                                    ((pdev->dev).of_node,"panel,height",&(ebc->panel).height,1,0),
                 iVar8 < 0)) ||
                (iVar8 = of_property_read_variable_u32_array
                                   ((pdev->dev).of_node,"panel,vir_width",&(ebc->panel).vir_width,1,
                                    0), iVar8 < 0)) ||
               ((iVar8 = of_property_read_variable_u32_array
                                   ((pdev->dev).of_node,"panel,vir_height",&(ebc->panel).vir_height,
                                    1,0), iVar8 < 0 ||
                (iVar8 = of_property_read_variable_u32_array
                                   ((pdev->dev).of_node,"panel,sdck",&(ebc->panel).sdck,1,0),
                iVar8 < 0)))) ||
              (((iVar8 = of_property_read_variable_u32_array
                                   ((pdev->dev).of_node,"panel,lsl",&(ebc->panel).lsl,1,0),
                iVar8 < 0 ||
                ((iVar8 = of_property_read_variable_u32_array
                                    ((pdev->dev).of_node,"panel,lbl",&(ebc->panel).lbl,1,0),
                 iVar8 < 0 ||
                 (iVar8 = of_property_read_variable_u32_array
                                    ((pdev->dev).of_node,"panel,ldl",&(ebc->panel).ldl,1,0),
                 iVar8 < 0)))) ||
               (iVar8 = of_property_read_variable_u32_array
                                  ((pdev->dev).of_node,"panel,lel",&(ebc->panel).lel,1,0), iVar8 < 0
               )))) || ((((iVar8 = of_property_read_variable_u32_array
                                             ((pdev->dev).of_node,"panel,gdck-sta",
                                              &(ebc->panel).gdck_sta,1,0), iVar8 < 0 ||
                          (iVar8 = of_property_read_variable_u32_array
                                             ((pdev->dev).of_node,"panel,lgonl",&(ebc->panel).lgonl,
                                              1,0), iVar8 < 0)) ||
                         (iVar8 = of_property_read_variable_u32_array
                                            ((pdev->dev).of_node,"panel,fsl",&(ebc->panel).fsl,1,0),
                         iVar8 < 0)) ||
                        (((iVar8 = of_property_read_variable_u32_array
                                             ((pdev->dev).of_node,"panel,fbl",&(ebc->panel).fbl,1,0)
                          , iVar8 < 0 ||
                          (iVar8 = of_property_read_variable_u32_array
                                             ((pdev->dev).of_node,"panel,fdl",&(ebc->panel).fdl,1,0)
                          , iVar8 < 0)) ||
                         (iVar8 = of_property_read_variable_u32_array
                                            ((pdev->dev).of_node,"panel,fel",&(ebc->panel).fel,1,0),
                         iVar8 < 0)))))) {
            iVar8 = -0x16;
            _dev_err(dev,"failed to probe panel: %d\n",0xffffffea);
            goto LAB_001025d0;
          }
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,panel_16bit",&(ebc->panel).panel_16bit,1,0);
          if (iVar8 < 0) {
            (ebc->panel).panel_16bit = 0;
          }
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,panel_color",&(ebc->panel).panel_color,1,0);
          if (iVar8 < 0) {
            (ebc->panel).panel_color = 0;
          }
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,mirror",&(ebc->panel).mirror,1,0);
          if (iVar8 < 0) {
            (ebc->panel).mirror = 0;
          }
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,width-mm",&(ebc->panel).width_mm,1,0);
          if (iVar8 < 0) {
            (ebc->panel).width_mm = 0;
          }
          iVar8 = of_property_read_variable_u32_array
                            ((pdev->dev).of_node,"panel,height-mm",&(ebc->panel).height_mm,1,0);
          if (iVar8 < 0) {
            (ebc->panel).height_mm = 0;
          }
          uVar4 = (ebc->panel).vir_height;
          (ebc->info).height = uVar4;
          uVar15 = (ebc->panel).vir_width;
          (ebc->info).width = uVar15;
          uVar5 = uVar4 * uVar15;
          (ebc->info).buf_align16 = (uint)((uVar15 & 0xf) == 0);
          (ebc->info).ebc_buf_real_size = uVar5 >> 1;
          (ebc->info).direct_buf_real_size = uVar5 >> 2;
          pdVar17 = ebc->dev;
          mem_region_np = (long)of_parse_phandle(pdVar17->of_node,"memory-region",0);
          if (mem_region_np == 0) {
            iVar8 = -0x13;
          }
          else {
            iVar8 = of_address_to_resource((device_node *)mem_region_np,0,&r);
            if (iVar8 == 0) {
              (ebc->info).ebc_buffer_phy = CONCAT44(r.start._4_4_,(uint)r.start);
              iVar8 = ((int)r.end + 1) - (uint)r.start;
              (ebc->info).ebc_buffer_size = iVar8;
              pcVar12 = (char *)devm_memremap(pdVar17,CONCAT44(r.start._4_4_,(uint)r.start),
                                              (long)iVar8,1);
              (ebc->info).ebc_buffer_vir = pcVar12;
              if ((pcVar12 != (char *)0x0) &&
                 (iVar8 = ebc_buf_init((ebc->info).ebc_buffer_phy,pcVar12,
                                       (ebc->info).ebc_buffer_size,0x200000,4), iVar8 == 0)) {
                pcVar12 = (ebc->info).ebc_buffer_vir;
                (ebc->panel).fb[0].size = (size_t)get_auto_image;
                (ebc->panel).fb[0].virt_addr = pcVar12 + 0xa00000;
                uVar14 = (ebc->info).ebc_buffer_phy;
                (ebc->panel).fb[0].phy_addr = uVar14 + 0xa00000;
                (ebc->info).direct_buffer[0] = pcVar12 + 0xa00000;
                (ebc->panel).fb[1].size = (size_t)get_auto_image;
                (ebc->panel).fb[1].virt_addr = pcVar12 + 0xb00000;
                (ebc->panel).fb[1].phy_addr = uVar14 + 0xb00000;
                (ebc->info).lut_data.wf_table = (u8 *)(pcVar12 + 0xc00000);
                iVar8 = (ebc->info).ebc_buf_real_size;
                (ebc->info).direct_buffer[1] = pcVar12 + 0xb00000;
                piVar13 = (int *)devm_kmalloc(pdVar17,(long)iVar8,0x6080c0);
                (ebc->info).auto_image_new = piVar13;
                if (piVar13 != (int *)0x0) {
                  piVar13 = (int *)devm_kmalloc(pdVar17,(long)(ebc->info).ebc_buf_real_size,0x6080c0
                                               );
                  (ebc->info).auto_image_old = piVar13;
                  if (piVar13 != (int *)0x0) {
                    piVar13 = (int *)devm_kmalloc(pdVar17,(long)(ebc->info).ebc_buf_real_size,
                                                  0x6080c0);
                    (ebc->info).auto_image_bg = piVar13;
                    if (piVar13 != (int *)0x0) {
                      __s = (u8 *)devm_kmalloc(pdVar17,(ulong)((ebc->panel).vir_width *
                                                              (ebc->panel).vir_height),0x6080c0);
                      (ebc->info).auto_frame_count = __s;
                      if (__s != (u8 *)0x0) {
                        memset(__s,0,(ulong)((ebc->panel).vir_width * (ebc->panel).vir_height));
                        memset((ebc->info).auto_image_bg,0xff,(long)(ebc->info).ebc_buf_real_size);
                        pdVar17 = (ebc->info).dev;
                        wf_region_np = of_parse_phandle(pdVar17->of_node,"waveform-region",0);
                        if (wf_region_np == (device_node *)0x0) {
                          iVar8 = -0x13;
                        }
                        else {
                          iVar8 = of_address_to_resource(wf_region_np,0,&r);
                          if (iVar8 == 0) {
                            iVar16 = ((int)r.end + 1) - (uint)r.start;
                            pcVar12 = (char *)devm_memremap(pdVar17,CONCAT44(r.start._4_4_,
                                                                             (uint)r.start),
                                                            (long)iVar16,1);
                            (ebc->info).lut_ddr_vir = pcVar12;
                            if (pcVar12 != (char *)0x0) {
                              iVar9 = epd_lut_from_mem_init(pcVar12);
                              if (iVar9 < 0) {
                                _dev_err((ebc->info).dev,
                                         "Failed to read waveform from mem, we use waveform file from kernel file instead\n"
                                        );
                                iVar16 = epd_lut_from_file_init
                                                   ((ebc->info).dev,(ebc->info).lut_ddr_vir,iVar16);
                                if (iVar16 < 0) {
                                  iVar8 = -1;
                                  _dev_err((ebc->info).dev,
                                           "Failed to read waveform file from kernel, no waveform!!!\n"
                                          );
                                  goto LAB_00102a78;
                                }
                              }
                              plVar1 = &(ebc->info).auto_buffer_work.entry;
                              (ebc->info).auto_buffer_work.data.counter = 0xfffffffe0;
                              (ebc->info).auto_buffer_work.entry.next = plVar1;
                              (ebc->info).auto_buffer_work.entry.prev = plVar1;
                              (ebc->info).auto_buffer_work.func = new_buffer_refresh;
                              r.start._0_4_ = 99;
                              ebc_auto_task =
                                   (undefined *)
                                   kthread_create_on_node
                                             (ebc_auto_tast_function,&ebc->info,-1,"ebc_task");
                              if (ebc_auto_task < (task_struct *)0xfffffffffffff001) {
                                sched_setscheduler_nocheck(ebc_auto_task,1,&r);
                                __ll_sc_atomic_add(1,ebc_auto_task + 0x30);
                                r.start._0_4_ = 99;
                                ebc_task = kthread_create_on_node
                                                     (ebc_thread,&ebc->info,-1,"ebc_thread");
                                if (ebc_task < (task_struct *)0xfffffffffffff001) {
                                  wake_up_process(ebc_task);
                                  (ebc->info).ebc_task = (undefined *)ebc_task;
                                  sched_setscheduler_nocheck(ebc_task,1,&r);
                                  __ll_sc_atomic_add(1,(ebc->info).ebc_task + 0x30);
                                  (ebc->info).full_mode_num = -1;
                                  ws = &(ebc->info).suspend_lock;
                                  (ebc->info).is_busy_now = 0;
                                  (ebc->info).ebc_dsp_buf_status = 0;
                                  (ebc->info).ebc_power_status = 0;
                                  (ebc->info).is_early_suspend = 0;
                                  ptVar2 = &(ebc->info).vdd_timer;
                                  (ebc->info).is_deep_sleep = 0;
                                  (ws->ws).name = (char *)0x0;
                                  *(undefined8 *)&(ebc->info).suspend_lock.ws.id = 0;
                                  (ebc->info).suspend_lock.ws.entry.next = (list_head *)0x0;
                                  (ebc->info).suspend_lock.ws.entry.prev = (list_head *)0x0;
                                  *(undefined8 *)&(ebc->info).suspend_lock.ws.lock = 0;
                                  (ebc->info).suspend_lock.ws.wakeirq = (wake_irq *)0x0;
                                  (ebc->info).suspend_lock.ws.timer.entry.next = (hlist_node *)0x0;
                                  (ebc->info).suspend_lock.ws.timer.entry.pprev = (hlist_node **)0x0
                                  ;
                                  (ebc->info).suspend_lock.ws.timer.expires = 0;
                                  (ebc->info).suspend_lock.ws.timer.function =
                                       (anon_subr_void_timer_list_ptr_for_function *)0x0;
                                  *(undefined8 *)&(ebc->info).suspend_lock.ws.timer.flags = 0;
                                  (ebc->info).suspend_lock.ws.timer.android_kabi_reserved1 = 0;
                                  (ebc->info).suspend_lock.ws.timer.android_kabi_reserved2 = 0;
                                  (ebc->info).suspend_lock.ws.timer_expires = 0;
                                  (ebc->info).suspend_lock.ws.total_time = 0;
                                  (ebc->info).suspend_lock.ws.max_time = 0;
                                  (ebc->info).suspend_lock.ws.last_time = 0;
                                  (ebc->info).suspend_lock.ws.start_prevent_time = 0;
                                  (ebc->info).suspend_lock.ws.prevent_sleep_time = 0;
                                  (ebc->info).suspend_lock.ws.event_count = 0;
                                  (ebc->info).suspend_lock.ws.active_count = 0;
                                  (ebc->info).suspend_lock.ws.relax_count = 0;
                                  (ebc->info).suspend_lock.ws.expire_count = 0;
                                  (ebc->info).suspend_lock.ws.wakeup_count = 0;
                                  (ebc->info).suspend_lock.ws.dev = (device *)0x0;
                                  *(undefined8 *)&(ebc->info).suspend_lock.ws.field_0xc8 = 0;
                                  (ebc->info).suspend_lock.ws.name = "ebc";
                                  wakeup_source_add(&ws->ws);
                                  (ebc->info).wake_lock_is_set = 0;
                                  init_timer_key(ptVar2,ebc_vdd_power_timeout,0,0,0);
                                  ptVar3 = &(ebc->info).frame_timer;
                                  mod_timer(ptVar2,jiffies + 0xfffffff);
                                  init_timer_key(ptVar3,ebc_frame_timeout,0,0,0);
                                  mod_timer(ptVar3,jiffies + 0xfffffff);
                                  pcVar12 = saved_command_line;
                                  local_6c = 0;
                                  r.start._0_4_ = 0;
                                  __s_00 = strstr(saved_command_line,"ulogo_addr=");
                                  pcVar12 = strstr(pcVar12,"klogo_addr=");
                                  if ((__s_00 == (char *)0x0) ||
                                     (sscanf(__s_00,"ulogo_addr=0x%x",&local_6c),
                                     (ulong)local_6c < (ebc->info).ebc_buffer_phy)) {
                                    bVar6 = false;
                                    __dest_00 = (void *)0x0;
                                    __dest = (void *)0x0;
                                    if (pcVar12 != (char *)0x0) {
LAB_00102d30:
                                      sscanf(pcVar12,"klogo_addr=0x%x",&r);
                                      pcVar12 = (char *)0x0;
                                      __dest = (void *)0x0;
                                      if ((ebc->info).ebc_buffer_phy <= (ulong)(uint)r.start) {
                                        _dev_info((ebc->info).dev,
                                                  "need show klogo, klogo addr = 0x%x\n");
                                        __dest = __kmalloc((ulong)((ebc->panel).vir_width *
                                                                   (ebc->panel).vir_height >> 1),
                                                           0x6080c0);
                                        if (__dest == (void *)0x0) {
                                          _dev_err((ebc->info).dev,"malloc klogo buffer failed\n");
                                          goto LAB_00102de4;
                                        }
                                        pcVar12 = (char *)0x1;
                                        memcpy(__dest,(ebc->info).ebc_buffer_vir +
                                                      ((ulong)(uint)r.start -
                                                      (ebc->info).ebc_buffer_phy),
                                               (ulong)((ebc->panel).vir_width *
                                                       (ebc->panel).vir_height >> 1));
                                      }
                                      iVar16 = (int)pcVar12;
                                      if (bVar6) goto LAB_00102ee0;
                                    }
                                    iVar16 = (int)pcVar12;
                                    _dev_info((ebc->info).dev,"no uboot logo, panel init\n");
                                    ebc_pmic_verity_vcom(ebc->pmic);
                                    buf = ebc_empty_buf_get();
                                    memset(buf->virt_addr,0xff,
                                           (ulong)((ebc->panel).vir_width * (ebc->panel).vir_height
                                                  >> 1));
                                    buf->win_x1 = 0;
                                    buf->win_y1 = 0;
                                    buf->buf_mode = EPD_RESET;
                                    buf->win_x2 = (ebc->panel).vir_width;
                                    buf->win_y2 = (ebc->panel).vir_height;
                                    ebc_add_to_dsp_buf_list(buf);
LAB_00102dbc:
                                    if ((iVar16 != 0) &&
                                       (buf = ebc_empty_buf_get(), buf != (ebc_buf_s *)0x0)) {
                                      memcpy(buf->virt_addr,__dest,
                                             (ulong)((ebc->panel).vir_width *
                                                     (ebc->panel).vir_height >> 1));
                                      buf->win_x1 = 0;
                                      buf->win_y1 = 0;
                                      buf->buf_mode = EPD_PART_GC16;
                                      buf->win_x2 = (ebc->panel).vir_width;
                                      buf->win_y2 = (ebc->panel).vir_height;
                                      ebc_add_to_dsp_buf_list(buf);
                                    }
                                    if ((ebc->info).ebc_dsp_buf_status == 0) {
                                      (ebc->info).ebc_dsp_buf_status = 1;
                                      __wake_up_sync(&ebc_thread_wq,1);
                                    }
                                    if (__dest_00 != (void *)0x0) {
                                      kfree(__dest_00);
                                    }
                                    if (__dest != (void *)0x0) {
                                      kfree(__dest);
                                    }
                                  }
                                  else {
                                    _dev_info((ebc->info).dev,
                                              "have ulogo display, ulogo addr = 0x%x\n");
                                    __dest_00 = __kmalloc((ulong)((ebc->panel).vir_width *
                                                                  (ebc->panel).vir_height >> 1),
                                                          0x6080c0);
                                    if (__dest_00 != (void *)0x0) {
                                      memcpy(__dest_00,
                                             (ebc->info).ebc_buffer_vir +
                                             ((ulong)local_6c - (ebc->info).ebc_buffer_phy),
                                             (ulong)((ebc->panel).vir_width *
                                                     (ebc->panel).vir_height >> 1));
                                      if (pcVar12 != (char *)0x0) {
                                        bVar6 = true;
                                        goto LAB_00102d30;
                                      }
                                      iVar16 = 0;
                                      __dest = (void *)0x0;
LAB_00102ee0:
                                      buf = ebc_empty_buf_get();
                                      if (buf != (ebc_buf_s *)0x0) {
                                        memcpy(buf->virt_addr,__dest_00,
                                               (ulong)((ebc->panel).vir_width *
                                                       (ebc->panel).vir_height >> 1));
                                        buf->win_x1 = 0;
                                        buf->win_y1 = 0;
                                        buf->buf_mode = EPD_PART_GC16;
                                        buf->win_x2 = (ebc->panel).vir_width;
                                        buf->win_y2 = (ebc->panel).vir_height;
                                        ebc_add_to_dsp_buf_list(buf);
                                      }
                                      goto LAB_00102dbc;
                                    }
                                    _dev_err((ebc->info).dev,"malloc ulogo buffer failed\n");
                                  }
LAB_00102de4:
                                  (pdev->dev).driver_data = ebc;
                                  misc_register(&ebc_misc);
                                  device_create_file((ebc->info).dev,&dev_attr_waveform_version);
                                  device_create_file((ebc->info).dev,&dev_attr_pmic_name);
                                  device_create_file((ebc->info).dev,&dev_attr_pmic_temp);
                                  device_create_file((ebc->info).dev,&dev_attr_pmic_vcom);
                                  device_create_file((ebc->info).dev,&dev_attr_ebc_version);
                                  device_create_file((ebc->info).dev,&dev_attr_ebc_state);
                                  device_create_file((ebc->info).dev,&dev_attr_ebc_buf_state);
                                  _dev_info((ebc->info).dev,"rockchip ebc driver %s probe success\n"
                                            ,&DAT_00104868);
                                  goto LAB_001025d0;
                                }
                                (ebc->info).ebc_task = (undefined *)ebc_task;
                                _dev_err((ebc->info).dev,"failed to run ebc thread\n");
                              }
                              else {
                                _dev_err((ebc->info).dev,"failed to create ebc_task thread\n");
                              }
                              iVar8 = -1;
                              _dev_err(dev,"task init failed\n");
                              goto LAB_001025d0;
                            }
                            iVar8 = -0xc;
                            _dev_err((ebc->info).dev,"%s:%d: failed to get mem from reserved\n",
                                     "ebc_lut_table_init",0x83c);
                          }
                        }
LAB_00102a78:
                        _dev_err(dev,"lut table init failed\n");
                        goto LAB_001025d0;
                      }
                    }
                  }
                }
              }
              iVar8 = -0xc;
            }
            else {
              _dev_err(pdVar17,"Couldn\'t address to resource for reserved memory\n");
            }
          }
          _dev_err(dev,"buffer manage init failed\n");
          goto LAB_001025d0;
        }
      }
      else {
        do {
          uVar5 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
          lVar11 = of_find_node_by_phandle(uVar5 >> 0x10 | uVar5 << 0x10);
          if (lVar11 == 0) {
            iVar8 = -0x13;
            _dev_err(dev,"not find pmic node\n");
            goto LAB_001025d0;
          }
          lVar11 = of_find_i2c_device_by_node();
          if (lVar11 == 0) {
            iVar8 = -0x13;
            _dev_err(dev,"not find pmic i2c client\n");
            goto LAB_001025d0;
          }
          pmic = *(ebc_pmic **)(lVar11 + 0xd8);
          ebc->pmic = pmic;
          if (pmic != (ebc_pmic *)0x0) {
            _dev_info(dev,"use pmic%d\n",(ulong)uVar15);
            goto LAB_0010261c;
          }
          uVar15 = uVar15 + 1;
          puVar10 = puVar10 + 1;
        } while ((int)uVar15 < local_70);
      }
      iVar8 = -0x205;
      _dev_err(dev,"get drvdata from pmic client failed\n");
      goto LAB_001025d0;
    }
  }
  iVar8 = -0x205;
LAB_001025d0:
  if (lVar7 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar8;
}



int ebc_power_set(ebc *ebc,int power_status)

{
  if ((ebc->info).wake_lock_is_set == 0) {
    (ebc->info).wake_lock_is_set = 1;
    __pm_stay_awake(&(ebc->info).suspend_lock,power_status);
  }
  (ebc->info).ebc_power_status = 1;
  (*ebc->pmic->pmic_power_req)(ebc->pmic,true);
  (*ebc->tcon->enable)(ebc->tcon,&ebc->panel);
  _dev_info(ebc->dev,"ebc hw power on\n");
  return 0;
}



void refresh_new_image2(u32 *image_new,u32 *image_fb,u32 *image_bg,u64 *frame_count,
                       ebc_info *ebc_info,int buf_mode)

{
  ulong frame_count_mask;
  long column;
  uint update_mask;
  uint image_new_dword;
  int row;
  int height;
  uint image_fb_dword;
  long stride;
  int width;
  int width_8px;
  
  height = ebc_info->height;
  width = ebc_info->width;
  width_8px = width + 7;
  if (-1 < width) {
    width_8px = width;
  }
  width_8px = width_8px >> 3;
  if (0 < height) {
    row = 0;
    stride = (ulong)(width_8px - 1) + 1;
    do {
      column = 0;
      if (0 < width_8px) {
        do {
          while( true ) {
            frame_count_mask = frame_count[column];
            update_mask = 0;
            image_fb_dword = image_fb[column];
            image_new_dword = image_new[column];
            if (((frame_count_mask & 0xff) == 0) &&
               (update_mask = 0xf, (image_fb_dword & 0xf) == 0xe)) {
              image_new_dword = image_new_dword | 0xf;
              update_mask = 0;
            }
            if ((frame_count_mask & 0xff00) == 0) {
              if ((image_fb_dword & 0xf0) == 0xe0) {
                image_new_dword = image_new_dword | 0xf0;
              }
              else {
                update_mask = update_mask | 0xf0;
              }
            }
            if ((frame_count_mask & 0xff0000) == 0) {
              if ((image_fb_dword & 0xf00) == 0xe00) {
                image_new_dword = image_new_dword | 0xf00;
              }
              else {
                update_mask = update_mask | 0xf00;
              }
            }
            if ((frame_count_mask & 0xff000000) == 0) {
              if ((image_fb_dword & 0xf000) == 0xe000) {
                image_new_dword = image_new_dword | 0xf000;
              }
              else {
                update_mask = update_mask | 0xf000;
              }
            }
            if ((frame_count_mask & 0xff00000000) == 0) {
              if ((image_fb_dword & 0xf0000) == 0xe0000) {
                image_new_dword = image_new_dword | 0xf0000;
              }
              else {
                update_mask = update_mask | 0xf0000;
              }
            }
            if ((frame_count_mask & 0xff0000000000) == 0) {
              if ((image_fb_dword & 0xf00000) == 0xe00000) {
                image_new_dword = image_new_dword | 0xf00000;
              }
              else {
                update_mask = update_mask | 0xf00000;
              }
            }
            if ((frame_count_mask & 0xff000000000000) == 0) {
              if ((image_fb_dword & 0xf000000) == 0xe000000) {
                image_new_dword = image_new_dword | 0xf000000;
              }
              else {
                update_mask = update_mask | 0xf000000;
              }
            }
            if ((frame_count_mask & 0xff00000000000000) == 0) break;
LAB_00103280:
            image_new[column] =
                 image_new_dword ^
                 (image_fb_dword & image_bg[column] ^ image_new_dword) & update_mask;
            column = column + 1;
            if (width_8px <= (int)column) goto LAB_00103304;
          }
          if ((image_fb_dword & 0xf0000000) != 0xe0000000) {
            update_mask = update_mask | 0xf0000000;
            goto LAB_00103280;
          }
          image_new[column] =
               (image_new_dword | 0xf0000000) ^
               (image_fb_dword & image_bg[column] ^ (image_new_dword | 0xf0000000)) & update_mask;
          column = column + 1;
        } while ((int)column < width_8px);
LAB_00103304:
        frame_count = frame_count + stride;
        image_fb = image_fb + stride;
        image_bg = image_bg + stride;
        image_new = image_new + stride;
      }
      row = row + 1;
    } while (height != row);
  }
  return;
}



void refresh_new_image_auto(u32 *image_new,u32 *image_fb,u64 *frame_count,ebc_info *ebc_info)

{
  ulong frame_count_mask;
  long column;
  int row;
  int height;
  long stride;
  uint update_mask;
  uint update_mask2;
  int width;
  int width_8px;
  
  height = ebc_info->height;
  width = ebc_info->width;
  width_8px = width + 7;
  if (-1 < width) {
    width_8px = width;
  }
  width_8px = width_8px >> 3;
  if (0 < height) {
    row = 0;
    stride = (ulong)(width_8px - 1) + 1;
    do {
      column = 0;
      if (0 < width_8px) {
        do {
          frame_count_mask = frame_count[column];
          update_mask2 = 0;
          if ((frame_count_mask & 0xff) == 0) {
            update_mask2 = 0xf;
          }
          update_mask = update_mask2 | 0xf0;
          if ((frame_count_mask & 0xff00) != 0) {
            update_mask = update_mask2;
          }
          update_mask2 = update_mask | 0xf00;
          if ((frame_count_mask & 0xff0000) != 0) {
            update_mask2 = update_mask;
          }
          update_mask = update_mask2 | 0xf000;
          if ((frame_count_mask & 0xff000000) != 0) {
            update_mask = update_mask2;
          }
          update_mask2 = update_mask | 0xf0000;
          if ((frame_count_mask & 0xff00000000) != 0) {
            update_mask2 = update_mask;
          }
          update_mask = update_mask2 | 0xf00000;
          if ((frame_count_mask & 0xff0000000000) != 0) {
            update_mask = update_mask2;
          }
          update_mask2 = update_mask | 0xf000000;
          if ((frame_count_mask & 0xff000000000000) != 0) {
            update_mask2 = update_mask;
          }
          update_mask = update_mask2 | 0xf0000000;
          if ((frame_count_mask & 0xff00000000000000) != 0) {
            update_mask = update_mask2;
          }
          image_new[column] =
               (image_fb[column] ^ image_new[column]) & update_mask ^ image_new[column];
          column = column + 1;
        } while ((int)column < width_8px);
        frame_count = frame_count + stride;
        image_fb = image_fb + stride;
        image_new = image_new + stride;
      }
      row = row + 1;
    } while (height != row);
  }
  return;
}



void new_buffer_refresh(work_struct *work)

{
  ebc_buf_s *curr_dsp_buf;
  ebc *ebc;
  
  ebc = global_ebc;
  down_write(&auto_buf_sema);
  curr_dsp_buf = (ebc->info).curr_dsp_buf;
  if (curr_dsp_buf->buf_mode != EPD_AUTO) {
    refresh_new_image2((u32 *)(ebc->info).auto_image_new,(u32 *)curr_dsp_buf->virt_addr,
                       (u32 *)(ebc->info).auto_image_bg,(u64 *)(ebc->info).auto_frame_count,
                       &ebc->info,curr_dsp_buf->buf_mode);
    up_write(&auto_buf_sema);
    return;
  }
  refresh_new_image_auto
            ((u32 *)(ebc->info).auto_image_new,(u32 *)curr_dsp_buf->virt_addr,
             (u64 *)(ebc->info).auto_frame_count,&ebc->info);
  up_write(&auto_buf_sema);
  return;
}



int ebc_thread(void *ptr)

{
  long *plVar1;
  long *plVar2;
  ebc_info *ebc_info;
  timer_list *ptVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ebc *ebc;
  long lVar10;
  int iVar11;
  ebc_buf_s *next_ebc_buf;
  long lVar12;
  device *dev;
  long lVar13;
  uint uVar14;
  char *pcVar15;
  u32 *image_fb;
  ulong uVar16;
  uint uVar17;
  int iVar18;
  char **ppcVar19;
  bool bVar20;
  int *piVar21;
  u8 *puVar22;
  int *piVar23;
  uint uVar24;
  int iVar25;
  wait_queue_entry __wq_entry;
  ebc_buf_s new_prev_buf;
  panel_refresh_mode buf_mode;
  ebc_buf_s *prev_ebc_buf;
  
  lVar10 = __stack_chk_guard;
  ebc = global_ebc;
  ebc_info = &global_ebc->info;
  iVar25 = 0;
LAB_00103514:
  iVar11 = (ebc->info).is_power_off;
  do {
    if (iVar11 != 0) {
      if ((ebc->info).ebc_power_status == 1) {
        ebc_power_set(ebc,0);
      }
      if (lVar10 == __stack_chk_guard) {
        return 0;
      }
                    // WARNING: Subroutine does not return
      __stack_chk_fail();
    }
    next_ebc_buf = ebc_dsp_buf_get();
    if ((next_ebc_buf == (ebc_buf_s *)0x0) || (next_ebc_buf->phy_addr == 0)) {
      if ((ebc->info).is_busy_now != 1) {
        iVar11 = (ebc->info).ebc_power_status;
        goto joined_r0x00103984;
      }
      if ((ebc->info).ebc_dsp_buf_status != 0) goto __out;
      init_wait_entry(&__wq_entry,0);
      break;
    }
    buf_mode = next_ebc_buf->buf_mode;
    if (buf_mode == EPD_POWER_OFF) {
      (ebc->info).overlay_enable = 0;
      (ebc->info).overlay_start = 0;
    }
    else if (*(long *)&(ebc->info).is_early_suspend == 0) {
      if (buf_mode == EPD_SUSPEND || buf_mode == EPD_FORCE_FULL) {
        (ebc->info).overlay_start = 0;
      }
      else if ((ebc->info).overlay_start != 0 && buf_mode != EPD_OVERLAY) {
        down_write(&auto_buf_sema);
        memcpy((ebc->info).auto_image_bg,next_ebc_buf->virt_addr,(long)(ebc->info).ebc_buf_real_size
              );
        ebc_remove_from_dsp_buf_list(next_ebc_buf);
        ebc_buf_release(next_ebc_buf);
        next_ebc_buf = (ebc->info).curr_dsp_buf;
        refresh_new_image2((u32 *)(ebc->info).auto_image_new,(u32 *)next_ebc_buf->virt_addr,
                           (u32 *)(ebc->info).auto_image_bg,(u64 *)(ebc->info).auto_frame_count,
                           ebc_info,next_ebc_buf->buf_mode);
        up_write(&auto_buf_sema);
        if ((ebc->info).is_busy_now == 0) {
          (ebc->info).ebc_irq_status = 0;
          (ebc->info).is_busy_now = 1;
          if ((ebc->info).ebc_power_status == 0) {
            ebc_power_set(ebc,1);
          }
          _dev_info((ebc->info).dev,"overlay mode start, update background, frame_total=%d\n",
                    (ulong)(byte)(ebc->info).frame_total);
          ebc_frame_start(ebc);
        }
        goto LAB_00103514;
      }
    }
    else if (buf_mode == EPD_RESUME) {
      (ebc->info).is_early_suspend = 0;
      ebc_notify(3);
      _dev_info((ebc->info).dev,"early resume\n");
    }
    else {
      if ((buf_mode & 0x12) == 0) goto LAB_00103760;
      _dev_info((ebc->info).dev,"refresh suspend logo\n");
    }
    pcVar15 = (char *)(jiffies + 0x18000000);
    mod_timer(&(ebc->info).vdd_timer);
    if ((ebc->info).first_in == 0) {
      (ebc->info).prev_dsp_buf = next_ebc_buf;
      prev_ebc_buf = next_ebc_buf;
    }
    else {
      prev_ebc_buf = (ebc->info).prev_dsp_buf;
    }
    buf_mode = prev_ebc_buf->buf_mode;
    if (next_ebc_buf->buf_mode != buf_mode) {
      pcVar15 = "change display mode from %d to %d\n";
      _dev_info((ebc->info).dev,"change display mode from %d to %d\n");
      if ((ebc->info).is_busy_now == 1) {
        _dev_info((ebc->info).dev,"ebc is busy now, waiting prev refresh mode end...\n");
        if ((ebc->info).ebc_irq_status == 0) {
          init_wait_entry(&__wq_entry,0);
          while (lVar13 = prepare_to_wait_event(&ebc_wq,&__wq_entry,1),
                (ebc->info).ebc_irq_status == 0) {
            if (lVar13 != 0) goto __out;
            schedule();
          }
          finish_wait(&ebc_wq,&__wq_entry);
        }
__out:
        pcVar15 = "prev refresh mode end\n";
        _dev_info((ebc->info).dev,"prev refresh mode end\n");
      }
      buf_mode = next_ebc_buf->buf_mode;
    }
    if ((int)buf_mode < 0xc) {
      if (6 < (int)buf_mode) {
LAB_00103898:
        prev_ebc_buf = (ebc->info).prev_dsp_buf;
        bVar20 = false;
        buf_mode = prev_ebc_buf->buf_mode;
        goto joined_r0x001038a8;
      }
      if (buf_mode == EPD_OVERLAY) {
        if ((ebc->info).overlay_enable == 0) {
          _dev_info((ebc->info).dev,"overlay disabled, drop EPD_OVERLAY frame\n");
          ebc_remove_from_dsp_buf_list(next_ebc_buf);
          ebc_buf_release(next_ebc_buf);
          goto LAB_00103514;
        }
        prev_ebc_buf = (ebc->info).prev_dsp_buf;
        (ebc->info).curr_dsp_buf = next_ebc_buf;
        (ebc->info).overlay_start = 1;
        buf_mode = prev_ebc_buf->buf_mode;
        if (buf_mode < EPD_FULL_GC16) {
          prev_ebc_buf = next_ebc_buf;
          if (buf_mode == EPD_AUTO) {
            memcpy((ebc->info).auto_image_bg,(ebc->info).auto_image_old,
                   (long)(ebc->info).ebc_buf_real_size);
            prev_ebc_buf = (ebc->info).curr_dsp_buf;
          }
        }
        else {
          memcpy((ebc->info).auto_image_new,prev_ebc_buf->virt_addr,
                 (long)(ebc->info).ebc_buf_real_size);
          memcpy((ebc->info).auto_image_old,((ebc->info).prev_dsp_buf)->virt_addr,
                 (long)(ebc->info).ebc_buf_real_size);
          memcpy((ebc->info).auto_image_bg,((ebc->info).prev_dsp_buf)->virt_addr,
                 (long)(ebc->info).ebc_buf_real_size);
          prev_ebc_buf = (ebc->info).curr_dsp_buf;
        }
        iVar4 = prev_ebc_buf->win_x1;
        iVar11 = prev_ebc_buf->win_y1;
        iVar5 = prev_ebc_buf->win_x2;
        iVar7 = (ebc->info).width;
        iVar6 = iVar4 + 7;
        if (-1 < iVar4) {
          iVar6 = iVar4;
        }
        iVar4 = iVar5 + 7;
        if (-1 < iVar5) {
          iVar4 = iVar5;
        }
        iVar5 = iVar7 + 7;
        if (-1 < iVar7) {
          iVar5 = iVar7;
        }
        iVar5 = iVar5 >> 3;
        iVar4 = (iVar4 >> 3) + 1;
        iVar18 = (ebc->info).height;
        pcVar15 = prev_ebc_buf->virt_addr;
        iVar7 = iVar5 + -1;
        if (iVar4 < iVar5) {
          iVar7 = iVar4;
        }
        uVar14 = iVar18 - 1;
        uVar17 = uVar14;
        if (prev_ebc_buf->win_y2 < iVar18) {
          uVar17 = prev_ebc_buf->win_y2;
        }
        iVar4 = iVar11 * iVar5;
        piVar21 = (ebc->info).auto_image_new;
        piVar23 = (ebc->info).auto_image_bg;
        puVar22 = (ebc->info).auto_frame_count;
        for (; iVar18 = iVar6 >> 3, iVar11 <= (int)uVar17; iVar11 = iVar11 + 1) {
joined_r0x00103ae4:
          if (iVar18 <= iVar7) {
            do {
              lVar12 = (long)iVar18;
              uVar24 = 0;
              lVar13 = (long)iVar4;
              uVar16 = *(ulong *)(puVar22 + lVar12 * 8 + (long)iVar4 * 8);
              uVar14 = piVar21[lVar13 + lVar12];
              uVar8 = *(uint *)(pcVar15 + lVar12 * 4 + lVar13 * 4);
              uVar9 = piVar23[lVar13 + lVar12];
              if (((uVar16 & 0xff) == 0) && (uVar24 = 0xf, (uVar8 & 0xf) == 0xe)) {
                uVar14 = uVar14 | 0xf;
                uVar24 = 0;
              }
              if ((uVar16 & 0xff00) == 0) {
                if ((uVar8 & 0xf0) == 0xe0) {
                  uVar14 = uVar14 | 0xf0;
                }
                else {
                  uVar24 = uVar24 | 0xf0;
                }
              }
              if ((uVar16 & 0xff0000) == 0) {
                if ((uVar8 & 0xf00) == 0xe00) {
                  uVar14 = uVar14 | 0xf00;
                }
                else {
                  uVar24 = uVar24 | 0xf00;
                }
              }
              if ((uVar16 & 0xff000000) == 0) {
                if ((uVar8 & 0xf000) == 0xe000) {
                  uVar14 = uVar14 | 0xf000;
                }
                else {
                  uVar24 = uVar24 | 0xf000;
                }
              }
              if ((uVar16 & 0xff00000000) == 0) {
                if ((uVar8 & 0xf0000) == 0xe0000) {
                  uVar14 = uVar14 | 0xf0000;
                }
                else {
                  uVar24 = uVar24 | 0xf0000;
                }
              }
              if ((uVar16 & 0xff0000000000) == 0) {
                if ((uVar8 & 0xf00000) == 0xe00000) {
                  uVar14 = uVar14 | 0xf00000;
                }
                else {
                  uVar24 = uVar24 | 0xf00000;
                }
              }
              if ((uVar16 & 0xff000000000000) == 0) {
                if ((uVar8 & 0xf000000) == 0xe000000) {
                  uVar14 = uVar14 | 0xf000000;
                }
                else {
                  uVar24 = uVar24 | 0xf000000;
                }
              }
              if ((uVar16 & 0xff00000000000000) == 0) {
                if ((uVar8 & 0xf0000000) == 0xe0000000) goto LAB_00103d58;
                uVar24 = uVar24 | 0xf0000000;
              }
              iVar18 = iVar18 + 1;
              uVar14 = uVar14 ^ (uVar8 & uVar9 ^ uVar14) & uVar24;
              piVar21[lVar13 + lVar12] = uVar14;
              if (iVar7 < iVar18) break;
            } while( true );
          }
          iVar4 = iVar4 + iVar5;
        }
        if ((ebc->info).is_busy_now == 0) {
          (ebc->info).is_busy_now = 1;
          (ebc->info).ebc_irq_status = 0;
          if ((ebc->info).ebc_power_status == 0) {
            ebc_power_set(ebc,uVar14);
          }
          iVar11 = ebc_lut_update(ebc);
          if (iVar11 != -1) {
            uVar17 = (ebc->info).lut_data.frame_num;
            (ebc->info).frame_total = (char)uVar17;
            pcVar15 = "overlay mode start, frame_total=%d\n";
            dev = (ebc->info).dev;
            goto LAB_00103cc8;
          }
        }
      }
      else {
        if (1 < (int)buf_mode) goto LAB_00103790;
        if (buf_mode != EPD_AUTO) goto LAB_0010374c;
        down_write(&auto_buf_sema);
        (ebc->info).curr_dsp_buf = next_ebc_buf;
        if (((ebc->info).prev_dsp_buf)->buf_mode < EPD_FULL_GC16) {
          image_fb = (u32 *)next_ebc_buf->virt_addr;
          refresh_new_image_auto
                    ((u32 *)(ebc->info).auto_image_new,image_fb,(u64 *)(ebc->info).auto_frame_count,
                     ebc_info);
          iVar11 = (int)image_fb;
        }
        else {
          memcpy((ebc->info).auto_image_new,next_ebc_buf->virt_addr,
                 (long)(ebc->info).ebc_buf_real_size);
          pcVar15 = ((ebc->info).prev_dsp_buf)->virt_addr;
          memcpy((ebc->info).auto_image_old,pcVar15,(long)(ebc->info).ebc_buf_real_size);
          iVar11 = (int)pcVar15;
        }
        up_write(&auto_buf_sema);
        if ((ebc->info).is_busy_now == 0) {
          (ebc->info).is_busy_now = 1;
          (ebc->info).ebc_irq_status = 0;
          if ((ebc->info).ebc_power_status == 0) {
            ebc_power_set(ebc,iVar11);
            iVar11 = ebc_lut_update(ebc);
          }
          else {
            iVar11 = ebc_lut_update(ebc);
          }
          if (iVar11 == -1) {
            _dev_err((ebc->info).dev,"ebc_lut_update err\n");
          }
          else {
            dev = (ebc->info).dev;
            uVar17 = (ebc->info).lut_data.frame_num;
            pcVar15 = "auto mode start, frame_total=%d\n";
            (ebc->info).frame_total = (char)uVar17;
LAB_00103cc8:
            (ebc->info).frame_bw_total = (char)(uVar17 >> 8);
            _dev_info(dev,pcVar15,(ulong)(uVar17 & 0xff));
            ebc_frame_start(ebc);
          }
        }
      }
one_buffer_end:
      buf_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
      if (buf_mode != EPD_POWER_OFF) goto LAB_0010363c;
LAB_0010384c:
      (ebc->info).ebc_last_display = 0;
      (ebc->info).is_power_off = 1;
      _dev_info((ebc->info).dev,"power off\n");
      __wake_up_sync(&ebc_poweroff_wq,1,1);
      ebc_remove_from_dsp_buf_list(next_ebc_buf);
      if ((ebc->info).first_in != 0) goto LAB_00103888;
LAB_00103654:
      (ebc->info).first_in = 1;
    }
    else {
      if ((int)buf_mode < 0x10) {
        if (0xd < (int)buf_mode) goto LAB_00103898;
      }
      else if (0x15 < (int)buf_mode) goto LAB_0010374c;
LAB_00103790:
      prev_ebc_buf = (ebc->info).prev_dsp_buf;
      bVar20 = true;
      buf_mode = prev_ebc_buf->buf_mode;
joined_r0x001038a8:
      if (buf_mode < EPD_FULL_GC16) {
        (ebc->info).ebc_irq_status = 0;
        (ebc->info).prev_dsp_buf = &new_prev_buf;
        (ebc->info).curr_dsp_buf = next_ebc_buf;
        new_prev_buf.virt_addr = (char *)(ebc->info).auto_image_old;
        if (next_ebc_buf->buf_mode + ~EPD_OVERLAY < 0xf) goto LAB_001037bc;
LAB_001038d4:
        if (bVar20) {
          iVar11 = (ebc->info).ebc_power_status;
          iVar25 = 0;
        }
        else {
          iVar11 = (ebc->info).full_mode_num;
          if ((0 < iVar11) && (iVar25 = iVar25 + 1, iVar11 <= iVar25)) {
            iVar25 = 0;
            next_ebc_buf->buf_mode = EPD_FULL_GC16;
          }
          iVar11 = (ebc->info).ebc_power_status;
        }
        if (iVar11 == 0) {
          ebc_power_set(ebc,(int)pcVar15);
        }
        iVar11 = ebc_lut_update(ebc);
        if (iVar11 == 0) {
          uVar17 = (ebc->info).lut_data.frame_num;
          (ebc->info).frame_total = (char)uVar17;
          _dev_info((ebc->info).dev,"frame start, mode = %d, framecount = %d\n",
                    (ulong)((ebc->info).curr_dsp_buf)->buf_mode,(ulong)(uVar17 & 0xff));
          (ebc->info).is_busy_now = 1;
          ebc_frame_start(ebc);
          ptVar3 = &(ebc->info).frame_timer;
          mod_timer(ptVar3,jiffies + 900);
          if ((ebc->info).ebc_irq_status == 0) {
            init_wait_entry(&__wq_entry,0);
            while (lVar13 = prepare_to_wait_event(&ebc_wq,&__wq_entry,1),
                  (ebc->info).ebc_irq_status == 0) {
              if (lVar13 != 0) goto __out;
              schedule();
            }
            finish_wait(&ebc_wq,&__wq_entry);
          }
__out:
          mod_timer(ptVar3,jiffies + 0x18000000);
          (ebc->info).ebc_irq_status = 0;
          (ebc->info).prev_dsp_buf = prev_ebc_buf;
        }
        else {
          _dev_err((ebc->info).dev,"ebc_lut_update err\n");
          (ebc->info).prev_dsp_buf = prev_ebc_buf;
        }
        goto one_buffer_end;
      }
      (ebc->info).ebc_irq_status = 0;
      (ebc->info).curr_dsp_buf = next_ebc_buf;
      if (0xe < next_ebc_buf->buf_mode + ~EPD_OVERLAY) goto LAB_001038d4;
LAB_001037bc:
      iVar6 = (ebc->info).ebc_buf_real_size;
      ppcVar19 = (char **)((ebc->info).prev_dsp_buf)->virt_addr;
      iVar11 = iVar6 + 7;
      if (-1 < iVar6) {
        iVar11 = iVar6;
      }
      if (0 < iVar11 >> 3) {
        pcVar15 = *(char **)next_ebc_buf->virt_addr;
        if (*ppcVar19 == pcVar15) {
          pcVar15 = (char *)(((ulong)((iVar11 >> 3) - 1) + 1) * 8);
          lVar13 = 8;
          do {
            if ((long)pcVar15 - lVar13 == 0) goto LAB_00103828;
            plVar2 = (long *)((long)next_ebc_buf->virt_addr + lVar13);
            plVar1 = (long *)((long)ppcVar19 + lVar13);
            lVar13 = lVar13 + 8;
          } while (*plVar2 == *plVar1);
        }
        goto LAB_001038d4;
      }
LAB_00103828:
      _dev_info((ebc->info).dev,"check_part_mode==0, no need refresh\n");
      (ebc->info).prev_dsp_buf = prev_ebc_buf;
      buf_mode = ((ebc->info).curr_dsp_buf)->buf_mode;
      if (buf_mode == EPD_POWER_OFF) goto LAB_0010384c;
LAB_0010363c:
      if (buf_mode == EPD_SUSPEND) {
        (ebc->info).ebc_last_display = 0;
        (ebc->info).is_early_suspend = 1;
        (ebc->info).overlay_start = 0;
        _dev_info((ebc->info).dev,"early suspend\n");
        ebc_notify(2);
        __wake_up_sync(&ebc_poweroff_wq,1,1);
      }
      ebc_remove_from_dsp_buf_list(next_ebc_buf);
      if ((ebc->info).first_in == 0) goto LAB_00103654;
LAB_00103888:
      ebc_buf_release((ebc->info).prev_dsp_buf);
    }
    (ebc->info).prev_dsp_buf = (ebc->info).curr_dsp_buf;
    iVar11 = (ebc->info).is_power_off;
  } while( true );
LAB_00103950:
  lVar13 = prepare_to_wait_event(&ebc_thread_wq,&__wq_entry,1);
  if (((ebc->info).is_busy_now == 0) || ((ebc->info).ebc_dsp_buf_status != 0)) goto LAB_00103968;
  if (lVar13 != 0) goto LAB_001036c8;
  schedule();
  goto LAB_00103950;
LAB_00103968:
  finish_wait(&ebc_thread_wq,&__wq_entry);
  if ((ebc->info).is_busy_now == 0) {
    iVar11 = (ebc->info).ebc_power_status;
joined_r0x00103984:
    if (iVar11 == 1) {
      ebc_power_set(ebc,0);
    }
  }
LAB_001036c8:
  if ((ebc->info).ebc_dsp_buf_status == 0) {
    init_wait_entry(&__wq_entry,0);
    while (lVar13 = prepare_to_wait_event(&ebc_thread_wq,&__wq_entry,1),
          (ebc->info).ebc_dsp_buf_status == 0) {
      if (lVar13 != 0) goto __out;
      schedule();
    }
    finish_wait(&ebc_thread_wq,&__wq_entry);
    (ebc->info).ebc_dsp_buf_status = 0;
  }
  else {
__out:
    (ebc->info).ebc_dsp_buf_status = 0;
  }
  goto LAB_00103514;
LAB_00103d58:
  uVar14 = (uVar14 | 0xf0000000) ^ (uVar8 & uVar9 ^ (uVar14 | 0xf0000000)) & uVar24;
  piVar21[lVar13 + lVar12] = uVar14;
  iVar18 = iVar18 + 1;
  goto joined_r0x00103ae4;
LAB_0010374c:
  _dev_err((ebc->info).dev,"ebc buffer mode %d error!!!\n");
LAB_00103760:
  ebc_remove_from_dsp_buf_list(next_ebc_buf);
  ebc_buf_release(next_ebc_buf);
  goto LAB_00103514;
}



void ebc_exit(void)

{
  platform_driver_unregister(&ebc_driver);
  return;
}



int ebc_init(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&ebc_driver,0);
  return iVar1;
}



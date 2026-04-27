// Decompiled from 1000:915b (character_select)
// Function size: 4435 bytes


/* WARNING: Removing unreachable block (ram,0x0001a277) */
/* WARNING: Removing unreachable block (ram,0x0001a08b) */
/* WARNING: Removing unreachable block (ram,0x00019eab) */
/* WARNING: Removing unreachable block (ram,0x00019cdd) */
/* WARNING: Removing unreachable block (ram,0x00019afd) */
/* WARNING: Removing unreachable block (ram,0x0001991e) */
/* WARNING: Removing unreachable block (ram,0x00019732) */
/* WARNING: Removing unreachable block (ram,0x0001954e) */
/* WARNING: Removing unreachable block (ram,0x0001936e) */
/* WARNING: Removing unreachable block (ram,0x00019469) */
/* WARNING: Removing unreachable block (ram,0x00019637) */
/* WARNING: Removing unreachable block (ram,0x00019817) */
/* WARNING: Removing unreachable block (ram,0x00019a03) */
/* WARNING: Removing unreachable block (ram,0x00019be2) */
/* WARNING: Removing unreachable block (ram,0x00019dc2) */
/* WARNING: Removing unreachable block (ram,0x00019fa6) */
/* WARNING: Removing unreachable block (ram,0x0001a192) */
/* WARNING: Removing unreachable block (ram,0x0001926b) */
/* WARNING: Removing unreachable block (ram,0x0001a28b) */

void __cdecl16near FUN_1000_915b(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 extraout_AH;
  undefined2 uVar3;
  undefined2 unaff_DS;
  int local_6;
  
  FUN_219e_02ad();
  FUN_1b5b_0387();
  FUN_1000_9077(&stack0xfffe,1000);
  FUN_1b5b_0099(0x9131,0x1b5b);
  FUN_20e5_004f(CONCAT11(extraout_AH,1),0x913c,0x1b5b);
  do {
    FUN_1bfc_0000();
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    uVar3 = FUN_219e_0285();
    FUN_1000_90b3(&stack0xfffe,uVar3);
    FUN_1000_9077(&stack0xfffe,0x7d);
    FUN_2110_033e();
    FUN_1000_9077(&stack0xfffe,0xaf);
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x3f);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0x25);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 4) break;
      local_6 = local_6 + 1;
    }
    FUN_1000_9077(&stack0xfffe,0xaf);
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x7d);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0xaf);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 3) break;
      local_6 = local_6 + 1;
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x3f);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0x26);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 6) break;
      local_6 = local_6 + 1;
    }
    uVar3 = FUN_219e_0285();
    FUN_1000_90b3(&stack0xfffe,uVar3);
    FUN_1000_9077(&stack0xfffe,0x7d);
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    FUN_2110_033e();
    FUN_1000_9077(&stack0xfffe,0xaf);
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x3f);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0x26);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 4) break;
      local_6 = local_6 + 1;
    }
    FUN_1000_9077(&stack0xfffe,0xaf);
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8fbf(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_8ffd(&stack0xfffe);
    }
    cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
    if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
      FUN_1000_903b(&stack0xfffe);
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      uVar2 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar2;
      cVar1 = FUN_219e_0285();
      if ((cVar1 == 'F') || (cVar1 == 'f')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      else if ((cVar1 == 'T') || (cVar1 == 't')) {
        FUN_1000_903b(&stack0xfffe);
      }
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x7d);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0xaf);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 3) break;
      local_6 = local_6 + 1;
    }
    local_6 = 1;
    while( true ) {
      uVar3 = FUN_219e_0285();
      FUN_1000_90b3(&stack0xfffe,uVar3);
      FUN_1000_9077(&stack0xfffe,0x3f);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      FUN_2110_033e();
      FUN_1000_9077(&stack0xfffe,0x26);
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x78,0x3c,0x3c);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8fbf(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0xbe,0x3c,0x82);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_8ffd(&stack0xfffe);
      }
      cVar1 = FUN_1000_90dc(&stack0xfffe,0x8c,0x104,0x3c,200);
      if ((cVar1 != '\0') && (cVar1 = FUN_1bfc_0050(1), cVar1 != '\0')) {
        FUN_1000_903b(&stack0xfffe);
      }
      cVar1 = FUN_2110_0345();
      if (cVar1 != '\0') {
        FUN_2110_0357();
        uVar2 = FUN_219e_0285();
        *(undefined1 *)0x11c8 = uVar2;
        cVar1 = FUN_219e_0285();
        if ((cVar1 == 'F') || (cVar1 == 'f')) {
          FUN_1000_8fbf(&stack0xfffe);
        }
        else if ((cVar1 == 'M') || (cVar1 == 'm')) {
          FUN_1000_8ffd(&stack0xfffe);
        }
        else if ((cVar1 == 'T') || (cVar1 == 't')) {
          FUN_1000_903b(&stack0xfffe);
        }
      }
      if (local_6 == 6) break;
      local_6 = local_6 + 1;
    }
  } while( true );
}


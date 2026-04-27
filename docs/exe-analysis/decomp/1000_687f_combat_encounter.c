// Decompiled from 1000:687f (combat_encounter)
// Function size: 2289 bytes


void __cdecl16near FUN_1000_687f(void)

{
  char cVar1;
  undefined1 extraout_AH;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined2 in_BX;
  undefined2 unaff_DS;
  undefined1 uVar7;
  int local_b;
  int local_9;
  
  FUN_219e_02ad();
  FUN_20e5_004f(CONCAT11(extraout_AH,1),0x67f7,0x219e);
  if (*(char *)0x446 == '\0') {
    *(undefined2 *)0x11cb = 0x32;
  }
  if (*(char *)0x446 == '\0') {
    *(undefined2 *)0x11cd = 0x32;
  }
  if (*(char *)0x446 == '\0') {
    *(undefined1 *)0x445 = 4;
  }
  do {
    uVar2 = FUN_219e_0285();
    uVar3 = FUN_219e_0285(uVar2);
    uVar4 = FUN_219e_0285(uVar3);
    FUN_1000_4cbe(uVar4,uVar3,uVar2);
    uVar3 = 0;
    FUN_219e_0b73();
    uVar2 = FUN_219e_0b65();
    uVar7 = 1;
    FUN_219e_0b73(uVar2,in_BX,uVar3);
    FUN_219e_0b6f();
    if ((bool)uVar7) {
      uVar2 = FUN_219e_0285();
      *(undefined2 *)0x11d4 = uVar2;
    }
    cVar1 = FUN_2110_0345();
    if (cVar1 != '\0') {
      FUN_2110_0357();
      FUN_219e_0285();
      cVar1 = FUN_219e_0285();
      if (cVar1 == '\0') {
        FUN_2110_0357();
        iVar5 = FUN_219e_0285();
        if (iVar5 == 0x48) {
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11cd = uVar2;
          *(undefined1 *)0x445 = 3;
          FUN_219e_0285();
        }
        else if (iVar5 == 0x4b) {
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11cb = uVar2;
          *(undefined1 *)0x445 = 1;
          FUN_219e_0285();
        }
        else if (iVar5 == 0x4d) {
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11cb = uVar2;
          *(undefined1 *)0x445 = 2;
          FUN_219e_0285();
        }
        else if (iVar5 == 0x50) {
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11cd = uVar2;
          *(undefined1 *)0x445 = 4;
          FUN_219e_0285();
        }
        else if (iVar5 == 0x1f) {
          FUN_1000_080a();
        }
        else {
          if (iVar5 == 0x10) {
            FUN_20e5_015a();
            return;
          }
          if (iVar5 == 0x3b) {
            FUN_1000_5c46();
          }
          else if (iVar5 == 0x68) {
            FUN_1000_6165();
          }
        }
      }
      else if ((cVar1 == 'S') || (cVar1 == 's')) {
        FUN_1000_172b();
      }
      else if ((cVar1 == 'H') || (cVar1 == 'h')) {
        if (*(int *)0x11f8 < 1) {
          if (*(char *)0x42d == '\0') {
            FUN_2110_0311(0x1b8);
            FUN_2110_02e9(0xfa);
            FUN_2110_033e();
          }
          else {
            FUN_20e5_01e1(0x681c,0x219e);
          }
        }
        if (0 < *(int *)0x11f8) {
          *(int *)0x11f8 = *(int *)0x11f8 + -1;
          FUN_219e_0285();
          if (*(char *)0x42d == '\0') {
            local_b = 1;
            while( true ) {
              local_9 = 100;
              while( true ) {
                uVar2 = FUN_219e_0285();
                FUN_2110_0311(uVar2);
                FUN_2110_02e9(1);
                if (local_9 == 300) break;
                local_9 = local_9 + 1;
              }
              if (local_b == 6) break;
              local_b = local_b + 1;
            }
            FUN_2110_033e();
            local_b = 1;
            while( true ) {
              uVar2 = FUN_219e_0285();
              FUN_2110_0311(uVar2);
              FUN_2110_02e9(0x26);
              if (local_b == 0x32) break;
              local_b = local_b + 1;
            }
            FUN_2110_033e();
          }
          else {
            FUN_20e5_01e1(0x6827,0x219e);
          }
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11d4 = uVar2;
          if (0x17 < *(int *)0x11d4) {
            *(undefined2 *)0x11d4 = 0x18;
          }
        }
      }
      else if (cVar1 == '*') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11d4 = uVar2;
        FUN_2110_0311(0x1b8);
        FUN_2110_033e();
      }
      else if (cVar1 == '/') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11d4 = uVar2;
        FUN_2110_0311(0x1b8);
        FUN_2110_033e();
      }
      else if (cVar1 == '+') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11e2 = uVar2;
        FUN_2110_0311(0x1b8);
        FUN_2110_033e();
      }
      else if (cVar1 == '-') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11e4 = uVar2;
        FUN_2110_0311(0x1b8);
        FUN_2110_033e();
      }
      else if ((cVar1 == 'M') || (cVar1 == 'm')) {
        if ((*(int *)0x11fa < 1) || (*(char *)0x11d3 != '\x02')) {
          if (*(char *)0x42d == '\0') {
            FUN_2110_0311(0x1b8);
            FUN_2110_02e9(0xfa);
            FUN_2110_033e();
          }
          else {
            FUN_20e5_01e1(0x681c,0x219e);
          }
        }
        if ((0 < *(int *)0x11fa) && (*(char *)0x11d3 == '\x02')) {
          *(int *)0x11fa = *(int *)0x11fa + -1;
          FUN_219e_0285();
          if (*(char *)0x42d == '\0') {
            local_b = 1;
            while( true ) {
              local_9 = 100;
              while( true ) {
                uVar2 = FUN_219e_0285();
                FUN_2110_0311(uVar2);
                FUN_2110_02e9(1);
                if (local_9 == 300) break;
                local_9 = local_9 + 1;
              }
              if (local_b == 6) break;
              local_b = local_b + 1;
            }
            FUN_2110_033e();
            local_b = 1;
            while( true ) {
              uVar2 = FUN_219e_0285();
              FUN_2110_0311(uVar2);
              FUN_2110_02e9(0x26);
              if (local_b == 0x32) break;
              local_b = local_b + 1;
            }
            FUN_2110_033e();
          }
          else {
            FUN_20e5_01e1(0x6827,0x219e);
          }
          uVar2 = FUN_219e_0285();
          *(undefined2 *)0x11e4 = uVar2;
          if (0x17 < *(uint *)0x11e4) {
            *(undefined2 *)0x11e4 = 0x18;
          }
        }
      }
    }
    iVar5 = FUN_219e_0285();
    iVar5 = iVar5 * 3;
    iVar6 = FUN_219e_0285();
    if (*(char *)(iVar6 * 300 + iVar5 + 0x10cd) == '\x01') {
LAB_1000_6e2b:
      FUN_2110_0311(0x1b8);
      FUN_2110_02e9(0x19);
      FUN_2110_033e();
      if (*(char *)0x445 == '\x03') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11cd = uVar2;
      }
      if (*(char *)0x445 == '\x04') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11cd = uVar2;
      }
      if (*(char *)0x445 == '\x01') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11cb = uVar2;
      }
      if (*(char *)0x445 == '\x02') {
        uVar2 = FUN_219e_0285();
        *(undefined2 *)0x11cb = uVar2;
      }
    }
    else {
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      if (*(char *)(iVar6 * 300 + iVar5 + 0x10cd) == '\x06') goto LAB_1000_6e2b;
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      if (*(char *)(iVar6 * 300 + iVar5 + 0x10cd) == '\a') goto LAB_1000_6e2b;
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      if (*(char *)(iVar6 * 300 + iVar5 + 0x10cd) == '\b') goto LAB_1000_6e2b;
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      if (*(char *)(iVar6 * 300 + iVar5 + 0x10cd) == '\x05') goto LAB_1000_6e2b;
    }
    iVar5 = FUN_219e_0285();
    iVar5 = iVar5 * 3;
    iVar6 = FUN_219e_0285();
    if (*(int *)(iVar6 * 300 + iVar5 + 0x10ce) != 0) {
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      if (*(int *)(iVar6 * 300 + iVar5 + 0x10ce) < 9) {
        uVar2 = FUN_219e_0285();
        uVar3 = FUN_219e_0285(uVar2);
        uVar4 = FUN_219e_0285(uVar3);
        FUN_1000_4cbe(uVar4,uVar3,uVar2);
        FUN_20e5_015a();
        if (*(char *)0x42d == '\0') {
          FUN_1f6f_02b7(0x14);
        }
        else {
          FUN_20e5_01e1(0x6836,0x20e5);
        }
        FUN_219e_0285();
        FUN_219e_0285();
        uVar2 = FUN_219e_0285();
        FUN_1000_43f7(0x11cd,unaff_DS,0x11cb,unaff_DS,uVar2);
        iVar5 = FUN_219e_0285();
        if (iVar5 == 1) {
          return;
        }
        if (iVar5 == 3) {
          return;
        }
        FUN_20e5_015a();
        FUN_20e5_004f(CONCAT11(extraout_AH_00,1),0x67f7,0x20e5);
      }
    }
    iVar5 = FUN_219e_0285();
    iVar5 = iVar5 * 3;
    iVar6 = FUN_219e_0285();
    if (*(int *)(iVar6 * 300 + iVar5 + 0x10ce) == 10) {
      FUN_219e_0b99(0x32);
      uVar2 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar2;
      FUN_2110_0260(0x19,2);
      uVar3 = 0xf1c2;
      uVar2 = unaff_DS;
      FUN_219e_122e(0,0x6840,0x2110);
      FUN_219e_118c(uVar3,uVar2);
      FUN_219e_0277();
      FUN_2110_0311(0x1b8);
      FUN_2110_02e9(0xfa);
      FUN_2110_033e();
      FUN_2110_02e9(0x6d6);
      FUN_2110_0260(CONCAT11(extraout_AH_01,0x19),CONCAT11(extraout_AH_01,2));
      uVar3 = 0xf1c2;
      uVar2 = unaff_DS;
      FUN_219e_122e(0,0x685b,0x2110);
      FUN_219e_118c(uVar3,uVar2);
      FUN_219e_0277();
      iVar5 = FUN_219e_0285();
      iVar5 = iVar5 * 3;
      iVar6 = FUN_219e_0285();
      *(undefined2 *)(iVar6 * 300 + iVar5 + 0x10ce) = 0;
    }
    iVar5 = FUN_219e_0285();
    iVar5 = iVar5 * 3;
    iVar6 = FUN_219e_0285();
    if (*(int *)(iVar6 * 300 + iVar5 + 0x10ce) == 9) {
      FUN_20e5_015a();
      if (*(char *)0x42d == '\0') {
        FUN_1f6f_0320(500,1,1);
        FUN_1f6f_0320(0,499,2);
        FUN_1f6f_0320(500,1,1);
        FUN_1f6f_0320(0,499,2);
        FUN_1f6f_0320(500,1,1);
        uVar2 = 0x1f6f;
        FUN_1f6f_0320(0,499,2);
      }
      else {
        uVar2 = 0x20e5;
        FUN_20e5_01e1(0x6876,0x20e5);
      }
      FUN_1000_5be6();
      FUN_20e5_004f(CONCAT11(extraout_AH_02,1),0x67f7,uVar2);
    }
  } while( true );
}


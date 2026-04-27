// Decompiled from 1000:50a6 (shop1_weapons)
// Function size: 1437 bytes


void FUN_1000_50a6(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 extraout_AH;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  
  FUN_219e_02ad();
  FUN_1b5b_0099(0x5075,0x219e);
  FUN_2110_0260(CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,1));
  uVar4 = 0xf1c2;
  FUN_219e_122e(0,0x507f,0x2110);
  uVar3 = 0;
  uVar4 = FUN_219e_0285(uVar4);
  FUN_219e_12b9(0,uVar4,uVar3);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0357();
  uVar1 = FUN_219e_0285();
  *(undefined1 *)0x11c8 = uVar1;
  cVar2 = FUN_219e_0285();
  if (cVar2 == '\x1b') {
    FUN_1b5b_0387();
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0x13) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0x11) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0xf) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0xd) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0xb) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -9) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -7) = uVar4;
    FUN_219e_0285();
    FUN_219e_0285();
    uVar4 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -5) = uVar4;
    if ((*(int *)(param_1 + -0x13) < 2) || (4 < *(int *)(param_1 + -0x13))) {
      if ((*(int *)(param_1 + -0x11) < 2) || (4 < *(int *)(param_1 + -0x11))) {
        if ((*(int *)(param_1 + -0xf) < 2) || (4 < *(int *)(param_1 + -0xf))) {
          if ((*(int *)(param_1 + -0xd) < 2) || (4 < *(int *)(param_1 + -0xd))) {
            if ((*(int *)(param_1 + -0xb) < 2) || (*(int *)(param_1 + -0xb) < 6)) {
              if ((*(int *)(param_1 + -9) < 2) || (4 < *(int *)(param_1 + -9))) {
                if ((*(int *)(param_1 + -7) < 2) || (4 < *(int *)(param_1 + -7))) {
                  if ((1 < *(int *)(param_1 + -5)) && (*(int *)(param_1 + -5) < 5)) {
                    uVar4 = FUN_219e_0285();
                    *(undefined2 *)0x11cb = uVar4;
                    uVar4 = FUN_219e_0285();
                    *(undefined2 *)0x11cd = uVar4;
                  }
                }
                else {
                  uVar4 = FUN_219e_0285();
                  *(undefined2 *)0x11cd = uVar4;
                }
              }
              else {
                uVar4 = FUN_219e_0285();
                *(undefined2 *)0x11cb = uVar4;
                uVar4 = FUN_219e_0285();
                *(undefined2 *)0x11cd = uVar4;
              }
            }
            else {
              uVar4 = FUN_219e_0285();
              *(undefined2 *)0x11cb = uVar4;
            }
          }
          else {
            uVar4 = FUN_219e_0285();
            *(undefined2 *)0x11cb = uVar4;
          }
        }
        else {
          uVar4 = FUN_219e_0285();
          *(undefined2 *)0x11cb = uVar4;
          uVar4 = FUN_219e_0285();
          *(undefined2 *)0x11cd = uVar4;
        }
      }
      else {
        uVar4 = FUN_219e_0285();
        *(undefined2 *)0x11cd = uVar4;
      }
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11cb = uVar4;
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11cd = uVar4;
    }
    *(undefined1 *)(param_1 + -1) = 0;
  }
  else if (cVar2 == '1') {
    if ((*(uint *)0x11e2 < 0x15e) || (*(char *)0x11ec != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11ec = 1;
    }
  }
  else if (cVar2 == '2') {
    if ((*(uint *)0x11e2 < 100) || (*(char *)0x11ed != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11ed = 1;
    }
  }
  else if (cVar2 == '3') {
    if ((*(uint *)0x11e2 < 0x4b) || (*(char *)0x11ee != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11ee = 1;
    }
  }
  else if (cVar2 == '4') {
    if ((*(uint *)0x11e2 < 400) || (*(char *)0x11ef != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11ef = 1;
    }
  }
  else if (cVar2 == '5') {
    if ((*(uint *)0x11e2 < 0xfa) || (*(char *)0x11f0 != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11f0 = 1;
    }
  }
  else if (cVar2 == '6') {
    if ((*(uint *)0x11e2 < 100) || (*(char *)0x11f1 != '\0')) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      *(undefined1 *)0x11f1 = 1;
    }
  }
  else if (cVar2 == '7') {
    if (*(uint *)0x11e2 < 0x32) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11f8 = uVar4;
    }
  }
  else if (cVar2 == '8') {
    if (*(uint *)0x11e2 < 0x32) {
      FUN_1000_503d();
    }
    else {
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11e2 = uVar4;
      uVar4 = FUN_219e_0285();
      *(undefined2 *)0x11fa = uVar4;
    }
  }
  else if (cVar2 == '9') {
    *(undefined1 *)(param_1 + -1) = 2;
  }
  return;
}


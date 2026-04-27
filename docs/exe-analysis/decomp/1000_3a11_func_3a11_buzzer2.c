// 1000:3a11 (func_3a11_buzzer2)  size=531


void FUN_1000_3a11(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined1 local_2c [38];
  undefined2 uStack_6;
  undefined2 local_4;
  
  local_4 = 0x1000;
  uStack_6 = 0x3a1c;
  FUN_219e_02ad();
  FUN_1000_3749(param_1);
  local_4 = FUN_219e_0285();
  FUN_219e_02c0(0x28,local_2c,unaff_SS,0x11d4,unaff_DS);
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    *(undefined2 *)0x11d8 = 2;
    *(undefined2 *)0x11da = 4;
  }
  else if (iVar2 == 2) {
    *(undefined2 *)0x11d8 = 2;
    *(undefined2 *)0x11da = 8;
  }
  else if (iVar2 == 3) {
    *(undefined2 *)0x11d8 = 3;
    *(undefined2 *)0x11da = 4;
  }
  FUN_1b5b_0000(0x39bb,0x219e);
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    FUN_1b5b_0248(0x39c4,0x219e);
  }
  else if (iVar2 == 2) {
    FUN_1b5b_0248(0x39ce,0x219e);
  }
  else if (iVar2 == 3) {
    FUN_1b5b_0248(0x39d8,0x219e);
  }
  FUN_1000_300a(param_1);
  cVar1 = FUN_219e_0285();
  if (cVar1 == '\x01') {
    iVar2 = FUN_219e_0285();
    if (iVar2 == 1) {
      iVar2 = FUN_219e_0b99(2);
      *(int *)(param_1 + -0x1b) = *(int *)(param_1 + -0x1b) - (iVar2 + 1);
      FUN_219e_0285();
    }
    else if (iVar2 == 2) {
      iVar2 = FUN_219e_0b99(3);
      *(int *)(param_1 + -0x1b) = *(int *)(param_1 + -0x1b) - (iVar2 + 2);
      FUN_219e_0285();
    }
    else if (iVar2 == 3) {
      iVar2 = FUN_219e_0b99(4);
      *(int *)(param_1 + -0x1b) = *(int *)(param_1 + -0x1b) - (iVar2 + 2);
      FUN_219e_0285();
    }
    FUN_1b5b_0248(0x39e9,0x219e);
    if (*(char *)0x42d == '\0') {
      uVar3 = 0x1f6f;
      FUN_1f6f_02b7(5);
    }
    else {
      uVar3 = 0x20e5;
      FUN_20e5_01e1(0x39f1,0x1b5b);
    }
  }
  else {
    uVar3 = FUN_219e_0285();
    FUN_2110_0260(0xd,uVar3);
    uVar4 = 0xf1c2;
    uVar3 = unaff_DS;
    FUN_219e_122e(0,0x39f9,0x2110);
    FUN_219e_118c(uVar4,uVar3);
    FUN_219e_0277();
    if (*(char *)0x42d == '\0') {
      FUN_2110_0311(0x1b8);
      FUN_2110_02e9(0xfa);
      uVar3 = 0x2110;
      FUN_2110_033e();
    }
    else {
      uVar3 = 0x20e5;
      FUN_20e5_01e1(0x3a06,0x219e);
    }
  }
  FUN_1b5b_01ba(0x39bb,uVar3);
  if ((*(int *)(param_1 + -0x1b) < 1) || (*(int *)0x11d4 < 1)) {
    *(undefined1 *)(param_1 + -0x232) = 1;
  }
  return;
}


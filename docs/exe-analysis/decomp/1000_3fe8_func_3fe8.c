// 1000:3fe8 (func_3fe8)  size=338


void FUN_1000_3fe8(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar4;
  undefined1 local_109 [256];
  char local_9;
  int local_8;
  uint local_6;
  undefined2 local_4;
  
  local_4 = 0x1000;
  local_6 = 0x3ff3;
  FUN_219e_02ad();
  FUN_1b5b_0000(0x3fb4,0x219e);
  puVar4 = local_109;
  FUN_219e_0693(param_1 + -0x131,unaff_SS);
  FUN_219e_0720(0x3fbd,0x219e);
  FUN_1b5b_0099(puVar4,unaff_SS);
  FUN_1000_3316(param_1);
  FUN_1000_30e2(param_1);
  local_9 = FUN_219e_0285();
  local_8 = 0;
  local_4 = 0;
  local_6 = (uint)(local_9 != '\0');
  FUN_219e_0b99(5);
  local_8 = FUN_219e_0285();
  iVar1 = FUN_219e_0b99(5);
  if ((-1 < local_8) && (local_8 == iVar1)) {
    local_6 = 1;
  }
  if (local_6 == 0) {
    FUN_219e_0b99(3);
    local_4 = FUN_219e_0285();
    if (*(char *)0x42d == '\0') {
      FUN_1f6f_02b7(5);
    }
    else {
      FUN_20e5_01e1(0x3fd3,0x219e);
    }
    uVar3 = 0x219e;
    uVar2 = FUN_219e_0285();
    *(undefined2 *)0x11d4 = uVar2;
  }
  else {
    uVar3 = FUN_219e_0285();
    FUN_2110_0260(0xd,uVar3);
    uVar3 = 0xf1c2;
    FUN_219e_122e(0,0x3fdb,0x2110);
    FUN_219e_118c(uVar3,unaff_DS);
    FUN_219e_0277();
    uVar3 = 0x2110;
    FUN_2110_02e9(500);
    local_6 = 1;
  }
  FUN_1b5b_01ba(0x3fb4,uVar3);
  return;
}


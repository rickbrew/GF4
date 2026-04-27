// 1000:0015 (early_init)  size=131


void FUN_1000_0015(undefined4 param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  
  uVar3 = 0x1000;
  uVar2 = 0x20;
  FUN_219e_02ad();
  FUN_219e_12fd(0,0x219e,0x3ac,unaff_DS);
  FUN_219e_132b(0x2a,0x3ac,unaff_DS);
  FUN_219e_0277(uVar2,uVar3);
  iVar1 = FUN_219e_0285();
  if (0 < iVar1) {
    iVar4 = 1;
    while( true ) {
      FUN_219e_13db((int)param_1,(int)((ulong)param_1 >> 0x10));
      FUN_219e_0277();
      if (iVar4 == iVar1) break;
      iVar4 = iVar4 + 1;
    }
  }
  FUN_219e_13ac(0x3ac,unaff_DS);
  FUN_219e_0277();
  return;
}


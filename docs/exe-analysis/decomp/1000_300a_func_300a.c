// 1000:300a (func_300a)  size=200


undefined2 FUN_1000_300a(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 uStack_4;
  bool local_3;
  
  uVar4 = 0x30;
  FUN_219e_02ad();
  uVar2 = FUN_219e_0285();
  FUN_219e_0b99(uVar2);
  uVar1 = FUN_219e_0285();
  uVar2 = FUN_219e_0285(uVar1,uVar4);
  FUN_219e_0b99(uVar2);
  uVar2 = FUN_219e_0285();
  uVar4 = (undefined1)uVar2;
  uStack_4 = (undefined1)((uint)uVar2 >> 8);
  uVar1 = FUN_219e_0285();
  iVar3 = FUN_219e_0285(uVar1);
  local_3 = CONCAT11(uStack_4,uVar4) <= iVar3 && CONCAT11(uStack_4,uVar4) < iVar3;
  return CONCAT11(uStack_4,local_3);
}


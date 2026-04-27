// 1000:30e2 (func_30e2)  size=515


bool FUN_1000_30e2(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  bool local_3;
  
  FUN_219e_02ad();
  uVar1 = FUN_219e_0285(param_1 + -0x31);
  FUN_219e_0b99(uVar1);
  FUN_219e_0285();
  uVar1 = FUN_219e_0285();
  FUN_219e_0b99(uVar1);
  iVar2 = FUN_219e_0285();
  FUN_219e_0285();
  iVar3 = FUN_219e_0285();
  local_3 = iVar3 <= iVar2;
  if ((iVar2 < iVar3) &&
     (((*(char *)0x11ef != '\0' || (*(char *)0x11f1 != '\0')) || (*(char *)0x11f0 != '\0')))) {
    FUN_219e_0285();
    FUN_219e_0285();
    if (*(char *)0x11f1 != '\0') {
      *(undefined2 *)0x11de = 1;
      *(undefined2 *)0x11e0 = 4;
    }
    if (*(char *)0x11f0 != '\0') {
      *(undefined2 *)0x11de = 3;
      *(undefined2 *)0x11e0 = 4;
    }
    if (*(char *)0x11ef != '\0') {
      *(undefined2 *)0x11de = 3;
      *(undefined2 *)0x11e0 = 6;
    }
    if (((*(char *)0x11ef == '\0') && (*(char *)0x11f0 == '\0')) && (*(char *)0x11f1 == '\0')) {
      *(undefined2 *)0x11d8 = 2;
      *(undefined2 *)0x11da = 2;
    }
    uVar1 = FUN_219e_0285();
    FUN_219e_0b99(uVar1);
    iVar2 = FUN_219e_0285();
    uVar1 = FUN_219e_0285();
    FUN_219e_0b99(uVar1);
    iVar3 = FUN_219e_0285();
    local_3 = iVar2 < iVar3;
    uVar1 = FUN_219e_0285();
    *(undefined2 *)0x11d8 = uVar1;
    uVar1 = FUN_219e_0285();
    *(undefined2 *)0x11da = uVar1;
  }
  return local_3;
}


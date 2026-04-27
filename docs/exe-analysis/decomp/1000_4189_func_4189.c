// 1000:4189 (func_4189)  size=417


void FUN_1000_4189(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar3;
  undefined1 local_102 [252];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  uStack_4 = 0x1000;
  uStack_6 = 0x4194;
  FUN_219e_02ad();
  while( true ) {
    puVar3 = local_102;
    uVar1 = unaff_SS;
    FUN_219e_0693(param_1 + -0x131,unaff_SS);
    FUN_219e_0720(0x417b,0x219e);
    FUN_1b5b_01ba(puVar3,uVar1);
    FUN_1000_3316(param_1);
    FUN_1000_34fa(param_1);
    uVar1 = FUN_219e_0285();
    *(undefined2 *)(param_1 + -0x234) = uVar1;
    iVar2 = FUN_219e_0285();
    if (iVar2 == 1) {
      FUN_1000_3a11(param_1);
    }
    else if (iVar2 == 2) {
      *(undefined1 *)(param_1 + -7) = 3;
      *(undefined2 *)(param_1 + -2) = 2;
      iVar2 = FUN_219e_0285();
      if (iVar2 == 3) {
        uVar1 = FUN_219e_0285();
        *(undefined2 *)*(undefined4 *)(param_1 + 4) = uVar1;
      }
      else if (iVar2 == 4) {
        uVar1 = FUN_219e_0285();
        *(undefined2 *)*(undefined4 *)(param_1 + 4) = uVar1;
      }
      else if (iVar2 == 2) {
        uVar1 = FUN_219e_0285();
        *(undefined2 *)*(undefined4 *)(param_1 + 8) = uVar1;
      }
      else if (iVar2 == 1) {
        uVar1 = FUN_219e_0285();
        *(undefined2 *)*(undefined4 *)(param_1 + 8) = uVar1;
      }
    }
    else if (iVar2 == 3) {
      FUN_1000_4142(param_1);
    }
    else if (iVar2 == 4) {
      FUN_1000_2313(param_1);
    }
    if (*(char *)(param_1 + -0x232) == '\x01') {
      return;
    }
    if (*(int *)(param_1 + -0x234) != 2) {
      FUN_1000_3fe8(param_1);
    }
    if (*(int *)0x11d4 < 1) {
      *(undefined1 *)0x430 = 1;
    }
    if (*(int *)(param_1 + -0x234) == 2) {
      return;
    }
    if (*(char *)0x430 == '\x01') {
      return;
    }
    if (*(int *)0x11d4 < 1) break;
    if (*(int *)(param_1 + -0x1b) < 1) {
      return;
    }
    if (*(char *)(param_1 + -0x232) == '\x01') {
      return;
    }
  }
  return;
}


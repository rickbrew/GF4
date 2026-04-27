// Decompiled from 1000:4cbe (graphics_init)
// Function size: 884 bytes


void FUN_1000_4cbe(undefined2 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  undefined2 uVar6;
  undefined2 uVar7;
  int local_a;
  int local_8;
  
  FUN_219e_02ad();
  FUN_1bfc_0028();
  uVar7 = 0x8c;
  uVar6 = 0x52;
  iVar2 = FUN_219e_0285(0x52,0x8c);
  uVar1 = *(undefined4 *)(iVar2 * 4 + -0x78b4);
  FUN_1c14_0d95(0,(int)uVar1,(int)((ulong)uVar1 >> 0x10),uVar6,uVar7);
  iVar2 = FUN_219e_0285();
  local_a = FUN_219e_0285();
  if (local_a <= iVar2) {
    while( true ) {
      iVar3 = FUN_219e_0285();
      local_8 = FUN_219e_0285();
      if (local_8 <= iVar3) {
        while( true ) {
          if ((local_a != param_3) || (local_8 != param_2)) {
            uVar6 = FUN_219e_0285();
            uVar7 = FUN_219e_0285(uVar6);
            FUN_219e_0285(uVar7);
            FUN_219e_0285();
            iVar4 = FUN_219e_0285();
            uVar1 = *(undefined4 *)(iVar4 * 4 + -0x78d4);
            FUN_1c14_0d95(0,(int)uVar1,(int)((ulong)uVar1 >> 0x10),uVar7,uVar6);
          }
          iVar4 = FUN_219e_0285();
          iVar4 = iVar4 * 3;
          iVar5 = FUN_219e_0285();
          if (*(int *)(iVar5 * 300 + iVar4 + 0x10ce) == 9) {
            uVar6 = FUN_219e_0285();
            uVar7 = FUN_219e_0285(uVar6);
            FUN_1c14_0d95(0,(int)*(undefined4 *)0x8760,(int)((ulong)*(undefined4 *)0x8760 >> 0x10),
                          uVar7,uVar6);
          }
          iVar4 = FUN_219e_0285();
          iVar4 = iVar4 * 3;
          iVar5 = FUN_219e_0285();
          if (*(int *)(iVar5 * 300 + iVar4 + 0x10ce) == 8) {
            uVar6 = FUN_219e_0285();
            uVar7 = FUN_219e_0285(uVar6);
            FUN_1c14_0d95(0,(int)*(undefined4 *)0x8764,(int)((ulong)*(undefined4 *)0x8764 >> 0x10),
                          uVar7,uVar6);
          }
          if (local_8 == iVar3) break;
          local_8 = local_8 + 1;
        }
      }
      if (local_a == iVar2) break;
      local_a = local_a + 1;
    }
  }
  FUN_1bfc_0000();
  return;
}


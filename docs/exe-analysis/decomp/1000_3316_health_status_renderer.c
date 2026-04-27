// Decompiled from 1000:3316 (health_status_renderer)
// Function size: 377 bytes


void FUN_1000_3316(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined1 local_204 [256];
  undefined1 local_104 [254];
  undefined2 uStack_6;
  int local_4;
  
  local_4 = 0x1000;
  uStack_6 = 0x3321;
  FUN_219e_02ad();
  FUN_1c14_152c(0);
  local_4 = 0;
  while( true ) {
    uVar6 = 0;
    uVar1 = FUN_219e_0285(0);
    uVar5 = 0x13f;
    uVar2 = FUN_219e_0285(0x13f,uVar1);
    FUN_1c14_1426(uVar2,uVar5,uVar1,uVar6);
    if (local_4 == 0x18) break;
    local_4 = local_4 + 1;
  }
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_0e50(2,0);
  FUN_1c14_152c(2);
  uVar7 = 5;
  uVar6 = 0;
  puVar4 = local_204;
  uVar2 = unaff_SS;
  FUN_219e_0693(0x32ed,0x1c14);
  puVar3 = local_104;
  uVar1 = unaff_SS;
  uVar5 = FUN_219e_0285(puVar3);
  FUN_1b9f_006b(0,uVar5);
  FUN_219e_0720(puVar3,uVar1);
  FUN_1c14_1603(puVar4,uVar2,uVar6,uVar7);
  FUN_1c14_0e50(2,2);
  uVar7 = 0x13a;
  uVar6 = 0;
  puVar4 = local_104;
  uVar2 = unaff_SS;
  FUN_219e_0693(param_1 + -0x231,unaff_SS);
  FUN_219e_0720(0x32fb,0x219e);
  puVar3 = local_204;
  uVar1 = unaff_SS;
  uVar5 = FUN_219e_0285(puVar3);
  FUN_1b9f_006b(0,uVar5);
  FUN_219e_0720(puVar3,uVar1);
  FUN_1c14_1603(puVar4,uVar2,uVar6,uVar7);
  if (*(char *)0x11d3 == '\x02') {
    FUN_1c14_0e50(2,0);
    uVar7 = 0;
    uVar6 = 10;
    puVar4 = local_204;
    uVar2 = unaff_SS;
    FUN_219e_0693(0x3307,0x1c14);
    puVar3 = local_104;
    uVar1 = unaff_SS;
    uVar5 = FUN_219e_0285(puVar3);
    FUN_1b9f_006b(0,uVar5);
    FUN_219e_0720(puVar3,uVar1);
    FUN_1c14_1603(puVar4,uVar2,uVar6,uVar7);
  }
  if ((*(int *)(param_1 + -0x1b) < 1) || (*(int *)0x11d4 < 1)) {
    *(undefined1 *)(param_1 + -0x232) = 1;
  }
  return;
}


// 1000:2313 (func_2313_buzzer1)  size=662


void FUN_1000_2313(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 local_202 [256];
  undefined1 local_102 [252];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  uStack_4 = 0x1000;
  uStack_6 = 0x231e;
  FUN_219e_02ad();
  FUN_1c14_0e50(0,0);
  FUN_1c14_152c(2);
  FUN_1c14_1603(0x228b,0x1c14,0x96,2);
  uVar8 = 2;
  uVar7 = 0xa0;
  puVar5 = local_202;
  uVar6 = unaff_SS;
  FUN_219e_0693(0x22a5,0x1c14);
  puVar4 = local_102;
  uVar3 = unaff_SS;
  uVar2 = FUN_219e_0285(puVar4);
  FUN_1b9f_006b(0,uVar2);
  FUN_219e_0720(puVar4,uVar3);
  FUN_219e_0720(0x22c1,0x219e);
  FUN_1c14_1603(puVar5,uVar6,uVar7,uVar8);
  uVar8 = 2;
  uVar7 = 0xaa;
  puVar5 = local_202;
  uVar6 = unaff_SS;
  FUN_219e_0693(0x22c3,0x1c14);
  puVar4 = local_102;
  uVar3 = unaff_SS;
  uVar2 = FUN_219e_0285(puVar4);
  FUN_1b9f_006b(0,uVar2);
  FUN_219e_0720(puVar4,uVar3);
  FUN_219e_0720(0x22c1,0x219e);
  FUN_1c14_1603(puVar5,uVar6,uVar7,uVar8);
  FUN_1c14_1603(0x22d5,0x1c14,0xb4,2);
  FUN_1c14_1603(0x22dd,0x1c14,0xbe,2);
  do {
    FUN_2110_0357();
    uVar1 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar1;
    if ((*(char *)0x11c8 == '1') || (*(char *)0x11c8 == '2')) break;
  } while (*(char *)0x11c8 != '3');
  FUN_1c14_152c(0);
  FUN_1c14_1603(0x228b,0x1c14,0x96,2);
  uVar8 = 2;
  uVar7 = 0xa0;
  puVar5 = local_202;
  uVar6 = unaff_SS;
  FUN_219e_0693(0x22a5,0x1c14);
  puVar4 = local_102;
  uVar3 = unaff_SS;
  uVar2 = FUN_219e_0285(puVar4);
  FUN_1b9f_006b(0,uVar2);
  FUN_219e_0720(puVar4,uVar3);
  FUN_219e_0720(0x22c1,0x219e);
  FUN_1c14_1603(puVar5,uVar6,uVar7,uVar8);
  uVar8 = 2;
  uVar7 = 0xaa;
  puVar5 = local_202;
  uVar6 = unaff_SS;
  FUN_219e_0693(0x22c3,0x1c14);
  puVar4 = local_102;
  uVar3 = unaff_SS;
  uVar2 = FUN_219e_0285(puVar4);
  FUN_1b9f_006b(0,uVar2);
  FUN_219e_0720(puVar4,uVar3);
  FUN_219e_0720(0x22c1,0x219e);
  FUN_1c14_1603(puVar5,uVar6,uVar7,uVar8);
  FUN_1c14_1603(0x22d5,0x1c14,0xb4,2);
  uVar3 = 0x1c14;
  FUN_1c14_1603(0x22dd,0x1c14,0xbe,2);
  if (*(char *)0x11c8 == '1') {
    if (*(int *)0x11f8 < 1) {
      uVar3 = 0x20e5;
      FUN_20e5_01e1(0x22f3,0x1c14);
    }
    else {
      *(int *)0x11f8 = *(int *)0x11f8 + -1;
      FUN_219e_0285();
      *(int *)0x11d4 = *(int *)0x11d4 + 3;
      FUN_219e_0285();
      uVar3 = 0x20e5;
      FUN_20e5_01e1(0x22fe,0x219e);
    }
  }
  if (*(char *)0x11c8 == '2') {
    if (*(int *)0x11fa < 1) {
      FUN_20e5_01e1(0x22f3,uVar3);
    }
    else {
      *(int *)0x11fa = *(int *)0x11fa + -1;
      FUN_219e_0285();
      *(int *)0x11e4 = *(int *)0x11e4 + 3;
      FUN_219e_0285();
      FUN_20e5_01e1(0x22fe,0x219e);
    }
  }
  puVar5 = local_102;
  FUN_219e_0693(param_1 + -0x131,unaff_SS);
  FUN_219e_0720(0x230d,0x219e);
  FUN_1b5b_01ba(puVar5,unaff_SS);
  FUN_1000_3316(param_1);
  return;
}


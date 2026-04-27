// Decompiled from 1000:43f7 (boss_or_hidden_screen)
// Function size: 2215 bytes


uint FUN_1000_43f7(void)

{
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined1 extraout_AH_01;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_0000000a;
  undefined1 *puVar4;
  undefined1 local_336 [258];
  undefined1 local_234;
  undefined1 local_233 [256];
  undefined1 local_133 [256];
  undefined1 local_33 [22];
  int local_1d;
  undefined2 local_1b;
  undefined2 local_19;
  undefined2 local_17;
  undefined2 local_15;
  undefined2 local_13;
  undefined2 local_11;
  int local_f;
  undefined2 local_d;
  undefined2 local_b;
  char local_9;
  undefined2 uStack_6;
  uint local_4;
  
  local_4 = 0x1000;
  uStack_6 = 0x4402;
  FUN_219e_02ad();
  local_4 = 2;
  if (in_stack_0000000a == 8) {
    FUN_20e5_01e1(0x432a,0x219e);
    FUN_20e5_004f(CONCAT11(extraout_AH_00,1),0x4335,0x20e5);
  }
  else {
    FUN_20e5_004f(CONCAT11(extraout_AH,1),0x4341,0x219e);
  }
  uVar1 = FUN_219e_0285();
  FUN_1000_0015(local_33,unaff_SS,uVar1);
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_1d = 3;
  }
  else if (iVar2 == 2) {
    local_1d = 0xe;
  }
  else if (iVar2 == 3) {
    local_1d = 0xc;
  }
  else if (iVar2 == 4) {
    local_1d = 4;
  }
  else if (iVar2 == 5) {
    local_1d = 5;
  }
  else if (iVar2 == 6) {
    local_1d = 8;
  }
  else if (iVar2 == 7) {
    local_1d = 4;
  }
  else if (iVar2 == 8) {
    local_1d = 0x12;
  }
  FUN_1c14_0e94(4,0,2);
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x4355,0x219e);
  }
  else if (iVar2 == 2) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x435c,0x219e);
  }
  else if (iVar2 == 3) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x4365,0x219e);
  }
  else if (iVar2 == 4) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x436e,0x219e);
  }
  else if (iVar2 == 5) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x4372,0x219e);
  }
  else if (iVar2 == 6) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x4378,0x219e);
  }
  else if (iVar2 == 7) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x437f,0x219e);
  }
  else if (iVar2 == 8) {
    FUN_219e_06ad(0x14,local_33,unaff_SS,0x4385,0x219e);
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_1d = 3;
  }
  else if (iVar2 == 2) {
    local_1d = 0x10;
  }
  else if (iVar2 == 3) {
    local_1d = 0xc;
  }
  else if (iVar2 == 4) {
    local_1d = 4;
  }
  else if (iVar2 == 5) {
    local_1d = 5;
  }
  else if (iVar2 == 6) {
    local_1d = 8;
  }
  else if (iVar2 == 7) {
    local_1d = 4;
  }
  else if (iVar2 == 8) {
    local_1d = 0x12;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_1b = 4;
  }
  else if (iVar2 == 2) {
    local_1b = 10;
  }
  else if (iVar2 == 3) {
    local_1b = 8;
  }
  else if (iVar2 == 4) {
    local_1b = 6;
  }
  else if (iVar2 == 5) {
    local_1b = 5;
  }
  else if (iVar2 == 6) {
    local_1b = 0xc;
  }
  else if (iVar2 == 7) {
    local_1b = 0x10;
  }
  else if (iVar2 == 8) {
    local_1b = 0x12;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_19 = 2;
  }
  else if (iVar2 == 2) {
    local_19 = 4;
  }
  else if (iVar2 == 3) {
    local_19 = 3;
  }
  else if (iVar2 == 4) {
    local_19 = 3;
  }
  else if (iVar2 == 5) {
    local_19 = 4;
  }
  else if (iVar2 == 6) {
    local_19 = 6;
  }
  else if (iVar2 == 7) {
    local_19 = 4;
  }
  else if (iVar2 == 8) {
    local_19 = 2;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_17 = 2;
  }
  else if (iVar2 == 2) {
    local_17 = 3;
  }
  else if (iVar2 == 3) {
    local_17 = 3;
  }
  else if (iVar2 == 4) {
    local_17 = 3;
  }
  else if (iVar2 == 5) {
    local_17 = 2;
  }
  else if (iVar2 == 6) {
    local_17 = 2;
  }
  else if (iVar2 == 7) {
    local_17 = 4;
  }
  else if (iVar2 == 8) {
    local_17 = 0xb;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_15 = 4;
  }
  else if (iVar2 == 2) {
    local_15 = 4;
  }
  else if (iVar2 == 3) {
    local_15 = 0xe;
  }
  else if (iVar2 == 4) {
    local_15 = 9;
  }
  else if (iVar2 == 5) {
    local_15 = 8;
  }
  else if (iVar2 == 6) {
    local_15 = 8;
  }
  else if (iVar2 == 7) {
    local_15 = 8;
  }
  else if (iVar2 == 8) {
    local_15 = 0xc;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_13 = 2;
  }
  else if (iVar2 == 2) {
    local_13 = 4;
  }
  else if (iVar2 == 3) {
    local_13 = 3;
  }
  else if (iVar2 == 4) {
    local_13 = 3;
  }
  else if (iVar2 == 5) {
    local_13 = 4;
  }
  else if (iVar2 == 6) {
    local_13 = 2;
  }
  else if (iVar2 == 7) {
    local_13 = 4;
  }
  else if (iVar2 == 8) {
    local_13 = 5;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_11 = 4;
  }
  else if (iVar2 == 2) {
    local_11 = 2;
  }
  else if (iVar2 == 3) {
    local_11 = 3;
  }
  else if (iVar2 == 4) {
    local_11 = 4;
  }
  else if (iVar2 == 5) {
    local_11 = 3;
  }
  else if (iVar2 == 6) {
    local_11 = 4;
  }
  else if (iVar2 == 7) {
    local_11 = 3;
  }
  else if (iVar2 == 8) {
    local_11 = 4;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_f = 0x14;
  }
  else if (iVar2 == 2) {
    local_f = 0x24;
  }
  else if (iVar2 == 3) {
    local_f = 0x1f;
  }
  else if (iVar2 == 4) {
    local_f = 0x19;
  }
  else if (iVar2 == 5) {
    local_f = 10;
  }
  else if (iVar2 == 6) {
    local_f = 5;
  }
  else if (iVar2 == 7) {
    local_f = 0x32;
  }
  else if (iVar2 == 8) {
    local_f = 0;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_d = 2;
  }
  else if (iVar2 == 2) {
    local_d = 0x14;
  }
  else if (iVar2 == 3) {
    local_d = 0x10;
  }
  else if (iVar2 == 4) {
    local_d = 7;
  }
  else if (iVar2 == 5) {
    local_d = 0x12;
  }
  else if (iVar2 == 6) {
    local_d = 0x10;
  }
  else if (iVar2 == 7) {
    local_d = 0xc;
  }
  else if (iVar2 == 8) {
    local_d = 4;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    local_b = 0xc;
  }
  else if (iVar2 == 2) {
    local_b = 2;
  }
  else if (iVar2 == 3) {
    local_b = 4;
  }
  else if (iVar2 == 4) {
    local_b = 4;
  }
  else if (iVar2 == 5) {
    local_b = 2;
  }
  else if (iVar2 == 6) {
    local_b = 1;
  }
  else if (iVar2 == 7) {
    local_b = 6;
  }
  else if (iVar2 == 8) {
    local_b = 0xc;
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x4355,0x219e);
  }
  else if (iVar2 == 2) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x435c,0x219e);
  }
  else if (iVar2 == 3) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x4365,0x219e);
  }
  else if (iVar2 == 4) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x436e,0x219e);
  }
  else if (iVar2 == 5) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x4392,0x219e);
  }
  else if (iVar2 == 6) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x4378,0x219e);
  }
  else if (iVar2 == 7) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x437f,0x219e);
  }
  else if (iVar2 == 8) {
    FUN_219e_06ad(0xff,local_233,unaff_SS,0x4385,0x219e);
  }
  iVar2 = FUN_219e_0285();
  if (iVar2 == 1) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43a3,0x219e);
  }
  else if (iVar2 == 2) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43aa,0x219e);
  }
  else if (iVar2 == 3) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43b2,0x219e);
  }
  else if (iVar2 == 4) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43ba,0x219e);
  }
  else if (iVar2 == 5) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43be,0x219e);
  }
  else if (iVar2 == 6) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43c4,0x219e);
  }
  else if (iVar2 == 7) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43cb,0x219e);
  }
  else if (iVar2 == 8) {
    FUN_219e_06ad(0xff,local_133,unaff_SS,0x43d1,0x219e);
  }
  puVar4 = local_336;
  FUN_219e_0693(local_133,unaff_SS);
  FUN_219e_0720(0x43d7,0x219e);
  uVar1 = 0x1b5b;
  FUN_1b5b_0099(puVar4,unaff_SS);
  local_234 = 0;
  FUN_1000_3316(&stack0xfffe);
  local_9 = '\0';
  do {
    FUN_1000_4189(&stack0xfffe);
    if ((local_9 != '\0') || (*(int *)0x11d4 < 1)) break;
  } while (0 < local_1d);
  local_4 = (uint)(*(int *)0x11d4 < 1);
  if (local_1d < 1) {
    FUN_20e5_01e1(0x432a,0x1b5b);
    *(int *)0x11e2 = *(int *)0x11e2 + local_f;
    FUN_219e_0285();
    iVar2 = FUN_219e_0285();
    iVar2 = iVar2 * 3;
    uVar1 = 0x219e;
    iVar3 = FUN_219e_0285();
    *(undefined2 *)(iVar3 * 300 + iVar2 + 0x10ce) = 0;
    local_4 = 0;
    if (in_stack_0000000a == 8) {
      FUN_1000_21a4();
      local_4 = 3;
    }
  }
  if (*(int *)0x11d4 < 1) {
    FUN_20e5_01e1(0x432a,uVar1);
    FUN_20e5_015a();
    FUN_2110_02e9(500);
    FUN_1000_20db();
    FUN_20e5_004f(CONCAT11(extraout_AH_01,1),0x43ed,0x2110);
    local_4 = 1;
  }
  FUN_1b5b_0387();
  return local_4;
}


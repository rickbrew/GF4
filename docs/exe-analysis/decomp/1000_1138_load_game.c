// Decompiled from 1000:1138 (load_game)
// Function size: 955 bytes


void __cdecl16near FUN_1000_1138(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 local_41d [256];
  undefined1 local_31d [229];
  undefined1 auStack_238 [27];
  int local_21d;
  undefined1 local_219 [31];
  undefined1 local_1fa [31];
  undefined1 local_1db [31];
  undefined1 local_1bc [31];
  undefined1 local_19d [31];
  undefined1 local_17e [31];
  undefined1 local_15f [31];
  undefined1 local_140 [31];
  undefined1 local_121 [31];
  undefined1 local_102 [252];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  uStack_4 = 0x1000;
  uStack_6 = 0x1143;
  FUN_219e_02ad();
  FUN_1b5b_0387();
  FUN_219e_0dba(0x10db,0x1b5b,local_102,unaff_SS);
  FUN_219e_0e2a(0x219e,local_102);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_219,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_1fa,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_1db,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_1bc,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_19d,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_17e,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_15f,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_140,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  puVar6 = local_102;
  FUN_219e_11f5(0x1e,local_121,unaff_SS);
  FUN_219e_1126(0x219e,puVar6);
  FUN_219e_0277();
  FUN_219e_0e8d(local_102,unaff_SS);
  FUN_219e_0277();
  local_21d = 1;
  while( true ) {
    FUN_1c14_0e94(4,0,2);
    FUN_1c14_0e50(1,1);
    FUN_1c14_152c(3);
    uVar8 = 0x9f;
    uVar2 = FUN_219e_0285(0x9f);
    puVar6 = local_31d;
    uVar7 = unaff_SS;
    uVar3 = FUN_219e_0285(puVar6);
    FUN_1b9f_006b(0,uVar3);
    FUN_219e_0720(0x10f0,0x1b9f);
    iVar4 = FUN_219e_0285();
    FUN_219e_0720(auStack_238 + iVar4 * 0x1f,unaff_SS);
    FUN_1c14_1603(puVar6,uVar7,uVar2,uVar8);
    if (local_21d == 9) break;
    local_21d = local_21d + 1;
  }
  FUN_1c14_1603(0x10fb,0x1c14,0xb3,0x9f);
  FUN_1c14_0e94(3,0,1);
  FUN_1c14_1603(0x1112,0x1c14,0x1d,0x9f);
  FUN_1c14_0e94(4,0,2);
  while( true ) {
    FUN_2110_0357();
    uVar1 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar1;
    if (((((*(char *)0x11c8 == '1') || (*(char *)0x11c8 == '2')) || (*(char *)0x11c8 == '3')) ||
        ((*(char *)0x11c8 == '4' || (*(char *)0x11c8 == '5')))) ||
       ((*(char *)0x11c8 == '6' || ((*(char *)0x11c8 == '6' || (*(char *)0x11c8 == '7')))))) break;
    if ((*(char *)0x11c8 == '8') || (*(char *)0x11c8 == '9')) break;
  }
  FUN_1c14_1603(0x1124,0x219e,0xbd,0x9f);
  uVar3 = 0x1047;
  puVar6 = local_41d;
  uVar7 = unaff_SS;
  uVar2 = unaff_DS;
  FUN_219e_0693(0x112f,0x1c14);
  puVar5 = local_31d;
  FUN_219e_07ae(CONCAT11(extraout_AH,*(undefined1 *)0x11c8));
  FUN_219e_0720(puVar5,unaff_SS);
  FUN_219e_0720(0x1133,0x219e);
  FUN_219e_12fd(puVar6,uVar7,uVar3,uVar2);
  FUN_219e_132b(1,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,30000,0x11fc,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,0x28,0x11d4,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,1,0x11d3,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,2,0x11cb,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,2,0x11cd,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_1411(0,0,1,0x445,unaff_DS,0x1047,unaff_DS);
  FUN_219e_0277();
  FUN_219e_13ac(0x1047,unaff_DS);
  FUN_219e_0277();
  *(undefined1 *)0x446 = 1;
  FUN_1b5b_0387();
  return;
}


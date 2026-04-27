// 1000:172b (func_172b)  size=1942


void __cdecl16near FUN_1000_172b(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined1 extraout_AH_05;
  undefined1 extraout_AH_06;
  undefined1 extraout_AH_07;
  undefined1 extraout_AH_08;
  undefined1 extraout_AH_09;
  undefined1 extraout_AH_10;
  undefined1 extraout_AH_11;
  undefined1 extraout_AH_12;
  undefined1 extraout_AH_13;
  undefined1 extraout_AH_14;
  undefined1 extraout_AH_15;
  undefined1 extraout_AH_16;
  undefined1 extraout_AH_17;
  undefined1 extraout_AH_18;
  undefined1 extraout_AH_19;
  undefined1 extraout_AH_20;
  undefined1 extraout_AH_21;
  undefined1 extraout_AH_22;
  undefined1 extraout_AH_23;
  undefined1 extraout_AH_24;
  undefined1 extraout_AH_25;
  undefined1 extraout_AH_26;
  undefined1 extraout_AH_27;
  undefined1 extraout_AH_28;
  undefined1 extraout_AH_29;
  undefined1 extraout_AH_30;
  undefined1 extraout_AH_31;
  undefined1 extraout_AH_32;
  undefined1 extraout_AH_33;
  undefined1 extraout_AH_34;
  undefined1 extraout_AH_35;
  undefined1 extraout_AH_36;
  undefined1 extraout_AH_37;
  undefined1 extraout_AH_38;
  undefined1 extraout_AH_39;
  undefined1 extraout_AH_40;
  undefined1 extraout_AH_41;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 ***local_217;
  undefined1 local_117 [256];
  undefined1 local_17;
  undefined2 local_16 [8];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  uStack_4 = 0x1000;
  uStack_6 = 0x1736;
  FUN_219e_02ad();
  *(undefined1 *)0xef20 = 0x1e;
  local_17 = FUN_219e_0285();
  FUN_1b5b_0387();
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  if (*(char *)0xef34 == '\x01') {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)();
  }
  local_217 = (undefined2 ***)0x1774;
  FUN_2110_020d();
  local_217 = (undefined2 ***)0x1779;
  FUN_1bfc_0000();
  local_217 = (undefined2 ***)0x1786;
  iVar4 = FUN_219e_0285();
  if (iVar4 == 1) {
    local_217 = (undefined2 ***)0x1503;
    FUN_219e_06ad(0xff,local_117,unaff_SS);
  }
  else if (iVar4 == 2) {
    local_217 = (undefined2 ***)0x150b;
    FUN_219e_06ad(0xff,local_117,unaff_SS);
  }
  else if (iVar4 == 3) {
    local_217 = (undefined2 ***)0x1516;
    FUN_219e_06ad(0xff,local_117,unaff_SS);
  }
  local_217 = &local_217;
  FUN_219e_0693(local_117,unaff_SS);
  FUN_219e_0720(0x151c,0x219e);
  FUN_219e_06ad(0xff,local_117,unaff_SS);
  local_217 = (undefined2 ***)0x181b;
  FUN_219e_0285();
  local_217 = (undefined2 ***)CONCAT11(extraout_AH,2);
  FUN_2110_0260();
  local_217 = (undefined2 ***)0xf1c2;
  FUN_219e_122e(0,local_117,unaff_SS);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_00,5),CONCAT11(extraout_AH_00,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x152e,0x2110);
  iVar4 = *(int *)0x11d4 >> 0xf;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,iVar4);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_01,7),CONCAT11(extraout_AH_01,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x1546,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_02,9),CONCAT11(extraout_AH_02,1));
  uVar6 = 0xf1c2;
  FUN_219e_122e(0,0x155e,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar6);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_11d0(0,CONCAT11(extraout_AH_03,0x44));
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar6);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_04,0xb),CONCAT11(extraout_AH_04,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x1576,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_05,0xd),CONCAT11(extraout_AH_05,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x158e,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_11d0(0,CONCAT11(extraout_AH_06,0x44));
  uVar5 = 0;
  uVar7 = FUN_219e_0285();
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  uVar3 = extraout_AH_07;
  if (*(char *)0x11d3 == '\x02') {
    FUN_2110_0260(CONCAT11(extraout_AH_07,0xf),CONCAT11(extraout_AH_07,1));
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x15a6,0x2110);
    uVar5 = 0;
    uVar7 = FUN_219e_0285(uVar7);
    FUN_219e_12b9(0,uVar7,uVar5);
    FUN_219e_1173(0x219e);
    FUN_219e_0277();
    FUN_2110_0260(CONCAT11(extraout_AH_08,0x11),CONCAT11(extraout_AH_08,1));
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x15be,0x2110);
    uVar5 = 0;
    uVar7 = FUN_219e_0285(uVar7);
    FUN_219e_12b9(0,uVar7,uVar5);
    FUN_219e_1173(0x219e);
    FUN_219e_0277();
    uVar3 = extraout_AH_09;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x13),CONCAT11(uVar3,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x15d6,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_10,0x15),CONCAT11(extraout_AH_10,1));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x15ee,0x2110);
  uVar5 = 0;
  uVar7 = FUN_219e_0285(uVar7);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_11,5),CONCAT11(extraout_AH_11,0x28));
  uVar7 = 0xf1c2;
  FUN_219e_122e(0,0x1606,0x2110);
  FUN_219e_1173(0x219e,uVar7);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_12,6),CONCAT11(extraout_AH_12,0x28));
  uVar5 = 0;
  uVar7 = FUN_219e_0285(0xf1c2);
  FUN_219e_12b9(0,uVar7,uVar5);
  FUN_219e_122e(0,0x1615,0x219e);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_13,7),CONCAT11(extraout_AH_13,0x28));
  uVar3 = extraout_AH_14;
  if (*(char *)0x11ec != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1621,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_15;
  }
  FUN_2110_0260(CONCAT11(uVar3,8),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_16;
  if (*(char *)0x11ed != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1629,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_17;
  }
  FUN_2110_0260(CONCAT11(uVar3,9),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_18;
  if (*(char *)0x11ee != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x163f,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_19;
  }
  FUN_2110_0260(CONCAT11(uVar3,0xb),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_20;
  if (*(char *)0x11ef != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1647,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_21;
  }
  FUN_2110_0260(CONCAT11(uVar3,0xc),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_22;
  if (*(char *)0x11f0 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1654,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_23;
  }
  FUN_2110_0260(CONCAT11(uVar3,0xd),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_24;
  if (*(char *)0x11f1 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1665,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_25;
  }
  FUN_2110_0260(CONCAT11(uVar3,0xe),CONCAT11(uVar3,0x28));
  iVar4 = *(int *)0x11f8 >> 0xf;
  uVar7 = FUN_219e_0285(0xf1c2);
  FUN_219e_12b9(0,uVar7,iVar4);
  FUN_219e_122e(0,0x1674,0x219e);
  FUN_219e_1173(0x219e);
  FUN_219e_0277();
  FUN_2110_0260(CONCAT11(extraout_AH_26,0xf),CONCAT11(extraout_AH_26,0x28));
  uVar3 = extraout_AH_27;
  if (*(char *)0x11d3 == '\x02') {
    iVar4 = *(int *)0x11fa >> 0xf;
    uVar7 = FUN_219e_0285(0xf1c2);
    FUN_219e_12b9(0,uVar7,iVar4);
    FUN_219e_122e(0,0x1687,0x219e);
    FUN_219e_1173(0x219e);
    FUN_219e_0277();
    uVar3 = extraout_AH_28;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x11),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_29;
  if (*(char *)0x11d3 == '\x02') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x1698,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_30;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x12),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_31;
  if (*(char *)0x11f2 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16a4,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_32;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x13),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_33;
  if (*(char *)0x11f3 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16b3,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_34;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x14),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_35;
  if (*(char *)0x11f4 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16be,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_36;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x15),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_37;
  if (*(char *)0x11f5 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16cc,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_38;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x16),CONCAT11(uVar3,0x28));
  uVar3 = extraout_AH_39;
  if (*(char *)0x11f6 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16d8,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
    uVar3 = extraout_AH_40;
  }
  FUN_2110_0260(CONCAT11(uVar3,0x17),CONCAT11(uVar3,0x28));
  if (*(char *)0x11f7 != '\0') {
    uVar7 = 0xf1c2;
    FUN_219e_122e(0,0x16e1,0x2110);
    FUN_219e_1173(0x219e,uVar7);
    FUN_219e_0277();
  }
  uVar7 = FUN_219e_0285();
  FUN_2110_0260(0x19,uVar7);
  uVar5 = 0xf1c2;
  uVar7 = unaff_DS;
  FUN_219e_122e(0,0x16ef,0x2110);
  FUN_219e_118c(uVar5,uVar7);
  FUN_219e_0277();
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x1719,0x219e);
  }
  do {
    cVar2 = FUN_2110_0345();
    if (cVar2 != '\0') break;
    cVar2 = FUN_1bfc_0050(1);
    if (cVar2 != '\0') break;
    cVar2 = FUN_1bfc_0050(2);
    if (cVar2 != '\0') break;
    cVar2 = FUN_1bfc_0050(2);
  } while (cVar2 == '\0');
  cVar2 = FUN_2110_0345();
  if (cVar2 != '\0') {
    FUN_2110_0357();
    uVar3 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar3;
  }
  local_16[0] = FUN_219e_0285();
  FUN_1bfc_0028();
  FUN_218e_0015(local_16,unaff_SS,CONCAT11(extraout_AH_41,0x10));
  FUN_1bfc_0000();
  return;
}


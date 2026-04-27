// Decompiled from 1000:72cf (intro_sequence)
// Function size: 959 bytes


void __cdecl16near FUN_1000_72cf(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  uint uVar2;
  undefined2 uVar3;
  undefined1 extraout_AH_00;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 local_4;
  
  FUN_219e_02ad();
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  FUN_1000_5d15();
  FUN_1b5b_0387();
  FUN_20e5_004f(CONCAT11(extraout_AH,1),0x7172,0x1b5b);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x7179,0x2110);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x7184,0x2110);
  local_6 = 15000;
  while( true ) {
    uVar2 = FUN_219e_0285();
    if (uVar2 < 0x8000) {
      local_4 = 0;
      while( true ) {
        uVar3 = FUN_219e_0285();
        FUN_219e_0b99(uVar3);
        uVar3 = FUN_219e_0285();
        FUN_2110_0311(uVar3);
        if (local_4 == uVar2) break;
        local_4 = local_4 + 1;
      }
    }
    if (local_6 == 0) break;
    local_6 = local_6 + -1;
  }
  FUN_2110_033e();
  FUN_1b5b_0099(0x7179,0x2110);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x719f,0x2110);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x71aa,0x2110);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x71b5,0x2110);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x71c0,0x2110);
  if (*(char *)0x42d == '\0') {
    uVar3 = 0x1f6f;
    FUN_1f6f_02b7(0x1e);
  }
  else {
    uVar3 = 0x20e5;
    FUN_20e5_01e1(0x71cb,0x1b5b);
  }
  FUN_1b5b_0099(0x71d4,uVar3);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x71df,0x2110);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x71ea,0x2110);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  uVar3 = 0x1b5b;
  FUN_1b5b_0099(0x71f5,0x2110);
  if (*(char *)0x42d == '\0') {
    local_6 = 1;
    while( true ) {
      FUN_1f6f_02b7(4);
      uVar3 = 0x2110;
      FUN_2110_02e9(0x96);
      if (local_6 == 4) break;
      local_6 = local_6 + 1;
    }
  }
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x7201,uVar3);
    uVar3 = 0x20e5;
    FUN_20e5_01e1(0x71cb,0x20e5);
  }
  FUN_1b5b_0099(0x720a,uVar3);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x7216,0x2110);
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x7222,0x2110);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x722e,0x2110);
  FUN_2110_02e9(1000);
  if (*(char *)0x42d == '\0') {
    uVar3 = 0x1f6f;
    FUN_1f6f_0320(15000,0,1);
  }
  else {
    uVar3 = 0x20e5;
    FUN_20e5_01e1(0x723a,0x2110);
  }
  FUN_1b5b_0099(0x7243,uVar3);
  uVar3 = 0x2110;
  FUN_2110_02e9(1000);
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x724f,0x2110);
    FUN_20e5_01e1(0x724f,0x20e5);
    uVar3 = 0x20e5;
    FUN_20e5_01e1(0x7258,0x20e5);
  }
  if (*(char *)0x42d == '\0') {
    local_6 = 1;
    while( true ) {
      FUN_1f6f_02b7(4);
      uVar3 = 0x2110;
      FUN_2110_02e9(0x96);
      if (local_6 == 4) break;
      local_6 = local_6 + 1;
    }
  }
  FUN_1b5b_0099(0x7261,uVar3);
  FUN_2110_02e9(1000);
  FUN_1b5b_0099(0x726d,0x2110);
  FUN_20e5_01e1(0x7279,0x1b5b);
  FUN_2110_02e9(1000);
  if (*(char *)0x42d == '\0') {
    uVar3 = 0x1f6f;
    FUN_1f6f_0320(0,15000,2);
  }
  else {
    uVar3 = 0x20e5;
    FUN_20e5_01e1(0x723a,0x2110);
  }
  FUN_1b5b_0099(0x7282,uVar3);
  FUN_1b5b_0099(0x728e,0x1b5b);
  FUN_2110_02e9(0x5dc);
  if (*(char *)0x42d == '\0') {
    FUN_1c14_0e94(4,0,2);
    FUN_1c14_0e50(1,1);
    FUN_1c14_1603(0x729a,0x1c14,0xbe,0x9f);
    FUN_2110_0357();
    uVar1 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar1;
    *(undefined1 *)0x11c8 = 0;
  }
  if (*(char *)0x42d != '\0') {
    FUN_2110_02e9(23000);
  }
  if (*(char *)0x42d == '\0') {
    FUN_1b5b_0387();
  }
  else {
    FUN_1c14_0ba2();
  }
  FUN_2110_02e9(0x5dc);
  FUN_1b5b_0099(0x72bc,0x2110);
  FUN_20e5_004f(CONCAT11(extraout_AH_00,1),0x72c5,0x1b5b);
  return;
}


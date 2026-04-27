// 1000:5d15 (func_5d15)  size=537


void __cdecl16near FUN_1000_5d15(void)

{
  byte extraout_AH;
  byte extraout_AH_00;
  byte bVar1;
  undefined1 extraout_AH_01;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined2 local_6;
  
  FUN_219e_02ad();
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  uVar2 = 0x1b5b;
  FUN_1b5b_0099(0x5c77,0x2110);
  bVar1 = extraout_AH;
  if (*(char *)0x42d == '\0') {
    uVar2 = 0x1f6f;
    FUN_1f6f_0189();
    bVar1 = extraout_AH_00;
  }
  uVar3 = uVar2;
  if (*(char *)0x42d != '\0') {
    uVar3 = 0x20e5;
    FUN_20e5_004f((uint)bVar1 << 8,0x5c84,uVar2);
  }
  uVar2 = 0x1b5b;
  FUN_1b5b_0099(0x5c8e,uVar3);
  if (*(char *)0x42d != '\0') {
    uVar2 = 0x20e5;
    FUN_20e5_004f(CONCAT11(extraout_AH_01,1),0x5c9b,0x1b5b);
  }
  if (*(char *)0x42d == '\0') {
    local_6 = 1;
    while( true ) {
      FUN_219e_0b99(5000);
      uVar2 = FUN_219e_0285();
      FUN_2110_0311(uVar2);
      FUN_219e_0b99(0x19);
      uVar2 = FUN_219e_0285();
      FUN_2110_02e9(uVar2);
      FUN_2110_033e();
      if (local_6 == 0xfa) break;
      local_6 = local_6 + 1;
    }
  }
  else {
    FUN_20e5_01e1(0x5caf,uVar2);
    FUN_20e5_01e1(0x5cbc,0x20e5);
  }
  FUN_2110_02e9(3000);
  FUN_1b5b_0099(0x5cc7,0x2110);
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x5cd4,0x1b5b);
  }
  FUN_2110_02e9(3000);
  FUN_1b5b_0099(0x5ce1,0x2110);
  if (*(char *)0x42d == '\0') {
    FUN_1f6f_0000();
  }
  else {
    FUN_20e5_01e1(0x5cee,0x1b5b);
    FUN_2110_02e9(4000);
  }
  if (*(char *)0x42d == '\0') {
    FUN_1f6f_0189();
  }
  else {
    FUN_2110_02e9(2000);
  }
  if (*(char *)0x42d == '\0') {
    FUN_1f6f_0320(5000,0,1);
    FUN_1f6f_0320(0,5000,2);
    FUN_1f6f_0320(5000,0,1);
    FUN_1f6f_0320(0,5000,2);
    FUN_1f6f_0320(5000,0,1);
    FUN_1f6f_0320(0,5000,2);
    FUN_1f6f_0320(5000,0,1);
    FUN_1f6f_0320(0,5000,2);
    FUN_1f6f_0320(5000,0,1);
    FUN_1f6f_0320(0,5000,2);
  }
  FUN_2110_02e9(2000);
  FUN_1b5b_0099(0x5cfb,0x2110);
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x5d08,0x1b5b);
  }
  FUN_2110_02e9(3000);
  FUN_1b5b_0387();
  return;
}


// 1000:21a4 (func_21a4_starfm)  size=231


void __cdecl16near FUN_1000_21a4(void)

{
  code *pcVar1;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  
  FUN_219e_02ad();
  FUN_1b5b_0387();
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  FUN_2110_02e9();
  FUN_20e5_004f(CONCAT11(extraout_AH,1),0x212f);
  FUN_1b5b_0099(0x213a);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x2146);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x2152);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x215e);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x216a);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x2176);
  FUN_2110_02e9();
  FUN_1b5b_0099(0x2182);
  if (*(char *)0x42d == '\0') {
    FUN_2110_02e9();
  }
  else {
    FUN_20e5_01e1(0x218e);
    FUN_2110_02e9();
  }
  FUN_1b5b_0099(0x2198);
  FUN_2110_02e9();
  FUN_20e5_015a();
  return;
}


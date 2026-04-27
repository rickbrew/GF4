// 1000:8fbf (fighter_init)  size=52


void FUN_1000_8fbf(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_219e_02ad();
  *(undefined1 *)(param_1 + -5) = 1;
  if (*(char *)0x42d != '\0') {
    FUN_20e5_01e1(0x8fb3,0x219e);
  }
  *(undefined1 *)0x11d3 = 1;
  FUN_1000_1ec9();
  FUN_1000_76f9();
  return;
}


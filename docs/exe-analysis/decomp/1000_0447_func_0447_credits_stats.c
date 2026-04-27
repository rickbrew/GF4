// 1000:0447 (func_0447_credits_stats)  size=860


void __cdecl16near FUN_1000_0447(void)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar5;
  
  FUN_219e_02ad();
  iVar5 = 1;
  while( true ) {
    FUN_219e_0285();
    uVar2 = FUN_219e_0285();
    iVar3 = FUN_219e_0285();
    (&stack0xbffd)[iVar3] = uVar2;
    if (iVar5 == 0x4000) break;
    iVar5 = iVar5 + 1;
  }
  FUN_2110_01b8();
  if (*(char *)0xef34 == '\x01') {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)();
  }
  FUN_1bfc_0000();
  *(undefined1 *)0xef1c = 0;
  *(undefined1 *)0xef1d = 1;
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_122e();
  FUN_219e_1173();
  FUN_219e_0277();
  FUN_219e_1126();
  FUN_219e_0277();
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  iVar5 = 1;
  while( true ) {
    FUN_219e_0285();
    uVar2 = FUN_219e_0285();
    puVar4 = (undefined1 *)FUN_219e_0285();
    *puVar4 = uVar2;
    if (iVar5 == 0x4000) break;
    iVar5 = iVar5 + 1;
  }
  FUN_1bfc_0000();
  *(undefined1 *)0xef1c = 0;
  *(undefined1 *)0xef1d = 0;
  return;
}


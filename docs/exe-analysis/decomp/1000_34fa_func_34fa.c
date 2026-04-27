// 1000:34fa (func_34fa)  size=492


undefined2 FUN_1000_34fa(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar3;
  undefined1 local_104 [254];
  undefined2 uStack_6;
  undefined2 local_4;
  
  local_4 = 0x1000;
  uStack_6 = 0x3505;
  FUN_219e_02ad();
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_152c(1);
  FUN_1c14_0e50(2,0);
  FUN_1c14_1603(0x348f,0x1c14,0x8c,2);
  FUN_1c14_1603(0x34a6,0x1c14,0x96,2);
  FUN_1c14_1603(0x34b4,0x1c14,0xa0,2);
  if (*(char *)0x11d3 == '\x02') {
    FUN_1c14_1603(0x34c0,0x1c14,0xaa,2);
  }
  FUN_1c14_1603(0x34ce,0x1c14,0xb4,2);
  FUN_1c14_1603(0x34de,0x1c14,0xbe,2);
  do {
    FUN_2110_0357();
    uVar1 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar1;
    if ((*(char *)0x11d3 != '\x02') && (*(char *)0x11c8 == '3')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
  } while ((((*(char *)0x11c8 != '1') && (*(char *)0x11c8 != '2')) && (*(char *)0x11c8 != '3')) &&
          (*(char *)0x11c8 != '4'));
  cVar2 = FUN_219e_0285();
  if (cVar2 == '1') {
    local_4 = 1;
  }
  else if (cVar2 == '2') {
    local_4 = 2;
  }
  else if (cVar2 == '3') {
    local_4 = 3;
  }
  else if (cVar2 == '4') {
    local_4 = 4;
  }
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_152c(0);
  FUN_1c14_0e50(2,0);
  FUN_1c14_1603(0x348f,0x1c14,0x8c,2);
  FUN_1c14_1603(0x34a6,0x1c14,0x96,2);
  FUN_1c14_1603(0x34b4,0x1c14,0xa0,2);
  if (*(char *)0x11d3 == '\x02') {
    FUN_1c14_1603(0x34c0,0x1c14,0xaa,2);
  }
  FUN_1c14_1603(0x34ce,0x1c14,0xb4,2);
  FUN_1c14_1603(0x34de,0x1c14,0xbe,2);
  puVar3 = local_104;
  FUN_219e_0693(param_1 + -0x131,unaff_SS);
  FUN_219e_0720(0x34f4,0x219e);
  FUN_1b5b_01ba(puVar3,unaff_SS);
  FUN_1000_3316(param_1);
  return local_4;
}


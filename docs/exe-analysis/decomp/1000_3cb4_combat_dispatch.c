// Decompiled from 1000:3cb4 (combat_dispatch)
// Function size: 768 bytes


undefined2 FUN_1000_3cb4(int param_1)

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
  uStack_6 = 0x3cbf;
  FUN_219e_02ad();
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_152c(1);
  FUN_1c14_0e50(2,0);
  FUN_1c14_1603(0x3c24,0x1c14,100,2);
  if (*(char *)0x11f2 != '\0') {
    FUN_1c14_1603(0x3c3b,0x1c14,0x6e,2);
  }
  if (*(char *)0x11f3 != '\0') {
    FUN_1c14_1603(0x3c4d,0x1c14,0x78,2);
  }
  if (*(char *)0x11f4 != '\0') {
    FUN_1c14_1603(0x3c5b,0x1c14,0x82,2);
  }
  if (*(char *)0x11f5 != '\0') {
    FUN_1c14_1603(0x3c6c,0x1c14,0x8c,2);
  }
  if (*(char *)0x11f6 != '\0') {
    FUN_1c14_1603(0x3c7b,0x1c14,0x96,2);
  }
  if (*(char *)0x11f7 != '\0') {
    FUN_1c14_1603(0x3c87,0x1c14,0xa0,2);
  }
  FUN_1c14_1603(0x3c98,0x1c14,0xaa,2);
  do {
    FUN_2110_0357();
    uVar1 = FUN_219e_0285();
    *(undefined1 *)0x11c8 = uVar1;
    if ((*(char *)0x11f2 == '\0') && (*(char *)0x11c8 == '1')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
    if ((*(char *)0x11f3 == '\0') && (*(char *)0x11c8 == '2')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
    if ((*(char *)0x11f4 == '\0') && (*(char *)0x11c8 == '3')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
    if ((*(char *)0x11f5 == '\0') && (*(char *)0x11c8 == '4')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
    if ((*(char *)0x11f6 == '\0') && (*(char *)0x11c8 == '5')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
    if ((*(char *)0x11f7 == '\0') && (*(char *)0x11c8 == '6')) {
      *(undefined1 *)0x11c8 = 0x78;
    }
  } while ((((*(char *)0x11c8 != '1') && (*(char *)0x11c8 != '2')) && (*(char *)0x11c8 != '3')) &&
          (((*(char *)0x11c8 != '4' && (*(char *)0x11c8 != '5')) && (*(char *)0x11c8 != '6'))));
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
  else if (cVar2 == '5') {
    local_4 = 5;
  }
  else if (cVar2 == '6') {
    local_4 = 6;
  }
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_152c(0);
  FUN_1c14_0e50(2,0);
  FUN_1c14_1603(0x3c24,0x1c14,100,2);
  if (*(char *)0x11f2 != '\0') {
    FUN_1c14_1603(0x3c3b,0x1c14,0x6e,2);
  }
  if (*(char *)0x11f3 != '\0') {
    FUN_1c14_1603(0x3c4d,0x1c14,0x78,2);
  }
  if (*(char *)0x11f4 != '\0') {
    FUN_1c14_1603(0x3c5b,0x1c14,0x82,2);
  }
  if (*(char *)0x11f5 != '\0') {
    FUN_1c14_1603(0x3c6c,0x1c14,0x8c,2);
  }
  if (*(char *)0x11f6 != '\0') {
    FUN_1c14_1603(0x3c7b,0x1c14,0x96,2);
  }
  if (*(char *)0x11f7 != '\0') {
    FUN_1c14_1603(0x3c87,0x1c14,0xa0,2);
  }
  FUN_1c14_1603(0x3c98,0x1c14,0xaa,2);
  puVar3 = local_104;
  FUN_219e_0693(param_1 + -0x131,unaff_SS);
  FUN_219e_0720(0x3cae,0x219e);
  FUN_1b5b_01ba(puVar3,unaff_SS);
  FUN_1000_3316(param_1);
  return local_4;
}


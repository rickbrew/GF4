// 1000:3749 (func_3749)  size=618


undefined2 FUN_1000_3749(int param_1)

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
  uStack_6 = 0x3754;
  FUN_219e_02ad();
  FUN_1c14_0e94(4,0,2);
  FUN_1c14_152c(3);
  FUN_1c14_0e50(2,0);
  FUN_1c14_1603(0x36e6,0x1c14,0x96,2);
  if (*(char *)0x11ee != '\0') {
    FUN_1c14_1603(0x36fe,0x1c14,0xa0,2);
  }
  if (*(char *)0x11ec != '\0') {
    FUN_1c14_1603(0x3707,0x1c14,0xaa,2);
  }
  if (*(char *)0x11ed != '\0') {
    FUN_1c14_1603(0x3710,0x1c14,0xb4,2);
  }
  if (((*(char *)0x11ee == '\0') && (*(char *)0x11ec == '\0')) && (*(char *)0x11ed == '\0')) {
    FUN_1c14_1603(0x3718,0x1c14,0xaa,2);
    FUN_2110_0311(0x1b8);
    FUN_2110_02e9(0xfa);
    FUN_2110_033e();
    FUN_1c14_152c(0);
    FUN_1c14_1603(0x3718,0x1c14,0xaa,2);
    local_4 = 0;
    FUN_1c14_1603(0x36e6,0x1c14,0x96,2);
  }
  else {
    FUN_1c14_1603(0x372d,0x1c14,0xbe,2);
    do {
      FUN_2110_0357();
      uVar1 = FUN_219e_0285();
      *(undefined1 *)0x11c8 = uVar1;
      if ((*(char *)0x11c8 == '1') && (*(char *)0x11ee == '\0')) {
        *(undefined1 *)0x11c8 = 0x78;
      }
      if ((*(char *)0x11c8 == '2') && (*(char *)0x11ec == '\0')) {
        *(undefined1 *)0x11c8 = 0x78;
      }
      if ((*(char *)0x11c8 == '3') && (*(char *)0x11ed == '\0')) {
        *(undefined1 *)0x11c8 = 0x78;
      }
    } while (((*(char *)0x11c8 != '1') && (*(char *)0x11c8 != '2')) && (*(char *)0x11c8 != '3'));
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
    FUN_1c14_0e94(4,0,2);
    FUN_1c14_152c(0);
    FUN_1c14_0e50(2,0);
    FUN_1c14_1603(0x36e6,0x1c14,0x96,2);
    if (*(char *)0x11ee != '\0') {
      FUN_1c14_1603(0x36fe,0x1c14,0xa0,2);
    }
    if (*(char *)0x11ec != '\0') {
      FUN_1c14_1603(0x3707,0x1c14,0xaa,2);
    }
    if (*(char *)0x11ed != '\0') {
      FUN_1c14_1603(0x3710,0x1c14,0xb4,2);
    }
    FUN_1c14_1603(0x372d,0x1c14,0xbe,2);
    puVar3 = local_104;
    FUN_219e_0693(param_1 + -0x131,unaff_SS);
    FUN_219e_0720(0x3743,0x219e);
    FUN_1b5b_01ba(puVar3,unaff_SS);
    FUN_1000_3316(param_1);
  }
  return local_4;
}


// Decompiled from 1000:2625 (spell_fiery)
// Function size: 2517 bytes


void FUN_1000_2625(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar6;
  int local_a;
  uint local_8;
  uint local_6;
  
  FUN_219e_02ad();
  FUN_1b5b_0000(0x25a9,0x219e);
  uVar5 = 0x219e;
  iVar1 = FUN_219e_0285();
  if (iVar1 == 1) {
    FUN_219e_0b99(6);
    uVar2 = FUN_219e_0285();
    if (((int)uVar2 >> 0xf < 1) &&
       (((int)uVar2 < 0 && (int)uVar2 >> 0xf < 1 || (uVar2 <= *(uint *)0x11e4)))) {
      FUN_1b5b_0000(0x25a9,0x219e);
      FUN_1b5b_0248(0x25de,0x1b5b);
      local_8 = 5000;
      while( true ) {
        uVar2 = FUN_219e_0285();
        if (uVar2 < 0x8000) {
          local_6 = 0;
          while( true ) {
            uVar5 = FUN_219e_0285();
            FUN_219e_0b99(uVar5);
            uVar5 = FUN_219e_0285();
            FUN_2110_0311(uVar5);
            if (local_6 == uVar2) break;
            local_6 = local_6 + 1;
          }
        }
        if (local_8 == 0) break;
        local_8 = local_8 + -1;
      }
      FUN_2110_033e();
      FUN_1b5b_01ba(0x25a9,0x2110);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
    else {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
  }
  else if (iVar1 == 2) {
    FUN_219e_0b99(5);
    uVar2 = FUN_219e_0285();
    if (((int)uVar2 >> 0xf < 1) &&
       (((int)uVar2 < 0 && (int)uVar2 >> 0xf < 1 || (uVar2 <= *(uint *)0x11e4)))) {
      FUN_1b5b_0000(0x25a9,0x219e);
      FUN_1b5b_0248(0x25f3,0x1b5b);
      if (*(char *)0x42d == '\0') {
        uVar5 = 0x1f6f;
        FUN_1f6f_02b7(0x14);
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25fd,0x1b5b);
      }
      FUN_1b5b_01ba(0x25a9,uVar5);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
    else {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
  }
  else if (iVar1 == 3) {
    FUN_219e_0b99(3);
    uVar2 = FUN_219e_0285();
    iVar1 = (int)uVar2 >> 0xf;
    if ((iVar1 < 1) && (((int)uVar2 < 0 && iVar1 < 1 || (uVar2 <= *(uint *)0x11e4)))) {
      FUN_1b5b_0000(0x25a9,0x219e);
      FUN_1b5b_0248(0x2606,0x1b5b);
      uVar2 = FUN_219e_0285();
      if (uVar2 < 0x8000) {
        local_8 = 0;
        while( true ) {
          FUN_219e_0b99(500);
          FUN_219e_0b99(0x5dc);
          uVar5 = FUN_219e_0285();
          FUN_2110_0311(uVar5);
          iVar4 = (int)local_8 >> 0xf;
          FUN_219e_0b73();
          uVar6 = 1;
          uVar5 = FUN_219e_0b65();
          FUN_219e_0b73(uVar5,iVar1,iVar4);
          FUN_219e_0b6f();
          if ((bool)uVar6) {
            FUN_2110_033e();
          }
          if (local_8 == uVar2) break;
          local_8 = local_8 + 1;
        }
      }
      FUN_2110_033e();
      FUN_1b5b_01ba(0x25a9,0x2110);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
    else {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
  }
  else if (iVar1 == 4) {
    FUN_219e_0b99(3);
    uVar2 = FUN_219e_0285();
    if (((int)uVar2 >> 0xf < 1) &&
       (((int)uVar2 < 0 && (int)uVar2 >> 0xf < 1 || (uVar2 <= *(uint *)0x11e4)))) {
      if (*(char *)0x42d == '\0') {
        local_8 = 0;
        while( true ) {
          local_6 = 0x1f9;
          while( true ) {
            iVar1 = FUN_219e_0285();
            if (0 < iVar1) {
              local_a = 1;
              while( true ) {
                uVar5 = FUN_219e_0285();
                FUN_2110_0311(uVar5);
                if (local_a == iVar1) break;
                local_a = local_a + 1;
              }
            }
            if (local_6 == 0x9c4) break;
            local_6 = local_6 + 1;
          }
          local_6 = 0x9c4;
          while( true ) {
            iVar1 = FUN_219e_0285();
            if (0 < iVar1) {
              local_a = 1;
              while( true ) {
                uVar5 = FUN_219e_0285();
                FUN_2110_0311(uVar5);
                if (local_a == iVar1) break;
                local_a = local_a + 1;
              }
            }
            if (local_6 == 500) break;
            local_6 = local_6 + -1;
          }
          if (local_8 == 3) break;
          local_8 = local_8 + 1;
        }
      }
      else {
        FUN_20e5_01e1(0x2613,0x219e);
      }
      FUN_2110_033e();
      FUN_1b5b_01ba(0x25a9,0x2110);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
    else {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
  }
  else if (iVar1 == 5) {
    if (*(int *)0x11e4 == 0) {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
    else {
      if (*(char *)0x42d == '\0') {
        uVar5 = 0x1f6f;
        FUN_1f6f_02b7(5);
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x261c,0x219e);
      }
      FUN_1b5b_01ba(0x25a9,uVar5);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
  }
  else if (iVar1 == 6) {
    FUN_219e_0b99(3);
    uVar2 = FUN_219e_0285();
    if (((int)uVar2 >> 0xf < 1) &&
       (((int)uVar2 < 0 && (int)uVar2 >> 0xf < 1 || (uVar2 <= *(uint *)0x11e4)))) {
      local_8 = 0;
      while( true ) {
        iVar1 = FUN_219e_0285();
        if (0 < iVar1) {
          local_6 = 1;
          while( true ) {
            uVar5 = FUN_219e_0285();
            FUN_219e_0b99(uVar5);
            uVar5 = FUN_219e_0285();
            FUN_2110_0311(uVar5);
            if (local_6 == iVar1) break;
            local_6 = local_6 + 1;
          }
        }
        if (local_8 == 0x1d4c) break;
        local_8 = local_8 + 1;
      }
      local_8 = 0;
      while( true ) {
        iVar1 = FUN_219e_0285();
        if (0 < iVar1) {
          local_6 = 1;
          while( true ) {
            FUN_219e_0b99(15000);
            uVar5 = FUN_219e_0285();
            FUN_2110_0311(uVar5);
            if (local_6 == iVar1) break;
            local_6 = local_6 + 1;
          }
        }
        if (local_8 == 5000) break;
        local_8 = local_8 + 1;
      }
      local_8 = 0x1d4c;
      while( true ) {
        iVar1 = FUN_219e_0285();
        if (0 < iVar1) {
          local_6 = 1;
          while( true ) {
            uVar5 = FUN_219e_0285();
            FUN_219e_0b99(uVar5);
            uVar5 = FUN_219e_0285();
            FUN_2110_0311(uVar5);
            if (local_6 == iVar1) break;
            local_6 = local_6 + 1;
          }
        }
        if (local_8 == 0) break;
        local_8 = local_8 + -1;
      }
      FUN_2110_033e();
      FUN_1b5b_01ba(0x25a9,0x2110);
      uVar5 = FUN_219e_0285();
      *(undefined2 *)0x11e4 = uVar5;
      uVar5 = FUN_219e_0285();
      *(undefined2 *)(param_1 + -0x1b) = uVar5;
      FUN_219e_0b73();
      FUN_219e_0b65();
      FUN_219e_0b7f();
      uVar5 = 0x219e;
      uVar3 = FUN_219e_0285();
      *(undefined2 *)0x11e6 = uVar3;
    }
    else {
      FUN_1c14_0e94(4,0,2);
      FUN_1c14_0e50(1,1);
      FUN_1c14_152c(2);
      FUN_1c14_1603(0x25ba,0x1c14,0xc1,0x9f);
      if (*(char *)0x42d == '\0') {
        FUN_2110_0311(0x1b8);
        FUN_2110_02e9(0xfa);
        uVar5 = 0x2110;
        FUN_2110_033e();
      }
      else {
        uVar5 = 0x20e5;
        FUN_20e5_01e1(0x25d3,0x1c14);
      }
    }
  }
  FUN_1b5b_01ba(0x25a9,uVar5);
  if ((*(int *)(param_1 + -0x1b) < 1) || (*(int *)0x11d4 < 1)) {
    *(undefined1 *)(param_1 + -0x232) = 1;
  }
  return;
}


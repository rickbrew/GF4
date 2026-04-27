// Decompiled from 1000:76f9 (main_game_loop)
// Function size: 6330 bytes


void FUN_1000_76f9(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  int local_6;
  int local_4;
  
  FUN_219e_02ad();
  FUN_219e_0c1f();
  FUN_1b5b_0387();
  FUN_2110_02e9(0x5dc);
  FUN_1c14_152c(3);
  FUN_1c14_0e94(1,0,0);
  FUN_1c14_0e50(1,1);
  FUN_1c14_1603(0x76c8,0x1c14,99,0x9f);
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    *(undefined2 *)0x11cd = 1;
    while( true ) {
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
      *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 0;
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
      *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 3;
      if (*(int *)0x11cd == 100) break;
      *(int *)0x11cd = *(int *)0x11cd + 1;
    }
    if (*(int *)0x11cb == 100) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cd = 2;
  while( true ) {
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x11f9) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1325) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1451) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x157d) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x16a9) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x17d5) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1901) = 7;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1a2d) = 6;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1b59) = 5;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7a03) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7b2f) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7c5b) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7d87) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7eb3) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + -0x7fdf) = 8;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7ef5) = 7;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7dc9) = 6;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7c9d) = 5;
    if (*(int *)0x11cd == 99) break;
    *(int *)0x11cd = *(int *)0x11cd + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    FUN_219e_0b99(0x46);
    uVar3 = FUN_219e_0285();
    FUN_219e_0b99(0x46);
    uVar4 = FUN_219e_0285(uVar3);
    iVar1 = FUN_219e_0285(uVar3,uVar4);
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 5;
    if (*(int *)0x11cb == 0x19) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10d0) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10d3) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10d6) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10d9) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10dc) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10df) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10e2) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10e5) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10e8) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11f9) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11f6) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11f3) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11f0) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11ed) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11ea) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11e7) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11e4) = 1;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11e1) = 1;
    if (*(int *)0x11cb == 100) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cd = 10;
  while( true ) {
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1c85) = 2;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1db1) = 2;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x1edd) = 2;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7b71) = 2;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7a45) = 2;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 3 + 0x7919) = 2;
    if (*(int *)0x11cd == 0x5b) break;
    *(int *)0x11cd = *(int *)0x11cd + 1;
  }
  *(undefined2 *)0x11cd = 1;
  while( true ) {
    FUN_219e_0b99(0x46);
    uVar3 = FUN_219e_0285(uVar3,uVar4);
    FUN_219e_0b99(0x46);
    uVar4 = FUN_219e_0285();
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 2;
    if (*(int *)0x11cd == 0x19) break;
    *(int *)0x11cd = *(int *)0x11cd + 1;
  }
  *(undefined2 *)0x11cb = 10;
  while( true ) {
    iVar1 = FUN_219e_0285(uVar3,uVar4);
    *(undefined1 *)(iVar1 * 300 + 0x10eb) = 4;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10ee) = 4;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x10f1) = 4;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11de) = 4;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11db) = 4;
    iVar1 = FUN_219e_0285();
    *(undefined1 *)(iVar1 * 300 + 0x11d8) = 4;
    if (*(int *)0x11cb == 0x5b) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cd = 1;
  while( true ) {
    FUN_219e_0b99(0x46);
    uVar3 = FUN_219e_0285();
    FUN_219e_0b99(0x46);
    uVar4 = FUN_219e_0285(uVar3);
    local_6 = -3;
    while( true ) {
      local_4 = -3;
      while( true ) {
        iVar1 = FUN_219e_0285(uVar3,uVar4);
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
        *(undefined1 *)(iVar2 * 300 + iVar1 + 0x10cd) = 4;
        if (local_4 == 3) break;
        local_4 = local_4 + 1;
      }
      if (local_6 == 3) break;
      local_6 = local_6 + 1;
    }
    if (*(int *)0x11cd == 0x1e) break;
    *(int *)0x11cd = *(int *)0x11cd + 1;
  }
  *(undefined2 *)0x11cd = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              FUN_219e_0b99(0x46);
              uVar3 = FUN_219e_0285(uVar3,uVar4);
              FUN_219e_0b99(0x46);
              uVar4 = FUN_219e_0285();
              iVar1 = FUN_219e_0285();
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
          iVar1 = FUN_219e_0285(uVar3,uVar4);
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 9;
    if (*(int *)0x11cd == 0xf) break;
    *(int *)0x11cd = *(int *)0x11cd + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 1;
    if (*(int *)0x11cb == 0xaf) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 2;
    if (*(int *)0x11cb == 0x6e) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 3;
    if (*(int *)0x11cb == 0x4b) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 4;
    if (*(int *)0x11cb == 100) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 5;
    if (*(int *)0x11cb == 100) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 6;
    if (*(int *)0x11cb == 100) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 7;
    if (*(int *)0x11cb == 0x32) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 10;
    if (*(int *)0x11cb == 10) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  *(undefined2 *)0x11cb = 1;
  while( true ) {
    do {
      do {
        do {
          do {
            do {
              do {
                FUN_219e_0b99(0x46);
                uVar3 = FUN_219e_0285(uVar3,uVar4);
                FUN_219e_0b99(0x46);
                uVar4 = FUN_219e_0285();
                iVar1 = FUN_219e_0285();
                iVar1 = iVar1 * 3;
                iVar2 = FUN_219e_0285();
              } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x05');
              iVar1 = FUN_219e_0285(uVar3,uVar4);
              iVar1 = iVar1 * 3;
              iVar2 = FUN_219e_0285();
            } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x06');
            iVar1 = FUN_219e_0285(uVar3,uVar4);
            iVar1 = iVar1 * 3;
            iVar2 = FUN_219e_0285();
          } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\a');
          iVar1 = FUN_219e_0285();
          iVar1 = iVar1 * 3;
          iVar2 = FUN_219e_0285();
        } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\b');
        iVar1 = FUN_219e_0285();
        iVar1 = iVar1 * 3;
        iVar2 = FUN_219e_0285();
      } while (*(char *)(iVar2 * 300 + iVar1 + 0x10cd) == '\x01');
      iVar1 = FUN_219e_0285();
      iVar1 = iVar1 * 3;
      iVar2 = FUN_219e_0285();
    } while (*(int *)(iVar2 * 300 + iVar1 + 0x10ce) != 0);
    iVar1 = FUN_219e_0285();
    iVar1 = iVar1 * 3;
    iVar2 = FUN_219e_0285();
    *(undefined2 *)(iVar2 * 300 + iVar1 + 0x10ce) = 8;
    if (*(int *)0x11cb == 1) break;
    *(int *)0x11cb = *(int *)0x11cb + 1;
  }
  FUN_1b5b_0387();
  FUN_1bfc_0000();
  return;
}


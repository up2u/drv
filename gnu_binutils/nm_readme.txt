See the type of symbols

[sand@universe gnu_binutils]$ gcc nm_test.c -o nm_test.exe
[sand@universe gnu_binutils]$ nm -n nm_test.exe 
         w _Jv_RegisterClasses
         w __gmon_start__
         U __libc_start_main@@GLIBC_2.0
         U time@@GLIBC_2.0
08048290 T _init
08048300 T _start
08048330 t __do_global_dtors_aux
08048390 t frame_dummy
080483b4 T foo                            !! T
080483c8 t bar  			  !! t
080483cd T main 			  !! T
080483f0 T __libc_csu_init
08048450 T __libc_csu_fini
08048455 T __i686.get_pc_thunk.bx
08048460 t __do_global_ctors_aux
0804848c T _fini
080484a8 R _fp_hw
080484ac R _IO_stdin_used
080484b0 R __dso_handle
08048550 r __FRAME_END__
08049554 d __CTOR_LIST__
08049554 d __init_array_end
08049554 d __init_array_start
08049558 d __CTOR_END__
0804955c d __DTOR_LIST__
08049560 D __DTOR_END__
08049564 d __JCR_END__
08049564 d __JCR_LIST__
08049568 d _DYNAMIC
08049634 d _GLOBAL_OFFSET_TABLE_
0804964c D __data_start
0804964c W data_start
08049650 D global2	                     !! D
08049654 d static_global1		     !! d
08049658 d static_global2              	     !! d
0804965c A __bss_start
0804965c A _edata
0804965c b completed.5530
08049660 b dtor_idx.5532
08049664 b internal2.1676		     !! b
08049668 b internal1.1675              	     !! b
0804966c B global1                     	     !! B
08049670 A _end
[sand@universe gnu_binutils]$

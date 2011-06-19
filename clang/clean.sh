#! /bin/bash

#clean dirty

find . -name "*~" 		| xargs rm  2>/dev/null
find . -name "*.swp" 	| xargs rm  2>/dev/null
find . -name "*.o" 		| xargs rm  2>/dev/null
find . -name "a.out" 	| xargs rm  2>/dev/null
find . -name "*.elf" 	| xargs rm  2>/dev/null

exit $?

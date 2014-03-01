So.
We have some bash files: build.sh, clean.sh, cptom.sh, create.sh and run.sh.

	build.sh file1 file2 file3 ...
Compile files file1.c, file2.c, file3.c etc. Output -- file1.o, file2.o, file3.o and file1.app. file1.app is the application for BareMetal.

	clean.sh file1 file2 ...
Removing file1.o, file1.app, file2.o etc.

	cptom.sh file1
Copying file1.app to BareMetal/bin directory and write it to BareMetal disk image.

	create.sh file1
Creating files file1.c and file1.cpp with some template.

	run.sh file1 file2 file3 ...
Executing for files file1.cpp, file2.cpp, etc build.sh, cptom.sh and clean.sh

Enjoy!

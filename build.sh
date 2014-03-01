:
if [ $# -lt 1 ]
then
echo "Too few parameters..."
exit
fi

file=$1
obj_output=""
for file in $@
do
if [ -e ${file}.c ]
then
gcc -std=c99 -Wall -o0 -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o ${file}.o ${file}.c
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
gcc -std=c99 -Wall -o0 -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o lexisLib.o lexisLib.c
obj_output+="${file}.o "
if [ ! -e ${file}.o ]
then
echo "Build  failed!"
exit
fi
else
echo "File ${file}.c NOT exist! Aborting..."
exit
fi

ld -T app.ld -o $1.app $obj_output libBareMetal.o lexisLib.o
done

#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o helloc.o helloc.c
#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
#ld -T app.ld -o helloc.app helloc.o libBareMetal.o

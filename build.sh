:
file=$1
obj_output=""
for file in $@
do
if [ -e ${file}.c ]
then
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o ${file}.o ${file}.c
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
obj_output+=${file}.o
else
echo "File ${file}.c NOT exist! Aborting..."
exit
fi
ld -T app.ld -o $1.app $obj_output libBareMetal.o
done

#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o helloc.o helloc.c
#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
#ld -T app.ld -o helloc.app helloc.o libBareMetal.o

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
if [ -e ${file}.o ]
then
rm ${file}.o
fi
done
rm $1.app
echo "Cleaning done!"

#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o helloc.o helloc.c
#gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
#ld -T app.ld -o helloc.app helloc.o libBareMetal.o

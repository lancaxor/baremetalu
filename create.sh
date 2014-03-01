echo "#include \"${1}.h\"" >> $1.c
echo "int main(int argc,char*argv[]){" >> $1.c
echo "">>$1.c
echo "return 0;}" >> ${1}.c

echo "#include \"libBareMetal.h\"" >> ${1}.h
echo "#include \"lexisLib.h\"" >> $1.h

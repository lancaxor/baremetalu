if [ $# -lt 1 ]
then
echo "Too few parameters..."
exit
fi

if [ ! -e ${1}.app ]
then
echo "File $1.app NOT created!"
exit
fi

cp $1.app ../bin
cd ../bin
./bmfs bmfs.image create ${1}.app 1
./bmfs bmfs.image write ${1}.app

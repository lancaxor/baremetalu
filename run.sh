if [ $# -lt 1 ]
then
echo "Too few parameters..."
exit
fi
./build.sh $*
if [ ! -e ${1}.app ]
then
exit
fi
./cptom.sh $1
./clean.sh $*
cd ../bin
rm $1.app
cd -
echo "Done!"

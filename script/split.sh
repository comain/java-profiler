#/bin/sh
while read line
do
    echo $line | grep -q 'dumpTime'
    if [ $? -eq 0 ]
    then
        F=`echo $line | cut -d ' ' -f 3`
    else
        echo $line >> ${F}.txt
    fi
done

#!/bin/sh

set -e
set -u

if [ $# -lt 2 ]
then
    echo "Required arguments not provided"
    exit 1
fi

writeFile=$1 #path to assignment directory
writeStr=$2 #search string to check within the files
dirname1=`dirname ${writeFile}`
if [ ! -d dirname1 ]; then
    mkdir -p $dirname1
fi

`echo "$writeStr" > ${writeFile}`

if [ ! -f ${writeFile} ]
then
    echo "File path does not exist"
    exit 1
fi

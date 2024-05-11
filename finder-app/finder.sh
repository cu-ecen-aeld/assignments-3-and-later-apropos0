#!/bin/sh

set -e

if [ $# -lt 2 ]
then
    echo "Required arguments not provided"
    exit 1
fi

filesdir=$1 #path to assignment directory
searchstr=$2 #search string to check within the files

if [ ! -d ${filesdir} ]
then
    echo "${filesdir}"
    echo "File path does not exist"
    exit 1
fi

countStr=`grep -R -s "${searchstr}" ${filesdir} | wc -l`
countFile=`ls ${filesdir} -1 | wc -l`
echo "The number of files are ${countFile} and the number of matching lines are ${countStr}" 
#!/usr/local/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then 
    echo "Requires three args: class code, ass number, ass name."
fi

if ls ${1^^}*.tex
    then 
        latexmk -pdf -outdir="${1^}" -jobname="Sckans_Fall2020_${1^}_Assignment${2}_${3}" ${1^^}*.tex
        latexmk -c -outdir="${1^}" -jobname="Sckans_Fall2020_${1^}_Assignment${2}_${3}" ${1^^}*.tex
    else
        echo "You typed the class code incorrectly."
fi
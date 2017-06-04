#!/bin/bash
# checkout darkside from github 
curpath=$(PWD)
cd ../../ 
par=$(PWD)
if [[ -d "$par/ZLTCPTransfer" ]]; then 
        cd ZLTCPTransfer
        git pull origin develop
else
        git clone git@github.com:ZQYA/ZLTCPTransfer.git --branch develop
fi 

# make output files
cd $(curpath)
make clean
make receiver
make clean
make sender SD=1

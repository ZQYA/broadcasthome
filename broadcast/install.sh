#!/bin/bash
# checkout darkside from github 
curpath=$(PWD)
cd ../../ 
par=$(PWD)
pull_remote() {
reponame=$1
if [[ -d "$par/$reponame" ]]; then 
        cd $par/$reponame 
        git pull origin develop
else
        git clone git@github.com:ZQYA/"$reponame".git --branch develop
fi 
}
pull_remote "ZLTCPTransfer"
pull_remote "MMTP"
# make output files
cd $curpath
make clean
make receiver
make clean
make sender SD=1

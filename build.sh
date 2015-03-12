#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
CMAKEOPTS=

if [ "$1" != "" ]; then
	CMAKEOPTS="-G $1"
fi

mkdir -p $DIR/build
cd $DIR/build
cmake $CMAKEOPTS ..
#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

if [[ ! -e $DIR/webradio.pid ]]; then
    echo Not running
    exit
fi

WEBRADIOPID=`cat $DIR/webradio.pid`
rm $DIR/webradio.pid

echo Stopping WebRadio [ PID = $WEBRADIOPID ]
kill $WEBRADIOPID


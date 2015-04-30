#!/bin/bash

if [[ ! -e webradio.pid ]]; then
    echo Not running
    exit
fi

WEBRADIOPID=`cat webradio.pid`
rm webradio.pid

echo Stopping WebRadio [ PID = $WEBRADIOPID ]
kill $WEBRADIOPID


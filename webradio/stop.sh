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

GSTREAMERPID=`cat $DIR/gstreamer.pid`
rm $DIR/gstreamer.pid

echo Waiting for GStreamer to starve [ PID = $GSTREAMERPID ]
while [[ `ps --no-headers $GSTREAMERPID` ]]; do
    sleep 1
done


#!/bin/bash

if [[ "$1" = "" ]]; then
    echo Using fifo = 977fifo
    FIFO_PATH=977fifo
else
    FIFO_PATH=$1
fi

if [[ ! -e $FIFO_PATH ]]; then
    mkfifo $FIFO_PATH
fi

if [[ ! -p $FIFO_PATH ]]; then
    echo $FIFO_PATH is not a valid FIFO
    exit
fi

if [[ ! -d logs ]]; then
    mkdir logs
fi

echo Making...
make >/dev/null

bin/webradio $FIFO_PATH >logs/webradio.log 2>&1 &
echo $! > webradio.pid
gst-launch filesrc location=$FIFO_PATH ! aacparse ! faad ! audioconvert ! alsasink >logs/gstreamer.log 2>&1 &

echo Started


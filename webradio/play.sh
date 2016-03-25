#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

if [[ "$1" = "" ]]; then
    echo Using fifo = 977fifo
    FIFO_PATH=$DIR/977fifo
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

if [[ ! -d $DIR/logs ]]; then
    mkdir $DIR/logs
fi

$DIR/webradio.out $FIFO_PATH >$DIR/logs/webradio.log 2>&1 &
echo $! > $DIR/webradio.pid
gst-launch-1.0 filesrc location=$FIFO_PATH ! aacparse ! faad ! audioconvert ! alsasink >logs/gstreamer.log 2>&1 &
echo $! > $DIR/gstreamer.pid

echo Started


Bearded Ninja
=============

## What is this place?

It's a collection of small programs that I've found interesting for my own personal education and interest. They are typically algorithms, or they set out to solve a task that proved non-trivial for some reason.

### Why the name?

Github chose it. :)

### I'm impatient!

#### CMake-based Projects
* Install CMake >= 3.1.3
* In the root, run `build.sh`
* If that works, run `cd build && make`
* Fix any errors that result from missing dependencies

#### Other Projects
Follow the build steps included with the project, or open the `.sln` file in Visual Studio. 

## Table of Contents

- BinarySearch - an implementation of a binary search function in F#, with a main function that runs it through some test data.
- countsort - an implementation of the count sort algorithm in C
- countsortcpp - an implementation of the count sort algorithm in C++, making as much use of rvalue/move semantics as possible
- fibonacci - a Fibonacci series generator as a C++ template
- webradio - an ICY stream reader that requests metadata, strips it out of the stream and logs it, and passes the remainder out to a FIFO, for use by a decoder/player like GStreamer



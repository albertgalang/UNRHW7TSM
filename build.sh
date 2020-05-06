#!/usr/bin/env bash

export CXX=$(which g++)

if [ -z "$testing" ]
then
    export CXX=g++-5
fi

cmake .
make
./App

#!/bin/bash

./generator --big-superposition > map_from_generator
./beautymapper_rust map_from_generator $1
./lem-in -paths -file map_from_generator-beautified-$1 > beautified
./visualizer_rust beautified 
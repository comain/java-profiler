#!/bin/sh
../script/stackcollapse.pl  trace.txt >merged.txt
../script/flamegraph.pl merged.txt > stack.svg

#!/bin/sh

ifconfig -a link | grep "ether" | cut -c 8- | rev | cut -c 2- | rev

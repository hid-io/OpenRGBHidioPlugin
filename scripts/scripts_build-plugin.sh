#!/bin/bash

#-----------------------------------------------------------------------#
# OpenRGB E1.31 Receiver Plugin Build Script                            #
#-----------------------------------------------------------------------#

#set -x
#set -e

source /opt/qt512/bin/qt512-env.sh

#-----------------------------------------------------------------------#
# Configure build files with qmake                                      #
# we need to explicitly set the install prefix, as qmake's default is   #
# /usr/local for some reason...                                         #
#-----------------------------------------------------------------------#
qmake .

#-----------------------------------------------------------------------#
# Build project and install files into AppDir                           #
#-----------------------------------------------------------------------#
make -j$(nproc)

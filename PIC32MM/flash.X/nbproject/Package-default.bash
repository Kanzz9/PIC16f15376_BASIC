#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_CONF=default
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${IMAGE_TYPE}/tmp-packaging
TMPDIRNAME=tmp-packaging
<<<<<<< HEAD:PIC32MM/flash.X/nbproject/Package-default.bash
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/flash.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=flash.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=flash.x/
=======
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/KX126_1063.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=KX126_1063.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=kx1261063.x/
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54:PIC32MM/KX126_1063.X/nbproject/Package-default.bash

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/package
rm -rf ${TMPDIR}
mkdir -p ${TMPDIR}

# Copy files and create directories and links
cd "${TOP}"
<<<<<<< HEAD:PIC32MM/flash.X/nbproject/Package-default.bash
makeDirectory ${TMPDIR}/flash.x/bin
=======
makeDirectory ${TMPDIR}/kx1261063.x/bin
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54:PIC32MM/KX126_1063.X/nbproject/Package-default.bash
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}bin/${OUTPUT_BASENAME}" 0755


# Generate tar file
cd "${TOP}"
<<<<<<< HEAD:PIC32MM/flash.X/nbproject/Package-default.bash
rm -f ${CND_DISTDIR}/${CND_CONF}/package/flash.x.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/flash.x.tar *
=======
rm -f ${CND_DISTDIR}/${CND_CONF}/package/kx1261063.x.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/kx1261063.x.tar *
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54:PIC32MM/KX126_1063.X/nbproject/Package-default.bash
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}

#!/usr/bin/env bash

# convert yuyv422 format image to JPEG

yuvfiles=`ls yuv-*.yuv`

for yuv in $yuvfiles
do
  echo "converting $yuv"
  jpegfile=`echo "$yuv" | sed 's/yuv/jpeg/g'`
  echo $jpegfile
  ffmpeg -s 640x480 -pix_fmt yuyv422 -i $yuv $jpegfile << EOF
y
EOF
done

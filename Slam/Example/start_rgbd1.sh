#!/bin/bash

seq_path=$1 #sequnce file of video
slam_path=$2 #slam file path
python associate.py $seq_path/rgb.txt $seq_path/depth.txt > $seq_path/associations1.txt
$slam_path/Examples/RGB-D/rgbd_tum $slam_path/Vocabulary/ORBvoc.txt $slam_path/Examples/RGB-D/TUM1.yaml $seq_path $seq_path/associations1.txt

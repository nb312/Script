#!/bin/bash
# install slam2 script https://github.com/raulmur/ORB_SLAM2
sudo apt-get install -y freeglut3-dev #installOpenGL
sudo apt-get install -y libglew-dev #
sudo apt-get install -y cmake #
sudo apt-get install -y libboost-dev libboost-thread-dev libboost-filesystem-dev #boost
sudo apt-get install -y libpython2.7-dev  python-numpy
sudo apt-get install -y g++
sudo apt-get install -y libopencv-dev #opencv
sudo apt-get install -y libeigen3-dev #eigen
sudo apt-get install -y libblas-dev #blas
sudo apt-get install -y liblapack-dev #lapack
sudo apt-get install -y git

cd ~
mkdir DeveloperTool
cd ~/DeveloperTool/ #come to the default file 
git clone https://github.com/stevenlovegrove/Pangolin.git
cd Pangolin
mkdir build
cd build
cmake -DCPP11_NO_BOOST=1 ..
make -j
#install the slam page from github
cd ~/DeveloperTool/ #come to the default file
git clone https://github.com/raulmur/ORB_SLAM2.git ORB_SLAM2
cd ORB_SLAM2
chmod +x build.sh
./build.sh

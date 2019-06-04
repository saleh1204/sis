# SIS 
Logic Synthesis System from University of California at Berkeley (Unofficial Distribution)

The original code was downloaded from the following [link](https://ptolemy.berkeley.edu/projects/embedded/Alumni/pchong/sis/)

***
This repository's objective is to compile the SIS tool using new versions of the compilers.

***
To install the precompiled version, head to [Releases Page](https://github.com/saleh1204/sis/releases) and download the package for your OS. Then, install the package using the following command for Debian Based Distros:
```
sudo dpkg -i sis_1.3.6.1_amd64.deb
```
Or this command for RedHat Based Distros
```
sudo rpm -i sis-1.3.6.1-2.x86_64.rpm
```


Dependencies for building from source (Debian Based Distros):
* libfl-dev
* flex 
* byacc 
* gcc
* autoconf
* automake
* make


***
To compile the source code, please run the following commands after installing all dependencies:

```
git clone https://github.com/saleh1204/sis.git
cd sis 
./configure --without-x
make 
sudo make install 

```


***

**_All Rights are reserved to University of California at Berkeley_**

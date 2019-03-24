# wxMP3gain
wxMP3gain is a free front-end for the MP3gain.

## Getting Started

### Install from binaries

Link to download the binary files: https://sourceforge.net/projects/wxmp3gain/

This program has been tested on the following platforms:
* Windows XP, Vista, 7, 8, 8.1
* Several major Linux distributions

### Install from Personal Package Archives (Ubuntu)

```sh
sudo add-apt-repository -y ppa:cfgnunes/ppa
sudo apt-get update
sudo apt-get -y install wxmp3gain
```
### Install from sources

This section assumes Ubuntu 14.04 (also tested on Ubuntu 16.04), but the procedure is similar for other Linux distributions. The prerequisites to build the source is to install the following packages:
```sh
sudo apt-get -y install build-essential cmake
sudo apt-get -y install libwxgtk3.0-dev
sudo apt-get -y install mp3gain
```

Compile the sources and install with following commands in the terminal:
```sh
mkdir build && cd build && cmake ..
make
sudo make install
```

### Generate Debian package for Linux systems
Install the prerequisites:
```sh
sudo apt-get -y install devscripts debhelper
```

Run the following command on source directory:
```sh
debuild -us -uc
```

## Built With

Code written completely in C++ using:
* [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
* [wxWidgets](https://www.wxwidgets.org/) - Open-Source GUI framework
* [wxFormBuilder](https://github.com/wxFormBuilder/) - wxWidgets GUI-builder

Other tools:
* [CMake](https://cmake.org/) - Build, test and package software
* [Inno Setup](http://www.jrsoftware.org/isinfo.php) - Installer for Windows programs
* [UPX](https://upx.github.io/) - The Ultimate Packer for eXecutables

## License

This program is licensed under the terms of the GNU General Public License version 3. Available online under:
http://www.gnu.org/licenses/gpl-3.0.html

## Acknowledgments

* Carlos Sánchez <carlos1994sanchez@gmail.com>
* Jan Rimmek <jan@rimmek.de>
* Pavel Fric <pavelfric@seznam.cz>
* Sergey Basalaev <sbasalaev@gmail.com>

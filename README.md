# wxMP3gain [![Actions Status](https://github.com/cfgnunes/wxmp3gain/workflows/build/badge.svg)](https://github.com/cfgnunes/wxmp3gain/actions)

wxMP3gain is a free front-end for the [MP3gain](https://mp3gain.sourceforge.net).

![screenshot](doc/screenshot.png)

## Getting Started

### Install from binaries

The pre-compiled binaries have been tested to work on the following platforms:

- Windows Vista, 7, 8, 10
- Ubuntu 16.04, 18.04, 20.04, 22.04
- Mint 20.2, 20.4

Link to download the pre-compiled binary files: <https://github.com/cfgnunes/wxmp3gain/releases>

On Linux, you can also install them via *Personal Package Archive (PPA)*:

```sh
sudo add-apt-repository -y ppa:cfgnunes/ppa
sudo apt-get update
sudo apt-get -y install wxmp3gain
```

### Install from sources

Alternatively to downloading the pre-compiled binaries, you can build the application using the source code.

#### Linux

This section assumes you are using Ubuntu 20.04 (Focal Fossa), but the procedure is similar for other Linux distributions.

The prerequisites to build the source is to install the following packages:

```sh
sudo apt-get -y install build-essential cmake gettext libwxgtk3.0-gtk3-dev mp3gain
```

Compile the sources and install the binaries, entering the following commands in the terminal:

```sh
mkdir build
cd build
cmake ..
cmake --build .
sudo make install
```

#### Windows

This section assumes Windows 10, but the procedure is similar for other Windows versions. The prerequisites to build the source is to install the following dependencies:

- [MinGW-W64 GCC-8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/i686-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) - i686-posix-sjlj
- [wxWidgets 3.1.3](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.3/wxWidgets-3.1.3-headers.7z) - header files ('include' folder)
- [wxWidgets 3.1.3](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.3/wxMSW-3.1.3_gcc810_Dev.7z) - development files for MinGW GCC 8.1.0 ('lib' folder)
- [Gettext](https://mlocati.github.io/articles/gettext-iconv-windows.html) - 32 bit, static
- [CMake](https://cmake.org/download/)

Compile the sources and install with following commands in the terminal:

```sh
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=dist ..
cmake --build . --tar
```

To create an installer on Windows, which is optional, the [Inno Setup](http://www.jrsoftware.org/isinfo.php) must to be downloaded and installed.
To generate the installer setup, use file `installer.iss` in the Inno Setup after build the binaries.

## Contributing

If you spot a bug, or want to improve the code, or even improve the content, you can do the following:

- [Open an issue](https://github.com/cfgnunes/wxmp3gain/issues/new) describing the bug or feature idea;
- Fork the project, make changes, and submit a pull request.

## Versioning

This project uses [SemVer](https://semver.org) for versioning. For the versions available, see the [tags on this repository](https://github.com/cfgnunes/wxmp3gain/tags).

## License

This program is licensed under the terms of the GNU General Public License version 3. Available online under:
<https://www.gnu.org/licenses/gpl-3.0.html>

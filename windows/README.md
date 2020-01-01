# wxMP3gain

## Windows packaging

This section assumes Windows 10, but the procedure is similar for other Windows versions. The prerequisites to build the source is to install the following applications:

### Install prerequisites

* [MinGW-W64 GCC-8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/i686-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) - i686-posix-sjlj
* [wxWidgets 3.1.3](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.3/wxWidgets-3.1.3-headers.7z) - header files ('include' folder)
* [wxWidgets 3.1.3](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.3/wxMSW-3.1.3_gcc810_Dev.7z) - development files for MinGW GCC 8.1.0 ('lib' folder)
* [Gettext](https://mlocati.github.io/articles/gettext-iconv-windows.html) - 32 bit, static
* [Inno Setup](http://www.jrsoftware.org/download.php/is.exe)

### Build the binaries

```sh
build-binaries.cmd
```

### Build the installer

To generate the installer setup, use file 'build-installer.iss' in the Inno Setup after build the binaries.

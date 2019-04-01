# wxMP3gain

## Windows packaging

This section assumes Windows XP (also tested on Windows 7), but the procedure is similar for other Windows versions. The prerequisites to build the source is to install the following applications:

### Install prerequisites

* [TDM-GCC 5.1.0-3](http://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/tdm-gcc-5.1.0-3.exe)
* [wxWidgets 3.1.2](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.2/wxWidgets-3.1.2-headers.7z) - header files for MinGW-TDM 5.10 ('include' folder).
* [wxWidgets 3.1.2](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.2/wxMSW-3.1.2_gcc510TDM_Dev.7z) - developtment files for MinGW-TDM 5.10 ('lib' folder).
* [Gettext 0.19.8.1](https://mlocati.github.io/articles/gettext-iconv-windows.html) - 32 bit, static.
* [Inno Setup 5.6.1](http://www.jrsoftware.org/download.php/is-unicode.exe) - unicode.

### Build the binaries

```sh
build-binaries.cmd
```

### Build the installer

To generate the installer setup, use file 'build-installer.iss' in the Inno Setup after build the binaries.

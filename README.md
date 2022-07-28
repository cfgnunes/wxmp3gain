# wxMP3gain [![Actions Status](https://github.com/cfgnunes/wxmp3gain/workflows/build/badge.svg)](https://github.com/cfgnunes/wxmp3gain/actions)

wxMP3gain is a free front-end for the [MP3gain](http://mp3gain.sourceforge.net).

![screenshot](doc/screenshot.png)

## Getting Started

### Install from binaries

The pre-compiled binaries have been tested to work on the following platforms:

- Windows XP, Vista, 7, 8, 10
- Ubuntu 16.04, 18.04, 20.04, 22.04
- Mint 20.2, 20.4

Link to download the pre-compiled binary files: <https://github.com/cfgnunes/wxmp3gain/releases>

On Linux, you can also install them via **Personal Package Archive (PPA)**:

```sh
sudo add-apt-repository -y ppa:cfgnunes/ppa
sudo apt update
sudo apt install wxmp3gain
```

### Install from sources

Alternatively to downloading the pre-compiled binaries, you can build the application using the source code.

#### Dependencies

The project depends on the following tools:

- [MP3gain](http://mp3gain.sourceforge.net) - Analyze and adjust mp3 files so that they have the same volume
- [CMake](https://cmake.org) - Build, test and package software
- [wxWidgets](http://wxwidgets.org) - Open-Source GUI framework
- [gettext](https://www.gnu.org/software/gettext) - Internationalization and localization (i18n and l10n) system

which you need to download and install before being able to build the project.

To create an installer on Windows, which is optional, the following dependency needs to be downloaded and installed:

- [Inno Setup](http://www.jrsoftware.org/isinfo.php) - Installer for Windows programs

#### Linux

On Linux the dependencies are best installed via your package manager, if available.

This section assumes you are using Ubuntu 20.04, but the procedure is similar for other Linux distributions.

The prerequisites to build the source is to install the following packages:

```sh
sudo apt -y install build-essential cmake
sudo apt -y install libwxgtk3.0-gtk3-dev
```

For old Linux distributions, the package `libwxgtk3.0-dev` (instead of `libwxgtk3.0-gtk3-dev`) needs to be installed.

The MP3gain executable can be not available in the distro repositories.
You can download the `.deb` file for Ubuntu 20.04 (Focal Fossa) though, as it works also for Ubuntu 22.04 (Jammy Jellyfish).

```sh
sudo apt -y install wget
wget https://launchpad.net/~cfgnunes/+archive/ubuntu/ppa/+files/mp3gain_1.6.2-2ubuntu0~ppa1_amd64.deb
sudo apt -y install ./mp3gain_1.6.2-2ubuntu0~ppa1_amd64.deb
```

Compile the sources and install the binaries, entering the following commands in the terminal:

```sh
mkdir build
cd build
cmake ..
cmake --build .
sudo make install
```

## Contributing

If you spot a bug, or want to improve the code, or even improve the content, you can do the following:

- [Open an issue](https://github.com/cfgnunes/wxmp3gain/issues/new) describing the bug or feature idea;
- Fork the project, make changes, and submit a pull request.

## Versioning

This project uses [SemVer](https://semver.org) for versioning. For the versions available, see the [tags on this repository](https://github.com/cfgnunes/wxmp3gain/tags).

## License

This program is licensed under the terms of the GNU General Public License version 3. Available online under:
<https://www.gnu.org/licenses/gpl-3.0.html>

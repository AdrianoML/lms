# LMS - Lightweight Media Server

LMS is a self-hosted media streaming software, released under the GPLv3 license.
It allows you to access your music and your videos using an https web interface.

## Features
 - Winamp-like interface, suited for large media collections
 - Audio/Video transcode for maximum interoperability and low bandwith requirements
 - User management
 - Multi genre
 - MusicBrainzID support

Please note LMS is still under development and will gain more features in the future:
 - Radio function (using AcousticBrainz)
 - Interface suited for mobile devices
 - Video support
 - Subsonic and/or Ampache API

LMS is written entirely in C++. Therefore, it is suitable to run on embedded devices, where space and memory are limited.
Please note some media files may require significant CPU usage to be transcoded.

## Dependencies
### Debian or Ubuntu packages

```sh
$ apt-get install g++ autoconf automake libboost-dev libboost-locale-dev libboost-iostreams-dev libavcodec-dev libwtdbosqlite-dev libwthttp-dev libwtdbo-dev libwt-dev libmagick++-dev libavcodec-dev libavformat-dev libav-tools libpstreams-dev
```

## Build

```sh
$ autoreconf -vfi
$ mkdir build
$ cd build
$ ../configure --prefix=/usr
```
configure will complain if a mandatory library is missing.

```sh
$ make -j 4
```

## Install

```sh
$ make install
```
This command requires root privileges

## Running
Here is a command line example to run on port 5081:
```sh
$ /usr/bin/lms --docroot='/usr/share/lms/docroot/;/resources,/css,/images,/favicon.ico' --approot=/usr/share/lms/approot --http-address 0.0.0.0 --http-port 5081
```
It is highly recommended to run LMS as a non root user.
The exectuable needs write accesses to the /var/lms/ directory.

To connect to LMS, just open your favorite browser and go to http://localhost:5081

## Mobile

Add the following code in your wt_config.xml file:
```
<application-settings location="/usr/bin/lms">
	<progressive-bootstrap>true</progressive-bootstrap>
</application-settings>
```

## Setting up SSL materials (optional)
Here is just a self signed certificate example, you could do use a CA if you want.

Generate a dh file:
```sh
$ openssl dhparam -out dh2048.pem 2048
```
Generate a self signed certificate:
```sh
$ openssl req -x509 -out cert.pem -keyout privkey.pem -newkey rsa:4096
```
Run (on port 5081):
```sh
$ /usr/bin/lms --docroot='/usr/share/lms/docroot/;/resources,/css,/images,/favicon.ico' --approot=/usr/share/lms/approot --https-address 0.0.0.0 --https-port 5081 --ssl-certificate cert.pem --ssl-private-key privkey.pem --ssl-tmp-dh dh2048.pem
```
Depending on your SSL parameters, you may be asked for the PEM passphrase to unlock the private key.

To connect to LMS, just open your favorite browser and go to https://localhost:5081

## Credits

- Wt (http://www.webtoolkit.eu/)
- bootstrap3 (http://getbootstrap.com/)
- libav project (https://www.libav.org/)
- Magick++ (http://www.imagemagick.org/Magick++/)

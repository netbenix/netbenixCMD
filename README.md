# netbenixCMD

A little project of mine to learn C.

Available for: *Linux*

Tested on: *Ubuntu, Debian, Arch*

Used libs for Linux: *gtk+3.0, libmysqlclient*

Version: *0.2.4*

## Features:

-   A help page (OMG!!!)

-   A little GTK Test

-   Can detect if you're using linux or not and tell the Architecture you're
    running on

-   Can give you a bit of information about your CPU (but just a little bit)

-   Checks your client version on start with the server

## Building:

Install packages:

-   Ubuntu: `sudo apt-get install make gcc git libgtk-3-dev libmysqlclient-dev`

-   Debian: `sudo apt-get install make gcc git libgtk-3-dev libmariadbclient-dev
    libmariadb-dev-compat`

-   Arch: `sudo pacman -S make gcc git gtk3 mariadb-libs pkgconf`

Clone repository: `git clone https://github.com/netbenix/netbenixCMD.git`

Go into the cloned directory: `cd netbenixCMD`

Build program: `make`

## Usage

After building use `./netbenixCMD` to start the program

If you want to use the testing arguments use `./netbenixCMD <argument>`

## Arguments

-   `--help` =\> Displays all arguments

-   `--gtk-test` =\> Opens the GTK Test Window

-   `--sql-test` =\> Makes a test connection to a mysql server

-   `--sys-info` =\> Gives you information about your system

-   `--no-version-check` =\> Skips the client version check

-   `--dev-mode` =\> Starts the program in developer mode (right now it just
    skips version check)

## Known Bugs

-   `sql-test` sha-256 passwords not working on Debian

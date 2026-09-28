# timetolocal

converts a time from a different timezone to your local time.

## Build

    make

## Usage

    ./timetolocal [TIME (24h)] [ZONE]

Example:

    ./timetolocal 7:15 est

Zone names are not case sensitive. abbreviations come from `tztable.h`

## Installing

    sudo make install

# **netbenixCMD**

A little project of mine to learn C.

Available for: *Linux*

Used Libs for Linux: *gtk+3.0, libmysqlclient*

Version: *0.1.0* 

## Features:
- A help page (OMG!!!)
- A little GTK Test
- Can detect if you're using linux or Windows and tell the Architecture you're running on

## Building:
Install packages: make, gtk3, libgtk-3-dev, gcc, mysql

Clone Repositroy: ```git clone https://github.com/netbenix/netbenixCMD.git```

Go into the just cloned directory

Build with command: ```make```

## Usage
After building use ```./netbenixCMD <argument>``` to start the program

## Arguments
- ```--help```      	=> Displays all arguments
- ```--gtk-test``` 		=> Opens the GTK Test Window
- ```--sql-test```		=> Makes a test connection to a mysql server
- ```--os-info```  		=> Outputs your OS Information
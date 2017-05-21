# AwakeMUD
A fork of the Awakened Worlds MUD codebase.

# OS Support
Tested on:
- OSX 10.12
- Raspbian Jessie

#Installation
Install MySQL 5.
Clone this repository to your machine.
Run SQL/gensql.sh (or do the steps manually if it doesn't support your OS).
Copy the mysql_config.cpp file to src.
Edit src/Makefile and select the OS that looks closest to yours.
From the src directory, run 'make clean && make'.
Change to the root directory and run the game (ex: 'gdb bin/awake').

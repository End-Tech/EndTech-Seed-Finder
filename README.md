# EndTech seed finder

## Compilation Instructions

You need to install the GNU C/C++ compiler onto your local system before starting.
Depending on your local system you need to setup the GNU compilers differently by installing different things.
Then you are ready to build libcubiomes a library that is then used to build the entire seed-finder.
Once again this functions differently on different systems.

### Windows

For windows you need to install minge. I personally followed the instructions provided by a Visual Studio Code extension:
[Here](https://code.visualstudio.com/docs/cpp/config-mingw)
Point 3 starts to describe how to install mingw.

After installing mingw and making sure it works you can now run the provided .bat files:
[make-libcubiomes.bat](/make-libcubiomes.bat) and [make-seedfinder.bat](/make-seedfinder.bat)
These will compile the cubiomes library and the seedfinder.  
Note: You only need to compile libcubiomes once - afterwards you only need to recompile the seed finder when changes were made there.  
Running [make-libcubiomes.bat](/make-libcubiomes.bat) should result in a file named libcubiomes.a.
If it doesn't you have a problem.

### Linux & Mac

TODO

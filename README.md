# basic ed copy

This is a c++ program that mimic the "ed" text editer basic operations.
This program was main as an assignment for a university course,
and should not be used as a substitute for the ed editor as it's not well tested.

## Installation
can be downloaded by git with:

```bash
git clone https://github.com/IdoGuzi/basic_ed_copy.git
```

or download the project as a zip.
to compile the program
```bash
make all
```
Note: this program is built in Ubuntu 20.04 and should be 
compatible with all Unix like operating systems(linux,macos).

## Usage

to just use the editor:
```bash
./run file.txt
```
to start editing from an existing file.
To start with empty file:
```bash
./run
```

for usage of the code itself in other projects:
```cpp
#include "Editor.h"

Document d; //for a new document.
Document doc(fileName); //fileName should be std::ifstream.
Editor e; //create editor object.
e.loop(); //start editing.
Editor ed(doc); // to load editor with existing file.
```

## Contributing
there is no reason to contribute to this project.
for special request please open an issue first to discuss the matter.
#include <iostream>
#include <fstream>
#include "Editor.h"
#include "Document.h"
using namespace std;



void runEditor(){
    Editor ed;
    ed.loop();
}

int main(int argc, char *argv[]){
    std::ifstream *file;
    if (argc==2) {
        file = new ifstream(argv[1]);
        if (file->good()) {
            Document d(*file);
            if (d.docSize()>0) std::cout << d.docSize()+d.getLineSize() << std::endl;
            Editor ed(d);
            ed.loop();
        }else runEditor();
    }else if (argc>2){
        throw runtime_error("too many arguments");
    }else{
        runEditor();
    }
    return EXIT_SUCCESS;
}
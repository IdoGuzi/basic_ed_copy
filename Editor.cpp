#include <iostream>
#include "Editor.h"

void Editor::loop(){
    std::string arg;
    while (true){
        getline(std::cin,arg);
        if (arg=="a"){
            append();
        }else if (arg=="c"){
            doc.deleteLine(line--);
            append();
        }else if (arg=="d"){
            doc.deleteLine(line);
        }else if (arg=="i"){
            --line;
            if (line<0) line=0;
            append();
        }else if (arg=="j"){
            if (line!=doc.getLineSize()){
                join();
            }else std::cout << "?" << std::endl;
        }else if (arg=="q"){
            if (saved) return;
            std::cout << "?" << std::endl;
            saved=true;
        }else if (arg=="$"){
            line=doc.getLineSize();
        }else if (arg.at(0)=='w' && arg.at(1)==' '){
            arg=arg.substr(2);
            writeToFile(arg);
            saved=true;
        }else if (arg.at(0)=='s' && arg.at(1)=='/' &&
                  arg.substr(2).find('/')!=arg.size()-1 && arg.at(arg.size()-1)=='/'){
            changeString(arg);
        }else if (arg.at(0)=='/' && arg.at(arg.size()-1)=='/'){
            findText(arg);
        }else if (isInteger(arg)){
            changeLine(arg);
        }else{
            std::cout << "?" << std::endl;
        }
    }
}



void Editor::join(){
    std::string tmp = doc.getLine(line);
    doc.deleteLine(line);
    tmp.append(doc.getLine(line));
    doc.deleteLine(line);
    doc.addLine(--line,tmp);
}

void Editor::append(){
    std::string text = "";
    getline(std::cin,text);
    while (text!="."){
        saved=false;
        doc.addLine(line++, text);
        getline(std::cin,text);
    }
}

void Editor::changeLine(std::string &s){
    int num = std::stoi(s);
    if (s.at(0)=='+' || s.at(0)=='-'){
        if (line+num<=0 || (line+num)>doc.getLineSize()){
            std::cout << "?" << std::endl;
            return;
        }
        line+=num;
    }else {
        if (num<=0 || num>doc.getLineSize()){
            std::cout << "?" << std::endl;
            return;
        }
        line=num;
    }
    std::cout << doc.getLine(line) << std::endl;
}

void Editor::changeString(std::string &s){
    std::string old,replacement;
    s = s.substr(2);
    int pos = s.find('/');
    old = s.substr(0,pos);
    replacement = s.substr(pos+1,s.size()-(pos+1)-1);
    int op = doc.getLine(line).find(old);
    if (op==-1) return;
    replacement = doc.getLine(line).replace(op,old.size(),replacement);
    doc.deleteLine(line);
    doc.addLine(line-1,replacement);
}

void Editor::findText(std::string &s){
    std::string text = s.substr(1,s.size()-2);
    int l = doc.findLine(line,doc.getLineSize(),text);
    if (l==-1) {
        l = doc.findLine(0,line,text);
        if (l==-1) return;
    }
    line=l+1;
}

void Editor::writeToFile(std::string &fileName){
    remove(fileName.c_str());
    std::ofstream myfile(fileName);
    int size = doc.getLineSize();
    for (int i=1;i<=size;i++) myfile << doc.getLine(i) << '\n';
    std::cout << myfile.tellp() << std::endl;
    myfile.close();

}

inline bool Editor::isInteger(const std::string & s){
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
   char * p;
   strtol(s.c_str(), &p, 10);
   return (*p == 0);
}
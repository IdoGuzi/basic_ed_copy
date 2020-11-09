#include "Document.h"


std::string Document::getLine(int line){
    return lines.at(line-1);
}

void Document::addLine(int line, std::string &s){
    lines.insert(lines.begin()+line, s);
}

void Document::deleteLine(int line){
    lines.erase(lines.begin()+line-1);
}

int Document::findLine(int start, int end, std::string &s){
    for (int i=start;i<end;i++){
        int l = lines.at(i).find(s);
        if (l!=-1) return i;
    }
    return -1;
}

int Document::docSize(){
    int count=0;
    for (std::vector<std::string>::iterator itr = lines.begin(); itr!=lines.end();itr++){
        count+=(*itr).size();
    }
    return count;
}

void Document::debug(){
    for (std::vector<std::string>::iterator itr = lines.begin();itr!=lines.end();itr++){
        std::cout << *itr <<std::endl;
    }
}

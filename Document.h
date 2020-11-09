#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Document{
  private:
    std::vector<std::string> lines;    
  public:
    Document(): lines() {}
    Document(std::ifstream &file): lines(){
    	std::string s;
    	while (getline(file,s)){
    		lines.push_back(s);
    	}

    }
    ~Document(){}

    void debug();
    /**
     * returning the text in the document in the choosen line.
     * @param line integer refering to a number of a line.
     * @returns a string represnting the text in a specific line.
     */
    std::string getLine(int line);

    /**
     * addLine takes a string and an integer representing text and number of line respectively and adding the string in the choosen line.
     * @param line where to insert the text. 
     * @param s text to add to the document.
     */
    void addLine(int line, std::string &s);


    /**
     * deleting the text in the specified line.
     * @param line the number of the line to delete.
     */
    void deleteLine(int line);

    /**
     * searching for the first appearance of the string in the document from line \p start to \p end.
     * @param start the number of the line to start searching from.
     * @param end the number of the line to end the search
     * @param s the text to search in the document.
     * @returns the number of the line of the first appearance of \p s.
     */
    int findLine(int start, int end, std::string &s);

    /**
     * return the number of chars in the document.
     * @returns the size of the document.
     */
    int docSize();


    /**
     * return the number of lines in the document.
     * @returns the number of line in the document.
     */
    int getLineSize() {return lines.size();}
};



#endif
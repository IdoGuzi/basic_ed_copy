#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"


/**
 * This class operate as a text editor.
 * supporting the opertions:
 * a - to write to the document in the next line, to stop writing write ".".
 * i - to write to the document in the line before, to stop writeing write ".".
 * c - to writh to the document in the current line while replacing the text in the current line, to stop write ".".
 * j - join the current line with the next one.
 * w fileName - save the text to a file with the name fileName (overriding existing file).
 * q - to quit the editor.
 * /text/ - find the text in the document and change the line to the text line.
 * s/old/new/ - replace the first time the text "old" showing in the current line with "new".
 * $ - go to the last line in the document.
 * +number - go the number of lines forward in the document.
 * -number - go the number of lines backward in the document.
 * number - go to line number.
 * 
 */
class Editor{
  private:
    Document doc;
    int line;
    bool saved;
  public:
    Editor(): doc(), line(0), saved(true) {}
    Editor(Document d): doc(d), line(doc.getLineSize()), saved(true) {}
    ~Editor(){}

    /**
     * the main function of the editor.
     * to start editing call this mehod.
     * provide the Editor functionality.
     * waiting for user input and act according to the input.
     * support the basic operations:
     * a, c, d, i, j, q, w file, /text/, s/old/new/
     */
    void loop();

  private:
    void join();
    void append();
    void changeLine(std::string &s);
    void changeString(std::string &s);
    void findText(std::string &s);
    void writeToFile(std::string &fileName);
    inline bool isInteger(const std::string & s);
};




#endif
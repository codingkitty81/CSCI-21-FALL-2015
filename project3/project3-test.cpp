#include "DLList.h"
#include "DLNode.h"
#include "project3-test.h"
#include <fstream>

int main (int argc, char* argv[]) {
    
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " INPUT_FILE" << endl;
    } else {
        string fileName(argv[1]);
        fileProcess(fileName);
    }
    
    return 0;
}

void fileProcess (string fileName) {
    DLList* list = NULL;
    ifstream fileIn;
    fileIn.open(fileName.c_str());
    string line;
    
    while (getline(fileIn, line)) {
        istringstream input(line);
        char option;
        int content = 0;
        input >> option >> content;
        
        switch (option) {
            case '#':
                //do nothing
                break;
            case 'C':
                if (list != NULL) {
                    list->~DLList();
                }
                    list = new DLList;
                    cout << "LIST CREATED" << endl;
                break;
            case 'X':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    list->clear();
                    cout << "LIST CLEARED" << endl;
                }
                break;
            case 'D':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    list->~DLList();
                    cout << "LIST DELETED" << endl;
                    list = NULL;
                }
                break;
            case 'I':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    list->insert(content);
                    cout << "VALUE " << content << " INSERTED" << endl;
                }
                break;
            case 'F':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    list->pushFront(content);
                    cout << "VALUE " << content << " ADDED TO HEAD" << endl;
                }
                break;
            case 'B':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    list->pushBack(content);
                    cout << "VALUE " << content << " ADDED TO TAIL" << endl;
                }
                break;
            case 'A':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    try {
                        cout << "VALUE " << list->getFront() << " AT HEAD" << endl;
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'Z':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    try {
                        cout <<  "VALUE " << list->getBack() << " AT TAIL" << endl;
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'T':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    try {
                        list->popFront();
                        cout << "REMOVED HEAD" << endl;
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'K':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    try {
                        list->popBack();
                        cout << "REMOVED TAIL" << endl;
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'E':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    if (list->removeAll(content) == true) {
                        cout << "VALUE " << content << " ELIMINATED" << endl;
                    } else {
                        cout << "VALUE " << content << " NOT FOUND" << endl;
                    }
                }
                break;
            case 'R':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    if (list->removeFirst(content) == true) {
                        cout << "VALUE " << content << " REMOVED" << endl;
                    } else {
                        cout << "VALUE " << content << " NOT FOUND" << endl;
                    }
                }
                break;
            case 'G':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    if (list->get(content) == true) {
                        cout << "VALUE " << content << " FOUND" << endl;
                    } else {
                        cout << "VALUE " << content << " NOT FOUND" << endl;
                    }
                }
                break;
            case 'N':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    cout << "LIST SIZE IS " << list->getSize() << endl;
                }
                break;
            case 'P':
                if (list == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                } else {
                    cout << *list << endl;
                }   
                break;
        }
    }
    
    fileIn.close();

}
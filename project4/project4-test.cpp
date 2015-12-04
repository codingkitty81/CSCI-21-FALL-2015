#include "BSTree.h"
#include "word.h"
#include "project4-test.h"

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
    BSTree<Word>* tree = NULL;
    ifstream fileIn;
    fileIn.open(fileName.c_str());
    string line;
    
    while (getline(fileIn, line)) {
        istringstream input(line);
        char option;
        string content;
        input >> option >> content;
        option = toupper(option);
        
        switch (option) {
            case 'C':
                //Create
                if (tree != NULL) {
                    tree->~BSTree();
                }
                    tree = new BSTree<Word>;
                    cout << "TREE CREATED" << endl;
                break;
            case 'X':
                //Clear
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    tree->clear();
                    cout << "TREE CLEARED" << endl;
                }
                break;
            case 'D':
                //Delete
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    tree->~BSTree();
                    cout << "TREE DELETED" << endl;
                    tree = NULL;
                }
                break;
            case 'I':
                //Insert
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    Word* newWord = new Word(content);
                    if (tree->getSize() == 0 || tree->find(*newWord) == false) {
                        tree->insert(*newWord);
                        cout << "WORD " << content << " INSERTED" << endl;
                    } else {
                        Word* wordTemp = tree->get(*newWord);
                        wordTemp->incrementCount();
                        cout << "WORD " << newWord->getWord() << " INCREMENTED" << endl;
                    }
                }
                break;
            case 'F':
                //Find
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    Word* newWord = new Word(content);
                    try {
                        if (tree->find(*newWord) == true) {
                            cout << "FOUND " << content << endl;
                        } else {
                            cout << content << " NOT FOUND" << endl;
                        }
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'R':
                //Remove
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    Word* newWord = new Word(content);
                    try {
                        if (tree->find(*newWord) == true) {
                            tree->remove(*newWord);
                            cout << "REMOVED " << content << endl;
                        } else {
                            cout << content << " NOT FOUND" << endl;
                        }
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'G':
                //Get
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    Word* newWord = new Word(content);
                    try {
                        if (tree->find(*newWord) == true) {
                            Word* wordTemp = tree->get(*newWord);
                            cout << "GOT " << wordTemp->getWord() << " " << wordTemp->getCount() << endl;
                        } else {
                            cout << content << " NOT FOUND" << endl;
                        }
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'N':
                //Number of nodes
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    cout << "TREE SIZE IS " << tree->getSize() << endl;
                }
                break;
            case 'O':
                //Print in-order
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    try {
                        tree->inOrder();
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            case 'E':
                //Print reverse in-order
                if (tree == NULL) {
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                    try {
                        tree->reverseOrder();
                    } catch (string except) {
                        cout << except << endl;
                    }
                }
                break;
            default:
                //do nothing
                break;
        }
    }
    
    fileIn.close();
}
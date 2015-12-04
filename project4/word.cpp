#include "word.h"

Word::Word () : count(1) {}
        
Word::Word (string newWord) : count(1), word(newWord) {}

Word::~Word () {}

string Word::getWord () const {
    return word;
}

void Word::setWord (string newWord) {
    word = newWord;
}

unsigned int Word::getCount () const {
    return count;
}

void Word::incrementCount () {
    count++;
}

bool operator == (Word w1, Word w2) {
    string w1word = w1.getWord();
    string w2word = w2.getWord();
    transform(w1word.begin(), w1word.end(), w1word.begin(), ::toupper);
    transform(w2word.begin(), w2word.end(), w2word.begin(), ::toupper);
    
    return (w1word == w2word);
}

bool operator < (Word w1, Word w2) {
    string w1word = w1.getWord();
    string w2word = w2.getWord();
    transform(w1word.begin(), w1word.end(), w1word.begin(), ::toupper);
    transform(w2word.begin(), w2word.end(), w2word.begin(), ::toupper);

    return (w1word < w2word);
}

bool operator > (Word w1, Word w2) {
    string w1word = w1.getWord();
    string w2word = w2.getWord();
    transform(w1word.begin(), w1word.end(), w1word.begin(), ::toupper);
    transform(w2word.begin(), w2word.end(), w2word.begin(), ::toupper);

    return (w1word > w2word);
}

ostream& operator << (ostream& out, Word w1) {
     out << w1.getWord() << " " << w1.getCount() << endl;
     
     return out;
}
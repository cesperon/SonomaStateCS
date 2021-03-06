// Title: Lab4 WordData class and implementaion
// Author: Christian Esperon
// Description: WordData class to be used by the
// main function.

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const bool testing = false;

class WordData
{
  public:
  WordData ();
  WordData (const string & InWord);
  WordData (const WordData & OtherWord);
  ~WordData ();
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
  void SetWord (const string & InWord);
  string GetWord () const;
  void WriteData (ostream & outs) const;
  bool operator > (const WordData & OtherWord) const;
  bool operator < (const WordData & OtherWord) const;
  WordData & operator = (const WordData & OtherWord);
  bool operator == (const WordData & OtherWord) const;
  WordData operator + (const WordData & OtherWord) const;
  friend istream & operator >> (istream & ins, WordData & w);
  friend ostream & operator << (ostream & outs, const WordData & w);
  
  private:
  // C++ string to hold the word
  int length;
  char * word;
  int vowels; // vowel counter
  int consonants; // consonant counter
  int digits; // digit counter
  int specialchars; // special character counter

};



#endif

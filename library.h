//test
#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include<list>
#include<string>
using namespace std;
struct book{
  string title;
  string author;
  int pages;
  string isbn;
  float price;
  int year;
};

  class Library{
  private:
    list<book> collection;
  public:
    Library();
    ~Library();
    void read_from_file(string fileName);
    void write_to_file(string fileName);
    void push_font(string newTitle, string newAuthor, int newPages,
		   string newIsbn, float newPrice, int newYear);

    void push_back(string newTitle, string newAuthor, int newPages,
                   string newIsbn, float newPrice, int newYear);

    void insert_sorted(string newTitle, string newAuthor, int newPages,
                   string newIsbn, float newPrice, int newYear);
    
    string find_author(string authorsName);

    string find_album(string bookName);

    void genericDelete(string authorsName, string bookName);

    void print();
  };


#endif //LIBRARY_H

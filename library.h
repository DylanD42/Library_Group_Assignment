/**
 * @file library.h
 * @authors Dylan Daniels, Anna Hensley
 * @date 2024-11-08
 * @brief a program that works as a library holding books
 * 
 * reads in a list of books and using the STL List object 
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include<list>
#include<string>
using namespace std;

/**
 * book that goes in the library
 *
 * @class book{ library.h "Library_Group_Assignment/library.h"
 * @brief holds all the information a book has assigned to it, works with the library class to store data
 *
 */
struct book{
  string title;
  string author;
  int pages;
  string isbn;
  float price;
  int year;
};


/**
 * library class that holds the books
 *
 * @class Library{ library.h "Library_Group_Assignment/library.h"
 * @brief library class that holds the books and has various functions avabible 
 *
 */
  class Library{
  public:

/**
 * reads from file
 *
 * @param string fileName valid filename to be opened
 * @pre the file is loaded properly 
 * @return void 
 * @post List is filled with data provided in the file
 * 
 */
    void read_from_file(string fileName);

/**
 * writes to file
 *
 * @param string fileName is a valid file name to be written to
 * @pre the list is properly loaded with data
 * @return void 
 * @post the output file is written to with the data in the list
 * 
 */
    void write_to_file(string fileName);

/**
 * adds a new element to the front of the list
 *
 * @param string newTitle title of book
 * @param string newAuthor name of author we wish to add
 * @param int newPages number of pages of the book were adding
 * @pre the list is created 
 * @return void 
 * @post this new book is added to the front of the list
 * 
 */
    void push_front(string newTitle, string newAuthor, int newPages,
		   string newIsbn, float newPrice, int newYear);


/**
 * adds a new element to the back of the list
 *
 * @param string newTitle title of book we wish to add
 * @param string newAuthor name of the author we wish to add
 * @param int newPages number of pages of the book were adding
 * @pre the list is created
 * @return void 
 * @post the new element is added to the end of the list
 * 
 */
    void push_back(string newTitle, string newAuthor, int newPages,
                   string newIsbn, float newPrice, int newYear);


/**
 * adds a new element in a sorted position inside the list
 *
 * @param string newTitle title of book we wish to add
 * @param string newAuthor name of the author we wish to add
 * @param int newPages number of pages of the book were adding
 * @pre the list is created
 * @return void 
 * @post the new element is inserted sorted in the list
 * 
 */
    void insert_sorted(string newTitle, string newAuthor, int newPages,
                   string newIsbn, float newPrice, int newYear);
    

/**
 * searchs through the list to see if there exits any books under the authors name 
 *
 * @param string authorsName is the name of the author we wish to lookup
 * @pre assumes that list is loaded properly, preferably with a book by the author we are looking up
 * @return void 
 * @post prints all of the books that by the author
 * 
 */
    void find_author(string authorsName);


/**
 * prints all of the data associated with the passed book
 *
 * @param string bookName is the book name were looking up
 * @pre assumes the list is loaded, preferably incuding the name of the book we are searching for
 * @return void 
 * @post prints the data associated with that book to the screen
 * 
 */
    void find_album(string bookName);


/**
 * deletes a element in the list
 *
 * @param string authorsName is the name of the author tied to the book we wish to delete
 * @param string bookName is the name of the book we wish to delete
 * @pre the list is loaded with data, preferably with the book by the author we are trying to delete
 * @return void 
 * @post the element is deleted if found
 * 
 */
    void genericDelete(string authorsName, string bookName);


/**
 * prints the library 
 *
 * @pre the library is loaded with data
 * @return void 
 * @post the library is printed to the screen
 * 
 */
    void print();
    private:
    list<book> bookList;
  };


#endif //LIBRARY_H

/**
 * @file library.cpp
 * @authors Dylan Daniels, Anna Hensley
 * @date 2024-11-08
 * @brief the cpp file for the library project
 * 
 * reads in a list of books and using the STL List object
 */

#include "library.h"
#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;


/**
 * reads from file
 *
 * @param string fileName valid filename to be opened
 * @pre the file is loaded properly 
 * @return void 
 * @post List is filled with data provided in the file
 * 
 */
void Library::read_from_file(string fileName){
  string newTitle, newAuthor,newIsbn;
  int newPages, newYear;
  float newPrice;

  ifstream infile(fileName);
  
  if(!infile){
    cout << "Error. Unable to open the input file." << endl;
  }
  getline(infile,newTitle);
  getline(infile,newAuthor);
  infile >> newPages;
  infile.ignore(1, '\n'); // ignores the newline that gets left from the extraction operator
  getline(infile,newIsbn);
  infile >> newPrice >> newYear;
  infile.ignore(1, '\n');
  infile.ignore(1, '\n');  // the second ignore is so that the imput file can include
                           // a space for readablility
  
  while(infile){
    push_back(newTitle, newAuthor, newPages, newIsbn, newPrice, newYear);
    getline(infile,newTitle);
    getline(infile,newAuthor);
    infile >> newPages;
    infile.ignore(1, '\n');
    getline(infile,newIsbn);
    infile >> newPrice >> newYear;
    infile.ignore(1, '\n');
    infile.ignore(1, '\n');  
  }
  infile.close();
}

/**
 * writes to file
 *
 * @param string fileName is a valid file name to be written to
 * @pre the list is properly loaded with data
 * @return void 
 * @post the output file is written to with the data in the list
 * 
 */
void Library::write_to_file(string fileName) {
  ofstream outFile(fileName);

  if (!outFile) {
    cout << "File could not be opened." << endl;
  }

  list<book>::iterator it;
  for (it = bookList.begin(); it != bookList.end(); it++) {
    outFile << it->title << endl
            << it->author << endl
            << it->pages << endl
            << it->isbn << endl
            << it->price << endl
            << it->year << endl << endl;
  }

  outFile.close();
  cout << "The Library has been written to " << fileName << " successfully," << endl;
}



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
void Library::push_front(string newTitle, string newAuthor, int newPages,
	       string newIsbn, float newPrice, int newYear){
  book temp;
  temp.title = newTitle;
  temp.author = newAuthor;
  temp.pages = newPages;
  temp.isbn = newIsbn;
  temp.price = newPrice;
  temp.year = newYear;
  bookList.push_front(temp);
}

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
void Library::push_back(string newTitle, string newAuthor, int newPages,
               string newIsbn, float newPrice, int newYear){
  book temp;
  temp.title = newTitle;
  temp.author = newAuthor;
  temp.pages = newPages;
  temp.isbn = newIsbn;
  temp.price = newPrice;
  temp.year = newYear;
  bookList.push_back(temp);
}

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
void Library::insert_sorted(string newTitle, string newAuthor, int newPages,
                   string newIsbn, float newPrice, int newYear){
  book temp;
  temp.title = newTitle;
  temp.author = newAuthor;
  temp.pages = newPages;
  temp.isbn = newIsbn;
  temp.price = newPrice;
  temp.year = newYear;
  
  list<book>::iterator it = bookList.begin();

  while (it != bookList.end() && newTitle > it->title) {
    it++;
  }
  bookList.insert(it, temp);
}

/**
 * searchs through the list to see if there exits any books under the authors name 
 *
 * @param string authorsName is the name of the author we wish to lookup
 * @pre assumes that list is loaded properly, preferably with a book by the author we are looking up
 * @return void 
 * @post prints all of the books that by the author
 * 
 */   
void Library::find_author(string authorsName){
  list<book>::iterator it = bookList.begin();
  bool found = false;
  
  cout << "Looking up books from: " << authorsName << endl << endl;

  // loops through the list of books
  while(it != bookList.end()) {
    if (it->author == authorsName) {
      found = true;

      cout << "Title: " << it->title << endl;
      cout << "Author: " << it->author << endl;
      cout << "Pages: " << it->pages << endl;
      cout << "ISBN: " << it->isbn << endl;
      cout << "Price: $" << it->price << endl;
      cout << "Release year: " << it->year << endl << endl;
    }
    
    it++;
  }

  if (!found) {
    cout << "There are no books by " << authorsName << " in our library." << endl;
  }
}

/**
 * prints all of the data associated with the passed book
 *
 * @param string bookName is the book name were looking up
 * @pre assumes the list is loaded, preferably incuding the name of the book we are searching for
 * @return void 
 * @post prints the data associated with that book to the screen
 * 
 */

void Library::find_album(string bookName){
  list<book>::iterator it = bookList.begin();
  
  cout << "Looking info on the book: " << bookName << endl;

  while((it->title != bookName) && (it != bookList.end())){
    it++;
    }
    if(it->title == bookName){
      
      cout << endl;
      cout << "Title: "<< it->title << endl;
      cout << "Author: " << it->author << endl;
      cout << "Number of Pages: " << it->pages << endl;
      cout << "ISBN: " << it->isbn << endl;
      cout << "Shelf Price: $" << it->price << endl;
      cout << "Release Year: " << it->year << endl;
      cout << endl;
    }
    else if(it->title != bookName){
      cout << bookName << " was not found in the library." << endl;
    }    
    
}

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
void Library::genericDelete(string authorsName, string bookName){
  list<book>::iterator it = bookList.begin();
  cout << "Deleting " << bookName << " from "  << authorsName <<" from the library."<< endl;

  while((it->author != authorsName) && (it->title !=bookName) && (it != bookList.end())){
    it++;
    }
  if((it->title == bookName) && (it->author == authorsName)){
    cout << "Deleted " << it->title << " by " << it->author << endl;
    bookList.erase(it);
    return;
  }
  
  else if((it->title == bookName) && (it->author != authorsName)){
    cout << "The book " << it->title << " is not by "
	 << authorsName << " it is by " << it->author << endl;
    return;
  }
  else if((it->title != bookName) && (it->author == authorsName)){
    cout << "We do not have " << bookName << " from "
	 << it->author << " but we have other titles from them." << endl;
    return;
  }
  cout << "We do not have that title." << endl;
}


/**
 * prints the library 
 *
 * @pre the library is loaded with data
 * @return void 
 * @post the library is printed to the screen
 * 
 */
void Library::print(){
  bool swapped;
  do {
    swapped = false;
    list<book>::iterator it1 = bookList.begin();
    list<book>::iterator it2 = next(it1); // moves to next book in list

    // traverse the list and swap as necessary to list alphabetically by name
    while (it2 != bookList.end()) {
      if (it1->author > it2->author) {
        // swap by author's name
        book temp = *it1;
        *it1 = *it2;
        *it2 = temp;
        swapped = true;
          }
      
      it1++;
      it2++;
    }
  } while (swapped); // repeats even if a swap happens

  // prints list
  list<book>::iterator it;
  cout << endl << "printing list..." << endl << endl;
  cout <<"+---------------------------+" << endl;
  for(it = bookList.begin(); it != bookList.end(); it++){
    
    cout << "Title: " << it->title << endl;
    cout << "Author: " << it->author << endl;
    cout << "Pages: " << it->pages << endl;
    cout << "ISBN: " << it->isbn << endl;
    cout << "Price: $" << it->price << endl;
    cout << "Release year: " << it->year << endl << endl;
    
  }
  cout <<"+---------------------------+" << endl;
}

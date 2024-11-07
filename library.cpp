#include "library.h"
#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;


Library::Library(){
  //list<book> bookList;
  //list<book> books;
  //books.push_front();
  }
Library::~Library(){}
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
  infile.ignore(1, '\n');
  getline(infile,newIsbn);
  infile >> newPrice >> newYear;
  infile.ignore(1, '\n');  
  
  while(infile){
    push_back(newTitle, newAuthor, newPages, newIsbn, newPrice, newYear);
    getline(infile,newTitle);
    getline(infile,newAuthor);
    infile >> newPages;
    infile.ignore(1, '\n');
    getline(infile,newIsbn);
    infile >> newPrice >> newYear;
    infile.ignore(1, '\n');
    
  }
  infile.close();
}
//void write_to_file(string fileName);
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
  
  //cout << endl << it->author << endl;
  
  while(newAuthor > it->author && (it != bookList.end())){
    it++;
    cout << "it: "<<it->author << " new author : " << newAuthor << endl; 
  }
  /*
  for(it = bookList.begin(); it != bookList.end(); it++){
    cout << it->author << " " << newAuthor << endl;
    if(it->author < newAuthor){
      cout << "true" << endl;
    }
    if(it->author > newAuthor){
      cout << "false" << endl;
    }
  }
  */
  bookList.insert(it, temp);
}
//    
void Library::find_author(string authorsName){
  list<book>::iterator it = bookList.begin();
  cout << "Looking up books from: " << authorsName << endl;
  while((it->author != authorsName) && (it != bookList.end())){
    it++;
  }
  
  if(it->author == authorsName){
    cout << it->title << endl;
  }
  else if(it->author != authorsName){
    cout << "There are no books by " << authorsName << " in our library." << endl;
    
  }
}
void Library::find_album(string bookName){
  list<book>::iterator it = bookList.begin();
  cout << "Looking info on the book: " << bookName << endl;

  while((it->title != bookName) && (it != bookList.end())){
    it++;
    }
    
    //for(it = bookList.begin(); it != bookList.end(); it++){
    if(it->title == bookName){
      
      cout << endl;
      cout << "Title: "<< it->title << endl;
      cout << "Author: " << it->author << endl;
      cout << "# of Pages: " << it->pages << endl;
      cout << "isbn #: " << it->isbn << endl;
      cout << "Shelf Price: $" << it->price << endl;
      cout << "Release Year: " << it->year << endl;
      cout << endl;
     
      //}
    }
    else if(it->title != bookName){
      cout << bookName << " was not found in the library." << endl;
    }
    
    
    
}

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
  
  //if((it->title != bookName) && (it->author != authorsName)){
  cout << "We do not have that title." << endl;
  
}
void Library::print(){
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

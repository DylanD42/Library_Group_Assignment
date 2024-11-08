#include "library.h"
#include <iostream>

using namespace std;

int main() {
  Library PML;

  int choice;
  string fileName, authorsFN, authorsLN, bookTitle, isbn;
  int pages, year;
  float price;
  
<<<<<<< HEAD
  do {
    cout << endl;
    cout << "Hello! Please select one of the following options." << endl;
    cout << endl;
    cout << "1. Read from a specific library file.\n"
         << "2. Write the library to a file.\n"
         << "3. See a complete list of all the books in the library.\n"
         << "4. Search for a specific book.\n"
         << "5. Look to see if we have any books by a specific author!\n"
         << "6. If donating a book, please submit the book's information.\n"
         << "7. If a book is missing, please submit the book's information.\n"
         << "8. Exit this program.\n";
    cin >> choice;
    cout << endl;
       
    switch (choice) {
    case 1: {
      cout << "Please enter the library file to read from: ";
      cin >> fileName;
      PML.read_from_file(fileName);
      break;
    }
    case 2: {
      cout << "Please enter the name of the file to write to: ";
      cin >> fileName;
      PML.write_to_file(fileName);
      break;
    }
    case 3: {
      PML.print();
      break;
    }
    case 4: {
      cout << "In order to find information on a book, please enter the title.\n";
      cin.ignore();
      getline(cin, bookTitle);

      if (!bookTitle.empty()) {
        PML.find_album(bookTitle);
      } else {
        cout << "Oh no! We must not have any books with that title." << endl;
      }
      
      break;
    }
    case 5: {
      string authorsName;
      cout << "In order to find books by that author, please enter the author's "
           << "full name: ";
      cin.ignore();
      getline(cin, authorsName);

      PML.find_author(authorsName); 
      break;
    }
    case 6: {
      cout << "Thank you for the donation! Please enter the book's title: ";
      cin.ignore();
      getline(cin, bookTitle);

      string authorsName;
      cout <<" Great! Now enter the author's full name: ";
      getline(cin, authorsName);       

      cout << "Please enter the total pages: ";
      cin >> pages;
=======
  PML.read_from_file("imput.txt");
  PML.write_to_file("output.txt");
  PML.print();
>>>>>>> master

      cout << "Enter the ISBN: ";
      cin >> isbn;

      cout << "Enter the price (format example: 10.99): ";
      cin >> price;

      cout << "Finally, please enter the Year published: ";
      cin >> year;
      
      PML.insert_sorted(bookTitle, authorsName, pages, isbn, price, year);
      break;
    }
    case 7: {
      cout << "Thank you for letting us know! Please help us out by entering some "
           << "information." << endl;
      cout << "Please enter the book's title: ";
      cin.ignore();
      getline(cin, bookTitle);

      string authorsName;
      cout <<" Great! Now enter the author's first name: ";
      getline(cin, authorsName);
      
      cout << "Enter the total pages: ";
      cin >> pages;
      
      cout << "Enter the ISBN: ";
      cin >> isbn;
      
      cout << "Please enter the price: ";
      cin >> price;
      
      cout << "Enter the Year published: ";
      cin >> year;
      
      PML.genericDelete(authorsName, bookTitle);
      break;   
    }
    case 8: {
      cout << "Thank you for using our library system. You are now "
           << "Exiting the program. Goodbye!" << endl;
      break;
    }
    default: {
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
    }
  } while (choice != 8);
  
  return 0;
}

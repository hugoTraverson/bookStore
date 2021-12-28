#include "consoleview.h"

ConsoleView::ConsoleView(): 
	_currentChoice(EXIT_CHOICE)
{
}

void ConsoleView::askChoices()
{
	std::cout << "Would you like to :" << std::endl
		<< "0 -	stop the program" << std::endl
		<< "1 -	add a book" << std::endl
		<< "2 -	add an author" << std::endl
		<< "3 -	search the author who wrote a given book " << std::endl
		<< "4 - search books written by a given author" << std::endl;

	std::cin >> _currentChoice;
}

void ConsoleView::handleChoice(IBookLibraryManip& ctrlLibrary)
{
	std::string strBook = "", strAuthor = "";
	switch (_currentChoice)
	{
	case 1:
		std::cout << "book title ? ";
		std::cin >> strBook;
		std::cout << "author name ? ";
		std::cin >> strAuthor;
		ctrlLibrary.addBook(strBook, strAuthor);
		break;
	case 2:
		std::cout << "author name ? ";
		std::cin >> strAuthor;
		ctrlLibrary.addAuthor(strAuthor);
		break;
	case 3: 
		std::cout << "book title ? ";
		std::cin >> strBook;
		ctrlLibrary.searchAuthorOfBook(strBook);
		break;
	case 4:
		std::cout << "author name ? ";
		std::cin >> strAuthor;
		ctrlLibrary.searchBooksByAuthor(strAuthor);
		break;
	default: /* ==0 or >4 : do nothing */ break;
	}
}
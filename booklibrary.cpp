#include "booklibrary.h"
#include "strat_add_data.h"
#include "strat_search.h"
// first commit test
#include <sstream>

void BookLibrary::addBook(const std::string& bookTitle, const std::string& authorName)
{
	StratAddBook strategy;
	if (strategy.addData(*this, bookTitle, authorName))
		sendPrintLibrary();
}

void BookLibrary::addAuthor(const std::string& authorName)
{
	StratAddAuthor strategy;
	if (strategy.addData(*this, authorName))
		sendPrintLibrary();
}

void BookLibrary::searchAuthorOfBook(const std::string& bookTitle) const
{
	StratSearchAuthorFromBook strategy;
	_handlerGui.printData(strategy.search(*this, bookTitle));
}

void BookLibrary::searchBooksByAuthor(const std::string& authorName) const
{
	StratSearchBooksFromAuthor strategy;
	_handlerGui.printData(strategy.search(*this, authorName));
}

void BookLibrary::sendPrintLibrary() const
{
	std::ostringstream oss;
	oss << "********* list of books *********" << std::endl;
	for (auto book : _books)
		oss << "- book " << book->getTitle() << std::endl;

	oss << "********* list of authors *********" << std::endl;
	for (auto author : _authors)
		oss << "- author " << author->getname() << std::endl;

	_handlerGui.printData(oss.str());
}
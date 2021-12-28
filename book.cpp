#include "book.h"
// first commit test
#include <iostream>
#include <stdexcept>
#include <cassert>

std::set<std::string> Book::_sBookTitles = {};

std::unique_ptr<Book> Book::create(const std::string& title)
{
	try
	{
		if (_sBookTitles.count(title) > 0)
			throw std::invalid_argument("cannot add a book with the same name as a previous name");

		_sBookTitles.emplace(title);
		return std::unique_ptr<Book>(new Book(title));
	}
	catch (const std::exception& e)
	{
		assert(1);
		std::cerr << "Book::create : " << e.what() << std::endl;
		return std::unique_ptr<Book>(nullptr);
	}
}
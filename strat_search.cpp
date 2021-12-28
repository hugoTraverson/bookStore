#include "strat_search.h"

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <sstream>

std::string StratSearchAuthorFromBook::search(const BookLibrary& library, const std::string& bookTitle) const
{
	try
	{
		for (auto pair : library._mediatorAuthorBooks)
		{
			if (pair.first.expired() || pair.second.expired())
				throw std::out_of_range("pair data has been expired, stopping the search");

			auto book = pair.second.lock();
			if (book->getTitle() == bookTitle)
			{
				auto author = pair.first.lock();
				return "written by " + author->getname();
			}
		}
	}
	catch (const std::exception& e)
	{
		assert(1);
		std::cerr << "StratSearchAuthorFromBook::search : " << e.what();
	}

	return "cannot find author from book " + bookTitle;
}

std::string StratSearchBooksFromAuthor::search(const BookLibrary& library, const std::string& authorName) const
{
	try
	{
		std::ostringstream oss;
		int nbBooks = 0;
		oss << "Author " << authorName << " has written the following books : " << std::endl;
		for (auto pair : library._mediatorAuthorBooks)
		{
			if (pair.first.expired() || pair.second.expired())
				throw std::out_of_range("pair data has been expired, stopping the search");

			auto author = pair.first.lock();
			if (author->getname() == authorName)
			{
				auto book = pair.second.lock();
				nbBooks++;
				oss << nbBooks << " - book " << book->getTitle() << std::endl;
			}
		}

		if (nbBooks == 0)
			return authorName + " has not written any book";

		return oss.str();
	}
	catch (const std::exception& e)
	{
		assert(1);
		std::cerr << "StratSearchAuthorFromBook::search : " << e.what();
	}

	return "research stopped for books on author " + authorName;
}

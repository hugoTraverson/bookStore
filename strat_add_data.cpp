#include "strat_add_data.h"

#include <iostream>
#include <stdexcept>
#include <cassert>

bool StratAddBook::addData(BookLibrary& library, const std::string& bookTitle, const std::string& authorName) const
{
	try
	{
		auto iterAuthor = std::find_if(
			std::begin(library._authors),
			std::end(library._authors),
			[=](std::shared_ptr<Author>& el) { return el->getname() == authorName; }
		);
		if (iterAuthor == std::end(library._authors))
		{
			StratAddAuthor strat;
			if (!strat.addData(library, authorName))
				throw std::runtime_error("cannot add author when adding a book");

			iterAuthor = std::find_if(
				std::begin(library._authors),
				std::end(library._authors),
				[=](std::shared_ptr<Author>& el) { return el->getname() == authorName; }
			);
		}

		std::shared_ptr<Book> newBook = std::move(Book::create(bookTitle));
		if (newBook == nullptr)
			throw std::runtime_error("cannot create a book");
		library._books.emplace_back(newBook);

		std::pair<std::weak_ptr<Author>, std::weak_ptr<Book>> newPair = { *iterAuthor, newBook };
		library._mediatorAuthorBooks.emplace_back(newPair);

		return true;
	}
	catch (const std::exception& e)
	{
		assert(1);
		std::cerr << "StratAddBook::addData : " << e.what();
		return false;
	}
}

bool StratAddAuthor::addData(BookLibrary& library, const std::string& authorName) const
{
	std::shared_ptr<Author> newAuthor = std::move(Author::create(authorName));
	if (newAuthor != nullptr)
	{
		library._authors.emplace_back(newAuthor);
		return true;
	}
	else
	{
		std::cerr << "StratAddAuthor::addData : cannot create new author" << std::endl;
		return false;
	}
}

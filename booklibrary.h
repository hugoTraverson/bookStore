#pragma once

#include "Ibooklibrary.h"
#include "book.h"
#include "author.h"

#include <memory>
#include <vector>

class BookLibrary final : public IBookLibraryManip
{
public:
	BookLibrary(IBookLibraryGui& handlerGui): 
		_handlerGui(handlerGui), _books({}), _authors({}), _mediatorAuthorBooks({}) {}
	BookLibrary(const BookLibrary&) = delete;
	~BookLibrary() {}

	void addBook(const std::string& bookTitle, const std::string& authorName) override;
	void addAuthor(const std::string& authorName) override;
	void searchAuthorOfBook(const std::string& bookTitle) const override;
	void searchBooksByAuthor(const std::string& authorName) const override;

private:
	friend class StratAddBook;
	friend class StratAddAuthor;
	friend class StratSearchBooksFromAuthor;
	friend class StratSearchAuthorFromBook;

	void sendPrintLibrary() const;

	IBookLibraryGui& _handlerGui;

	std::vector<std::shared_ptr<Book>> _books;
	std::vector<std::shared_ptr<Author>> _authors;
	std::vector<std::pair<std::weak_ptr<Author>, std::weak_ptr<Book>>> _mediatorAuthorBooks;
};


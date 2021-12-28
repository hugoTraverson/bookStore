#pragma once
// first commit test
#include <string>

/**
 * \interface
 * \brief describes manipulation available for the book library controller
 */
class IBookLibraryManip
{
public:
	virtual void addBook(const std::string& bookTitle, const std::string& authorName) = 0;
	virtual void addAuthor(const std::string& authorName) = 0;
	virtual void searchAuthorOfBook(const std::string& bookTitle) const = 0;
	virtual void searchBooksByAuthor(const std::string& authorName) const = 0;
};

/**
 * \interface
 * \brief describes gui send commands used by the library controller
 */
class IBookLibraryGui
{
public:
	virtual void printData(const std::string& data) const = 0;
};
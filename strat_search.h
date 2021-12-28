#pragma once

#include "booklibrary.h"

template <typename T, typename ...Args>
class IStratSearchData
{
public:
	virtual std::string search(const T& object, Args ...args) const = 0;
};

class StratSearchAuthorFromBook final : public IStratSearchData<BookLibrary, const std::string&>
{
public:
	std::string search(const BookLibrary& library, const std::string& bookTitle) const override;
};

class StratSearchBooksFromAuthor final : public IStratSearchData<BookLibrary, const std::string&>
{
public:
	std::string search(const BookLibrary& library, const std::string& authorName) const override;
};

#pragma once

#include "booklibrary.h"

template <typename T, typename ...Args>
class IStratAddData
{
public:
	virtual bool addData(T& object, Args ...args) const = 0;
};

class StratAddBook final : public IStratAddData<BookLibrary, const std::string&, const std::string&>
{
public:
	bool addData(BookLibrary& library, const std::string& bookTitle, const std::string& authorName) const override;
};

class StratAddAuthor final : public IStratAddData<BookLibrary, const std::string&>
{
public:
	bool addData(BookLibrary& library, const std::string& authorName) const override;
};


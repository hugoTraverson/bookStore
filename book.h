#pragma once

#include <string>
#include <memory>
#include <set>

/**
 * \brief model class containing all data related to books
 */
class Book
{
public:
	~Book() {}

	const std::string& getTitle() const { return _title; }
	static std::unique_ptr<Book> create(const std::string& title);
private:
	Book(const std::string& title): _title(title) {}

	static std::set<std::string> _sBookTitles;
	std::string _title;
};


#include "author.h"
// first commit test
#include <iostream>
#include <stdexcept>
#include <cassert>

std::set<std::string> Author::_sAuthorNames = {};

std::unique_ptr<Author> Author::create(const std::string& name)
{
	try
	{
		if (_sAuthorNames.count(name) > 0)
			throw std::invalid_argument("cannot add a Author with the same name as a previous name");

		_sAuthorNames.emplace(name);
		return std::unique_ptr<Author>(new Author(name));
	}
	catch (const std::exception& e)
	{
		assert(1);
		std::cerr << "Author::create : " << e.what() << std::endl;
		return std::unique_ptr<Author>(nullptr);
	}
}
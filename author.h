#pragma once
// first commit test
#include <string>
#include <memory>
#include <set>

/**
 * \brief model class containing all data related to Authors
 */
class Author
{
public:
	~Author() {}

	const std::string& getname() const { return _name; }
	static std::unique_ptr<Author> create(const std::string& name);
private:
	Author(const std::string& name) : _name(name) {}

	static std::set<std::string> _sAuthorNames;
	std::string _name;
};

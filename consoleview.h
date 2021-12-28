#pragma once

#include "Ibooklibrary.h"

#include <iostream>
#include <string>

class ConsoleView final : public IBookLibraryGui
{
public:
	static constexpr int EXIT_CHOICE = 0;

	ConsoleView();
	ConsoleView(const ConsoleView&) = delete;
	~ConsoleView() {}

	void askChoices();
	void handleChoice(IBookLibraryManip& ctrlLibrary);
	void printData(const std::string& data) const override { std::cout << data << std::endl; }
	bool isQuitting() const { return _currentChoice == EXIT_CHOICE; }

private:
	int _currentChoice;
};


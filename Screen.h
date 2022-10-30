#pragma once
#include <iostream>
#include <iomanip>
#include <string>


class Screen
{

#define Pause  std::cin.get()
#define Clear std::system("cls")
#define Stop std::cin.get(); std::cin.get();


public:

	//	for all kind of Variables
	template <typename Ty>	friend Screen& operator >> (Screen& screen, Ty& value)
	{
		std::cin >> value;
		if (!std::cin) {
			std::cerr << "wrong input\n";
			std::cerr << "Try again : ";
			std::cin.clear();
			Stop;
			screen >> value;
		}

		return screen;
	}

	//	specially for std::string
	friend Screen& operator >> (Screen& screen, std::string& value)
	{
	//	Receiving string will not fail at all
		Stop;
		getline(std::cin, value);

		return screen;
	}

	//	show Text
	template <typename Ty>	friend Screen& operator << (Screen& screen, const Ty text) {
		std::cout << text;
	return screen;
	}

	//	shoe Massage
	template <typename Ty>	friend Screen& operator == (Screen& screen, const Ty text) {
		std::cout << "[MASSAGE] : " << text;
	return screen;
	}

	//	show Error
	template <typename Ty>	friend Screen& operator || (Screen& screen, const Ty text) {
		std::cerr << "[ERROR] : " << text << '\a';
	return screen;
	}

};


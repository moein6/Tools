#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>

//	Only 1D arrays
template <typename Ty = int, size_t size = 1>
class  Array : public std::array<Ty, size>
{
	bool Is_Unique(Ty Elem, const unsigned short Digit) {
		unsigned short temp = 0;

		while (true) {

			Elem /= 10;
			temp++;

			if (Elem == 0)
				break;
		}//	end while

		return temp == Digit;
	}

public:

	void Print()const {
		for (auto I : *this)
			std::cout << I << ' ';
		std::cout << '\n';
	}


	void Sort() {
		std::sort(this->begin(), this->end());
	}

	//	Initialaze array  with a specific number
	void Initializing_With(const Ty* Value) {
		this->fill(*Value);

	}

	//	Initialaze with random numbers
	void Random_initialaze(unsigned short	Digit = 1) {

		
		//	change time seed
		srand(static_cast<size_t> (time(NULL)));

		for (short i = 0; i < size; i++) {
			Ty Elem = (rand() % (int)(pow(10, Digit)));

			this->at(i) = Elem;

		}//	end for
	}//	end function


	//	Initialaze array with not repeated numbers (only numbers)
	void Unique_initialaze(const unsigned short	Digit = 1) {

		if (Digit > 0) {

			//	change time seed
			srand(static_cast<size_t>(time(NULL)));


			for (unsigned short i = 0; i < size; i++) {
				//	Generate the randon number
			Generate: {
				Ty Elem = (rand() % (int)(pow(10, Digit)));
				//	Check the array for matching numbers, if any matching numbers are found, go to generate a new number
				for (unsigned short step = 0; step < i; step++)
					if (Elem == this->at(step))
						goto Generate;

				//	if no matching numbers found then put it in array
				this->at(i) = Elem;

				}//	end lable
			}//	end for
		}//	end if
		else {
			std::cerr << "Digit most be more than 0!\n\a";
			this->fill(0);
		}
	}//	end function

	void  Unique_Unique_initialaze(const unsigned short	Digit = 1) {




		if (Digit > 0 && Digit < 6) {

			//	change time seed
			srand(static_cast<size_t>(time(NULL)));


			for (unsigned short i = 0; i < size; i++) {
				//	Generate the randon number
			Generate: {
				
				Ty Elem = (rand() % (int)(pow(10, Digit)));

				unsigned short step = 0;
				do {
					if (Is_Unique(Elem, Digit) == false || Elem == this->at(step))
						goto Generate;
					step++;
				} while (step <= i);



				//	if no matching numbers found then put it in array
				this->at(i) = Elem;

				}//	end lable
			}//	end for
		}//	end if
		else {
			std::cerr << "Digit most be between 1 - 5 !\n\a";
			this->fill(0);
		}

	}//	end function


	friend Array operator >> (std::istream& input, Array& arr) {

		for (unsigned short i = 0; i < arr.size(); i++) {
			std::cout << '[' << i << "]: ";
			input >> arr[i];
		}//	end for

		return arr;
	}

};

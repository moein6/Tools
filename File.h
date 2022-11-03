#pragma once
#include <fstream>
#include <iostream>

// Creating files in "fstream" mood.
// If you need help just open Help() function.
class File : public std::fstream
{

public:

	//	for all files
	File(const char* File_Name, const bool is_Binary) {

		//	check and open file binary mode
		if (is_Binary) {
			this->open(File_Name, std::ios::in | std::ios::out | std::ios::binary);

			if (!this->is_open()) {
				this->open(File_Name, std::ios::out | std::ios::binary);
				File(File_Name, is_Binary);
			}//	end if
		}
		else
		{
			//	check and open file in regular mode
			this->open(File_Name, std::ios::in | std::ios::out | std::ios::app);

			if (!this->is_open()) {
				this->open(File_Name, std::ios::out | std::ios::app);
				File(File_Name, is_Binary);
			}//	end if
		}//	end else
	}//	end constructor
	~File() {
		this->close();
	}




	//	Your class should contain this function : unsigned int Get_ID().
	template<typename Ty>	friend File& operator <<= (File& file, Ty& value) {

		file.seekp(sizeof(Ty) * (__int64)(value.Get_ID()));

		file.write((char*)&value, sizeof(Ty));
		return file;
	}

	//	Save data useing pair
	template<typename Ty , typename Pos>	friend File& operator<<= (File& file, std::pair<Ty , Pos>& var) {
		file.seekp(sizeof(Ty) * (__int64)(var.second));

		file.write((char*)&var.first, sizeof(Ty));
		
		return file;

	}

	//	saving object in txt files.
	template<typename Ty>	friend File& operator << (File& file, const Ty& value) {

		file.write((char*)&value, sizeof(Ty));

		return file;
	}
	
	//	specialy for saving string : save all of the string in file 
	friend File& operator << (File& file, const std::string val) {
		
		for (auto ch : val)
			file << ch;

		return file;
	}

	//	used spicialy for const char*.
	friend File& operator << (File& file, const char*& data) {
		file << data;
	}


//	=-----------------------------	 Read	--------------------------------------------------------------------------

	//	searching in binary file.
	template<typename Ty>	friend File& operator >>= (File& file, Ty& var) {
		file.seekg(sizeof(Ty) * (__int64)(var.Get_ID()));
		file.read((char*)&var, sizeof(Ty));
		return file;
	}

	//	Find data useing pair
	template<typename Ty , typename Pos>   friend File& operator >>= (File& file, std::pair<Ty, Pos>& var) {
		file.seekg(sizeof(Ty) * (var.second));
		file.read((char*)&var.first, sizeof(Ty));
		return file;

	}
	
	//	read all files.
	template<typename Ty>	friend File& operator >> (File &file , Ty& value) {
		file.read((char*)&value, sizeof(Ty));
		return file;
	}

	//	specialy for reading string : Put all file in string
	friend File& operator >> (File& file, std::string& val) {
		char ch;

		while (file >> ch)
			val.push_back(ch);

		return file;
	}



	void Help()const {
		std::cout << "1 - operator << : used for saving in files in regular way not Binay.\n";
		std::cout << "2 - operator <<= : used for savin in files in Binary mode (special location in file).\n";
		std::cout << "3 - operator >>= : used for searching in Binary files (Read a specific location).\n";
		std::cout << "4 - Operator >> : used for reading all of the file in all modes.\n";
		std::cout << "5 - operator <<= (with std::pair) : this is used to save data in a specific location that the object does not prvides a Get_ID() function.";
		std::cout << "6 - operator >>= (with std::pair) : this is used to read data in a specific location that the object does not prvides a Get_ID() function.";
	}

};


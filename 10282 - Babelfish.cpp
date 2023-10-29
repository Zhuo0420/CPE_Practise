#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map <std::string, std::string> dic;
	std::string key;
	while (std::getline(std::cin, key)) {
		if (key == "")	break;
		std::string val;
		std::string key2;
		std::size_t tmp = key.find(" ");
		for (int i = 0; i < key.length(); i++) {
			if (i < tmp) {
				key2 += key[i];
			}
			else if(i > tmp) {
				val += key[i];
			}
		}		
		dic[val] = key2;
	}
	std::string findWord;
	
	while (std::getline(std::cin, findWord)) {
		if (findWord == "")		break;
		
		std::map<std::string, std::string>::iterator it1;
		it1 = dic.find(findWord);

		if (it1 != dic.end()) {
			std::cout << it1->second << std::endl;
		}
		else {
			std::cout << "eh" << std::endl;
		}
	}
	return 0;
}

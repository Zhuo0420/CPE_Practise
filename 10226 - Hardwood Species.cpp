#include <iostream>
#include <map>  
#include <string>
#include <iomanip>

int main()
{
    int cases;
    std::cin >> cases;
    int tmp = cases;
    std::cin.ignore();      //\n
    std::cin.ignore();      //blank line

    while (cases--) {            

        std::map<std::string, double> trees = {};
        int counter = 0;
        std::string tmpTree;
        while (getline(std::cin, tmpTree)) {            

            if (tmpTree == "") break;

            trees[tmpTree]++;
            counter++;
        }
        /*for (auto it = trees.begin(); it != trees.end();it++) {
            std::cout << it->first << " " << it->second << std::endl;
        }*/
        for (auto it = trees.begin(); it != trees.end(); it++) {
            it->second /= counter;
            it->second *= 100;
        }
        for (auto it = trees.begin(); it != trees.end(); it++) {
            std::cout << it->first << " " << std::fixed << std::setprecision(4) << it->second << std::endl;
        }
        if(cases != 0){
            std::cout << std::endl;
        }
    }
}

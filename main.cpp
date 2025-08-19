#include <iostream>
#include <string>
#include <vector>
#include "utility.cpp"
#include "sorting.cpp"

// How to run: g++ main.cpp -o main
// ./main
static void selectSort(std::vector<int> base) {
    std::string userInput = "";
    while(userInput != "b") {
        std::cout << "\nYou have the following sorting algorithms to chose from: " << std::endl;
        std::cout << "1. Bubble Sort" << std::endl;
        std::cout << "2. Selection Sort" << std::endl;
        std::cout << "3. Insertion Sort" << std::endl;
        std::cout << "4. Merge Sort" << std::endl;
        std::cout << "5. Quick Sort" << std::endl;
        std::cout << "(back) To return to the main menu please enter \'b\'" << std::endl;
        std::cout << "\nYour input: ";
        std::cin >> userInput;

        if(userInput == "1") {
            Sorting::bubbleSort(base);
        }

        else if(userInput == "2") {
            Sorting::selectionSort(base);
        }

        else if(userInput == "3") {
            Sorting::insertionSort(base);
        }

        else if(userInput == "4") {
            Sorting::mergeSort(base, 0, base.size()-1);
            std::cout << "\nSort completed. Time = O(nlogn) and Space = O(n)" << std::endl;
            std::cout << std::endl;
        }
        else if(userInput == "5") {
            Sorting::quickSort(base, 0, base.size()-1);
            std::cout << "\nSort completed. Time = O(nlogn) and Space = O(n)" << std::endl;
        }

        else if(userInput != "b"){
            std::cout << "This does not appear to be a valid input, please try again." << std::endl;
        }
    }
}

int main(){
    std::string userInput = "";
    std::string userVector = "";
    std::vector<int> example = {1,5,4,2,3,10,7,8,9,6};
    std::vector<int> userExample;

    while(userInput != "x") {
        std::cout << "\nWelcome to the sorting algorithm demo, please chose a mode by entering the number:" << std::endl;
        std::cout << "\n1. (example) Run sorting algorithms with a provided list of numbers." << std::endl;
        std::cout << "2. (custom) Run sorting algorithms with a list you entered." << std::endl;
        std::cout << "3. (quit) Enter the key \'x\' to quit the program." << std::endl;
        std::cout << "\nYour input: ";

        std::cin >> userInput;

        if(userInput == "1") {
            std::cout << "\nThe following list is provided as an example: ";
            Utility::outputVector(example);
            selectSort(example);
        }
        else if(userInput == "2") {
            while(userVector != "b") {
                std::cout << "\nEnter your series of numbers seperated by a space or enter \'b\' to return to main menu" << std::endl;
                std::cin.clear();
                std::cin.sync();
                std::cout << "\nYour input: ";
                std::getline(std::cin, userVector);
                userExample = Utility::string2Vector(userVector);

                if(userExample.empty() && userVector != "b") {
                    std::cout << "No user input was recieved. :C " << std::endl;
                    continue;
                }
                else if(userVector != "b"){
                    Utility::outputVector(userExample);
                    selectSort(userExample);
                }
            }
            userVector = "";
            userExample.clear();
        }
        else if(userInput != "x"){
            std::cout << "This is not a valid option, please try again." << std::endl;
            continue;
        }
        else {
            std::cout << "\nThank you for trying out my demo" << std::endl;
        }
    }
}
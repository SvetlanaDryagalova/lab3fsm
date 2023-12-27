//Дрягалова Светлана
//Б18
#include <iostream>
#include <string>

enum Q {
    q0,
    q1,
    q2,
    q3,
    q4
};

bool isMultipleOfThree(const std::string& input) {
    Q currentState = q0;
    for (char c : input) {
        switch (currentState) {
            case q0:
                if (c == '0'){
                    currentState = q1;
                } else if (c == '1') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;
            case q1:
                if (c == '0') {
                    currentState = q3;
                } else if (c == '1') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;
            case q2:
                if (c == '0') {
                    currentState = q1;
                } else if (c == '1') {
                    currentState = q4;
                } else {
                    return false;
                }
                break;
            case q3:
                if (c == '0') {
                    currentState = q4;
                } else if (c == '1') {
                    currentState = q1;
                } else {
                    return false;
                }
                break;
            case q4:
                if (c == '0') {
                    currentState = q3;
                } else if (c == '1') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;
        }
        std::cout<<currentState<<std::endl;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter line with 0 and 1: ";
    std::cin >> input;

    if (isMultipleOfThree(input)) {
        std::cout << "Line is accepted" << std::endl;
    } else {
        std::cout << "Line is rejected" << std::endl;
    }

    return 0;
}

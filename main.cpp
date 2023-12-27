//Дрягалова Светлана
//Б18
#include <iostream>

using namespace std;

bool fsa() {
    int array[5][2];
    int n;
    for (int i=0; i<5; i++){
        for (int j=0; j<2; j++){
            cout << "Enter transition from state"<< i << " if " << j<< " entered"<< endl;
            cout << "state"<< endl;
            cin>>n;
            array[i][j] = n;
        }
    }

    string input;
    cout << "Enter line with 0 and 1: ";
    cin >> input;

    int currentState = 0;
    for (char ca : input) {
        switch (currentState) {
            case 0:
                if (ca == '0'){
                    currentState = array[0][0];
                } else if (ca == '1') {
                    currentState = array[1][1];
                } else {
                    return false;
                }
                break;
            case 1:
                if (ca == '0'){
                    currentState = array[0][0];
                } else if (ca == '1') {
                    currentState = array[1][1];
                } else {
                    return false;
                }
                break;
            case 2:
                if (ca == '0') {
                    currentState = array[2][0];
                } else if (ca == '1') {
                    currentState = array[2][1];
                } else {
                    return false;
                }
                break;
            case 3:
                if (ca == '0') {
                    currentState = array[3][0];
                } else if (ca == '1') {
                    currentState = array[3][1];
                } else {
                    return false;
                }
                break;
            case 4:
                if (ca == '0') {
                    currentState = array[4][0];
                } else if (ca == '1') {
                    currentState = array[4][1];
                } else {
                    return false;
                }
                break;
        }
        std::cout<<"state"<<currentState<<" -> ";
    }
    return true;
}

int main() {


    if (fsa()) {
        std::cout << "finish" << std::endl;
    } else {
        std::cout << "Line is rejected" << std::endl;
    }

    return 0;
}

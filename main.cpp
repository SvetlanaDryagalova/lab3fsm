//Дрягалова Светлана
//Б18

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum class CatState {
    MEOW,
    EAT,
    SLEEP,
    PLAY
};

enum class PlayAction {
    OWNERS_FOOT,
    TOY,
    WRAP
};

PlayAction ChoosePlayAction() {
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            return PlayAction::OWNERS_FOOT;
        case 1:
            return PlayAction::TOY;
        case 2:
            return PlayAction::WRAP;
    }
}

int main() {
    srand(time(0));

    string name;
    cout << "Choose your cat's name";
    cin >> name;

    int time = 7;
    int is_fed = 0;

    CatState currentState = CatState::MEOW;

    while (time<20) {
        switch (currentState) {
            case CatState::MEOW:
                cout << "time:" << time << endl;
                cout << "You should feed " << name << endl;
                currentState = CatState::EAT;
                cout << "If you have fed " << name << " enter 1" << endl;
                cin >> is_fed;
                if (is_fed == 1){
                    is_fed = 0;
                    break;
                }

            case CatState::EAT:
                cout << "Now " << name << " is eating" << endl;
                currentState = CatState::SLEEP;
                break;
            case CatState::SLEEP:
                cout << name << " is sleeping" << endl;
                time = time + 4;
                currentState = CatState::PLAY;
                break;
            case CatState::PLAY: {
                PlayAction action = ChoosePlayAction();
                cout << "time:" << time << endl;
                switch (action) {
                    case PlayAction::OWNERS_FOOT:
                        cout << "Save yourself! " << name << " is playing with your foot" << endl;
                        break;
                    case PlayAction::TOY:
                        cout << name << " is playing with toy" << endl;
                        break;
                    case PlayAction::WRAP:
                        cout << name << " is playing with wrap" << endl;
                        break;
                }
                time  = time + 3;
                currentState = CatState::MEOW;
                break;
            }
        }
    }

    return 0;
}

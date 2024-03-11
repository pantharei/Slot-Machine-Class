#include "SlotMachine.h"
#include <iostream>

void menu(){
    using namespace std;
    cout << "Scegli Opzione : " << endl;
    cout << "1) Deposita Monete" << endl;
    cout << "2) Spin" << endl;
    cout << "3) Esci" << endl;
} 

void goodbye(){
    std::cout << "ARRIVEDERCI, ALLA PROSSIMA\n";
}

int main(){
    using namespace std;
    atexit(goodbye);
    SlotMachine s;

    bool cicle = true;
    while(cicle){
        menu();
        cout << "Monete : " << s.getMonete() << endl;
        int scelta = 0;
        cin >> scelta;

        switch (scelta)
        {
        case 1:{
            cout << "Inserisci monete da depositare:";
            int input = 0;
            cin >> input;

            if(input > 0)
                s.Deposito(input);
            break;
        }
        case 2:{
            if(s.getMonete() > 0)
                s.spin();
            else
                cout << "Monete insufficienti!\n";
            break;
        }
            
        default:
            cicle = false;
        }

    }

    return 0;
}
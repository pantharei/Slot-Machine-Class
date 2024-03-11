/*

Creare una classe che permetta di rappresentare una slot machine e un main per gestirla, 
deve funzionare così: inserita una moneta girano le tre rotelle della slot machine 
e appaiono tre simboli (nel nostro caso tre lettere), 
l’utente per due volte può decidere di tenere una o più lettere apparse o fermarsi, 
una volta che si ferma se c’è una coppia viene restituita una moneta 
se c’è un tris di lettere uguali vengono restituite un numero di monete pari alla posizione in ordine alfabetico della lettera del tris.

*/

#include <iostream>
#include <cstdlib>

const int MAX_MONETE = 10;

class SlotMachine{

    char slot_1;
    char slot_2;
    char slot_3;

    int monete;
    
    //metodo privato che stampa lo stato della slot machine
    //utilizzo : dopo una giocata
    void status()const{
        using std::cout;
        using std::endl;

        cout << " | ";
        cout << slot_1 << " | ";
        cout << slot_2 << " | ";
        cout << slot_3 << " | \n";
    }

    //i simboli possono essere solamente le lettere a,b,c
    bool check_symbol(char c)const{
        return (c == 'a' || c == 'b' || c == 'c');
    }

    char conversione(int in){
        char ret = 0;
        if(in <= 33)ret = 'a';
        else if(in <= 66) ret = 'b';
        else ret = 'c';
        return ret;
    }

    bool coppia()const{
        bool ret = false;

        if(slot_1 == slot_2 || slot_1 == slot_3 || slot_2 == slot_3)
            ret = true;

        return ret;
    }

    /*
    metodo invocato dopo uno spin;
    elabora se si è ottenuta una vittoria.
    In caso positivo aggiorna il deposito delle monete.
    */
    void compute_status(){
        using std::cout;
        int prize = 0;
        if(slot_1 == slot_2 && slot_3 == slot_2){
            if(slot_1 == 'a') prize = 1;
            else if(slot_2 == 'b') prize = 2;
            else prize = 3;
            monete+=prize;
        }else if(coppia()) (++monete, prize = 1);
        if(prize > 0)
            cout << "Hai vinto " << prize << " monete!\n";
        else cout << "Mi spiace, ritenta sarai piu' fortunato!\n";
    }

    public:

    SlotMachine() : slot_1(0), slot_2(0), slot_3(0), monete(0) {}

    //metodo che permette di aggiungere monete alla slot machine
    void Deposito(int amount){
        if(monete+amount <= MAX_MONETE)
            monete+=amount;
    }

    int getMonete()const{
        return monete;
    }

    void spin(){
        if(monete > 0){
        --monete;
        int estrazioni[3];
        srand(time(NULL)); //inizializzazione per generazione di numeri casuali
        for(int &random:estrazioni)
            random = rand()%100;

        slot_1 = conversione(estrazioni[0]);
        slot_2 = conversione(estrazioni[1]);
        slot_3 = conversione(estrazioni[2]);

        status();
        compute_status();
        slot_1 = slot_2 = slot_3 = 0;
        }
    }
};
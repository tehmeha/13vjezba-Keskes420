#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
    unsigned long long int brRacuna[50];
    string prezimeime[50];
    float saldo [50];
    int brojKlijenata = 0;
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;
    datotekaUcitavanje.open("banka.txt");
    while(1)
    {
         datotekaUcitavanje>> brRacuna[brojKlijenata];
        if (datotekaUcitavanje.eof() ==true)
        {
            break;
        }
            datotekaUcitavanje.ignore();
            getline(datotekaUcitavanje,prezimeime[brojKlijenata]);
            datotekaUcitavanje >> saldo[brojKlijenata];
            brojKlijenata++;
    }
    datotekaUcitavanje.close();
    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos nove osobe" << endl;
        cout << "2. Ispisi podatke" << endl;
        cout << "3. pretraga prema racunu" << endl;
        cout << "4. Pretraga prema prezimenu" << endl;
        cout << "5. Ispisi sortirano" << endl;
        cout << "6. Izlaz iz programa" << endl;
        int izbor;
        cin >> izbor;


        if( izbor == 1)
        {
            cout << "Unesite broj racuna: ";
            cin >> brRacuna[brojKlijenata];
            cout << "Unesite prezime i ime: " << endl;
            cin.ignore();
            getline(cin, prezimeime[brojKlijenata]);
            cout << "Unesite saldo: ";
            cin >> saldo[brojKlijenata];
             datotekaUpisivanje.open("artikli.txt", ios::app);
            datotekaUpisivanje << brRacuna [brojKlijenata]<<endl;
             datotekaUpisivanje<< prezimeime[brojKlijenata]<<endl;
             datotekaUpisivanje<< saldo [brojKlijenata] << endl;
             datotekaUpisivanje.close();
            brojKlijenata ++;

        }
        else if (izbor == 2)
        {
            for (int i = 0; i < brojKlijenata; i++)
            {
                cout <<"broj racuna: \t" <<   brRacuna[i] <<endl<< "ime i prezime: \t" << prezimeime[i] <<endl << " saldo: \t" << saldo[i] << endl;
            }
        }
        else if ( izbor == 3)
        {
            cout << "unesite broje racuna koji zelite pronaci: ";
            unsigned int brRacunaKojiTrazimo;
            cin >> brRacunaKojiTrazimo;
            for(int i = 0; i< brojKlijenata;i++)
            {
                if(brRacunaKojiTrazimo == brRacuna[i])
                {
                    cout << " Osoba je pronadjena. " << endl;
                    cout <<"broj racuna: \t" <<   brRacuna[i] <<endl<< "ime i prezime: \t" << prezimeime[i] <<endl << " saldo: \t" << saldo[i] << endl;
                    break;
                }
            }
        }
        else if (izbor == 4)
        {
            string naziv;
            cout << " upisite prezime osobe; ";
                cin.ignore();
                getline( cin, naziv);
                bool pronadjen = false;
                for(int i = 0; i< brojKlijenata; i++)
                {

                    if(naziv == prezimeime[i])
                    {
                        cout << brRacuna[i] <<  "\t";
                        cout << prezimeime[i] << "\t";
                        cout << saldo[i] << "\t" << endl;
                        pronadjen=true;
                        break;

                    }
                    if(pronadjen == false)
                    {
                        cout << "racun ne postoji:" << endl;
                    }
                }
        }
        else if ( izbor == 5)
        {
        int n = brojKlijenata;
        int temp;
        for (int kraj = n-1; kraj >=0; kraj --)
        {

            for (int i =0; i< kraj; i++)
            {
                if (prezimeime[i] > prezimeime[i+1])
                {
                    temp = prezimeime [i];
                    prezimeime[i] =prezimeime[i+1];
                    prezimeime[i+1] = temp;
                }

            }
            }

        }
        else if( izbor ==6 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        cout << endl;
    }
}


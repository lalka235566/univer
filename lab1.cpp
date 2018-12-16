#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Menu(int &punkt),
    FuncVivoda(vector<string> &spisok, int &i),
    Dobavit(vector<string> &spisok, int &id),
	Ydalit(vector<string> &spisok),
	Pokazat(vector<string> &spisok),
	Sortirovka(vector<string> &spisok),
	SortirovkaPoDate(vector<string> &spisok),
    SortirovkaPoDur(vector<string> &spisok),
    SortirovkaPoFrom(vector<string> &spisok),
    SortirovkaPoTo(vector<string> &spisok);

int main(){
	int punkt, id=1;
	vector<string> spisok;
	Menu(punkt);
	while (punkt >= 1 && punkt <= 8){
		switch (punkt){
		case 1:
			system("cls");
			cin.get();
			Dobavit(spisok, id);
			Menu(punkt);
			break;
		case 2:
			system("cls");
			Ydalit(spisok);
			Menu(punkt);
			break;
		case 3:
			system("cls");
			cin.get();
			Pokazat(spisok);
			Menu(punkt);
			break;
		case 4:
			system("cls");
			Sortirovka(spisok);
			Menu(punkt);
			break;
		case 5:
			system("cls");
			SortirovkaPoDate(spisok);
			Menu(punkt);
			break;
		case 6:
			system("cls");
			SortirovkaPoDur(spisok);
			Menu(punkt);
			break;
		case 7:
			system("cls");
			SortirovkaPoFrom(spisok);
			Menu(punkt);
			break;
		case 8:
			system("cls");
			SortirovkaPoTo(spisok);
			Menu(punkt);
			break;
		}}
	system("pause");
	return 0;
}

void Dobavit(vector<string> &spisok, int &id) {
	string from, to, date, time, dur;
	cout << "Vvedite from: "; getline(cin, from);
	cout << "Vvedite to: ";  getline(cin, to);
	cout << "Vvedite date: ";  getline(cin, date);
	cout << "Vvedite time: ";  getline(cin, time);
	cout << "Vvedite dlitelnost: ";  getline(cin, dur);
	spisok.push_back(to_string(id));
	spisok.push_back(from);
	spisok.push_back(to);
	spisok.push_back(date);
	spisok.push_back(time);
	spisok.push_back(dur);
	id++;
}

void Ydalit(vector<string> &spisok) {
    int _id, it=0;
    cout<<"Vvedite id visova kotoriy hotite ydalit: "; cin>>_id;
    try{
    for(int i=0; i<spisok.size(); i+=6){
        if(spisok.at(i)==to_string(_id)){
            spisok.erase(spisok.begin()+i, spisok.begin()+(i+6));}
    }} catch (const std::out_of_range& oor){}
    system("pause");
}

void Pokazat(vector<string> &spisok) {
	for(int i=0; i<spisok.size(); i++){
            cout << spisok.at(i) << "\t";
            if((i+1)%6==0 && i!=0) cout<<endl;}
    system("pause");
}

void Sortirovka(vector<string> &spisok){
    int date, date1, n, m;
    string temp[6];
    div_t d1, d2;
    istringstream ss(spisok.at(3));
    while (ss){
        ss >> date;
    }
    for(int i=0; i<spisok.size(); i+=6)
    {
        for(int j=0; j<6; j++)
        {
            temp[j]=spisok.at(i+j);
        }
        istringstream iss(temp[3]);
        while (iss){
            iss >> date1;
        }
        n = date1%100;
        m = date%100;
        if(n<m){
            d1=div(date1,100);
            d2=div(date,100);
            n=d1.quot%100;
            m=d2.quot%100;
            if(n<m){
                d1=div(date1,10000);
                d2=div(date,10000);
                n=d1.quot;
                m=d2.quot;
                if(n<m){
                    spisok.at(i)=spisok.at(i-6);
                    spisok.at(i+1)=spisok.at(i-5);
                    spisok.at(i+2)=spisok.at(i-4);
                    spisok.at(i+3)=spisok.at(i-3);
                    spisok.at(i+4)=spisok.at(i-2);
                    spisok.at(i+5)=spisok.at(i-1);

                    spisok.at(i-6)=temp[0];
                    spisok.at(i-5)=temp[1];
                    spisok.at(i-4)=temp[2];
                    spisok.at(i-3)=temp[3];
                    spisok.at(i-2)=temp[4];
                    spisok.at(i-1)=temp[5];
                }
            }
        }
    }
}

void SortirovkaPoDur(vector<string> &spisok){
    int start, fin, lis;
    cout<<"Vvedite minimalnyu dlitelnost: "; cin>>start;
    cout<<"Vvedite maximalnyu dlitelnost: "; cin>>fin;
    for(int i=0; i<spisok.size(); i+=6)
    {
        istringstream ss(spisok.at(i+5));
        while (ss){
            ss >> lis;
        }
        if(lis>start && lis<fin){
            FuncVivoda(spisok, i);
        }
    }
    system("pause");
}

void SortirovkaPoDate(vector<string> &spisok){
    int start, fin, n , m, temp, lis;
    div_t d;
    cout<<"Vvedite minimalnyu daty: "; cin>>start;
    cout<<"Vvedite maximalnyu daty: "; cin>>fin;
    for(int i=0; i<spisok.size(); i+=6)
    {
        n = start%100;
        m = fin%100;
        istringstream ss(spisok.at(i+3));
        while (ss){
            ss >> temp;
        }
        lis=temp%100;
        if(lis>n && lis<m)
        {
            FuncVivoda(spisok, i);
        }
        else{
            d=div(start,100);
            n=d.quot%100;
            d=div(fin,100);
            m=d.quot%100;
            d=div(temp,100);
            lis=d.quot%100;
            if(lis>n && lis<m){
                FuncVivoda(spisok, i);
            }
            else{
                d=div(start,10000);
                n=d.quot%100;
                d=div(fin,10000);
                m=d.quot%100;
                d=div(temp,10000);
                lis=d.quot%100;
                if(lis>n && lis<m){
                    FuncVivoda(spisok, i);
                }
            }
            }
    }
    system("pause");
}

void SortirovkaPoFrom(vector<string> &spisok){
    string from;
    cout<<"Vvedite from: "; cin>>from;
    for(int i=0; i<spisok.size(); i+=6)
    {
        if(spisok.at(i+1)==from){
            FuncVivoda(spisok, i);
        }
    }
    system("pause");
}

void SortirovkaPoTo(vector<string> &spisok){
    string to;
    cout<<"Vvedite to: "; cin>>to;
    for(int i=0; i<spisok.size(); i+=6)
    {
        if(spisok.at(i+2)==to){
            FuncVivoda(spisok, i);
        }
    }
    system("pause");
}

void FuncVivoda(vector<string> &spisok, int &i){
    cout << spisok.at(i) << "\t";
    cout << spisok.at(i+1) << "\t";
    cout << spisok.at(i+2) << "\t";
    cout << spisok.at(i+3) << "\t";
    cout << spisok.at(i+4) << "\t";
    cout << spisok.at(i+5) << "\t";
    cout<<endl;
}

void Menu(int &punkt) {
	system("cls");
	cout << "1. dobavit visov" << endl;
	cout << "2. edalit visov po id" << endl;
	cout << "3. pokazat spisok" << endl;
	cout << "4. sortirovka spiska po date" << endl;
	cout << "5. pokazat spisok v promezhytke dat" << endl;
	cout << "6. pokazat spisok v promezhytke dlitelnosti" << endl;
	cout << "7. sortirovka spiska po from" << endl;
	cout << "8. sortirovka spiska po to" << endl;
	cin >> punkt;
}

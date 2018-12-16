#include <iostream>
using namespace std;

class Complex {
private:
    double r, i;
public:
    Complex() : r(0.0), i(0.0) { }
    Complex(double ar, double ai) : r(ar), i (ai) { }

    void Vvod();
    void Print();

    friend Complex operator+(Complex a, Complex b);
    friend Complex operator-(Complex a, Complex b);
    friend Complex operator*(Complex a, Complex b);
};

int main(){
    int v = 1;
    setlocale (LC_ALL, "Russian");
    Complex a, b;
    while(true){
        cout<<"1-�������� �����"<<endl;
        cout<<"2-��������� �����"<<endl;
        cout<<"3-��������� �����"<<endl;
        cout<<"0-�����"<<endl;
        cin >> v;
        if(v==0){
            break;
        }
        if(v<1 || v>3){
            cout<<"������!"<<endl;
            continue;
        }
        cout<<"\n������� ������ �����:\n";
        a.Vvod();
        cout<<"\n������� ������ �����:\n";
        b.Vvod();
        cout<<endl;
        switch(v){
            case 1:
                cout<<"��������� ��������: ";
                (a + b).Print();
                break;
            case 2:
                cout<<"��������� ���������: "<<endl;
                (a * b).Print();
                break;
            case 3:
                cout<<"��������� ���������: "<<endl;
                (a - b).Print();
                break;
        }
    }
    return 0;
}

void Complex::Print(){
    cout<<r<<"+i*";
    if(i<0){
        cout<<"(" << i << ")";
    }
    else{
        cout<<i;
    }
    cout<<endl;
}

void Complex::Vvod(){
    cout<<"  �������������� ����� �����: ";
    cin>>r;
    cout<<"  ������ ����� �����: ";
    cin>>i;
    cout<<"  ������� �����: ";
    Print();
}

Complex operator+(Complex a, Complex b){
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(Complex a, Complex b){
    return Complex(a.r - b.r, a.i - b.i);
}

Complex operator*(Complex a, Complex b){
    return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

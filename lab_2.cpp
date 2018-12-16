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
        cout<<"1-Сложение чисел"<<endl;
        cout<<"2-Умножение чисел"<<endl;
        cout<<"3-Вычитание чисел"<<endl;
        cout<<"0-Выход"<<endl;
        cin >> v;
        if(v==0){
            break;
        }
        if(v<1 || v>3){
            cout<<"Ошибка!"<<endl;
            continue;
        }
        cout<<"\nВведите первое число:\n";
        a.Vvod();
        cout<<"\nВведите второе число:\n";
        b.Vvod();
        cout<<endl;
        switch(v){
            case 1:
                cout<<"Результат сложения: ";
                (a + b).Print();
                break;
            case 2:
                cout<<"Результат умножения: "<<endl;
                (a * b).Print();
                break;
            case 3:
                cout<<"Результат вычитания: "<<endl;
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
    cout<<"  действительная часть числа: ";
    cin>>r;
    cout<<"  мнимая часть числа: ";
    cin>>i;
    cout<<"  введено число: ";
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

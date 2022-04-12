#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String A{ "Hello " }, B{ "World" }; // создадим пару объектов
    A.Show();
    B.Show();
    //проверим работу методов
    A = B;
    cout << "\n";
    cout << A;
    A.Add(B);

    cout << "\n";
    cout << A;

    String C(" !");
    A.Add(C);
    cout << A;

    //теперь перенесем
    cout << "\n";
    A = std::move(C); // оператор переноса отрабатывает нормально
    cout << A;
    cout << C;
    // работает

    cout << "\nObjects - " << A.Get_count();


    
}


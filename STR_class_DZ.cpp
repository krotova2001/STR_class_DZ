#include <iostream>
#include "String.h"
#include "Array.h"
using namespace std;
#include <ctime>


int main()
{
    srand(time(0));
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
    cout << C; // все ок, объекта C нет...

    cout << "\nStrings - " << A.Get_count();
    cout << "\n\n";

    Array T{5}; // создадим объект - массив с 5 элементами
    T.Init_random(); // заполним случайными значениями
    T.Show(); // посмотрим
    Array T1(2); // то же самое со вторым объектом на 6 элементов
    T1.Init_user();
    T1.Show();
    
    //проверим методы
    T.Add(T1);
    T.Append(10);
    T.Show(); // посмотрим
    T1 = T+T1; // проверяем перегрузку = и +
    T1.Show(); // посмотрим
    T1 = 1000 + T; // проверка перегрузки + для двух операндов
    T1.Show(); // посмотрим

    //теперь перенесем
    cout << "\n";
    Array T2(2);
    T2.Init_random();
    T1 = std::move(T2);
    T1.Show(); // посмотрим
    cout << "\nArrays - " << T.GetCount();



    
}


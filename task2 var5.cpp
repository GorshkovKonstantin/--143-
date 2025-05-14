#include <iostream>
using namespace std;

/**
*@brief Перевод веса из граммов 6 унции
*@param gramms бес 6 граммах
*@param ounces константа для перевода (1 унция = 28.3 грамма)
*@return возвращает значение в унциях
*/
double gramms_in_ounces(double gramms, double const ounces);

/**
 * @brief Запрашивает ввод данных с клавиатуры
 * @return возвращает значение в граммах
*/ 
double testinput();

int main() {
    setlocale(LC_ALL, "ru");
    const double ounces = 28.3;
    
    double gramms = testinput();
    if (gramms < 0) {
        cout << "Ошибка: вес не может быть отрицательным!" << end1;
        return 1;
    }
    cout << "Ввод выполнен корректно!" << endl;
    cout << "Вес в унциях:"<< gramms_in_ounces (gramms, ounces);
    
    return 0;
}

double gramms_in_ounces(double gramms, double const ounces) {
    return gramms / ounces;
}

double testinput() {
    double gramms;
    cout <<"Введите вес в граммах: ";
    cin >> gramms; 
    return gramms;
}
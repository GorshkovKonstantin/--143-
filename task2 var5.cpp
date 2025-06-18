#include <iostream>
#include <limits> // для numetric_limits

using namespace std;

/**
*@brief Перевод веса из граммов в унции
*@param gramms вес в граммах
*@param ounces константа для перевода (1 унция = 28.3 грамма)
*@return возвращает значение в унциях
*/
double gramms_in_ounces(const double gramms, double const ounces);// все переменные константы

/**
 * @brief Запрашивает ввод данных с клавиатуры и проверяет корректность ввода
 * @return возвращает значение в граммах (или -1 в случае ошибки)
*/ 
double testinput();

/**
    * @bief главная функция программы
    * @return 0  если успешно, 1 если ошибка
    */
int main() {
    setlocale(LC_ALL, "ru");
    const double ounces = 28.3;
    
    double gramms = testinput();
    if (gramms < 0) {
        cout << "Ошибка: вес не может быть отрицательным!" << endl;
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
    double gramms = 0.0; //инициализация переменной
    cout <<"Введите вес в граммах: ";
    cin >> gramms; //проверка корректности ввода
    if (cin.fail()){
        cout << "ошибка: некорректный ввод" << endl;
        cin.clear();//сбрасываем флаг ошибки
        cin.ignore(numetric_limits<streamsize>:max(), '\n'); //очищаем буфер ввода
        abort();// возвращаем прерывание пррограммы
        return -1;// возвращаем -1, чтобы обозначить ошибку
    }
    return gramms;
}

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетворяет условию n>=1
 * @param n считанное значение
 */
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
 */
double calculateFirstNSeriesSum(const int n);
/**
 * @brief проверяет, что введенное значение удовлетворяет условию e>0
 * @param e считанное значение
 */
void checkE(const double e);

/**
 * @brief Рассчитывает сумму членов ряда, не меньших по модулю e 
 * @param e заданная точность
 * @return сумму членов ряда, не меньших по модулю e
 */
double calculateSeriesSumAboveEpsilon(const double e);
/**
* @brief точка входа в программу
* @return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите число членов ряда для рассчета последовательности: ";
    int n = getValue();
    checkN(n);
    cout << "Сумма " << n << " членов ряда равна "
        << fixed << setprecision(2) << calculateFirstNSeriesSum(n) << endl;

    cout << "Введите погрешность для рассчета последовательности: ";
    double e = getDouble();
    checkE(e);
    cout << "Сумма членов ряда с точностью e равна "
        << fixed << setprecision(2) << calculateSeriesSumAboveEpsilon(e) << endl;

    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 1)
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
}

void checkE(const double e)
{
    if (e <= 0)
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
}

double calculateFirstNSeriesSum(const int n)
{
    double sum = 0.0;
    double term = -1.0; 

    for (int k = 1; k < n; ++k) 
    {
        sum += term;
        term = term * (-1.0) * pow(k + 1, 3) / pow(k, 4);
    }

    return sum;
}

double calculateSeriesSumAboveEpsilon(const double epsilon)
{
    double sum = 0.0;
    int k = 1;
    double term = -1.0; 

    while (fabs(term) >= epsilon) {
        sum += term;
        term = term * (-1.0) * pow(k + 1, 3) / pow(k, 4);
        k++;
    }

    return sum;
}
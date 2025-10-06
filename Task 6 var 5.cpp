
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, int min, int max);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, int min, int max);

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief Копирует массив целых чисел.
 * @param source Указатель на исходный массив целых чисел, который необходимо скопировать.
 * @param n Размер исходного массива (количество элементов).
 * @return Указатель на новый массив, содержащий копию элементов исходного массива.
 */
int* copyArray(const int* source, const int n);

/**
 * @brief Заменяет последние k элементов массива на противоположные по знаку.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param k Количество последних элементов для замены на противоположные.
 */
void replaceLastKWithOpposite(int* arr, const int n, int k);

/**
 * @brief Выводит индексы элементов массива, которые кратны 3.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 */
void printIndicesOfMultiplesOfThree(const int* arr, const int n);

/**
 * @brief Определяет, есть ли пара соседних элементов с заданной суммой.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param target Сумма, которую необходимо проверить.
 * @return Индекс первого элемента пары, если пара найдена; -1 в противном случае.
 */
int findPairWithSum(const int* arr,const  int n,const int target);


/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    //setlocale(LC_ALL, "Russian"); // Removed: setlocale is not fully cross-platform

    size_t n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное значение диапазона: ";
    int minValue = getNumber();

    cout << "Введите максимальное значение диапазона: ";
    int maxValue = getNumber();

    checkRange(minValue, maxValue);

    cout << "Выберите способ заполнения массива:" << endl
         << RANDOM << " — случайно" << endl
         << MANUALLY << " — вручную" << endl;

    int choice = getNumber();

    switch (choice) {
        case RANDOM:
            fillArrayRandom(arr, (int)n, minValue, maxValue);
            break;
        case MANUALLY:
            fillArray(arr, (int)n, minValue, maxValue);
            break;
        default:
            cout << "Неверный выбор." << endl;
            delete[] arr;
            return 1;
    }

    cout << "Исходный массив:" << endl;
    printArray(arr, (int)n);

    int* copy1 = copyArray(arr, (int)n);
     if (copy1==nullptr) {
        cout << "Не удалось выделить память для copy1." << endl;
        delete[] arr;
        return 1;
     }

    cout << "Введите количество последних элементов для замены на противоположные: ";
    int k = getNumber();
    replaceLastKWithOpposite(copy1, (int)n, k);
    cout << "Массив после замены последних " << k << " элементов на противоположные:" << endl;
    printArray(copy1, (int)n);


    int* copy2 = copyArray(arr, (int)n);
        if (copy2==nullptr) {
        cout << "Не удалось выделить память для copy2." << endl;
        delete[] arr;
        delete[] copy1;
        return 1;
    }
    cout << "Индексы элементов, кратных 3:" << endl;
    printIndicesOfMultiplesOfThree(copy2, (int)n);


    int* copy3 = copyArray(arr, (int)n);
    if (copy3==nullptr) {
        cout << "Не удалось выделить память для copy3." << endl;
        delete[] arr;
        delete[] copy1;
        delete[] copy2;
        return 1;
    }
    cout << "Введите целевую сумму для поиска пары: ";
    int target = getNumber();
    int pairIndex = findPairWithSum(copy3, (int)n, target);
    if (pairIndex != -1) {
        cout << "Пара найдена на индексах " << pairIndex << " и " << pairIndex + 1 << ", сумма = " << target << endl;
    }
    else {
        cout << "Пара с суммой " << target << " не найдена." << endl;
    }

    delete[] arr;
    delete[] copy1;
    delete[] copy2;
    delete[] copy3;

    return 0;
}


/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n) {
    if (n <= 0) {
        cout << "Размер массива должен быть положительным!" << endl;
        exit(1);
    }
}

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize()
{
    cout << "Введите размер массива: ";
    int n=0;
    cin >> n;
    if (cin.fail()) {
         cout << "Ошибка ввода!" << endl;
        exit(1);
    }
    checkN(n);
    return (size_t)n;
}

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber() {
    int number=0;
    cin >> number;
     if (cin.fail()) {
         cout << "Ошибка ввода!" << endl;
        exit(1);
    }
    return number;
}

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max) {
    if (min > max) {
        cout << "Неверный диапазон: минимальное значение больше максимального!" << endl;
        exit(1);
    }
}

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, int min, int max) {
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, int min, int max) {
    for (size_t i= 0; i < n; i++) {
        cout << "Введите элемент arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max) {
            cout << "Элемент вне допустимого диапазона! Повторите ввод." << endl;
            abort();
        }
    }
}

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

/**
 * @brief Копирует массив целых чисел.
 * @param source Указатель на исходный массив целых чисел, который необходимо скопировать.
 * @param n Размер исходного массива (количество элементов).
 * @return Указатель на новый массив, содержащий копию элементов исходного массива.
 */
int* copyArray(const int* source,const int n) {
    int* newArr = new int[n];
    for (size_t i = 0; i < n; i++) {
        newArr[i] = source[i];
    }
    return newArr;
}

/**
 * @brief Заменяет последние k элементов массива на противоположные по знаку.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param k Количество последних элементов для замены на противоположные.
 */
void replaceLastKWithOpposite(int* arr, const int n, int k) {
    if (k <= 0) return;
    if (k > n) {
       cout << "Количество элементов для замены превышает размер массива. Будут заменены все элементы." << endl;
       k = n; // Correctly adjusts k to be equal to n
    }

    for (int i = n - k; i < n; i++) {  // Use int for i, and start from n-k
        arr[i] = -arr[i];
    }
}

/**
 * @brief Выводит индексы элементов массива, которые кратны 3.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 */
void printIndicesOfMultiplesOfThree(const int* arr, const int n) {
    bool found = false;
    cout << "Индексы элементов, кратных 3: ";
    for (size_t i= 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Нет элементов, кратных 3.";
    }
    cout << endl;
}

/**
 * @brief Определяет, есть ли пара соседних элементов с заданной суммой.
 * @param arr Указатель на массив целых чисел.
 * @param n Размер массива.
 * @param target Сумма, которую необходимо проверить.
 * @return Индекс первого элемента пары, если пара найдена; -1 в противном случае.
 */
int findPairWithSum(const int* arr,const  int n,const int target) {
     if (n < 2) return -1; // Need at least 2 elements for a pair to exist
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] + arr[i + 1] == target) {
            return (int)i; // Explicitly cast size_t to int
        }
    }
    return -1;
}


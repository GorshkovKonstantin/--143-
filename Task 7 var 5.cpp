#include <iostream>
#include <vector>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <limits>  // Для numeric_limits

using namespace std;

// Объявления функций (прототипы)
void fillRandom(vector<vector<int>>& arr, size_t n, size_t m, int minVal, int maxVal);
void fillKeyboard(vector<vector<int>>& arr, size_t n, size_t m);
void printArray(const vector<vector<int>>& arr, size_t n, size_t m);
void replaceMaxWithOppositeSign(vector<vector<int>>& arr, size_t n, size_t m);
void insertZeroColumnsAfterMaxColumns(vector<vector<int>>& arr, size_t n, size_t& m);


int main() {
  size_t n, m;
  int minVal, maxVal;

  cout << "Введите количество строк (n): ";
  cin >> n;
  cout << "Введите количество столбцов (m): ";
  cin >> m;

  // Создаем многомерный массив (вектор векторов)
  vector<vector<int>> arr(n, vector<int>(m));

  int choice;
  cout << "Выберите способ заполнения массива:" << endl;
  cout << "1. Случайными числами" << endl;
  cout << "2. С клавиатуры" << endl;
  cout << "Ваш выбор: ";
  cin >> choice;

  if (choice == 1) {
    cout << "Введите минимальное значение диапазона: ";
    cin >> minVal;
    cout << "Введите максимальное значение диапазона: ";
    cin >> maxVal;
    fillRandom(arr, n, m, minVal, maxVal);
  } else if (choice == 2) {
    fillKeyboard(arr, n, m);
  } else {
    cout << "Неверный выбор." << endl;
    return 1;
  }

  cout << "\nИсходный массив:" << endl;
  printArray(arr, n, m);

  replaceMaxWithOppositeSign(arr, n, m);
  cout << "\nМассив после замены максимальных элементов:" << endl;
  printArray(arr, n, m);

  insertZeroColumnsAfterMaxColumns(arr, n, m);
  cout << "\nМассив после вставки столбцов из нулей:" << endl;
  printArray(arr, n, m);

  return 0;
}


// Функция для заполнения массива случайными числами
void fillRandom(vector<vector<int>>& arr, size_t n, size_t m, int minVal, int maxVal) {
  srand(time(0)); // Инициализация генератора случайных чисел
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
    }
  }
}

// Функция для заполнения массива с клавиатуры
void fillKeyboard(vector<vector<int>>& arr, size_t n, size_t m) {
  cout << "Введите элементы массива:" << endl;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      cout << "arr[" << i << "][" << j << "] = ";
      cin >> arr[i][j];
    }
  }
}

// Функция для вывода массива на экран
void printArray(const vector<vector<int>>& arr, size_t n, size_t m) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// 1. Функция для замены максимального элемента каждой строки на противоположный по знаку
void replaceMaxWithOppositeSign(vector<vector<int>>& arr, size_t n, size_t m) {
  for (size_t i = 0; i < n; ++i) {
    int maxVal = arr[i][0];
    size_t maxIndex = 0;

    for (size_t j = 1; j < m; ++j) {
      if (arr[i][j] > maxVal) {
        maxVal = arr[i][j];
        maxIndex = j;
      }
    }

    arr[i][maxIndex] = -maxVal; // Заменяем на противоположный знак
  }
}

// 2. Функция для вставки после всех столбцов, содержащих максимальный элемент столбец из нулей
void insertZeroColumnsAfterMaxColumns(vector<vector<int>>& arr, size_t n, size_t& m) {
  vector<size_t> maxColumnIndices; // Храним индексы столбцов с максимальными элементами

  // Находим индексы столбцов с максимальными элементами хотя бы в одной строке
  for (size_t j = 0; j < m; ++j) {
    bool hasMax = false;
    for (size_t i = 0; i < n; ++i) {
      int maxValInRow = arr[i][0];
      for (size_t k = 1; k < m; ++k){
          maxValInRow = max(maxValInRow, arr[i][k]);
      }
      if (arr[i][j] == maxValInRow) {
        hasMax = true;
        break;
      }
    }
    if (hasMax) {
      maxColumnIndices.push_back(j);
    }
  }

  // Вставляем столбцы из нулей.  Важно итерироваться в обратном порядке, чтобы индексы не сбивались
  for (int i = (int)maxColumnIndices.size() - 1; i >= 0; --i) {
    size_t columnIndex = maxColumnIndices[i];
    for (size_t row = 0; row < n; ++row) {
      arr[row].insert(arr[row].begin() + columnIndex + 1, 0);
    }
    ++m; // Увеличиваем количество столбцов
  }
}

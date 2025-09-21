#include <iostream>
#include <vector>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <limits>  // Для numeric_limits

using namespace std;

// Функция для заполнения массива случайными числами
void fillRandom(vector<vector<int>>& arr, int n, int m) {
  srand(time(0)); // Инициализация генератора случайных чисел
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = rand() % 100 - 50; // Случайные числа от -50 до 49
    }
  }
}

// Функция для заполнения массива с клавиатуры
void fillKeyboard(vector<vector<int>>& arr, int n, int m) {
  cout << "Введите элементы массива:" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << "arr[" << i << "][" << j << "] = ";
      cin >> arr[i][j];
    }
  }
}

// Функция для вывода массива на экран
void printArray(const vector<vector<int>>& arr, int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// 1. Функция для замены максимального элемента каждой строки на противоположный по знаку
void replaceMaxWithOppositeSign(vector<vector<int>>& arr, int n, int m) {
  for (int i = 0; i < n; ++i) {
    int maxVal = arr[i][0];
    int maxIndex = 0;

    for (int j = 1; j < m; ++j) {
      if (arr[i][j] > maxVal) {
        maxVal = arr[i][j];
        maxIndex = j;
      }
    }

    arr[i][maxIndex] = -maxVal; // Заменяем на противоположный знак
  }
}

// 2. Функция для вставки после всех столбцов, содержащих максимальный элемент столбец из нулей
void insertZeroColumnsAfterMaxColumns(vector<vector<int>>& arr, int n, int& m) {
  vector<int> maxColumnIndices; // Храним индексы столбцов с максимальными элементами

  // Находим индексы столбцов с максимальными элементами хотя бы в одной строке
  for (int j = 0; j < m; ++j) {
    bool hasMax = false;
    for (int i = 0; i < n; ++i) {
      int maxValInRow = arr[i][0];
      for (int k = 1; k < m; ++k){
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
  for (int i = maxColumnIndices.size() - 1; i >= 0; --i) {
    int columnIndex = maxColumnIndices[i];
    for (int row = 0; row < n; ++row) {
      arr[row].insert(arr[row].begin() + columnIndex + 1, 0);
    }
    ++m; // Увеличиваем количество столбцов
  }
}

int main() {
  int n, m;

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
    fillRandom(arr, n, m);
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
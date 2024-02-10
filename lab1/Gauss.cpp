#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int
main ()
{
  int i, j, n, m;
  // создаем массив
  cout << "Введите количество уравнений: ";
  cin >> n;

  cout << "Введите количество переменных: ";
  cin >> m;

  m += 1;
  float **matrix = new float *[n];
  for (i = 0; i < n; i++)
    matrix[i] = new float[m];

  // инициализируем
  for (i = 0; i < n; i++)

    for (j = 0; j < m; j++)
      {
        cout << " Элемент "
             << "[" << i + 1 << " , " << j + 1 << "]: ";

        cin >> matrix[i][j];
      }

  // выводим массив
  cout << "matrix: " << endl;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        cout << matrix[i][j] << " ";
      cout << endl;
    }
  cout << endl;

  // Метод Гаусса
  //(получение нулей под главной диагональю)
  float tmp;
  int k;
  float *xx = new float[m];

  for (i = 0; i < n; i++)
    {
      tmp = matrix[i][i];

      for (j = n; j >= i; j--)
        matrix[i][j] /= tmp;

      for (j = i + 1; j < n; j++)
        {
          tmp = matrix[j][i];
          for (k = n; k >= i; k--)
            matrix[j][k] -= tmp * matrix[i][k];
        }
    }
  //(получение нулей над главной диагональю)
  xx[n - 1] = matrix[n - 1][n];
  for (i = n - 2; i >= 0; i--)
    {
      xx[i] = matrix[i][n];
      for (j = i + 1; j < n; j++)
        xx[i] -= matrix[i][j] * xx[j];
    }

  // Вывод
  for (i = 0; i < n; i++)
    cout << xx[i] << " ";
  cout << endl;

  delete[] matrix;
  return 0;
}
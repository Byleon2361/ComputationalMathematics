#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<double>
solveSystem (const vector<vector<double> > &A, const vector<double> &B,
             double tolerance = 0.01, int maxIterations = 1000)
{
  int n = A.size ();
  vector<double> x (n, 0); // Начальное приближение
  int iterations = 0; // Переменная для подсчета итераций

  for (int iter = 0; iter < maxIterations; iter++)
    {
      vector<double> newX (n, 0);

      // Вычисляем новое приближение для каждой переменной
      for (int i = 0; i < n; i++)
        {
          double sum = B[i];
          for (int j = 0; j < n; j++)
            {
              if (i != j)
                {
                  sum -= A[i][j] * x[j];
                }
            }
          newX[i] = sum / A[i][i];
        }

      // Проверяем условие останова
      bool stop = true;
      for (int i = 0; i < n; i++)
        {
          if (fabs (newX[i] - x[i]) > tolerance)
            {
              stop = false;
              break;
            }
        }

      if (stop)
        {
          cout << "Решение найдено на " << iterations << " шаге." << endl;
          return newX; // Возвращаем решение
        }

      x = newX;     // Обновляем приближение
      iterations++; // Увеличиваем счетчик итераций
    }

  cout << "Решение не сходится к заданной точности в " << maxIterations
       << " итераций." << endl;
  return {}; // Возвращаем пустой вектор в случае неудачи
}

int
main ()
{
  setlocale (LC_ALL, "rus");
  vector<vector<double> > A = { { 5, -1, 2 }, { -2, -10, 3 }, { 1, 2, 5 } };
  vector<double> B = { 3, -4, 12 };

  vector<double> solution = solveSystem (A, B);

  cout << "Решение СЛАУ:" << endl;
  for (int i = 0; i < solution.size (); i++)
    {
      cout << "x[" << i << "] = " << solution[i] << endl;
    }

  return 0;
}
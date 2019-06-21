#include <iostream>

#include "SumOfSubset.hpp"
#include "UtilityProvider.hpp"

int main() {
  int n, sum;
  std::cout << "Enter the size of array" << std::endl;

  std::cin >> n;

  int *arr = (int *)malloc(sizeof(int) * n);

  UtilityProvider u;
  u.ArrayPopulator<int>(arr, n);

  std::cout << "List: ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << "\nPlease enter the sum: " << std::endl;
  std::cin >> sum;

  SumOfSubset s;

  const clock_t begin_time = clock();

  if (!s.EvaluateSumOfSubset(arr, n, sum))
    std::cout << "Subset for sum " << sum << " not found! :p" << std::endl;

  clock_t execution_time = clock() - begin_time / CLOCKS_PER_SEC;

  std::cout << "\nTime: ";
  u.ShowExecutionTimeRecursive(execution_time);

  free(arr);

  return 0;
}
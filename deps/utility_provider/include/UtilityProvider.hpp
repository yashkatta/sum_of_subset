#pragma once

class UtilityProvider {
 private:
  /* data */
 public:
  UtilityProvider(/* args */) {}
  ~UtilityProvider() {}

  int NormalizedValue(float val, float maxVal, float minVal, float desiredMax,
                      float desiredMin);
  void GenerateRandomString(char *str, int n);

  template <typename T>
  void ArrayPopulator(T *arr, unsigned int size);

  template <typename T>
  void AdjecencyMatrixForBiDirectionalGraphPopulator(T **arr,
                                                     unsigned int size);

  template <typename T>
  void AdjecencyMatrixForGraphPopulator(T **arr, unsigned int size);

  void ShowExecutionTime(long int t);

  void ShowExecutionTimeRecursive(long int t);
};
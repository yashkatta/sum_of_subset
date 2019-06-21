#pragma once
#include <algorithm>
#include <iostream>

class SumOfSubset {
 private:
  /* data */
  bool *m_x, m_subsetFound = false;

  template <typename T>
  void SumOfSubsetByBacktracking(T *w, T s, long int k, T r, T m);

 public:
  SumOfSubset(/* args */) {}
  ~SumOfSubset() { delete[] m_x; }

  template <typename T>
  bool EvaluateSumOfSubset(T *w, long int n, T m);
};

// Find all the subsets of w[0:n-1] that sum to m. Tthe values of x[j],
// 0 <= j < k, have already been determined. s = SUM j=0 to k-1 w[j] * x[j]
// and r = SUM j=k to n w[j]. The w[j]'s are nondecreasing order.
// It is assumed that w[1] <= m and SUM i=0 to n-1 >= m.
template <typename T>
void SumOfSubset::SumOfSubsetByBacktracking(T *w, T s, long int k, T r, T m) {
  // Generate left child. Note: s + w[k] <= m since Bk-1 is true.
  m_x[k] = 1;
  if (s + w[k] == m) {  // Subset found
    std::cout << "Subset Found: ";
    for (int i = 0; i <= k; i++)
      if (m_x[i] == 1) std::cout << w[i] << " ";
    std::cout << std::endl;
    m_subsetFound = true;
  } else if (s + w[k] + w[k + 1] <= m)
    SumOfSubsetByBacktracking(w, s + w[k], k + 1, r - w[k], m);

  // Generate right child and evaluate Bk.
  if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
    m_x[k] = 0;
    SumOfSubsetByBacktracking(w, s, k + 1, r - w[k], m);
  }
}

template <typename T>
bool SumOfSubset::EvaluateSumOfSubset(T *w, long int n, T m) {
  m_x = new bool[n];
  T sum = 0;
  for (int i = 0; i < n; i++) sum += w[i];
  std::sort(w, w + n);
  SumOfSubsetByBacktracking(w, 0, 0, sum, m);
  if (m_subsetFound)
    return true;
  else
    return false;
}

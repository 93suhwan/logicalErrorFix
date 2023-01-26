#include <bits/stdc++.h>
using namespace std;
double mod = 1e9 + 7;
double pairSum(double *arr, int n, double k) {
  unordered_map<double, double> umap;
  double num = k;
  for (int i = 0; i < n; i++) umap[arr[i]]++;
  double count = 0;
  unordered_map<double, double>::iterator it = umap.begin();
  while (it != umap.end()) {
    if (num - it->first == it->first) {
      count += (it->second) * (it->second - 1);
    } else if (umap.count(num - it->first) > 0) {
      count += it->second * umap[num - it->first];
    }
    it++;
  }
  return count / 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double arr[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    double k = (2 * sum) / (double)n;
    cout << pairSum(arr, n, k) << '\n';
  }
}

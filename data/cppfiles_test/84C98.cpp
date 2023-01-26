#include <bits/stdc++.h>
using namespace std;
void pline(long long int v[], long long int n) {
  for (long long int i = 0; i < n; i++) std::cout << v[i] << " ";
  std::cout << endl;
}
void pline(vector<long long int> v) {
  for (long long int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    long long int x, second;
    std::cin >> x >> second;
    long long int m = (x - 1) / 2;
    long long int n = x - m;
    std::cout << second / n << '\n';
  }
  return 0;
}

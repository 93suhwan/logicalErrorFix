#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_vec(vector<T> &v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << std::endl;
  return;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  vector<long long> co(v);
  sort(begin(co), end(co));
  int subarrays = 0;
  for (auto i = begin(v); i < end(v); i++) {
    auto j = lower_bound(begin(co), end(co), *i);
    while (i < end(v) - 1 && j < end(co) - 1 && (*(i + 1) == *(j + 1))) {
      i++;
      j++;
    }
    subarrays++;
  }
  cout << (k >= subarrays ? "YES" : "NO") << std::endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cout << fixed;
  unsigned long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
template <typename... T>
static inline void gt(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
static inline void wt(T&&... args) {
  ((cout << args), ...);
}
template <typename... T>
static inline void wt_n(T&&... args) {
  ((cout << args), ...);
  cout << "\n";
}
long long int solve2(long long int a) {
  if (!a) return 0;
  for (int i = 2; i <= sqrt(a); i++) {
    if (!(a % i)) return 0;
  }
}
void solve() {
  long long int n, i, j;
  cin >> n;
  long long int arr[n];
  vector<pair<long long int, long long int>> res;
  vector<bool> temp(1e6 + 1, 0);
  for (long long int i = 0; i < n; i++) {
    gt(arr[i]);
    temp[arr[i]] = 1;
  }
  sort(arr, arr + n);
  for (i = (1); i <= ((n - 1)); i++) {
    for (j = 0; j < i; j++) {
      if ((long long int)temp[arr[i] % arr[j]] == 0)
        res.push_back({arr[i], arr[j]});
      if ((long long int)res.size() >= (n / 2)) {
        break;
      };
    }
    if ((long long int)res.size() >= (n / 2)) {
      break;
    };
  }
  for (long long int i = 0; i < (long long int)res.size(); i++) {
    cout << res[i].first << " " << res[i].second << "\n";
  }
}
int main() {
  long long int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}

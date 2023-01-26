#include <bits/stdc++.h>
template <typename T>
void print(T x) {
  std::cout << x << '\n';
}
template <typename T, typename TT>
void print(T x, TT y) {
  std::cout << x << ' ' << y << '\n';
}
template <typename T, typename TT>
void print(std::pair<T, TT> x) {
  std::cout << x.first << ' ' << x.second << '\n';
}
template <typename T>
void print(std::vector<T> v) {
  for (auto z : v) std::cout << z << ' ';
  std::cout << '\n';
}
template <typename T>
void print(T x[], int n) {
  for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');
}
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    n % 2 == 0 ? cout << "YES\n" : cout << "NO\n";
    return;
  }
  for (int i = n; i >= 1; i -= 2) {
    int p = k;
    int j = 2;
    for (; j <= m; j += 2) {
      if (p < i)
        break;
      else
        p -= i;
    }
    if (p >= i) continue;
    if (p == 0) {
      cout << "YES\n";
      return;
    } else {
      if ((i - p) % 2 == 0) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

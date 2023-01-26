#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};
bool prime[100];
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (auto c : s) {
    if (c == '1') {
      cout << 1 << endl << 1 << endl;
      return;
    } else if (c == '4') {
      cout << 1 << endl << 4 << endl;
      return;
    } else if (c == '6') {
      cout << 1 << endl << 6 << endl;
      return;
    } else if (c == '8') {
      cout << 1 << endl << 8 << endl;
      return;
    } else if (c == '9') {
      cout << 1 << endl << 9 << endl;
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
        cout << 2 << endl;
        cout << s[i] << s[j] << endl;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 2; i < 100; i++) {
    prime[i] = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime[i] = false;
      }
    }
  }
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}

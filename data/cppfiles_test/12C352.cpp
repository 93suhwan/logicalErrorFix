#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
}
template <typename... T>
void writen(T&&... args) {
  ((cout << args << "\n"), ...);
}
template <typename... T>
void cn(T&&... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
long long bin(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b % 2 == 0) return bin((a * a) % mod, b / 2, mod) % mod;
  return ((a % mod) * (bin((a * a) % mod, b / 2, mod) % mod)) % mod;
}
void solve() {
  int n, m, k;
  read(n, m, k);
  if (n == 1) {
    if (k == n * m / 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else if (m == 1) {
    if (k == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (m % 2 == 0) {
      int val = (n * m) / 2;
      if (k >= m / 2 && k % 2 == val % 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      int val = (n * m) / 2;
      k = val - k;
      if (k >= n / 2 && k % 2 == val % 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

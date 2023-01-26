#include <bits/stdc++.h>
using namespace std;
inline int Int() {
  int x;
  cin >> x;
  return x;
}
inline long long Long() {
  long long x;
  cin >> x;
  return x;
}
inline float Float() {
  float x;
  cin >> x;
  return x;
}
inline double Double() {
  double x;
  cin >> x;
  return x;
}
inline void Yes() { cout << "Yes" << endl; }
inline void No() { cout << "No" << endl; }
inline void YES() { cout << "YES" << endl; }
inline void NO() { cout << "NO" << endl; }
const int N = (int)2e5 + 5;
const int maxN = (int)1e6 + 6;
const long long Mod = (long long)1e9 + 7;
const int inf = (int)2e9;
const long long Inf = (long long)1e18;
int main() {
  int t, q;
  cin >> t;
  for (q = 1; q <= t; q++) {
    long long x, n, i, y, d = 0;
    cin >> x >> n;
    y = n % 4;
    if (x % 2) {
      if (y == 0)
        cout << x << '\n';
      else if (y == 1)
        cout << x + n << '\n';
      else if (y == 2)
        cout << x + (n - 1) - n << '\n';
      else
        cout << x + (n - 2) - (n - 1) - n << '\n';
    } else {
      if (y == 0)
        cout << x << '\n';
      else if (y == 1)
        cout << x - n << '\n';
      else if (y == 2)
        cout << x - (n - 1) + n << '\n';
      else
        cout << x - (n - 2) + (n - 1) + n << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using ftype = long double;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ftype p;
  cin >> n >> p;
  ftype nc3 = 1.0 * n * (n - 1) * (n - 2) / 6;
  for (int i = (0); i < (n + 1); i++) {
    ftype prob = 0;
    prob += 0.5 * (1.0 * i * (n - i) * (n - i - 1) / 2) / nc3;
    prob += 1.0 * (1.0 * i * (i - 1) * (n - i) / 2) / nc3;
    prob += 1.0 * (1.0 * i * (i - 1) * (i - 2) / 6) / nc3;
    if (prob >= p - 1e-12) {
      cout << i << '\n';
      return 0;
    }
  }
}

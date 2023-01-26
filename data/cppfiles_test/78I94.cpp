#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
  if (s.empty()) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
inline long long mult(long long a, long long b, long long mod) {
  return (a * b - (long long)((long double)a / mod * b) * mod + mod) % mod;
}
inline long long ksm(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = mult(res, a, mod);
    a = mult(a, a, mod);
    b >>= 1;
  }
  return res % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n;
    vector<int> cont(31);
    for (int i = 0; i < n; i++) {
      cin >> x;
      for (int j = 0; j <= 30; j++) {
        if (x & (1 << j)) cont[j]++;
      }
    }
    vector<int> res;
    if (count(cont.begin(), cont.end(), 0) == cont.size()) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      for (int i = 1; i * i <= n; i++) {
        int flag = 1, flag2 = 1;
        for (int j = 0; j <= 30; j++) {
          if (cont[j] % i != 0) flag = 0;
          if (cont[j] % (n / i) != 0) flag2 = 0;
        }
        if (flag) res.push_back(i);
        if (flag2 && i * i != n) res.push_back(n / i);
      }
      sort(res.begin(), res.end());
      for (auto x : res) cout << x << " ";
      cout << "\n";
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto c : s) {
      a[i][c - 'a']++;
    }
  }
  vector<long long> f(1 << n);
  function<void(int, int, vector<int>& vec)> fn = [&](int p, int s,
                                                      vector<int> vec) {
    if (p == n) {
      long long sum = 1;
      for (auto x : vec) {
        sum = (sum * (x + 1)) % mod;
      }
      f[s] = sum;
      return;
    }
    fn(p + 1, s, vec);
    for (int i = 0; i < 26; i++) {
      vec[i] = min(vec[i], a[p][i]);
    }
    fn(p + 1, s | 1 << p, vec);
  };
  auto flip = [](vector<long long>& f, int n) {
    int s = (1 << n) - 1;
    for (int i = 0; i * 2 < 1 << n; i++) {
      swap(f[i], f[s ^ i]);
    }
  };
  vector<int> vec(26, 1e5);
  fn(0, 0, vec);
  flip(f, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      if ((1 << i) & j) {
        f[j] = (f[j] - f[j ^ (1 << i)] + mod) % mod;
      }
    }
  }
  flip(f, n);
  long long sum = 0;
  for (int i = 0; i < 1 << n; i++) {
    sum = (sum + f[i]) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      if ((1 << i) & j) {
        f[j] = (f[j] + f[j ^ (1 << i)]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1 << n; i++) {
    long long v = ((sum - f[i]) % mod + mod) % mod;
    int k = 0, s = 0;
    for (int j = 0; j < n; j++) {
      if (!((1 << j) & i)) {
        k++, s += j + 1;
      }
    }
    ans ^= (k * s * v);
  }
  cout << ans << endl;
  return 0;
}

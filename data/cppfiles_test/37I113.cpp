#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long MOD = 998244353;
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
long long ncr(long long n, long long r) {
  vector<vector<long long>> c(5001, vector<long long>(5001, 0));
  for (int i = 1; i <= 5000; i++) {
    c[i][0] = 1;
  }
  c[1][1] = 1;
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= i && j <= 5000; j++) {
      if (i == 1 && j == 1)
        continue;
      else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
      }
    }
  }
  return c[n][r];
}
vector<long long> primefact(long long n) {
  vector<long long> arr(100001);
  for (int i = 0; i < 100001; i++) arr[i] = i;
  for (int i = 2; i * i < 100001; i++) {
    if (arr[i] == i) {
      for (int j = i * i; j < 100001; j += i) {
        if (arr[j] == j) {
          arr[j] = i;
        }
      }
    }
  }
  vector<long long> ans;
  while (n > 1) {
    ans.push_back(arr[n]);
    n = n / arr[n];
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  long long m;
  cin >> m;
  while (m--) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (a[y - 1] == x && a[y + 1] == z) {
      long long temp = y;
      a[y] = z;
      a[y + 1] = y;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << a[i] << " " << a[i + 1] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

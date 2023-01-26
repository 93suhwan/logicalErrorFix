#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long MOD = 998244353;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    n >>= 1;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> tmp(n);
  vector<long long> ans(n, -1);
  long long minRight = n + 1;
  for (long long pos = n - 1; pos >= 0; pos--) {
    long long curAdd = 0;
    while (ans[pos] == -1) {
      cout << "? ";
      for (long long i = 0; i < n; i++) {
        if (i == pos) {
          cout << curAdd + 2;
        } else {
          cout << 1;
        }
        cout << ' ';
      }
      cout << endl;
      long long res;
      cin >> res;
      res--;
      if (res == pos) {
        ans[pos] = minRight - curAdd - 1;
      } else if (res == -1) {
        if (pos != n - 1) {
          ans[pos] = n;
        } else {
          ans[pos] = minRight - curAdd - 1;
        }
      } else if (curAdd + 2 == n) {
        tmp[res] = curAdd + 1;
        ans[pos] = 1;
      } else {
        tmp[res] = curAdd + 1;
      }
      curAdd++;
      if (ans[pos] != -1) {
        for (long long j = 0; j < n; j++) {
          if (ans[j] == -1 && tmp[j] != 0) {
            ans[j] = tmp[j] + ans[pos];
          }
        }
      }
    }
    minRight = min(minRight, ans[pos]);
  }
  cout << "! ";
  for (auto u : ans) {
    cout << u << ' ';
  }
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

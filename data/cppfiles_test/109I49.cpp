#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}
int mul(int a, int b) { return a * (long long)b % M; }
int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}
int dv(int a, int b) { return mul(a, pw(b, M - 2)); }
const int N = (int)1e5 + 7;
int n, t1 = 0, t2 = 0, t0 = 0;
int fact(int n) {
  assert(n >= 0);
  int sol = 1;
  for (int i = 1; i <= n; i++) {
    sol = mul(sol, i);
  }
  return sol;
}
int comb(int n, int k) {
  assert(0 <= k && k <= n);
  return dv(fact(n), mul(fact(k), fact(n - k)));
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  bool bad = false;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s[1] == 'W') {
      s[1] = 'B';
    } else {
      if (s[1] == 'B') {
        s[1] = 'W';
      }
    }
    if (s[0] == s[1]) {
      if (s[0] == '?') {
        cnt0++;
      } else {
        if (s[0] == 'W') {
          cnt1++;
        } else {
          assert(s[0] == 'B');
          cnt2++;
        }
      }
    } else {
      if (s[0] == '?' || s[1] == '?') {
        if (s[0] == '?') {
          assert(s[1] == 'W' || s[1] == 'B');
          if (s[1] == 'W') {
            cnt1++;
          } else {
            cnt2++;
          }
        } else {
          assert(s[0] == 'W' || s[0] == 'B');
          if (s[0] == 'W') {
            cnt1++;
          } else {
            cnt2++;
          }
        }
      } else {
        bad = true;
      }
    }
    for (auto &ch : s) {
      if (ch == 'W') {
        t1++;
      } else {
        if (ch == 'B') {
          t2++;
        } else {
          assert(ch == '?');
          t0++;
        }
      }
    }
  }
  if (t1 > n || t2 > n) {
    cout << "0\n";
    return 0;
  }
  int sol = comb(t0, n - t1);
  if (!bad && n % 2 == 0 && cnt1 <= n / 2 && cnt2 <= n / 2) {
    sol = add(sol, -comb(cnt0, n / 2 - cnt1));
  }
  cout << sol << "\n";
}

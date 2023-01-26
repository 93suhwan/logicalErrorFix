#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d = 0, e = 0, i, f = 0, g = 0, j, k = 0, l, r, z, m, h,
                   mod = 1000000007, mod1 = 998244353;
string s, t, x, q;
long long df[101], dp;
vector<long long> v;
vector<long long> u;
vector<long long> dv[101];
multiset<long long> y;
deque<long long> w;
multiset<long long>::iterator it;
void dfs(long long x) {
  df[x] = 1;
  for (long long i = 0; i < dv[x].size(); i++) {
    if (df[dv[x][i]] == 0) {
      dfs(dv[x][i]);
    }
  }
}
long long fastPow(long long a, long long b) {
  long long d = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      d = d * a % mod;
    }
    b /= 2;
    a = a * a % mod;
  }
  return d;
}
long long check(string s) {
  long long ans = 0;
  x = s;
  if (t == "__" || t == "2_" || t == "_5" || t == "25") {
    x[a - 2] = '2';
    x[a - 1] = '5';
    if (x[0] != '0') {
      long long ans1 = 1;
      for (long long i = 0; i < a; i++) {
        if (x[i] == '_') {
          if (i == 0) {
            ans1 *= 9;
          } else {
            ans1 *= 10;
          }
        }
      }
      ans += ans1;
    }
  }
  x = s;
  if (t == "__" || t == "5_" || t == "_0" || t == "50") {
    x[a - 2] = '5';
    x[a - 1] = '0';
    if (x[0] != '0') {
      long long ans1 = 1;
      for (long long i = 0; i < a; i++) {
        if (x[i] == '_') {
          if (i == 0) {
            ans1 *= 9;
          } else {
            ans1 *= 10;
          }
        }
      }
      ans += ans1;
    }
  }
  x = s;
  if (t == "__" || t == "7_" || t == "_5" || t == "75") {
    x[a - 2] = '7';
    x[a - 1] = '5';
    if (x[0] != '0') {
      long long ans1 = 1;
      for (long long i = 0; i < a; i++) {
        if (x[i] == '_') {
          if (i == 0) {
            ans1 *= 9;
          } else {
            ans1 *= 10;
          }
        }
      }
      ans += ans1;
    }
  }
  x = s;
  if (t == "__" || t == "0_" || t == "_0" || t == "00") {
    x[a - 2] = '0';
    x[a - 1] = '0';
    if (x[0] != '0') {
      long long ans1 = 1;
      for (long long i = 0; i < a; i++) {
        if (x[i] == '_') {
          if (i == 0) {
            ans1 *= 9;
          } else {
            ans1 *= 10;
          }
        }
      }
      ans += ans1;
    }
  }
  return ans;
}
int main() {
  cin >> s;
  a = s.size();
  if (a == 1) {
    if (s == "0" || s == "_" || s == "X") {
      cout << 1;
    } else {
      cout << 0;
    }
    return 0;
  }
  for (i = 0; i < a; i++) {
    if (s[i] == 'X') {
      v.push_back(i);
    }
  }
  if (v.size() == 0) {
    t = s[a - 2];
    t += s[a - 1];
    cout << check(s);
  } else {
    d = 0;
    for (i = 0; i <= 9; i++) {
      for (j = 0; j < v.size(); j++) {
        s[v[j]] = char(i + 48);
      }
      t = s[a - 2];
      t += s[a - 1];
      x = s;
      d += check(x);
    }
    cout << d;
  }
}

#include <bits/stdc++.h>
using namespace std;
long long MOD;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long add(long long a, long long b) {
  return a + b < MOD ? a + b : a + b - MOD;
}
long long sub(long long a, long long b) {
  return a - b >= 0 ? a - b : a - b + MOD;
}
long long mul(long long a, long long b) { return (long long)a * b % MOD; }
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
long long inv(long long a) { return binpow(a, MOD - 2); }
long long divide(long long a, long long b) { return mul(a, inv(b)); }
struct hashe {
  vector<long long> a, inv;
  void build(string s) {
    long long now = 0, pow10 = 1;
    reverse(s.begin(), s.end());
    for (auto to : s) {
      now = add(now, mul(to - '0', pow10));
      a.push_back(now);
      inv.push_back(binpow(pow10, MOD - 2));
      pow10 = mul(pow10, 10);
    }
    reverse(a.begin(), a.end());
  }
  long long get(long long l, long long r) {
    return mul(sub(a[l], (r + 1 < a.size() ? a[r + 1] : 0)),
               inv[(long long)(a.size()) - r - 1]);
  }
};
bool stupid_solve(string s, string x) {
  hashe hash_s, hash_x;
  hash_s.build(s);
  hash_x.build(x);
  long long n = s.size(), m = x.size();
  bool f = 0;
  for (long long i = 0; i < s.size(); i++) {
    for (long long j = i; j + 1 < s.size(); j++) {
      for (long long k = j + 1; k < s.size(); k++) {
        if (add(hash_s.get(i, j), hash_s.get(j + 1, k)) ==
            hash_x.get(0, m - 1)) {
          f = 1;
          cout << i + 1 << ' ' << j + 1 << endl;
          cout << j + 2 << ' ' << k + 1 << endl;
          exit(0);
        }
      }
    }
  }
  return f;
}
bool solve(string s, string x) {
  hashe hash_s, hash_x;
  hash_s.build(s);
  hash_x.build(x);
  long long n = s.size(), m = x.size();
  set<long long> st;
  st.insert(m);
  st.insert(m - 1);
  long long super_val = hash_x.get(0, m - 1);
  for (auto len : st) {
    if (len <= 0 || len > m) continue;
    for (long long i = 0; i + len - 1 < n; i++) {
      vector<long long> check;
      if (len == m) {
        long long l = 0, r = len;
        while (r - l > 1) {
          long long mid = (r + l) / 2;
          if (hash_s.get(i, i + mid - 1) == hash_x.get(0, mid - 1)) {
            l = mid;
          } else {
            r = mid;
          }
        }
        for (long long j = -2; j <= 2; j++) check.push_back(m - l + j);
      } else {
        check.push_back(m);
        check.push_back(m - 1);
      }
      for (auto t : check) {
        if (t <= 0 || t > m) continue;
        if (i + len + t - 1 < n) {
          long long val = add(hash_s.get(i, i + len - 1),
                              hash_s.get(i + len, i + len + t - 1));
          if (val == super_val) {
            cout << i + 1 << ' ' << i + len << endl;
            cout << i + len + 1 << ' ' << i + len + t << endl;
            exit(0);
          }
        }
        if (i - t >= 0) {
          long long val =
              add(hash_s.get(i, i + len - 1), hash_s.get(i - t, i - 1));
          if (val == super_val) {
            cout << i - t + 1 << ' ' << i << endl;
            cout << i + 1 << ' ' << i + len << endl;
            exit(0);
          }
        }
      }
    }
  }
}
long long prime(long long v) {
  for (long long i = 2; i * i <= v; i++) {
    if (v % i == 0) return 0;
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (1) {
    MOD = rnd() % (long long)(1e9) + 1e9;
    if (prime(MOD)) break;
  }
  string s, x;
  cin >> s >> x;
  solve(s, x);
  return 0;
}

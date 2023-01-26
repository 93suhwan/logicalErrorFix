#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
const long long mod1 = 1e9 + 7;
const long long mod = 998244353;
long long k, A, h;
long long pw[100];
long long get_hash(vector<long long> x) {
  long long s = 0;
  for (long long i = 0; i < (long long)x.size(); i++) {
    s = (s + pw[x[i]] * (i + 1)) % mod;
  }
  return s;
}
vector<long long> evaluate(long long mask, long long n) {
  long long cur_place = n / 2 + 1;
  vector<long long> mass(n);
  vector<long long> p(n);
  for (long long i = 0; i < n; i++) {
    p[i] = i;
  }
  long long it = 0;
  while ((long long)p.size() > 1) {
    vector<long long> p1(n / 2);
    for (long long i = 0; i < n; i += 2) {
      if (mask & (1 << it)) {
        mass[p[i + 1]] = cur_place;
        p1[i / 2] = p[i];
      } else {
        mass[p[i]] = cur_place;
        p1[i / 2] = p[i + 1];
      }
      it++;
    }
    p = p1;
    n /= 2;
    cur_place /= 2;
    cur_place++;
  }
  mass[p[0]] = 1;
  return mass;
}
void funct(vector<long long> &p, bool winning) {
  for (long long i = 0; i < (long long)p.size(); i++) {
    if (p[i] == 1) {
      if (!winning) {
        p[i]++;
      }
    } else {
      p[i] = 2 * p[i] - 1;
    }
  }
}
long long get_hash(vector<long long> p, bool flag = 0, bool flag1 = 0,
                   long long it = 0) {
  if (flag) {
    funct(p, flag1);
  }
  long long res = 0;
  for (long long i = 0; i < (long long)p.size(); i++) {
    res = (res + (it + i + 1) * pw[p[i]]) % mod;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> A >> h;
  pw[0] = 1;
  for (long long i = 1; i < 100; i++) {
    pw[i] = pw[i - 1] * A % mod;
  }
  if (k <= 4) {
    for (long long i = 0; i < (1 << ((1 << k) - 1)); i++) {
      vector<long long> p = evaluate(i, 1 << k);
      if (get_hash(p, 0, 0, 0) == h) {
        for (long long j = 0; j < (1 << k); j++) {
          cout << p[j] << " ";
        }
        return 0;
      }
    }
    cout << -1;
    return 0;
  }
  for (long long c = 0; c < 2; c++) {
    map<long long, vector<long long> > hash_left;
    for (long long i = 0; i < 1 << 16; i++) {
      vector<long long> p = evaluate(i, 16);
      long long hash_ = get_hash(p, true, c == 0, 0);
      hash_left[hash_] = p;
    }
    for (long long i = 0; i < (1 << 16); i++) {
      vector<long long> p = evaluate(i, 16);
      long long right_hash = get_hash(p, true, c == 1, 16);
      long long h1 = (h + mod - right_hash) % mod;
      if (hash_left.count(h1)) {
        for (auto x : hash_left[h1]) {
          cout << x << " ";
        }
        for (auto x : p) {
          cout << x << " ";
        }
        return 0;
      }
    }
  }
  return 0;
}

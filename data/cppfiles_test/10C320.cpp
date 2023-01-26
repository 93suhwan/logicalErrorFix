#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mxn = 1e5 + 7;
const long long inf = 1e18;
inline void normal(long long &a) {
  a %= mod;
  (a < 0) && (a += mod);
}
inline long long modMul(long long a, long long b) {
  a %= mod, b %= mod;
  normal(a), normal(b);
  return (a * b) % mod;
}
inline long long modAdd(long long a, long long b) {
  a %= mod, b %= mod;
  normal(a), normal(b);
  return (a + b) % mod;
}
inline long long modSub(long long a, long long b) {
  a %= mod, b %= mod;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, mod - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long i, j, k, a, b, c, d, n, m, t, u, v, w, x, y, z;
  cin >> t;
  for (long long zz = 1; zz <= t; zz++) {
    cin >> n >> k;
    vector<long long> vec(n);
    set<long long> st;
    map<long long, long long> frq;
    map<long long, vector<long long> > pos;
    for (i = 0; i < n; i++) {
      cin >> vec[i];
      a = vec[i];
      st.insert(a);
      frq[a] += 1;
      pos[a].push_back(i);
    }
    vector<long long> ans(n, 0), tem1, tem2;
    for (auto it : st) {
      if (frq[it] >= k) {
        tem1.push_back(it);
      } else {
        tem2.push_back(it);
      }
    }
    for (auto a : tem1) {
      long long col = 0;
      for (auto b : pos[a]) {
        col += 1;
        ans[b] = col;
        if (col == k) {
          break;
        }
      }
    }
    long long col = 0, cnt = (long long)tem1.size();
    for (auto a : tem2) {
      for (auto b : pos[a]) {
        long long tem = (col % k) + 1;
        ans[b] = tem;
        if (tem == k) {
          cnt += 1;
        }
        col += 1;
      }
    }
    map<long long, long long> check;
    for (i = 0; i < n; i++) {
      a = ans[i];
      if (a >= 1) {
        check[a] += 1;
      }
      if (check[a] <= cnt) {
        cout << ans[i] << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &i : a) in >> i;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &i : a) out << i << ' ';
  return out;
}
template <class T, class U>
istream &operator>>(istream &in, pair<T, U> &a) {
  in >> a.first >> a.second;
  return in;
}
template <class T, class U>
ostream &operator<<(ostream &out, pair<T, U> &a) {
  out << a.first << ' ' << a.second << "\n";
  return out;
}
mt19937 rnd(time(NULL));
void files() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
template <typename T1, typename T2>
inline bool chkmin(T1 &x, T2 &y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chkmax(T1 &x, T2 &y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline long long min(long long a, long long b) { return (a < b ? a : b); }
inline long long max(long long a, long long b) { return (a > b ? a : b); }
const long long mod = 998244353;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long t = binpow(a, b / 2);
    return t * t % mod;
  }
  return binpow(a, b - 1) * a % mod;
}
void solve() {
  long long k, a, h;
  cin >> k >> a >> h;
  long long x = (1 << k) - 1;
  auto get_ranks = [&](vector<long long> bts, long long base) {
    vector<long long> ans((long long)(bts.size()) + 1);
    vector<long long> aboba;
    vector<long long> naboba;
    for (long long i = 0; i < ((long long)(bts.size()) + 1); i++) {
      aboba.push_back(base + i);
    }
    long long it = 0;
    long long rk = ((long long)(bts.size()) + 1) / 2 + 1;
    while ((long long)(aboba.size()) > 1) {
      for (long long i = 0; i < (long long)(aboba.size()); i += 2) {
        long long A = aboba[i], B = aboba[i + 1];
        if (bts[it]) {
          naboba.push_back(A);
          ans[B - base] = rk;
        } else {
          naboba.push_back(B);
          ans[A - base] = rk;
        }
        it++;
      }
      rk = (rk + 1) / 2;
      aboba = naboba;
      naboba.clear();
    }
    ans[aboba[0] - base] = 1;
    return ans;
  };
  auto get_hash = [&](vector<long long> bts, long long base) {
    long long ht = 0;
    vector<long long> vk = get_ranks(bts, base);
    for (long long i = 0; i < ((long long)(vk.size())); i++) {
      ht += binpow(a, vk[i]) * (i + 1) % mod;
      ht %= mod;
    }
    return ht;
  };
  if (k < 5) {
    vector<long long> st(x);
    iota((st).begin(), (st).end(), 1);
    vector<long long> bts;
    for (long long msk = 0; msk < (1 << x); msk++) {
      for (long long j = 0; j < x; j++) {
        bts.push_back((msk >> j) & 1);
      }
      if (get_hash(bts, 1) == h) {
        vector<long long> k = get_ranks(bts, 1);
        cout << k << "\n";
        return;
      }
      bts.clear();
    }
  } else {
    x = (1 << (k - 1)) - 1;
    vector<pair<long long, vector<long long>>> h1, h2, h3, h4;
    vector<long long> bts;
    for (long long msk = 0; msk < (1 << x); msk++) {
      for (long long j = 0; j < x; j++) {
        bts.push_back((msk >> j) & 1);
      }
      vector<long long> g = get_ranks(bts, 1);
      for (auto &i : g) {
        if (i == 1) {
          i = 2;
          continue;
        }
        i = (i - 1) * 2 + 1;
      }
      long long H = 0;
      long long winner = 0;
      for (long long i = 0; i < ((long long)(g.size())); i++) {
        if (g[i] == 2) {
          winner = i + 1;
          continue;
        }
        H += binpow(a, g[i]) * (i + 1) % mod;
        H %= mod;
      }
      H += winner * a;
      H %= mod;
      g[winner - 1] = 1;
      h1.push_back({H, g});
      H -= winner * a;
      H += winner * a * a;
      H %= mod;
      g[winner - 1] = 2;
      h2.push_back({H, g});
      bts.clear();
    }
    for (long long msk = 0; msk < (1 << x); msk++) {
      for (long long j = 0; j < x; j++) {
        bts.push_back((msk >> j) & 1);
      }
      vector<long long> g = get_ranks(bts, 17);
      for (auto &i : g) {
        if (i == 1) {
          i = 2;
          continue;
        }
        i = (i - 1) * 2 + 1;
      }
      long long H = 0;
      long long winner = 0;
      for (long long i = 0; i < ((long long)(g.size())); i++) {
        if (g[i] == 2) {
          winner = i + 17;
          continue;
        }
        H += binpow(a, g[i]) * (i + 17) % mod;
        H %= mod;
      }
      H += winner * a;
      H %= mod;
      g[winner - 17] = 1;
      h3.push_back({H, g});
      H -= winner * a;
      H += winner * a * a;
      H %= mod;
      g[winner - 17] = 2;
      h4.push_back({H, g});
      bts.clear();
    }
    sort((h1).begin(), (h1).end());
    sort((h2).begin(), (h2).end());
    sort((h3).begin(), (h3).end());
    sort((h4).begin(), (h4).end());
    long long s1 = h;
    long long s2 = h + mod;
    for (long long i = 0; i < ((long long)(h1.size())); i++) {
      auto it = lower_bound((h4).begin(), (h4).end(),
                            make_pair(s1 - h1[i].first, vector<long long>()));
      if (it != h4.end() and it->first == s1 - h1[i].first) {
        cout << h1[i].second;
        cout << it->second << "\n";
        return;
      }
      it = lower_bound((h4).begin(), (h4).end(),
                       make_pair(s2 - h1[i].first, vector<long long>()));
      if (it != h4.end() and it->first == s2 - h1[i].first) {
        cout << h1[i].second;
        cout << it->second << "\n";
        return;
      }
    }
    for (long long i = 0; i < ((long long)(h2.size())); i++) {
      auto it = lower_bound((h3).begin(), (h3).end(),
                            make_pair(s1 - h2[i].first, vector<long long>()));
      if (it != h3.end() and it->first == s1 - h2[i].first) {
        cout << h2[i].second;
        cout << it->second << "\n";
        return;
      }
      it = lower_bound((h3).begin(), (h3).end(),
                       make_pair(s2 - h2[i].first, vector<long long>()));
      if (it != h3.end() and it->first == s2 - h2[i].first) {
        cout << h2[i].second;
        cout << it->second << "\n";
        return;
      }
    }
  }
  cout << -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  while (q--) {
    solve();
  }
}

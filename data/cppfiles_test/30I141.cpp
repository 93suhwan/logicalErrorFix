#include <bits/stdc++.h>
using namespace std;
const int INF = (is_same<int, long long>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class t1, class t2>
inline bool cmin(t1& a, const t2& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class t1, class t2>
inline bool cmax(t1& a, const t2& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
inline int bpow(long long a, long long b, int mod) {
  int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = int((1ll * a * res) % mod);
      res %= mod;
    }
    a *= a;
    a %= mod;
  }
  return res;
}
void UseFiles(const string& s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void run();
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
}
pair<int, int> norm(pair<int, int> p) {
  if (p.first > p.second) {
    swap(p.first, p.second);
  }
  return p;
}
void run() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  int maxa = *max_element(a.begin(), a.end());
  maxa += 2;
  vector<int> long double(maxa, -1);
  vector<int> primes;
  for (int i = 2; i < maxa; ++i) {
    if (long double[i] == -1) {
      primes.push_back(long double[i] = i);
    }
    for (int j = 0; j < ((int)(primes).size()) && primes[j] <= long double[i] &&
                    i * primes[j] < maxa;
         ++j) {
      long double[i * primes[j]] = primes[j];
    }
  }
  auto get_pdivisors = [&long double, &primes](int val) {
    vector<int> res;
    res.reserve(13);
    while (val > 1) {
      if (res.empty() || res.back() != long double[val]) {
        res.push_back(long double[val]);
      }
      val /= long double[val];
    }
    for (auto& x : res) {
      x = (int)(lower_bound(primes.begin(), primes.end(), x) - primes.begin());
    }
    return res;
  };
  const int m = ((int)(primes).size());
  vector<vector<int>> g(n + m);
  for (int i = 0; i < n; ++i) {
    for (auto& x : get_pdivisors(a[i])) {
      g[i].push_back(x + n);
      g[x + n].push_back(i);
    }
  }
  vector<int> color(n + m, -1);
  function<void(int, int)> paint = [&g, &color, &paint](int v, int c) {
    color[v] = c;
    for (auto& x : g[v]) {
      if (color[x] == -1) {
        paint(x, c);
      }
    }
  };
  int c = 0;
  for (int i = 0; i < n + m; ++i) {
    if (color[i] == -1) {
      paint(i, c++);
    }
  }
  set<pair<int, int>> edges;
  for (int i = 0; i < n; ++i) {
    for (auto& x : get_pdivisors(a[i] + 1)) {
      if (color[i] != color[x + n]) {
        edges.insert(norm({color[i], color[x + n]}));
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    if (color[s] == color[t]) {
      cout << "0\n";
    } else if (edges.count(norm({color[s], color[t]}))) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}

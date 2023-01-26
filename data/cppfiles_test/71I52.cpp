#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
vector<long long> FA, INV;
void fcalc(long long n, long long M) {
  FA.resize(n + 1);
  FA[0] = 1;
  for (long long i = 1; i <= n; i++) {
    FA[i] = (FA[i - 1] * i) % M;
  }
}
void icalc(long long n, long long M) {
  INV.resize(n + 1);
  INV[n] = mod_inv(FA[n], M);
  for (long long i = n - 1; i >= 0; i--) {
    INV[i] = (INV[i + 1] * (i + 1)) % M;
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long a = FA[n];
  a *= INV[r];
  a %= M;
  a *= INV[n - r];
  a %= M;
  return a;
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
ifstream fin;
ofstream fout;
void solve() {
  long long n, st;
  cin >> n >> st;
  st--;
  vector<pair<long long, long long>> v(n);
  for (auto& w : v) cin >> w.first >> w.second;
  auto init = v;
  sort(v.begin(), v.end());
  vector<pair<long long, long long>> slp(n);
  auto slope = [&](pair<long long, long long> a, pair<long long, long long> b) {
    long long x = b.first - a.first;
    long long y = b.second - a.second;
    long long g = gcd(x, y);
    x /= g;
    y /= g;
    if (x < 0) {
      x *= -1;
      y *= -1;
    }
    return make_pair(x, y);
  };
  map<pair<long long, long long>, vector<long long>> mm;
  for (long long i = 1; i < n; i++) {
    mm[slope(v[0], v[i])].push_back(i);
  }
  long long tinct = 0;
  if (mm.size() != n - 1 || n == 3) {
    for (auto& w : mm) {
      if (w.second.size() == 1) {
        tinct = w.second.back();
      }
    }
  }
  vector<pair<long long, long long>> ln;
  for (long long i = 0; i < n; i++) {
    if (i != tinct) {
      ln.push_back(v[i]);
    }
  }
  auto give_dis = [&](pair<long long, long long> a,
                      pair<long long, long long> b) -> long double {
    long long x = a.first - b.first;
    long long y = a.second - b.second;
    return sqrt((long double)(x) * (x) + (y) * (y));
  };
  if (v[tinct] == init[st]) {
    long double aa = give_dis(ln[0], ln.back());
    cout << min(give_dis(v[tinct], ln[0]) + aa,
                give_dis(v[tinct], ln.back()) + aa)
         << endl;
    return;
  } else {
    long double dis = give_dis(ln[0], v[tinct]) + give_dis(ln[0], init[st]);
    long long lt = 0;
    for (long long i = 0; i < ln.size(); i++) {
      if (ln[i] == init[st]) {
        lt = i;
        break;
      }
    }
    long double prt = 1e18;
    for (long long i = lt + 1; i < ln.size(); i++) {
      prt =
          min(prt, give_dis(v[tinct], ln[i]) + 2 * give_dis(ln[i - 1], ln[lt]) +
                       give_dis(ln.back(), ln[i]));
    }
    long double d1 = prt + dis;
    long double dis3 = 2 * give_dis(ln[0], init[st]);
    long double prt3 =
        give_dis(init[st], ln.back()) + give_dis(v[tinct], ln.back());
    for (long long i = lt; i < ln.size() - 1; i++) {
      prt3 = min(prt3,
                 give_dis(v[tinct], ln[i]) + give_dis(ln[i + 1], ln.back()) +
                     give_dis(v[tinct], ln[i + 1]) + give_dis(ln[st], ln[i]));
    }
    long double d3 = prt3 + dis3;
    reverse(ln.begin(), ln.end());
    long double dis2 = give_dis(ln[0], v[tinct]) + give_dis(ln[0], init[st]);
    long long lt2 = 0;
    for (long long i = 0; i < ln.size(); i++) {
      if (ln[i] == init[st]) {
        lt2 = i;
        break;
      }
    }
    long double prt2 = 1e18;
    for (long long i = lt2 + 1; i < ln.size(); i++) {
      prt2 = min(prt2, give_dis(v[tinct], ln[i]) +
                           2 * give_dis(ln[i - 1], ln[lt2]) +
                           give_dis(ln.back(), ln[i]));
    }
    long double d2 = prt2 + dis2;
    long double dis4 = 2 * give_dis(ln[0], init[st]);
    long double prt4 =
        give_dis(init[st], ln.back()) + give_dis(v[tinct], ln.back());
    for (long long i = lt2; i < ln.size() - 1; i++) {
      prt4 = min(prt4,
                 give_dis(v[tinct], ln[i]) + give_dis(ln[i + 1], ln.back()) +
                     give_dis(v[tinct], ln[i + 1]) + give_dis(ln[st], ln[i]));
    }
    long double d4 = prt4 + dis4;
    cout << min({d1, d2, d3, d4}) << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

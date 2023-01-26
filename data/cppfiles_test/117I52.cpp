#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
};
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
bool BREAKTIME(long double v) { return 1.0 * clock() >= v * CLOCKS_PER_SEC; }
unsigned int COUNT(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
const long long inf = 1e18;
long long mod = 1e9 + 7;
struct Tree {
  vector<long long> t;
  vector<long long> m;
  long long n = 1;
  Tree(long long N) {
    while (n < N) n *= 2;
    t.assign(2 * n, 0);
    m.assign(2 * n, 1);
  }
  void Push(long long x) {
    long long l = x * 2;
    long long r = x * 2 + 1;
    if (l >= t.size()) {
      t[x] *= m[x];
      t[x] %= mod;
      m[x] = 1;
    } else {
      m[l] *= m[x];
      m[r] *= m[x];
      m[l] %= mod;
      m[r] %= mod;
      m[x] = 1;
    }
    return;
  }
  void mul(long long l, long long r) {
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        m[l] = m[l] * 2 % mod;
        ++l;
      }
      if (r % 2 == 0) {
        m[r] = m[r] * 2 % mod;
        --r;
      }
    }
  }
  long long Get(long long x) {
    vector<long long> p;
    x += n;
    long long X = x;
    while (x >= 1) {
      p.push_back(x);
      x /= 2;
    }
    reverse((p).begin(), (p).end());
    for (auto v : p) {
      Push(v);
    }
    return t[X];
  }
  void Add(long long x, long long add) {
    vector<long long> p;
    x += n;
    long long X = x;
    while (x >= 1) {
      p.push_back(x);
      x /= 2;
    }
    reverse((p).begin(), (p).end());
    for (auto v : p) {
      Push(v);
    }
    t[X] += add;
    t[X] %= mod;
  }
};
long long XA[4] = {1, -1, 0, 0};
long long YA[4] = {0, 0, 1, -1};
void solve() {
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  vector<vector<char>> A(n, vector<char>(m));
  pair<long long, long long> L;
  for (long long i = 0; i < (n); ++i) {
    for (long long j = 0; j < (m); ++j) {
      cin >> A[i][j];
      if (A[i][j] == 'L') L = {i, j};
    }
  }
  vector<vector<long long>> D(n, vector<long long>(m, 0));
  vector<vector<long long>> E(n, vector<long long>(m, 0));
  vector<vector<long long>> Dead(n, vector<long long>(m, 0));
  for (long long a = 0; a < n; ++a) {
    for (long long b = 0; b < m; ++b) {
      pair<long long, long long> p = {a, b};
      for (long long k = 0; k < (4); ++k) {
        long long i = p.first + XA[k];
        long long j = p.second + YA[k];
        if (i < 0 || j < 0 || i >= n || j >= m) continue;
        if (A[i][j] == '#') continue;
        E[a][b]++;
      }
    }
  }
  D[L.first][L.second] = 1;
  Dead[L.first][L.second] = 1;
  queue<pair<long long, long long>> q;
  q.push(L);
  while (q.size() > 0) {
    pair<long long, long long> p = q.front();
    q.pop();
    Dead[p.first][p.second] = 1;
    if (D[p.first][p.second] == 0) continue;
    for (long long k = 0; k < (4); ++k) {
      long long i = p.first + XA[k];
      long long j = p.second + YA[k];
      if (i < 0 || j < 0 || i >= n || j >= m) continue;
      if (A[i][j] == '#') continue;
      if (Dead[i][j]) continue;
      if (E[i][j] > 2) continue;
      D[i][j] = D[p.first][p.second];
      q.push({i, j});
    }
  }
  for (long long i = 0; i < (n); ++i) {
    for (long long j = 0; j < (m); ++j) {
      if (A[i][j] == '#' || A[i][j] == 'L') {
        cout << A[i][j];
      } else {
        if (D[i][j] == 1)
          cout << '+';
        else
          cout << ".";
      }
    }
    cout << '\n';
  }
}
int32_t main() {
  boostIO();
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

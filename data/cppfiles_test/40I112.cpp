#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
using vi = vector<long long>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long prime(long long p) {
  if (p == 1) return 0;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
template <typename T1>
void ifmax(T1 &max, T1 kek) {
  if (kek > max) max = kek;
  return;
}
template <typename T1>
void ifmin(T1 &min, T1 kek) {
  if (kek < min) min = kek;
  return;
}
template <typename T1>
istream &operator>>(std::istream &in, vector<T1> &a) {
  for (long long i = 0; i < a.size(); i++) in >> a[i];
  return in;
}
template <typename T1>
ostream &operator<<(std::ostream &out, vector<T1> &b) {
  for (long long i = 0; i < b.size(); i++) out << b[i] << " ";
  out << "\n";
  return out;
}
template <typename T1>
void sort(vector<T1> &m) {
  sort(m.begin(), m.end());
}
template <typename T1>
void reverse(vector<T1> &m) {
  reverse(m.begin(), m.end());
}
void solve() {
  long long a, b;
  cin >> a >> b;
  vector<vector<long long>> g(a);
  for (long long i = 0; i < b; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long q;
  cin >> q;
  vector<long long> deg(a);
  vector<pair<long long, long long>> m1(q);
  for (long long i = 0; i < q; i++) {
    cin >> m1[i].first >> m1[i].second;
    m1[i].first--;
    deg[m1[i].first]++;
    m1[i].second--;
    deg[m1[i].second]++;
  }
  long long check = 0;
  for (long long i = 0; i < a; i++) {
    check += (deg[i] % 2);
  }
  if (check > 0) {
    cout << "NO\n";
    cout << check / 2;
  }
  cout << "YES\n";
  vector<long long> parent(a);
  queue<long long> q1;
  vector<bool> used(a);
  q1.push(0);
  used[0] = true;
  vector<long long> dist(a);
  dist[0] = 0;
  while (!q1.empty()) {
    long long c = q1.front();
    q1.pop();
    for (long long i = 0; i < g[c].size(); i++) {
      if (!used[g[c][i]]) {
        used[g[c][i]] = true;
        parent[g[c][i]] = c;
        q1.push(g[c][i]);
        dist[g[c][i]] = dist[c] + 1;
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    long long x = m1[i].first;
    long long y = m1[i].second;
    long long x1 = x, y1 = y;
    while (dist[x1] > dist[y1]) {
      x1 = parent[x1];
    }
    while (dist[x1] < dist[y1]) {
      y1 = parent[y1];
    }
    while (x1 != y1) {
      x1 = parent[x1];
      y1 = parent[y1];
    }
    long long cur1 = x;
    vector<long long> pepega;
    while (x1 != cur1) {
      pepega.push_back(cur1);
      cur1 = parent[cur1];
    }
    vector<long long> pepega2;
    cur1 = y;
    while (y1 != cur1) {
      pepega2.push_back(cur1);
      cur1 = parent[cur1];
    }
    reverse(pepega2);
    cout << pepega.size() + pepega2.size() + 1 << "\n";
    for (long long i = 0; i < pepega.size(); i++) cout << pepega[i] + 1 << " ";
    cout << x1 + 1 << " ";
    for (long long i = 0; i < pepega2.size(); i++)
      cout << pepega2[i] + 1 << " ";
    cout << "\n";
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long multitest = 0;
  long long tututu;
  tututu = 1;
  if (multitest) cin >> tututu;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}

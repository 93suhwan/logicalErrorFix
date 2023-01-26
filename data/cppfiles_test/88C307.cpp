#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#pragma GCC optimize("-O2")
void setIO() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
void amax(long long &a, long long b) { a = max(a, b); }
void amin(long long &a, long long b) { a = min(a, b); }
const long double epsilon = 1e-9;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
bool comp(long long a, long long b) { return (a > b); }
long long POW(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long p = MOD) {
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) (res *= a) %= p;
    (a *= a) %= p;
    b >>= 1;
    a %= p;
    res %= p;
  }
  return res;
}
struct segtree {
  long long size;
  vector<long long> tree;
  const long long ID = 0;
  void init(long long n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, ID);
  }
  void upd(long long i, long long v) {
    tree[i += size] = v;
    for (i /= 2; i; i /= 2) tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  long long qry(long long l, long long r) {
    long long res = 0;
    for (l += size, r += size; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) res += tree[l++];
      if (r % 2 == 0) res += tree[r--];
    }
    return res;
  }
};
void runcase() {
  long long n, m;
  cin >> n >> m;
  long long tot = n * m;
  vector<long long> a(tot), b;
  for (long long i = 0; i < tot; i++) {
    long long x;
    cin >> x;
    a[i] = x;
  }
  b = a;
  sort(b.begin(), b.end());
  vector<vector<long long>> seats(n, vector<long long>(m));
  map<long long, set<long long>> elemrow;
  map<long long, long long> seated[n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long st = i * m + j;
      seats[i][j] = b[st];
      seated[i][b[st]]++;
      elemrow[b[st]].insert(i);
    }
  }
  map<long long, long long> backpos[n];
  for (long long i = 0; i < n; i++) {
    for (long long j = m - 1; j >= 0; j--) {
      if (j == m - 1)
        backpos[i][seats[i][j]] = j;
      else {
        if (seats[i][j] == seats[i][j + 1])
          continue;
        else
          backpos[i][seats[i][j]] = j;
      }
    }
  }
  segtree st[n];
  for (long long i = 0; i < n; i++) st[i].init(m);
  long long res = 0;
  for (long long i = 0; i < tot; i++) {
    long long val = a[i], r = *elemrow[val].begin();
    long long j = backpos[r][val], inconv = st[r].qry(0, j);
    st[r].upd(j, 1);
    seated[r][val]--;
    backpos[r][val]--;
    if (!seated[r][val]) elemrow[val].erase(r);
    res += inconv;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true);
       blockTime.second;
       fprintf(stderr, "%s: %lld ms\n", "Main",
               chrono::duration_cast<chrono::milliseconds>(
                   chrono::high_resolution_clock::now() - blockTime.first)
                   .count()),
            fflush(stderr), blockTime.second = false) {
    long long tests = 1;
    cin >> tests;
    while (tests--) {
      runcase();
    }
  }
  return 0;
}

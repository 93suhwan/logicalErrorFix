#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 3e5 + 10;
const long long mod = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
int p[N];
int cnt[N];
int f[N];
int find(int x) { return f[x] < 0 ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  if (f[fx] > f[fy]) swap(fx, fy);
  f[fx] += f[fy];
  f[fy] = fx;
}
void solve(int tCase) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    cnt[i] = 0;
  }
  int lim = n - 2 * m;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cnt[(i - p[i] + n) % n]++;
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= lim) s.insert(i);
  }
  vector<int> ans;
  for (int k : s) {
    for (int i = 0; i < n; ++i) f[i] = -1;
    for (int i = 0; i < n; ++i) {
      if (i == (k + p[i]) % n)
        continue;
      else
        merge(i, (p[i] + k) % n);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i == (k + p[i]) % n) continue;
      if (f[i] > 0)
        continue;
      else
        sum += (-f[i] - 1);
    }
    if (sum <= m) ans.push_back(k);
  }
  cout << ans.size();
  for (int i : ans) {
    cout << ' ' << i;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}

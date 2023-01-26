#include <bits/stdc++.h>
using namespace std;
template <class C>
void min_self(C &a, C b) {
  a = min(a, b);
}
template <class C>
void max_self(C &a, C b) {
  a = max(a, b);
}
const long long MOD = 1000000007;
template <class T1, class T2>
void add(T1 &x, T2 y, long long m = MOD) {
  x += y;
  if (x >= m) x -= m;
}
template <class T1, class T2>
void sub(T1 &x, T2 y, long long m = MOD) {
  x -= y;
  if (x < 0) x += m;
}
long long mod(long long n, long long m = MOD) {
  n %= m;
  if (n < 0) n += m;
  return n;
}
const int MAXN = 1e5 + 5;
const int LOGN = 21;
const long long INF = 1e16;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  int n, k;
  cin >> n >> k;
  vector<array<int, 2>> edges(k);
  set<int> vertices;
  for (int i = 1; i <= 2 * n; i++) vertices.insert(i);
  for (int i = 0; i < k; i++) {
    cin >> edges[i][0] >> edges[i][1];
    if (edges[i][0] > edges[i][1]) swap(edges[i][0], edges[i][1]);
    vertices.erase(edges[i][0]);
    vertices.erase(edges[i][1]);
  }
  auto intersect = [&](array<int, 2> a, array<int, 2> b) {
    if (a[0] > a[1]) swap(a[0], a[1]);
    if (b[0] > b[1]) swap(b[0], b[1]);
    if (a[0] > b[0]) swap(a, b);
    if (a[0] < b[0] && b[0] < a[1] && a[1] < b[1]) return true;
    return false;
  };
  auto calculate = [&](vector<array<int, 2>> &v) {
    long long ans = 0;
    int nv = v.size();
    for (int i = 0; i < nv; i++) {
      for (int j = i + 1; j < nv; j++) {
        if (intersect(v[i], v[j])) ans++;
      }
    }
    return ans;
  };
  vector<int> v(vertices.begin(), vertices.end());
  int sz = v.size(), half = sz / 2;
  for (int i = 0; i < half; i++) edges.push_back({v[i], v[i + half]});
  cout << calculate(edges), cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}

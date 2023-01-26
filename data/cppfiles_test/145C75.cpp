#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
struct dsu {
  vector<int> p, sze;
  dsu(int n) {
    p = sze = vector<int>(n + 1);
    for (int i = 0; i < n + 1; i++) p[i] = i, sze[i] = 1;
  }
  int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  int size(int v) { return sze[get(v)]; }
  void merge(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return;
    if (sze[a] < sze[b]) swap(a, b);
    sze[a] += sze[b], p[b] = a;
  }
};
void test_case() {
  int a, k;
  cin >> a >> k;
  vector<array<int, 3>> t(a);
  vector<array<int, 3>> m1, m2;
  for (int i = 0; i < a; i++) {
    cin >> t[i][0] >> t[i][1] >> t[i][2];
    m1.push_back({t[i][0], t[i][1], i});
    m2.push_back({t[i][1], t[i][0], i});
  }
  sort(m1.begin(), m1.end()), sort(m2.begin(), m2.end());
  int l = 0, r = 2e5, ans = 2e5;
  auto D = [&](int x, int y) { return x > y ? x - y : y - x; };
  dsu d(a);
  while (l <= r) {
    int mid = (l + r) / 2;
    for (int i = 0; i < a; i++) {
      int x = t[i][0], y = t[i][1];
      const array<int, 3> query1 = {x, y, i};
      auto pos = upper_bound(m1.begin(), m1.end(), query1);
      if (pos != m1.end() && (*pos)[0] == x) {
        if (D((*pos)[1], y) <= k) {
          d.merge(i, (*pos)[2]);
        }
      }
      pos--;
      if (pos != m1.begin()) {
        pos--;
        if (D((*pos)[1], y) <= k && (*pos)[0] == x) {
          d.merge(i, (*pos)[2]);
        }
      }
      const array<int, 3> query2 = {y, x, i};
      auto pos2 = upper_bound(m2.begin(), m2.end(), query2);
      if (pos2 != m2.end() && (*pos2)[0] == y && D((*pos2)[1], x) <= k) {
        d.merge(i, (*pos2)[2]);
      }
      pos2--;
      if (pos2 != m2.begin()) {
        pos2--;
        if ((*pos2)[0] == y && D((*pos2)[1], x) <= k) {
          d.merge(i, (*pos2)[2]);
        }
      }
    }
    vector<bool> dead(a);
    for (int i = 0; i < a; i++) {
      if (t[i][2] <= mid) {
        dead[d.get(i)] = 1;
      }
    }
    int req = 0;
    for (int i = 0; i < a; i++) {
      if (!dead[d.get(i)]) {
        dead[d.get(i)] = 1;
        req++;
      }
    }
    if (req <= mid + 1)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
    for (int i = 0; i < a; i++) {
      d.p[i] = i, d.sze[i] = 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) test_case();
}

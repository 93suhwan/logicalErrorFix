#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
void show(vector<long long> &a) {
  for (long long e : a) {
    if (e == (long long)(1000000000000000000 + 5))
      cout << "INF ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
void show(vector<int> &a) {
  for (int e : a) {
    if (e == (long long)(1000000000 + 7))
      cout << "MOD ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
template <typename T>
void enter(vector<T> &a) {
  for (T &e : a) cin >> e;
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
void JUDGE() {}
long long inline mo(long long a) { return a % (long long)(1000000000 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
struct segtree {
  long long size;
  vector<long long> sum;
  void init(long long n) {
    size = 1;
    while (size <= n) size *= 2;
    sum.assign(2 * size, neutral());
  }
  long long update(long long first, long long second) {
    return (first + second);
  }
  long long neutral() { return 0LL; }
  long long get(long long l, long long r) { return get(l, r, 0, 0, size); }
  long long get(long long l, long long r, long long x, long long lx,
                long long rx) {
    if (lx >= r || rx <= l) return neutral();
    if (lx >= l && rx <= r) {
      return sum[x];
    }
    long long m = (lx + rx) / 2;
    long long a = get(l, r, 2 * x + 1, lx, m);
    long long b = get(l, r, 2 * x + 2, m, rx);
    return update(a, b);
  }
  void set(long long l, long long r, long long v) { set(l, r, v, 0, 0, size); }
  void set(long long l, long long r, long long v, long long x, long long lx,
           long long rx) {
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
      sum[x] = v;
      return;
    }
    long long m = (lx + rx) / 2;
    set(l, r, v, 2 * x + 1, lx, m);
    set(l, r, v, 2 * x + 2, m, rx);
    sum[x] = update(sum[2 * x + 1], sum[2 * x + 2]);
  }
};
int n, m;
vector<int> place, a, b;
void rec(int l, int r, int b_l, int b_r) {
  if (b_l > b_r) return;
  int b_mid = (b_l + b_r) / 2, res = 0;
  for (int i = l; i < r; i++)
    if (a[i] < b[b_mid]) res++;
  int mini = res, index = l;
  for (int i = l; i < r; i++) {
    if (a[i] < b[b_mid]) res--;
    if (a[i] > b[b_mid]) res++;
    if (mini > res) {
      mini = res;
      index = i + 1;
    }
  }
  place[b_mid] = index;
  rec(l, index, b_l, b_mid - 1);
  rec(index, r, b_mid + 1, b_r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    a.assign(n, 0);
    b.assign(m, 0);
    enter(a);
    enter(b);
    sort(begin(b), end(b));
    place.assign(m, -1);
    rec(0, n, 0, m - 1);
    long long ans = 0;
    vector<long long> cur;
    int index = 0;
    for (int i = 0; i < m; i++) {
      while (index < place[i]) {
        cur.push_back(a[index]);
        index++;
      }
      cur.push_back(b[i]);
    }
    while (index < n) {
      cur.push_back(a[index]);
      index++;
    }
    int si = (int)cur.size();
    vector<pair<int, int>> second(si);
    for (int i = 0; i < si; i++) {
      second[i] = {cur[i], i};
    }
    sort(begin(second), end(second));
    second[0].first = 0;
    for (int i = 1; i < si; i++) {
      second[i].first = second[i - 1].first;
      if (cur[second[i - 1].second] != cur[second[i].second]) second[i].first++;
    }
    for (int i = 0; i < si; i++) cur[second[i].second] = second[i].first;
    vector<int> updates;
    segtree sg;
    sg.init(si);
    for (int i = 0; i < si; i++) {
      if (i && second[i - 1].first != second[i].first) {
        for (int e : updates) sg.set(e, e + 1, 1);
        updates.assign(0, 0);
      }
      ans += sg.get(second[i].second, si);
      updates.push_back(second[i].second);
    }
    cout << ans << "\n";
  }
  return 0;
}

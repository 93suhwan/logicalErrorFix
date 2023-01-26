#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int MOD2 = 9982441003;
long double PI = 2 * acos(0.0);
template <typename T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T mod_exp(T b, T p, T m) {
  T x = 1;
  while (p) {
    if (p & 1) x = (x * b) % m;
    b = (b * b) % m;
    p = p >> 1;
  }
  return x;
}
template <typename T>
T invFermat(T a, T p) {
  return mod_exp(a, p - 2, p);
}
template <typename T>
T exp(T b, T p) {
  T x = 1;
  while (p) {
    if (p & 1) x = (x * b);
    b = (b * b);
    p = p >> 1;
  }
  return x;
}
string tostring(long long int number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
long long int toint(const string& s) {
  stringstream ss;
  ss << s;
  long long int x;
  ss >> x;
  return x;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
struct segtree {
  long long int sz;
  vector<long long int> values;
  void init(long long int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    values.assign(2 * sz, 0);
  }
  void set(long long int i, long long int v, long long int x, long long int lx,
           long long int rx) {
    if (rx - lx == 1) {
      values[x] = v;
      return;
    }
    long long int mid = (lx + rx) / 2;
    if (mid > i) {
      set(i, v, 2 * x + 1, lx, mid);
    } else {
      set(i, v, 2 * x + 2, mid, rx);
    }
    values[x] = values[2 * x + 1] + values[2 * x + 2];
  }
  long long int query(long long int l, long long int r, long long int x,
                      long long int lx, long long int rx) {
    if (lx >= r or rx <= l) return 0;
    if (lx >= l and rx <= r) return values[x];
    long long int mid = (lx + rx) / 2;
    long long int left = query(l, r, 2 * x + 1, lx, mid);
    long long int right = query(l, r, 2 * x + 2, mid, rx);
    return left + right;
  }
};
bool comp(pair<long long int, long long int>& p1,
          pair<long long int, long long int>& p2) {
  if (p1.first != p2.first) {
    return p1.first < p2.first;
  }
  return p1.second > p2.second;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<pair<long long int, long long int> > a, b;
  for (long long int i = 0; i < n * m; i++) {
    long long int x;
    cin >> x;
    a.push_back({x, i});
    b.push_back({x, i});
  }
  map<pair<long long int, long long int>, pair<long long int, long long int> >
      seats;
  sort(b.begin(), b.end(), comp);
  long long int x = 0;
  long long int y = 0;
  for (auto r : b) {
    seats[r] = {x, y};
    y++;
    if (y >= m) {
      x++;
      y = 0;
    }
  }
  vector<segtree> prefs(n);
  for (long long int i = 0; i < n; i++) {
    prefs[i].init(m);
  }
  long long int ans = 0;
  for (auto r : a) {
    long long int smol = prefs[seats[r].first].query(0, seats[r].second, 0, 0,
                                                     prefs[seats[r].first].sz);
    ans += smol;
    prefs[seats[r].first].set(seats[r].second, 1, 0, 0,
                              prefs[seats[r].first].sz);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

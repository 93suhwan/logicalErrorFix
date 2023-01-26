#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> maxd(n);
  long long maxdamage = 0, sum = 0;
  for (long long i = 0; i < n - 1; i++) {
    maxd[i] = a[i + 1] - a[i];
    maxdamage = max(maxd[i], maxdamage);
    sum += maxd[i];
  }
  maxd[n - 1] = INT64_MAX;
  if ((h - sum) >= maxdamage) {
    cout << h - sum << "\n";
    return;
  }
  long long st = 1;
  long long ans = maxdamage;
  while (st <= maxdamage) {
    long long mid = (st + maxdamage) / 2;
    sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += min(mid, maxd[i]);
    }
    if (sum >= h) {
      ans = min(mid, ans);
      maxdamage = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

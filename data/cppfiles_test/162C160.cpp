#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << " " << p.second;
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
istream &operator>>(istream &is, T_container &v) {
  for (T &x : v) is >> x;
  return is;
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  bool f = false;
  for (const T &x : v) {
    if (f) os << " ";
    os << x;
    f = true;
  }
  return os;
}
void scan() {}
template <typename Head, typename... Tail>
void scan(Head &H, Tail &...T) {
  cin >> H;
  scan(T...);
}
void print() { cout << "\n"; }
template <typename Head>
void print(const Head &H) {
  cout << H << "\n";
}
template <typename Head, typename... Tail>
void print(const Head &H, const Tail &...T) {
  cout << H << " ";
  print(T...);
}
bool check(vector<long long int> a, long long int val) {
  long long int n = a.size();
  vector<long long int> copy(n, 0);
  for (long long int i = n - 1; i >= 2; i--) {
    if (a[i] + copy[i] < val) return false;
    long long int l = 0, r = a[i], mid, d = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      long long int req = 3 * mid;
      if (a[i] >= req && (a[i] - req + copy[i] >= val)) {
        l = mid + 1;
        d = mid;
      } else {
        r = mid - 1;
      }
    }
    copy[i - 1] += d;
    copy[i - 2] += (2 * d);
  }
  long long int mn = INT_MAX;
  for (long long i = 0; i < n; i++) {
    mn = min(copy[i] + a[i], mn);
  }
  if (mn >= val) return true;
  return false;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  scan(a);
  long long int low = 0, high = 1e9, mid, ans = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    bool flag = check(a, mid);
    if (flag) {
      low = mid + 1;
      ans = max(ans, mid);
    } else {
      high = mid - 1;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

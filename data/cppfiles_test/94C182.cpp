#include <bits/stdc++.h>
using namespace std;
template <class T, template <class T2, class A = allocator<T2> > class cont>
inline ostream &operator<<(ostream &out, const cont<T> &x) {
  for (const auto &it : x) {
    out << it << " ";
  }
  return out;
}
template <class T, template <class T2, class A = allocator<T2> > class cont>
inline istream &operator>>(istream &in, cont<T> &x) {
  for (auto &it : x) {
    in >> it;
  }
  return in;
}
template <class T, class T2>
inline ostream &operator<<(ostream &out, const pair<T, T2> &x) {
  out << x.first << " " << x.second;
  return out;
}
template <class T, class T2>
inline istream &operator>>(istream &in, pair<T, T2> &x) {
  in >> x.first >> x.second;
  return in;
}
template <class T, class T2>
inline bool chkmax(T &x, const T2 &y) {
  return x < y ? x = y, 1 : 0;
}
template <class T, class T2>
inline bool chkmin(T &x, const T2 &y) {
  return x > y ? x = y, 1 : 0;
}
const long long mod = 1e9 + 7;
const long long MAX_N = 100;
long long arr[MAX_N];
long long n, k;
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    long long pw = 1;
    while (arr[i]) {
      pw = (pw * 10ll);
      arr[i]--;
    }
    arr[i] = pw;
  }
  sort(arr, arr + n);
  k++;
  long long ret = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long can = arr[i + 1] / arr[i] - 1;
    can = min(can, k);
    k -= can;
    ret += can * arr[i];
  }
  ret += k * arr[n - 1];
  cout << ret << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << "[ " << *it << " = " << a << " ] ";
  err(++it, args...);
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const pair<Tk, Tv>& p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (T x : p) os << x << " ";
  os << "]" << '\n';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const map<Tk, Tv>& p) {
  os << "{ ";
  for (pair<Tk, Tv> x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int a[3], m;
    for (long long int i = 0; i < 3; i++) cin >> a[i];
    cin >> m;
    sort(a, a + 3);
    long long int hold = a[0] + a[1];
    long long int min = 0;
    if (a[2] > hold) {
      min = a[2] - hold - 1;
    }
    long long int max = a[0] + a[1] + a[2] - 3;
    if (m >= min && m <= max) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

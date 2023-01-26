#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
void deb(istream_iterator<string> it) {}
template <typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << ' ';
  deb(++it, args...);
}
int Set(int n, int pos) { return n | (1 << pos); }
int Reset(int n, int pos) { return n = n & ~(1 << pos); }
bool Check(int n, int pos) { return (bool)(n & (1 << pos)); }
mt19937 mt_rand(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 5002;
const int M = 1000006;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].first == a[i].second) {
      cout << a[i].first << ' ' << a[i].second << ' ' << a[i].second << '\n';
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (a[i].first == a[j].first && a[j].second < a[i].second) {
        cout << a[i].first << ' ' << a[i].second << ' ' << a[j].second + 1
             << '\n';
        break;
      }
      if (a[i].first < a[j].first && a[j].second == a[i].second) {
        cout << a[i].first << ' ' << a[i].second << ' ' << a[j].first - 1
             << '\n';
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int q = 1;
  cin >> q;
  for (int kase = 1; kase <= q; kase++) {
    solve();
  }
  return 0;
}

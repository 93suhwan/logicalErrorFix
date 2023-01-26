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
  set<pair<int, int> > st;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    st.insert({a[i].first, a[i].second});
  }
  for (int i = 0; i < n; i++) {
    if (a[i].first == a[i].second) {
      cout << a[i].first << ' ' << a[i].second << ' ' << a[i].second << '\n';
      continue;
    }
    for (int j = a[i].first; j <= a[i].second; j++) {
      vector<pair<int, int> > v;
      if (a[i].first <= j - 1) v.emplace_back(a[i].first, j - 1);
      if (j + 1 <= a[i].second) v.emplace_back(j + 1, a[i].second);
      if (v.size() == 1 && st.find(v[0]) != st.end()) {
        cout << a[i].first << ' ' << a[i].second << ' ' << j << '\n';
        break;
      } else if (st.find(v[0]) != st.end() && st.find(v[1]) != st.end()) {
        cout << a[i].first << ' ' << a[i].second << ' ' << j << '\n';
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

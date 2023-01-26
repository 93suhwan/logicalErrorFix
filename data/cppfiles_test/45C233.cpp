#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
inline int ceili(int x, int y) { return (x + y - 1) / y; }
inline long long ceili(long long x, long long y) { return (x + y - 1) / y; }
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n), even_pos;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> arr[i];
    if (arr[i] % 2 == 0) even_pos.push_back(i);
  }
  long long ans = 1e18;
  for (int i = 0; i < (int)(2); ++i) {
    vector<int> pos;
    for (int j = i; j < n; j += 2) pos.push_back(j);
    ;
    if (((int)((even_pos).size())) == ((int)((pos).size()))) {
      long long cnt = 0;
      for (int j = 0; j < ((int)((pos).size())); ++j)
        cnt += abs(pos[j] - even_pos[j]);
      ans = min(ans, cnt);
    }
  }
  if (ans == 1e18)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}

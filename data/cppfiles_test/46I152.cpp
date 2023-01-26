#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void _print(long long int t) { cerr << t; }
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
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int mx = -1;
  long long int pos = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= mx) {
      if (a[i] == mx)
        pos = i;
      else {
        mx = a[i];
        pos = i;
      }
    }
  }
  long long int ans = 0;
  long long int pos2 = pos;
  long long int fnd = mx - 1;
  bool en = false;
  for (long long int i = pos + 1; i < n; i++) {
    if (a[i] == fnd) {
      if (i == n - 1) {
        ans++;
        en = true;
      } else {
        ans++;
        fnd -= 1;
        pos = i;
      }
    }
  }
  if (en) {
    cout << ans;
  } else {
    ans += n - pos - 1;
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}

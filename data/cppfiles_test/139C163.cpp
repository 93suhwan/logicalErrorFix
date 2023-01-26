#include <bits/stdc++.h>
using namespace std;
void _print(long long int x) { cerr << x << " "; }
void _print(float x) { cerr << x << " "; }
void _print(double x) { cerr << x << " "; }
void _print(char x) { cerr << x << " "; }
void _print(string x) { cerr << x << " "; }
void _print(bool x) { cerr << x << " "; }
template <class T, class V>
void _print(pair<T, V> x) {
  cerr << "{";
  _print(x.first);
  cerr << ",";
  _print(x.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> x) {
  cerr << "[ ";
  for (auto i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
void solve() {
  string s;
  cin >> s;
  long long int n = s.size();
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  for (long long int i = 0; i <= (n / 2) - 1; i++) {
    if (s[i] != s[i + (n / 2)]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start, end;
  start = clock();
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "Time taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec " << endl;
  return 0;
}

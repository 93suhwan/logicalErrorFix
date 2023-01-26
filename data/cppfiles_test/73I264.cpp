#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(bool b) { cerr << b; }
template <class T, class V>
void _print(pair<T, V> push);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> push) {
  cerr << "{";
  _print(push.ff);
  cerr << ",";
  _print(push.ss);
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
void intext() {}
void solve() {
  long long n;
  cin >> n;
  vector<long long> ar(n);
  for (long long i = 0; i < n; i++) cin >> ar[i];
  vector<long long> br = ar;
  sort(br.begin(), br.end());
  long long cnt = 0;
  for (long long i = 0; ar != br; i++) {
    for (long long j = 0; j < n - 1;) {
      if (ar[j] > ar[j + 1]) {
        swap(ar[j], ar[j + 1]);
        ;
        j += 2;
      } else
        j++;
    };
    cnt++;
    if (ar == br) break;
  }
  cout << cnt << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  intext();
  long long t;
  cin >> t;
  while (t--) solve();
}

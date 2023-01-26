#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v1(n);
  for (long long i = 0; i < n; i++) {
    cin >> v1[i];
  }
  sort((v1).begin(), (v1).end());
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += v1[i];
  long long q;
  cin >> q;
  while (q--) {
    long long d, a;
    cin >> d >> a;
    auto u = lower_bound((v1).begin(), (v1).end(), d);
    long long val = 0;
    if (u != v1.end()) {
      val = *u;
    }
    long long val2 = 0;
    if (u != v1.begin()) {
      u--;
      val2 = *u;
    }
    if (val >= d && sum - val >= a) {
      cout << 0 << "\n";
    } else if (val2 >= d && sum - val2 >= a) {
      cout << 0 << "\n";
    } else {
      if (val == 0) {
        val = val2 = v1.back();
      } else if (val2 == 0) {
        val2 = 1 < ((long long)(v1).size()) ? v1[1] : 0;
      };
      ;
      long long ans = min(max(0ll, d - val) + max(0ll, (a - sum + val)),
                          max(0ll, d - val2) + max(0ll, (a - sum + val2)));
      cout << ans << "\n";
    }
  }
}
signed main() {
  init_code();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

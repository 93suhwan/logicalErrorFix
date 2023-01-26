#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
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
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto& e : v) {
      cin >> e;
    }
    long long m = *max_element(v.begin(), v.end());
    if (m == v[n - 1]) {
      cout << 0 << "\n";
      continue;
    }
    long long ans = 1;
    long long x = v[n - 1];
    vector<long long> l;
    vector<long long> r;
    for (long long i = 0; i < n; i++) {
      if (v[i] <= x) {
        l.push_back(v[i]);
      }
      if (v[i] > x) {
        r.push_back(v[i]);
      }
    };
    ;
    ;
    ;
    long long max = *max_element(v.begin(), v.end());
    long long ans1 = 1;
    for (int i = r.size() - 1; i >= 0; i--) {
      if (r[i] != max) {
        ans1++;
      } else {
        break;
      }
    }
    ans += max - r[r.size() - 1];
    long long ans2 = min(ans, ans1);
    ;
    ;
    cout << ans2 << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

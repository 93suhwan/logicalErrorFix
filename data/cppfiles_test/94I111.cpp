#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
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
template <class T, class V>
void _print(multimap<T, V> v);
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
template <class T, class V>
void _print(multimap<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long productOfSubsetSums(vector<long long> a) {
  long long ans = 1;
  for (long long i = 0; i < a.size(); ++i) ans = ans * (a[i] + 1);
  return ans - 1;
}
void solve() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string o = to_string(n);
    vector<long long> v(o.length());
    for (long long i = 0; i < o.length(); i++) v[i] = (char)o[i] - '0';
    long long ans = 0, x = 1;
    for (long long i = 0; i < v.size(); i++) {
      if (v[i] != 0) x *= (v[i] + 1);
    }
    ans += x;
    ;
    ;
    x = 1;
    long long y = 1;
    if (n >= 100) {
      vector<long long> val;
      for (long long i = v.size() - 1; i >= 0; i--) {
        if (i >= 2) {
          if (i >= 4) {
            y = (10 - v[i] - 1);
            val.push_back(y);
          } else if (v[i - 2] > 0) {
            y = (10 - v[i] - 1);
            val.push_back(y);
          } else {
            if (i > v.size() - 3 && v[i] != 0)
              x *= (v[i] + 1);
            else if (v[i + 2] < 9 && v[i] != 0)
              x *= (v[i]);
          }
        } else {
          if (i > v.size() - 3 && v[i] != 0)
            x *= (v[i] + 1);
          else if (v[i + 2] < 9 && v[i] != 0)
            x *= (v[i]);
        }
      }
      ans += (productOfSubsetSums(val)) * x;
    }
    ans -= 2;
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}

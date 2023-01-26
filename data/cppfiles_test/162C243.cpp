#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long left = 0;
  long long max_val = -1;
  for (long long i = 0; i < n; i++) {
    max_val = max(max_val, v[i]);
  }
  long long right = max_val;
  long long ans = -1;
  while (left <= right) {
    ;
    ;
    vector<long long> temp = v;
    long long flag = 0;
    long long mid = (left + right) / 2;
    ;
    for (long long i = n - 1; i >= 2; i--) {
      if (temp[i] >= mid) {
        long long transfer = min(v[i], temp[i] - mid) / 3;
        temp[i] = temp[i] - 3 * transfer;
        temp[i - 1] = temp[i - 1] + transfer;
        temp[i - 2] = temp[i - 2] + 2 * transfer;
        ;
        ;
      } else {
        flag = 1;
      }
    }
    if (flag == 0) {
      ;
      if (temp[1] >= mid && temp[0] >= mid) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      right = mid - 1;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

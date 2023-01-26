#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<int> v;
    vector<pair<int, int>> p;
    int sumodd = 0;
    int sumeven = 0;
    for (int i = 0; i < n; i++) {
      char x;
      cin >> x;
      if (x == '+') {
        v.push_back(1);
      } else {
        v.push_back(-1);
      }
      if (i % 2 == 0) {
        sumodd += v[i];
      } else {
        sumeven -= v[i];
      }
      p.push_back({sumodd, sumeven});
    };
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (x >= 1) {
        sumodd = p[y].first - p[x - 1].first;
        sumeven = p[y].second - p[x - 1].second;
        if (x % 2 != 0) {
          sumodd = p[y].second * (-1) - p[x - 1].second * (-1);
          sumeven = p[y].first * (-1) - p[x - 1].first * (-1);
        }
      } else {
        sumodd = p[y].first;
        sumeven = p[y].second;
      }
      if (sumodd + sumeven == 0) {
        cout << 0 << "\n";
      } else {
        int diff = abs(sumeven + sumodd);
        if (diff > 2) {
          diff -= 2;
        }
        cout << diff << "\n";
      }
    }
  }
}

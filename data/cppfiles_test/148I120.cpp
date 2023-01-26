#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T t) {
  cerr << t;
}
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
template <class T, class V>
void _print(vector<pair<T, V>> v) {
  cerr << "[ ";
  for (auto i : v) {
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
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int tt;
  cin >> tt;
  while (tt--) {
    int w, h;
    cin >> w >> h;
    int b;
    cin >> b;
    int barr[b];
    for (int i = 0; i < b; i++) {
      cin >> barr[i];
    }
    int u;
    cin >> u;
    int uarr[u];
    for (int i = 0; i < u; i++) {
      cin >> uarr[i];
    }
    int l;
    cin >> l;
    int larr[l];
    for (int i = 0; i < l; i++) {
      cin >> larr[i];
    }
    int r;
    cin >> r;
    int rarr[r];
    for (int i = 0; i < r; i++) {
      cin >> rarr[i];
    }
    long long horizontal = max(barr[b - 1] - barr[0], uarr[u - 1] - uarr[0]);
    long long vertical = max(larr[l - 1] - larr[0], rarr[r - 1] - rarr[0]);
    if (horizontal >= vertical) {
      cout << horizontal * h << endl;
    } else {
      cout << vertical * w << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

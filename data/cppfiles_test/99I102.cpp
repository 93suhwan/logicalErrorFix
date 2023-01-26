#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char mat[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = '=';
      }
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        v.push_back(i);
      }
      mat[i][i] = 'X';
    }
    if (v.size() == 0 || v.size() > 2) {
      cout << "YES\n";
      if (v.size() > 0) {
        mat[v[0]][v[1]] = '+';
        mat[v[1]][v[0]] = '-';
        mat[v[1]][v[2]] = '+';
        mat[v[2]][v[1]] = '-';
        mat[v[0]][v[2]] = '-';
        mat[v[2]][v[0]] = '+';
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << mat[i][j];
        }
        cout << "\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}

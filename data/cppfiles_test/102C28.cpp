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
int is_possible(int min, int max, int width) {
  if (min * (-1) + max + 1 <= width) return min * (-1) + 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    string s;
    cin >> s;
    string x_axis = "";
    string y_axis = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R' || s[i] == 'L')
        x_axis.push_back(s[i]);
      else
        y_axis.push_back(s[i]);
    }
    int mini = 0, maxi = 0;
    int current = 0, x_coordinate = 1, y_coordinate = 1;
    for (int i = 0; i < x_axis.size(); i++) {
      if (x_axis[i] == 'L') {
        current -= 1;
        mini = min(current, mini);
        if (is_possible(mini, maxi, m)) {
          x_coordinate = is_possible(mini, maxi, m);
        } else
          break;
      } else {
        current += 1;
        maxi = max(current, maxi);
        if (is_possible(mini, maxi, m)) {
          x_coordinate = is_possible(mini, maxi, m);
        } else
          break;
      }
    }
    mini = 0;
    maxi = 0;
    current = 0;
    for (int i = 0; i < y_axis.size(); i++) {
      if (y_axis[i] == 'U') {
        current -= 1;
        mini = min(current, mini);
        if (is_possible(mini, maxi, n)) {
          y_coordinate = is_possible(mini, maxi, n);
        } else
          break;
      } else {
        current += 1;
        maxi = max(current, maxi);
        if (is_possible(mini, maxi, n)) {
          y_coordinate = is_possible(mini, maxi, n);
        } else
          break;
      }
    }
    cout << y_coordinate << " " << x_coordinate << "\n";
  }
}

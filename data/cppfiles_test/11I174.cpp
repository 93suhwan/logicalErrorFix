#include <bits/stdc++.h>
using namespace std;
void nl() { printf("\n"); }
void sc(int& n) { scanf("%d", &n); }
void sc(long long& n) { scanf("%lld", &n); }
void sc(char& n) { scanf(" %c", &n); }
void _print(long long t) { printf("%lld ", t); }
void _print(int t) { printf("%d ", t); }
void _print(string t) { cout << t; }
void _print(char t) { printf("%c", t); }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
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
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "vec->[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "set->[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "multiset->[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "map->[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
const long long inf = (long long)1e15 + 10;
const int N = (int)1e6 + 10;
void solve() {
  int n;
  sc(n);
  std::vector<string> s(n);
  std::vector<vector<int>> mark(n, vector<int>(5, 0));
  vector<int> tot(5, 0);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (auto x : s[i]) {
      mark[i][x - 'a']++;
    }
    for (int j = 0; j < 5; j++) {
      tot[j] += mark[i][j];
    }
  }
  int final = 0;
  for (int j = 0; j < 5; j++) {
    std::vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int k = 0; k < 5; k++) {
        if (k == j) {
          ans[i].second = mark[i][k];
        } else {
          sum += mark[i][k];
        }
      }
      ans[i].first = sum;
    }
    sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      return a.first < b.first;
    });
    int v1 = tot[j], v2 = 0;
    for (int i = 0; i < 5; ++i) {
      if (i != j) {
        v2 += tot[i];
      }
    }
    reverse(ans.begin(), ans.end());
    int res = n;
    for (int i = 0; i < n; i++) {
      if (v1 > v2) break;
      res--;
      v2 -= ans[i].first;
      v1 -= ans[i].second;
    }
    final = max(final, res);
  }
  _print(final);
  nl();
}
int main() {
  int t = 1;
  sc(t);
  while (t--) {
    solve();
  }
  return 0;
}

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
  int br[n][5];
  vector<int> total(5, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      sc(br[i][j]);
      if (br[i][j] == 1) {
        total[j]++;
      }
    }
  }
  vector<int> Thik_he;
  for (int i = 0; i < 5; i++) {
    if (total[i] >= (n / 2)) {
      Thik_he.push_back(i);
    }
  }
  for (int i = 0; i < (int)Thik_he.size(); i++) {
    for (int j = i + 1; j < (int)Thik_he.size(); j++) {
      int total = 0;
      int a = Thik_he[i];
      int b = Thik_he[j];
      for (int k = 0; k < n; k++) {
        if (br[k][a] || br[k][b]) {
          total++;
        }
      }
      if (total == n) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
}
int main() {
  int t = 1;
  sc(t);
  while (t--) {
    solve();
  }
  return 0;
}

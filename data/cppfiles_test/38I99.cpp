#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cout << '{';
  for (auto &i : x) cout << (first++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[n][m];
    memset(a, 0, sizeof(a));
    set<int> s;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i == 0 || j == 0) a[i][j] = 1;
        char x;
        cin >> x;
        if (x == 'X') a[i][j] = -1;
        if (j > 0 && i > 0) {
          if (a[i][j] == 0 && a[i][j - 1] == -1 && a[i - 1][j] == -1)
            s.insert(j);
        }
      }
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        if (a[i][j] == 0)
          if (a[i - 1][j] == 1 || a[i][j - 1] == 1) a[i][j] = 1;
    long long total = 0;
    vector<long long> ans;
    ans.push_back(0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        if (a[j][i] == 0) total++;
      ans.push_back(total);
    };
    long long q;
    cin >> q;
    while (q--) {
      long long x, y;
      cin >> x >> y;
      if (x == y) {
        cout << "YES" << endl;
        continue;
      }
      auto it = s.lower_bound(x);
      if (it == s.end()) {
        cout << "YES" << endl;
        continue;
      }
      long long val = *it;
      if (val > y) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long int mod = 1000000007;
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  map<long long int, long long int> make_pair;
  int mat[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[j][i] == 2) {
        make_pair[i]++;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    long long int x;
    cin >> x;
    x--;
    if (n == 1) {
      cout << x + 1 << " ";
      continue;
    }
    if (make_pair[x] == n) {
      cout << x + 1 << " ";
      continue;
    } else {
      int temp = 0;
      while (temp != n) {
        if (mat[temp][x] == 2) {
          temp++;
        } else {
          if (mat[temp][x] == 1) {
            mat[temp][x] = 2;
            make_pair[x]++;
            x++;
          } else {
            mat[temp][x] = 2;
            make_pair[x]++;
            x--;
          }
        }
      }
    }
    cout << x + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}

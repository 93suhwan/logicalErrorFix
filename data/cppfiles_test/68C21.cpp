#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e18;
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
struct dsu {
  int n;
  vector<int> p;
  void Union(long long int u, long long int v) {
    long long int temp = p[u];
    for (long long int i = 1; i < n + 1; i++) {
      if (p[i] == temp) {
        p[i] = p[v];
      }
    }
  }
  bool find(long long int a, long long int b) {
    if (p[a] == p[b]) return true;
    return false;
  }
};
vector<long long int> ans;
long long int vis[4][100009];
void solve() {
  long long int k;
  cin >> k;
  long long int f = 1;
  long long int a = pow(f, 2);
  while (a < k) {
    f++;
    a = pow(f, 2);
  }
  long long int row, col;
  long long int po = pow(f, 2);
  long long int ch = po - f;
  if (k > ch) {
    row = f;
    col = po - k + 1;
  } else {
    col = f;
    po = pow(f - 1, 2);
    row = k - po;
  }
  cout << row << " " << col << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int test = 1;
  cin >> test;
  for (long long int i = 0; i < test; i++) {
    solve();
  }
}

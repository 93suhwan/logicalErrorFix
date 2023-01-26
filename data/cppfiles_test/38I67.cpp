#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (long long int i = 0; i < v.size(); i++) res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (long long int i = 0; i < b; i++) res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { cout << ("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const long long int N = 1e6;
const long long int MOD = 1e9 + 7;
long long int m;
long long int seg[N + 1][20];
void buildsparsetable() {
  for (long long int j = 1; (1 << j) <= m; j++)
    for (long long int i = 0; (i + pow(2, j) - 1) < m; i++)
      seg[i][j] =
          max(seg[i][j - 1], seg[i + (long long int)pow(2, j - 1)][j - 1]);
}
long long int query(long long int l, long long int r) {
  long long int j = log2(r - l + 1);
  return max(seg[l][j], seg[r - (long long int)pow(2, j) + 1][j]);
}
void solve() {
  long long int n;
  cin >> n >> m;
  string s[n];
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long int dp[n + 1][m + 1], mx_left[n + 1][m + 1];
  memset(dp, -1, sizeof dp);
  memset(mx_left, MOD, sizeof mx_left);
  for (long long int i = 0; i < n; i++) {
    if (s[i][0] == '.') dp[i][0] = 1;
  }
  for (long long int i = 0; i < m; i++) {
    if (s[0][i] == '.') dp[0][i] = 1;
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        mx_left[i][j] = j;
        if (i && s[i - 1][j] == '.') {
          dp[i][j] = dp[i - 1][j];
          mx_left[i][j] = mx_left[i - 1][j];
        }
        if (j && s[i][j - 1] == '.') {
          dp[i][j] = dp[i][j - 1];
          mx_left[i][j] = min(mx_left[i][j], mx_left[i][j - 1]);
        }
      }
    }
  }
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      if (s[j][i] == '.' && dp[j][i] == -1)
        seg[i][0] = max(seg[i][0], mx_left[j][i]);
    }
  }
  long long int q;
  cin >> q;
  buildsparsetable();
  for (long long int i = 0; i < q; i++) {
    long long int l, r;
    cin >> l >> r;
    --l, --r;
    long long int x = query(l, r);
    if (x > l) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  clock_t time = clock();
  long long int t = 1;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
  double time_taken = ((double)(clock() - time)) / CLOCKS_PER_SEC;
  cerr << "LINE(" << 137 << ") -> ["
       << "time_taken"
       << "]: [",
      DBG(time_taken);
  return 0;
}

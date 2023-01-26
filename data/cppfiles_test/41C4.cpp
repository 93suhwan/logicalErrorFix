#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
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
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<long long>> r30(n, vector<long long>(3, 0));
  vector<vector<long long>> r31(n, vector<long long>(3, 0));
  vector<vector<long long>> r32(n, vector<long long>(3, 0));
  for (int i = 0; i < n; ++i) {
    if (i % 3 == 0) r30[i][s[i] - 'a']++;
    if (i % 3 == 1) r31[i][s[i] - 'a']++;
    if (i % 3 == 2) r32[i][s[i] - 'a']++;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      r30[i][j] += r30[i - 1][j];
      r31[i][j] += r31[i - 1][j];
      r32[i][j] += r32[i - 1][j];
    }
  }
  while (m--) {
    long long l, r;
    cin >> l >> r;
    --l;
    --r;
    vector<vector<long long>> cnt3(3, vector<long long>(3, 0));
    for (int i = 0; i < 3; ++i) {
      cnt3[0][i] = r30[r][i] - (l > 0 ? r30[l - 1][i] : 0);
      cnt3[1][i] = r31[r][i] - (l > 0 ? r31[l - 1][i] : 0);
      cnt3[2][i] = r32[r][i] - (l > 0 ? r32[l - 1][i] : 0);
    }
    long long ans = LLONG_MAX;
    ans = min(ans, cnt3[l % 3][1] + cnt3[l % 3][2] + cnt3[(l + 1) % 3][0] +
                       cnt3[(l + 1) % 3][2] + cnt3[(l + 2) % 3][0] +
                       cnt3[(l + 2) % 3][1]);
    ans = min(ans, cnt3[l % 3][1] + cnt3[l % 3][2] + cnt3[(l + 1) % 3][0] +
                       cnt3[(l + 1) % 3][1] + cnt3[(l + 2) % 3][0] +
                       cnt3[(l + 2) % 3][2]);
    ans = min(ans, cnt3[l % 3][0] + cnt3[l % 3][2] + cnt3[(l + 1) % 3][1] +
                       cnt3[(l + 1) % 3][2] + cnt3[(l + 2) % 3][0] +
                       cnt3[(l + 2) % 3][1]);
    ans = min(ans, cnt3[l % 3][0] + cnt3[l % 3][2] + cnt3[(l + 1) % 3][0] +
                       cnt3[(l + 1) % 3][1] + cnt3[(l + 2) % 3][2] +
                       cnt3[(l + 2) % 3][1]);
    ans = min(ans, cnt3[l % 3][1] + cnt3[l % 3][0] + cnt3[(l + 1) % 3][1] +
                       cnt3[(l + 1) % 3][2] + cnt3[(l + 2) % 3][0] +
                       cnt3[(l + 2) % 3][2]);
    ans = min(ans, cnt3[l % 3][1] + cnt3[l % 3][0] + cnt3[(l + 1) % 3][0] +
                       cnt3[(l + 1) % 3][2] + cnt3[(l + 2) % 3][2] +
                       cnt3[(l + 2) % 3][1]);
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

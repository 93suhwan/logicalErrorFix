#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int mod = 1e9 + 7;
map<long long, vector<long long>> f;
map<long long, int> mp;
set<long long, greater<long long>> st;
long long dp[70];
long long two[70];
long long check[7];
int get(string s) {
  if (s == "white") return 1;
  if (s == "yellow") return 2;
  if (s == "green") return 3;
  if (s == "blue") return 4;
  if (s == "red") return 5;
  if (s == "orange") return 6;
  return -1;
}
void init(int n) {
  dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = dp[i + 1] * dp[i + 1] % mod * 16 % mod;
  }
  two[0] = 1;
  for (int i = 1; i <= 60; i++) {
    two[i] = two[i - 1] * 2;
  }
  for (int i = 0; i <= 60; i++) {
    two[i]--;
  }
}
long long clac(int x, long long v1, long long v2) {
  long long x1 = 0, x2 = 0;
  for (int i = 1; i <= 6; i++) {
    x1 = (x1 + f[v1][i]) % mod;
    x2 = (x2 + f[v2][i]) % mod;
  }
  if (x == 1 || x == 2) {
    x1 = (x1 - f[v1][1] - f[v1][2] + mod) % mod;
    x2 = (x2 - f[v2][1] - f[v2][2] + mod) % mod;
  } else if (x == 3 || x == 4) {
    x1 = (x1 - f[v1][3] - f[v1][4] + mod) % mod;
    x2 = (x2 - f[v2][3] - f[v2][4] + mod) % mod;
  } else {
    x1 = (x1 - f[v1][5] - f[v1][6] + mod) % mod;
    x2 = (x2 - f[v2][5] - f[v2][6] + mod) % mod;
  }
  return x1 * x2 % mod;
}
int main() {
  int k;
  cin >> k;
  init(k);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    st.insert(v);
    mp[v] = get(s);
  }
  while (!st.empty()) {
    auto iter = st.begin();
    long long v = *iter;
    st.erase(iter);
    if (v / 2 >= 1) st.insert(v / 2);
    int pos = lower_bound(two, two + 60, v) - two;
    vector<long long> temp(7, 0);
    if (mp.find(v) != mp.end()) {
      int x = mp[v];
      if (pos == k) {
        temp[x] = 1;
        f[v] = temp;
      } else {
        long long ls = v << 1, rs = v << 1 | 1;
        if (f.find(ls) == f.end()) {
          vector<long long> v_ls(7, dp[pos + 1]);
          f[ls] = v_ls;
        }
        if (f.find(rs) == f.end()) {
          vector<long long> v_rs(7, dp[pos + 1]);
          f[rs] = v_rs;
        }
        temp[x] = clac(x, v << 1, v << 1 | 1);
        f[v] = temp;
      }
    } else {
      if (pos == k) {
        for (int i = 1; i <= 6; i++) {
          temp[i] = 1;
        }
        f[v] = temp;
      } else {
        long long ls = v << 1, rs = v << 1 | 1;
        if (f.find(ls) == f.end()) {
          vector<long long> v_ls(7, dp[pos + 1]);
          f[ls] = v_ls;
        }
        if (f.find(rs) == f.end()) {
          vector<long long> v_rs(7, dp[pos + 1]);
          f[rs] = v_rs;
        }
        for (int i = 1; i <= 6; i++) {
          temp[i] = clac(i, ls, rs);
        }
        f[v] = temp;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 6; i++) {
    ans = (ans + f[1][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}

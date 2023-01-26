#include <bits/stdc++.h>
using namespace std;
void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
template <typename T>
void PVecPrint(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i].first << "," << v[i].second << ' ';
  cout << '\n';
}
template <class T>
void VecPrint(vector<T> &v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << '\n';
}
string s;
vector<int> hashv;
int n, p = 31;
vector<int> dp;
int modpow(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c = c * 1LL * a % 998244353;
    a = a * 1LL * a % 998244353;
    b = (b >> 1);
  }
  return c;
}
int getHash(int l, int r) {
  if (l == 0) return hashv[r];
  int t = (hashv[r] - hashv[l] + 998244353) % 998244353;
  int t1 = modpow(modpow(p, l), 998244353 - 2);
  return t * 1LL * t1 % 998244353;
}
void calcHash() {
  hashv.resize(n);
  int h = 0;
  int pw = 1;
  for (int i = 0; i < n; i++) {
    int t = s[i] - 'a';
    t = t * 1LL * pw % 998244353;
    h = (h + t) % 998244353;
    hashv[i] = h;
    pw = pw * 1LL * p % 998244353;
  }
}
int getCommon(int id1, int id2) {
  int l = 1, r = n - id2;
  int ans;
  for (int i = 0; i < 20; i++) {
    if (l == r) {
      ans = l;
      break;
    }
    if (r == l + 1) {
      int h1 = getHash(id1, id1 + r - 1), h2 = getHash(id2, id2 + r - 1);
      if (h1 == h2)
        ans = r;
      else
        ans = l;
      break;
    }
    int mid = (l + r) / 2;
    int h1 = getHash(id1, id1 + mid - 1), h2 = getHash(id2, id2 + mid - 1);
    if (h1 == h2)
      l = mid;
    else
      r = mid - 1;
  }
  return ans;
}
void solve() {
  dp.clear();
  dp.resize(n, 0);
  dp[n - 1] = 1;
  for (int i = n - 2; i > -1; i--) {
    int ans = n - i;
    for (int j = i + 1; j < n; j++) {
      if (s[i] != s[j]) {
        if (s[i] < s[j]) ans = max(ans, n - i + dp[j]);
      } else {
        int len = getCommon(i, j);
        if (len != n - j) {
          if (s[i + len] < s[j + len]) ans = max(ans, n - i + dp[j] - len);
        }
      }
    }
    dp[i] = ans;
  }
  int ans = 0;
  for (auto &num : dp) ans = max(ans, num);
  cout << ans << '\n';
}
int main() {
  int te;
  cin >> te;
  while (te--) {
    cin >> n;
    cin >> s;
    calcHash();
    solve();
  }
}

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
vector<long long int> hashv;
int n, p = 31;
vector<int> dp;
vector<long long int> ppow(5010);
int lcp[5010][5010];
inline long long getHash(int l, int r) {
  if (l == 0) return hashv[r];
  long long int t = (hashv[r] - hashv[l - 1]) % 998244353;
  return (t + 998244353) % 998244353;
}
inline int compare(int id1, int id2, int len) {
  long long int h1 = getHash(id1, id1 + len - 1);
  long long int h2 = getHash(id2, id2 + len - 1);
  int d = abs(id1 - id2);
  if (id2 > id1)
    h1 = h1 * ppow[d] % 998244353;
  else
    h2 = h2 * ppow[d] % 998244353;
  return h1 == h2;
}
void calcHash() {
  hashv.resize(n);
  long long int h = 0;
  long long int pw = 1;
  for (int i = 0; i < n; i++) {
    h = (h + pw * (s[i] - 'a' + 1)) % 998244353;
    hashv[i] = h;
    pw = pw * p % 998244353;
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
      if (compare(id1, id2, r))
        ans = r;
      else
        ans = l;
      break;
    }
    int mid = (l + r) / 2;
    if (compare(id1, id2, mid))
      l = mid;
    else
      r = mid - 1;
  }
  return ans;
}
void solve() {
  for (int i = n - 1; i > -1; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        lcp[i][j] = n - i;
        continue;
      }
      if (s[i] != s[j]) {
        lcp[i][j] = 0;
        continue;
      }
      if (j == n - 1) {
        lcp[i][j] = 1;
        continue;
      }
      lcp[i][j] = 1 + lcp[i + 1][j + 1];
    }
  }
  dp.clear();
  dp.resize(n, 0);
  dp[n - 1] = 1;
  for (int i = n - 2; i > -1; i--) {
    int ans = n - i;
    vector<int> vis(26, 0);
    for (int j = i + 1; j < n; j++) {
      if (s[i] != s[j]) {
        if (s[i] < s[j]) ans = max(ans, n - i + dp[j]);
      } else {
        int len = lcp[i][j];
        if (len != n - j) {
          if (s[i + len] < s[j + len]) ans = max(ans, n - i + dp[j] - len);
        }
      }
    }
    dp[i] = ans;
  }
  int ans = 0;
  for (auto &num : dp) {
    ans = max(ans, num);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  ppow[0] = 1;
  for (int i = 1; i < 5010; i++) ppow[i] = ppow[i - 1] * p % 998244353;
  int te;
  cin >> te;
  while (te--) {
    cin >> n;
    cin >> s;
    calcHash();
    solve();
  }
}

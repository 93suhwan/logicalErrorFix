#include <bits/stdc++.h>
using namespace std;
const int nax = 5005;
int n;
int dp[nax][nax];
char s[nax];
void brut() {
  vector<string> ss;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      string cur = "";
      for (int k = i; k <= j; k++) cur += s[k];
      ss.push_back(cur);
    }
  }
  vector<int> best(ss.size(), 0);
  vector<int> pop(ss.size(), 0);
  int k = ss.size();
  best[0] = 1;
  pop[0] = -1;
  for (int i = 1; i < k; i++) {
    best[i] = 1;
    pop[i] = -1;
    for (int j = 0; j < i; j++) {
      if (ss[j] < ss[i] && best[j] + 1 > best[i]) {
        best[i] = best[j] + 1;
        pop[i] = j;
      }
    }
  }
  int ac = 0;
  int id = -1;
  for (int i = 0; i < k; i++) {
    if (best[i] > ac) {
      ac = best[i];
      id = i;
    }
  }
  vector<string> ans;
  while (id != -1) {
    ans.push_back(ss[id]);
    id = pop[id];
  }
  reverse(ans.begin(), ans.end());
  for (string x : ans) cout << x << endl;
}
struct Hashs {
  vector<int> hashs;
  vector<int> pows;
  int P;
  int MOD;
  Hashs() {}
  Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) {
    int n = s.size();
    pows.resize(n + 1, 0);
    hashs.resize(n + 1, 0);
    pows[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
      hashs[i] = (1LL * hashs[i + 1] * P + s[i] - 'a' + 1) % MOD;
      pows[n - i] = (1LL * pows[n - i - 1] * P) % MOD;
    }
    pows[n] = (1LL * pows[n - 1] * P) % MOD;
  }
  int get_hash(int l, int r) {
    int ans = hashs[l] + MOD - (1LL * hashs[r + 1] * pows[r - l + 1]) % MOD;
    ans %= MOD;
    return ans;
  }
};
void solve() {
  cin >> n;
  string x;
  cin >> x;
  Hashs h1(x, 29, 1e9 + 7);
  Hashs h2(x, 31, 1e9 + 9);
  for (int i = 0; i < n; i++) s[i + 1] = x[i];
  for (int i = 1; i <= n; i++) dp[1][i] = i;
  for (int i = 2; i <= n; i++) {
    int maxi = 0;
    for (int j = 1; j < i; j++) {
      if (s[j] < s[i]) maxi = max(maxi, dp[j][n + 1 - j]);
    }
    dp[i][1] = maxi + 1;
    int lo = -1;
    int hi = -1;
    for (int j = 1; j < i; j++) {
      if (s[j] == s[i] && s[j + 1] < s[i + 1]) {
        lo = j;
        hi = j;
      }
    }
    for (int j = 2; j <= n + 1 - i; j++) {
      dp[i][j] = dp[i][j - 1] + 1;
      if (lo != -1) {
        dp[i][j] = max(dp[i][j], dp[lo][n + 1 - lo] + 1);
      }
      if (s[hi + 1] == s[i + j - 1]) {
        hi++;
      } else if (lo != -1 && lo != 1 && j < n + 1 - i) {
        while (1) {
          lo--;
          int ac1 = h1.get_hash(lo - 1, lo - 1 + j - 1);
          int ac2 = h2.get_hash(lo - 1, lo - 1 + j - 1);
          int j1 = h1.get_hash(i - 1, i - 1 + j - 1);
          int j2 = h2.get_hash(i - 1, i - 1 + j - 1);
          if (ac1 == j1 && ac2 == j2 && s[lo + j - 1] < s[i + j]) {
            hi = lo + j - 1;
            break;
          }
          if (lo == 1) {
            lo = -1;
            hi = -1;
            break;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + 1 - i; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}

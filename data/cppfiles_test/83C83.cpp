#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k;
string s;
int d, sa[5141], pos[5141], temp[5141], lcp[5141];
bool cmp(int i, int j) {
  if (pos[i] != pos[j]) return pos[i] < pos[j];
  i += d;
  j += d;
  return (i < n && j < n) ? (pos[i] < pos[j]) : (i > j);
}
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> m; m--;) {
    cin >> n >> s;
    vector<int> dp(n);
    for (i = 0; i < n; ++i) {
      sa[i] = i;
      pos[i] = s[i];
    }
    for (d = 1;; d *= 2) {
      sort(sa, sa + n, cmp);
      memset(temp, 0, sizeof(temp));
      for (i = 0; i < n - 1; ++i) {
        temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
      }
      for (i = 0; i < n; ++i) {
        pos[sa[i]] = temp[i];
      }
      if (temp[n - 1] == n - 1) break;
    }
    for (i = k = 0; i < n; ++i, k = max(k - 1, 0)) {
      if (pos[i] == n - 1) continue;
      for (j = sa[pos[i] + 1]; s[i + k] == s[j + k]; ++k)
        ;
      lcp[pos[i]] = k;
    }
    k = 0;
    for (i = 0; i < s.size(); ++i) {
      int temp = 0, l = INT_MAX;
      for (j = pos[i]; j--;) {
        l = min(l, lcp[j]);
        if (sa[j] < i) {
          temp = max(dp[sa[j]] - l, temp);
        }
      }
      k = max(k, dp[i] = temp + s.size() - i);
    }
    cout << k << '\n';
  }
  return 0;
}

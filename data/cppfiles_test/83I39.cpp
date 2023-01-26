#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 10000 + 5;
const int kBase = 131;
int t;
int n;
char s[kMaxN];
int dp[kMaxN];
int rk[kMaxN * 2];
int oldrk[kMaxN * 2];
int sa[kMaxN];
int w;
unsigned long long base[kMaxN];
unsigned long long hs[kMaxN];
unsigned long long Get_hash(int x, int y) {
  return hs[y] - hs[x - 1] * base[y - x + 1];
}
int main() {
  for (int i = 1; i <= kMaxN - 5; i++) {
    base[i] = kBase * base[i - 1];
  }
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      hs[i] = kBase * hs[i - 1] + s[i];
    }
    for (int i = 1; i <= n; i++) {
      sa[i] = i;
      rk[i] = s[i];
    }
    for (w = 1; w < n; w = w * 2) {
      sort(sa + 1, sa + n + 1, [](int x, int y) {
        return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
      });
      memcpy(oldrk, rk, sizeof(rk));
      for (int p = 0, i = 1; i <= n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
          rk[sa[i]] = p;
        } else {
          rk[sa[i]] = ++p;
        }
      }
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        if (s[i] > s[j]) {
          dp[i] = max(dp[i], dp[j] + n - i + 1);
        } else if (s[i] == s[j] && rk[i] > rk[j]) {
          int l = 0, r = n - i;
          while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (Get_hash(i, i + mid) != Get_hash(j, j + mid)) {
              r = mid;
            } else {
              l = mid;
            }
          }
          if (l != n - i) {
            if (s[i + l + 1] == s[j + l + 1]) {
              l++;
            }
          }
          dp[i] = max(dp[i], dp[j] + n - i - l);
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

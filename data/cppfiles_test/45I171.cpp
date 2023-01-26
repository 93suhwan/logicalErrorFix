#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T rd(T &tmp) {
  char ch, f = 1;
  tmp = 0;
  while (ch = getchar(), ch <= 47) {
    if (ch == 45) {
      f = -f;
    }
  }
  do {
    tmp = (tmp << 1) + (tmp << 3) + (ch ^ 48);
  } while (ch = getchar(), ch > 47);
  return tmp *= f;
}
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int maxn = 2e5 + 5;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
int n, k, m, t, num[maxn];
int cnt1, cnt2;
void inti() {}
void solve() {
  rd(t);
  while (t--) {
    rd(n);
    cnt1 = cnt2 = 1;
    for (int i = (int)1; i <= (int)n; ++i) {
      rd(num[i]);
      if (num[i] & 1)
        cnt1++;
      else
        cnt2++;
    }
    if (abs(cnt1 - cnt2) > 1) {
      puts("-1");
    } else {
      if (cnt1 == cnt2) {
        int res = 0, ans = 0;
        int cnt = 1;
        for (int i = (int)1; i <= (int)n; ++i) {
          if (num[i] & 1) {
            res += abs(2 * cnt - 1 - i);
            ans += abs(2 * cnt - i);
            cnt++;
          }
        }
        printf("%d\n", min(res, ans));
      } else if (cnt1 > cnt2) {
        int res = 0;
        int cnt = 1;
        for (int i = (int)1; i <= (int)n; ++i) {
          if (num[i] & 1 && i & 1) {
            cnt++;
          } else if (num[i] & 1) {
            res += abs(2 * cnt - 1 - i);
            cnt++;
          }
        }
        printf("%d\n", res);
      } else {
        int res = 0;
        int cnt = 1;
        for (int i = (int)1; i <= (int)n; ++i) {
          if (num[i] % 2 == 0 && i & 1) {
            cnt++;
          } else if (num[i] % 2 == 0) {
            res += abs(2 * cnt - 1 - i);
            cnt++;
          }
        }
        printf("%d\n", res);
      }
    }
  }
}
int main() {
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int N = 1e5 + 5;
inline int read() {
  int x = 0, rev = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') rev = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return rev ? -x : x;
}
vector<int> V[2];
int cnt[2];
int main() {
  int T = read();
  while (T--) {
    int n = read();
    V[0].clear(), V[1].clear();
    cnt[0] = cnt[1] = 0;
    long long Ans = LONG_LONG_MAX, ans;
    for (int i = 1; i <= n; i++) {
      int x = read() & 1;
      cnt[x]++;
      V[x].push_back(i);
    }
    int t0 = 0, t1 = 0;
    if (abs(cnt[0] - cnt[1]) > 1) {
      puts("-1");
      continue;
    }
    if (cnt[0] >= cnt[1]) {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        int x = (i - 1) & 1;
        ans += abs(i - V[x][x & 1 ? t1++ : t0++]);
      }
      Ans = min(ans, Ans);
    }
    t0 = t1 = 0;
    if (cnt[0] <= cnt[1]) {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        int x = (i)&1;
        ans += abs(i - V[x][x & 1 ? t1++ : t0++]);
      }
      Ans = min(ans, Ans);
    }
    cout << Ans / 2 << endl;
  }
}

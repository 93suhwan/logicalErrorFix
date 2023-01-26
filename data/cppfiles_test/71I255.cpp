#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int p[10];
int length(int n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n /= 10;
  }
  return cnt;
}
int solve1(int n, int len) {
  int ans = 1e9 + 5;
  for (int i = 1; i < 10; i++) {
    int x = 0;
    for (int j = 0; j < len; j++) x += p[j] * i;
    if (x >= n) {
      ans = min(ans, x);
    }
  }
  return ans;
}
int ans = 1e9 + 5, ans2 = 1e9 + 5;
void find(int n1, int cnt, int len, int n, int i, int j) {
  if (cnt == len) {
    if (n1 >= n) {
      ans2 - min(ans2, ans);
      ans = min(ans, n1);
    }
    return;
  }
  find(p[cnt] * i + n1, cnt + 1, len, n, i, j);
  find(p[cnt] * j + n1, cnt + 1, len, n, i, j);
}
void solve2(int n, int len) {
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (ans2 == 1e9 + 5) find(0, 0, len, n, i, j);
    }
    ans2 = 1e9 + 5;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  p[0] = 1;
  for (int i = 1; i < 10; i++) p[i] = 10 * p[i - 1];
  while (t--) {
    int n, k;
    cin >> n >> k;
    int len = length(n);
    int ans1 = solve1(n, len);
    if (k == 1) {
      cout << ans1 << endl;
    } else {
      solve2(n, len);
      cout << min(ans1, ans) << endl;
    }
    ans = 1e9 + 5;
  }
}

#include <bits/stdc++.h>
using namespace std;
long long p[10];
long long b[10];
int length(long long n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n /= 10;
  }
  return cnt;
}
int solve1(long long n, int len) {
  long long ans = 1e10;
  for (int i = 1; i < 10; i++) {
    long long x = 0;
    for (int j = 0; j < len; j++) x += p[j] * i;
    b[i] = x;
    if (x >= n) {
      ans = min(ans, x);
    }
  }
  return ans;
}
long long ans = 1e10;
void find(long long n1, int cnt, int n2, int n3, int len, long long n, int i,
          int j) {
  if (cnt == 0) {
    if (n1 >= n) ans = min(ans, n1);
    return;
  }
  if (n1 + n2 >= n) {
    ans = min(ans, n1 + n2);
    return;
  }
  if (n1 + n3 < n) return;
  find(p[cnt - 1] * i + n1, cnt - 1, n2 / 10, n3 / 10, len, n, i, j);
  find(p[cnt - 1] * j + n1, cnt - 1, n2 / 10, n3 / 10, len, n, i, j);
}
void solve2(long long n, int len) {
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      long long n2 = b[i];
      long long n3 = b[j];
      if (i == 0)
        find(j * p[len - 1], len - 1, n2, n3, len, n, i, j);
      else
        find(0, len, n2, n3, len, n, i, j);
    }
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
    long long n, k;
    cin >> n >> k;
    int len = length(n);
    long long ans1 = solve1(n, len);
    if (k == 1) {
      cout << ans1 << endl;
    } else {
      solve2(n, len);
      cout << min(ans1, ans) << endl;
    }
    ans = 1e10;
  }
}

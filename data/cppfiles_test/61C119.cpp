#include <bits/stdc++.h>
using namespace std;
int ar[200005][3];
char ch[200005];
int n, m, ii, k;
long long cnt[200005], cnt1[200005];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ar[i][1], &ar[i][2]);
    cnt[ar[i][1]]++;
    cnt1[ar[i][2]]++;
  }
  long long re = (long long)n * (long long)(n - 1) * (long long)(n - 2);
  re /= 6;
  for (int i = 1; i <= n; i++) {
    long long cc = (cnt[ar[i][1]] - 1) * (cnt1[ar[i][2]] - 1);
    re -= cc;
  }
  printf("%lld\n", re);
  for (int i = 1; i <= n; i++) cnt[i] = 0, cnt1[i] = 0;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

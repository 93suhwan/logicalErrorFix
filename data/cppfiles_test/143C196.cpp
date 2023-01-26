#include <bits/stdc++.h>
using namespace std;
int ar[200005];
char ch[200005];
int n, m, ii, k;
int cnt[200005];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    cnt[ar[i]]++;
  }
  priority_queue<int> pq;
  int done = 0;
  long long tot = 0;
  for (int i = 0; i <= n; i++) {
    long long re = cnt[i];
    re += tot;
    printf("%lld ", re);
    done = i + 1;
    if (cnt[i] == 0) {
      if (pq.empty()) break;
      tot += i - pq.top();
      pq.pop();
    }
    for (int j = 2; j <= cnt[i]; j++) pq.push(i);
  }
  for (int i = done; i <= n; i++) printf("-1 ");
  printf("\n");
  for (int i = 0; i <= n; i++) cnt[i] = 0;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

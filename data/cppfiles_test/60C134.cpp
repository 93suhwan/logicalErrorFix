#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  long long sum = accumulate(a.begin(), a.end(), 0ll);
  if ((2 * sum) % n != 0) {
    puts("0");
    return;
  }
  long long need = (2 * sum) / n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a1 = a[i];
    int a2 = need - a1;
    if (cnt.count(a2)) ans += cnt[a2];
    if (a1 == a2) ans -= 1;
  }
  printf("%lld\n", ans / 2);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}

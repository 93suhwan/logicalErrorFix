#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, K, a[100005], b[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1] + 1) cnt++;
    }
    if (cnt < K)
      puts("Yes");
    else
      puts("No");
  }
}

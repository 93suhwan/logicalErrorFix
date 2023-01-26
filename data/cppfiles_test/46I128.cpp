#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
long long res, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i < n; i += 2) {
    long long sum = a[i - 1] - a[i];
    res += min(a[i - 1], a[i]);
    if (sum < 0) continue;
    long long s = 0;
    for (int j = i + 2; j < n; j += 2) {
      s += a[j - 1] - a[j];
      if (s <= 0) res++;
      res += max(0ll, min(-s, sum));
      if (s + sum < 0) break;
      if (s < 0) sum += s;
      if (sum < 0) break;
    }
  }
  cout << res << endl;
  return 0;
}

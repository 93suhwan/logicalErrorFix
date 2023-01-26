#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 500;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    long long ans1 = 0;
    for (int i = 1; i < n; i++) ans1 += a[i];
    double ans2 = ans1 * 1.0 / (n - 1);
    printf("%.9lf\n", double(a[n] + ans2));
  }
  return 0;
}

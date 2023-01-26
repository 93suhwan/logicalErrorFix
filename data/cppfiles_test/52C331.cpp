#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    printf("%.9lf\n", (sum - a[n - 1]) / (n - 1) + a[n - 1]);
  }
}

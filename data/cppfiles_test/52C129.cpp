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
    double sum = 0;
    int mx = a[0];
    for (int i = 0; i < n; i++) {
      if (a[i] > mx) mx = a[i];
      sum += a[i];
    }
    printf("%.9lf\n", (sum - mx) / (n - 1) + mx);
  }
}

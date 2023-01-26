#include <bits/stdc++.h>
int has[1000000], cnt = 0;
using namespace std;
int main() {
  int t;
  cin >> t;
  ;
  {
    while (t--) {
      long long int n;
      cin >> n;
      long long int a[n];
      long double ans1, ans = -100000001, sum = 0;
      for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (ans < a[i]) ans = a[i];
      }
      ans1 = ans + (sum - (ans)) / (n - 1);
      printf("%0.10f\n", ans1);
    }
  }
}

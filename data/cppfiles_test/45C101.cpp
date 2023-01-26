#include <bits/stdc++.h>
long long int M = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(25);
  ;
  long long int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long int a[n];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        sum2++, a[i] = 2;
      else
        sum1++, a[i] = 1;
    }
    if (abs(sum1 - sum2) > 1)
      cout << -1 << endl;
    else {
      long long int ans1 = 0, ans2 = 0, dis = 0, vis = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          ans2 = ans2 + abs(i - dis * 2);
          dis++;
        } else {
          ans1 = ans1 + abs(i - vis * 2);
          vis++;
        }
      }
      if (sum1 == sum2)
        cout << min(ans1, ans2) << endl;
      else if (sum1 > sum2)
        cout << ans1 << endl;
      else if (sum1 < sum2)
        cout << ans2 << endl;
    }
  }
}

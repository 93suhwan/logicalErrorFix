#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long m;
    cin >> m;
    long long arr[2][m];
    long long sum1[m];
    long long sum11 = 0;
    long long sum22 = 0;
    long long sum2[m];
    for (long long i = 0; i < m; i++) {
      cin >> arr[0][i];
      sum11 += arr[0][i];
      sum1[i] = sum11;
    }
    for (long long i = 0; i < m; i++) {
      cin >> arr[1][i];
      sum22 += arr[1][i];
      sum2[i] = sum22;
    }
    long long upar_bacha = sum11 - arr[0][0];
    long long niche_bacha = 0;
    long long ans = max(upar_bacha, niche_bacha);
    for (long long i = 1; i < m; i++) {
      niche_bacha += arr[1][i - 1];
      upar_bacha -= arr[0][i];
      long long z2 = max(upar_bacha, niche_bacha);
      if (z2 < ans) {
        ans = z2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long temp;
  cin >> temp;
  while (temp--) {
    long long n, k;
    cin >> n >> k;
    k++;
    int aa[n];
    for (long long i = 0; i < n; i++) {
      cin >> aa[i];
    }
    long long j = 0;
    long long count = (pow(10, aa[j + 1]) - 1);
    long long ans = 0;
    while (k > count && j <= n - 1) {
      if (j == n - 1) {
        ans += k * (pow(10, aa[j]));
        k = 0;
        break;
      }
      ans = ans + (pow(10, aa[j])) * count;
      k -= count;
      j++;
      count = pow(10, aa[j + 1] - aa[j]) - 1;
    }
    if (j < n - 1 && count >= k) {
      ans += k * (pow(10, aa[j]));
    }
    cout << ans << endl;
  }
}

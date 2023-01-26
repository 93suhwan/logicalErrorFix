#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int num[100];
    for (int i = 0; i < n; i++) cin >> num[i];
    long long number[1000];
    memset(number, 0, sizeof(number));
    for (int i = 0; i < n; i++) number[i] = pow(10, num[i]);
    long long prime[1000];
    memset(prime, 0, sizeof(prime));
    for (int i = 1; i < n; i++)
      prime[i - 1] = (number[i] - number[i - 1]) / number[i - 1];
    long long sum = 0;
    int i = 0;
    while (i < n - 1 && sum <= k) {
      sum += prime[i++];
    }
    if (i == n - 1 && k >= sum) {
      int x = k - sum;
      long long sum1 = 0;
      for (int j = 0; j < n - 1; j++) {
        sum1 += number[j] * prime[j];
      }
      long long ans = sum1 + (x + 1) * number[n - 1];
      cout << ans << endl;
    } else {
      sum -= prime[--i];
      int x = k - sum;
      long long sum1 = 0;
      for (int j = 0; j < i; j++) {
        sum1 += number[j] * prime[j];
      }
      long long ans = sum1 + (x + 1) * number[i];
      cout << ans << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ncr(long long int n, long long int k) {
  long long int C[n + 1][k + 1];
  long long int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
long long int power(long long int x, unsigned long long int y) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2) % 1000000007;
  p = (p * p) % 1000000007;
  return (y % 2 == 0) ? p : (x * p) % 1000000007;
}
long long int modInverse(long long int a) {
  long long int g = gcd(a, 1000000007);
  if (g != 1)
    return -1;
  else {
    return power(a, 1000000007 - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = INT_MIN;
    for (char c = 'a'; c <= 'e'; c++) {
      vector<int> occurance(n, 0);
      for (int i = 0; i < n; i++) {
        for (char d : arr[i]) {
          occurance[i] += (c == d) ? 1 : -1;
        }
      }
      sort(occurance.begin(), occurance.end());
      int res = 0, total = 0;
      for (int i = n; i--;) {
        total += occurance[i];
        if (total > 0) {
          res++;
        } else {
          break;
        }
      }
      ans = max(ans, res);
    }
    cout << ans << "\n";
  }
}

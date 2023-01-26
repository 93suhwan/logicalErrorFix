#include <bits/stdc++.h>
using namespace std;
long long int inf = 1000000007;
long long int facto[1000010];
long long int power(long long int a, long long int pow) {
  long long int ans = 1;
  if (a < 0) a += inf;
  while (pow) {
    if (pow % 2 == 1) {
      ans = ((ans % inf) * (a % inf)) % inf;
    }
    a = ((a % inf) * (a % inf)) % inf;
    if (a < 0) a += inf;
    pow /= 2;
  }
  return ans;
}
void fact(int n) {
  long long int fac = 1;
  for (int i = 1; i <= n; i++) {
    fac = ((fac % inf) * (i % inf)) % inf;
    facto[i] = fac;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  facto[0] = 1;
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    k += 1;
    long long int val = 0;
    for (int i = 0; i < n - 1; i++) {
      long long int x = power(10, arr[i + 1] - arr[i]) - 1;
      if (k > x) {
        val += x * power(10, arr[i]);
        k -= x;
      } else {
        val += k * power(10, arr[i]);
        k = 0;
        break;
      }
    }
    if (k > 0) val += k * power(10, arr[n - 1]);
    cout << val << "\n";
  }
  return 0;
}

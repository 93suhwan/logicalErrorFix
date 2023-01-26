#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long n;
    cin >> n;
    long long arr[n];
    int i = 0;
    long long sum = 0;
    int ones, zero;
    ones = zero = 0;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 1)
        ones++;
      else if (arr[i] == 0)
        zero++;
      sum = sum + arr[i];
    }
    long long ans = ones * (pow(2, zero));
    cout << ans << "\n";
  }
}

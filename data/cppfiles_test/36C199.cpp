#include <bits/stdc++.h>
using namespace std;
int dp[100005];
const int mod = 1e9 + 7;
bool isprime(long long int x) {
  bool lol = true;
  for (long long int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      lol = false;
    }
  }
  return lol;
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
read:
  while (T--) {
    long long int n, sum = 0, indx;
    cin >> n;
    long long int arr[n], ans[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i], sum += arr[i];
    }
    if (!isprime(sum)) {
      cout << n << "\n";
      for (long long int i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    } else {
      for (long long int i = 0; i < n; i++) {
        if (arr[i] % 2) {
          indx = i;
          break;
        }
      }
      cout << n - 1 << "\n";
      for (long long int i = 0; i < n; i++) {
        if (i == indx)
          continue;
        else
          cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int MOD1 = 998244353;
void printarr(vector<long long int>& arr) {
  for (auto i : arr) cout << i << " ";
  cout << endl;
}
long long int powermod(long long int n, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  if (p % 2 == 0) {
    long long int smallans = powermod(n, p / 2);
    return (smallans * smallans) % MOD;
  } else {
    long long int smallans = powermod(n, p / 2);
    return ((smallans * smallans) % MOD * n) % MOD;
  }
}
long long int GCD(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return GCD(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      bool flag = false;
      for (int i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
          cout << "YES" << endl;
          flag = true;
          break;
        }
      }
      if (flag == false) {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}

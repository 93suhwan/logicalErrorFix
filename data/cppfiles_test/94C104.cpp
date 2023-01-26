#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b = b / 2;
  }
  return ans;
}
int main() {
  vector<long long int> temp(11);
  temp[0] = 1;
  for (long long int i = 1; i <= 10; i++) temp[i] = temp[i - 1] * 10;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    k++;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int check = n - 1;
    long long int val = 0;
    for (long long int i = 0; i < n - 1; i++) {
      val += (temp[arr[i + 1] - arr[i]] - 1);
      if (val >= k) {
        check = i;
        break;
      }
    }
    long long int ans = 0;
    for (long long int j = 0; j <= check; j++) {
      if (j == check) {
        ans += (temp[arr[j]] * k);
        break;
      }
      long long int ta = (temp[arr[j + 1] - arr[j]] - 1);
      if (ta >= k) {
        ans += (temp[arr[j]] * k);
        break;
      } else {
        ans += (temp[arr[j]] * ta);
        k = k - ta;
      }
    }
    cout << ans << endl;
  }
}

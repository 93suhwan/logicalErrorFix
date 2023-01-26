#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
vector<long long int> arr(62);
void calc() {
  arr[0] = 1;
  for (int i = 1; i < 62; i++) {
    arr[i] = arr[i - 1] * 2;
  }
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2) ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
void test_case() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0;
  while (k > 0) {
    int index = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    if (arr[index] != k) index--;
    k -= arr[index];
    ans += power(n, index);
    ans %= mod;
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    calc();
    test_case();
  }
}

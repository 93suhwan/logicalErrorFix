#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n) {
    if (n & 1) result = result * x;
    n = n / 2;
    x = x * x;
  }
  return result;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    long long int count0 = 0;
    long long int count1 = 0;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 0) {
        count0++;
      } else if (v[i] == 1) {
        count1++;
      }
    }
    ans += (power(2, count0) * count1);
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq1, pq2;
long long mod = 1000000007;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, a, b, ans;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b) {
      cout << a << endl;
      continue;
    }
    if (a < b) {
      long long st = b / a;
      long long st1 = b % a;
      if (st1 == 0) {
        st--;
      }
      long long num = b - st * a;
      ans = st * a + num / 2;
      cout << ans << endl;
    } else {
      cout << a + b << endl;
    }
  }
  return 0;
}

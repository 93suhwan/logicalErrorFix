#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
long long int mod = 1e9 + 7;
int power(long long int n, long long int y) {
  long long int res = 1;
  n = n % mod;
  if (n == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) res = (res * n) % mod;
    y = y >> 1;
    n = (n * n) % mod;
  }
  return res;
}
int Binary(int n) {
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int temp = n >> i;
    if ((temp & 1) == 1) {
      ans++;
    }
  }
  return ans;
}
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (a == 0 && b == 0) {
    cout << "0\n";
  } else if (a == b) {
    cout << "1\n";
  } else if ((a + b) & 1) {
    cout << "-1\n";
  } else {
    cout << "2\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

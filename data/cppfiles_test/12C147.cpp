#include <bits/stdc++.h>
using namespace std;
long long int bpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return ans;
}
int main() {
  long long int testc;
  cin >> testc;
  while (testc--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int z = m / 2;
    long long int mn = 0;
    if (n % 2 != 0) {
      mn = z;
      n--;
    }
    k -= mn;
    bool flag = false;
    if (k >= 0 and k % 2 == 0) {
      if (k <= n * z) flag = true;
    }
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}

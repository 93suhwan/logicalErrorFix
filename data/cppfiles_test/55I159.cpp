#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void debug(int x = 0) { cout << "--ok(" << x << ")" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
const int N = 1e6 + 5, M = 3e5 + 5, mod = 1e9 + 7;
int power(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << ((long long)6 * power(4, (power(2, n) - 2 + mod) % mod) % mod)
       << endl;
  return 0;
}

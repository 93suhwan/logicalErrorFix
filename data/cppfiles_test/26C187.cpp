#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
unsigned long long v[100001];
int main() {
  int n, x, i;
  v[1] = 1;
  for (i = 2; i <= 100000; i++)
    v[i] = (((v[i - 1] * 2 * i) % mod) * (2 * i - 1)) % mod;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> x;
    cout << v[x] << '\n';
  }
  return 0;
}

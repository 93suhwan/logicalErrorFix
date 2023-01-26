#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
long long gt[200001];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  gt[1] = 1;
  for (int i = 2; i <= 200000; i++) gt[i] = gt[i - 1] * i % mod;
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    cout << gt[2 * n] * 500000004 % mod << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;
int test;
int n;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> test;
  for (int i = 1; i <= test; i++) {
    cin >> n;
    long long res = 1;
    for (int j = 1; j <= 2 * n - 1; j++) res = res * j % mod;
    res = res * n % mod;
    cout << res << endl;
  }
}

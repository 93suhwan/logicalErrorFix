#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int res = 0;
int r[10];
int v[10];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x = 1;
    int n;
    cin >> n;
    for (int i = 3; i <= n * 2; i++) {
      x = x * i % mod;
    }
    cout << x << endl;
  }
  return 0;
}

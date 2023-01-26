#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("abm,fma,mmx,avx,popcnt,avx2,sse,sse2,sse3")
using namespace std;
long long int mod = 998244353;
int fun() {
  long long int x, y;
  cin >> x >> y;
  if (x > y) {
    cout << x + y << endl;
    return 0;
  }
  cout << (x + y) / 2 << endl;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) fun();
}

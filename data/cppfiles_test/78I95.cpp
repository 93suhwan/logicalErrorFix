#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long h, p;
    cin >> h >> p;
    long long sp = 1, res = 0;
    while (sp <= p && res < h) {
      res++;
      sp *= 2;
    }
    sp--;
    res += ceil(((double)(pow(2, h) - sp - 1)) / p);
    cout << res << endl;
  }
  return 0;
}

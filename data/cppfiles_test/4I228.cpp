#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1, inf = 1e9;
int a[maxn], r[maxn], ans[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    cout << p - 1 << " " << ((p - 1) >> 1) << '\n';
  }
}

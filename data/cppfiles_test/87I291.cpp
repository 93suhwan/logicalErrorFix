#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = (int)5e5 + 7;
const int INF = (int)1e9 + 7;
using namespace std;
int t;
int n, m;
int ans, cnt;
int a[N], b[N];
string s;
int main() {
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    cin >> n;
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      maxx = max(a[i], maxx);
    }
    for (int i = 1; i <= n; ++i) {
      if (maxx == a[i]) cout << maxx - i << endl;
    }
  }
  exit(0);
}

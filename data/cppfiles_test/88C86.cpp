#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000099;
const int mod = 1000000007;
const int maxn = 1000011;
int ntest;
int n, a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  cin >> ntest;
  while (ntest--) {
    int n;
    cin >> n;
    for (int i = (1); i <= (n); ++i) cin >> a[i];
    if (n % 2 == 0)
      cout << "YES\n";
    else {
      int cur = 0;
      for (int i = (1); i <= (n - 1); ++i) {
        if (a[i] >= a[i + 1]) cur = 1;
      }
      if (cur)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}

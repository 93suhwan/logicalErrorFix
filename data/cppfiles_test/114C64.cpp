#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
int a[200000 + 10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n / 2 + 1; ++i) printf("%d %d\n", a[i], a[1]);
  }
  return 0;
}

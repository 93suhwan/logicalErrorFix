#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const double PI = 3.14159265359;
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] >= a[maxn]) {
        maxn = i;
      }
    }
    if (maxn == n) {
      cout << 0 << "\n";
      continue;
    }
    int temp = 0;
    for (int i = maxn + 1; i <= n; i++) {
      if (a[i] >= a[temp]) temp = i;
    }
    int judge = 0;
    for (int i = n; i >= maxn + 1; i--) {
      if (a[i] > a[judge]) ans++, judge = i;
      if (a[i] == a[temp]) continue;
    }
    cout << ans << "\n";
  }
}

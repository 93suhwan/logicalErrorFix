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
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int temp = a[n];
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] > temp) {
        temp = a[i];
        ans++;
      }
    }
    cout << ans << "\n";
  }
}

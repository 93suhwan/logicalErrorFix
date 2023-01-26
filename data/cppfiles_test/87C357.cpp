#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e3 + 10;
long long a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > sum) {
        ans += a[i] - sum;
        sum = a[i];
      }
      sum++;
    }
    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long temp = -1e18;
    for (int i = n; i >= 1; --i) {
      for (int j = i - 1; j >= 1; --j) {
        if (i * j < temp) break;
        temp = max(long long(i * j - k * (a[i] | a[j])), temp);
      }
    }
    cout << temp << endl;
  }
}

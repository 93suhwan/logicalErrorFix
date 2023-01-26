#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int t, n, k;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] >= a[i - 1]) {
        continue;
      } else {
        cnt++;
      }
    }
    if (cnt <= k)
      cout << "Yes\n";
    else
      cout << "no\n";
  }
  return 0;
}

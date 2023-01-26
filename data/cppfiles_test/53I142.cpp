#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] < a[i - 1]) {
        ans++;
      }
    }
    if (ans > k) {
      cout << "No" << endl;
    } else
      cout << "Yes" << endl;
  }
}

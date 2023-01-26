#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long mx = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, 1ll * a[i] * a[i - 1]);
    }
    cout << mx << endl;
  }
}

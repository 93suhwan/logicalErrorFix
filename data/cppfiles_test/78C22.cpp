#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1;
  cin >> TC;
  while (TC--) {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int f[33];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 30; j++) {
        if (arr[i] & (1 << j)) f[j]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      bool ok = 1;
      for (int j = 0; j < 30; j++) ok &= (f[j] % i == 0);
      if (ok) cout << i << " ";
    }
    cout << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAX = 1e5 + 10;
int freq[MAX];
bool cmp(int x, int y) { return freq[x] > freq[y]; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    if (a[n - 1] == mx) {
      cout << 0;
    } else {
      int las = a[n - 1];
      int ans = 0;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] > las) {
          las = a[i];
          ans++;
        }
        if (a[i] == mx) {
          break;
        }
      }
      cout << ans;
    }
    cout << "\n";
  }
}

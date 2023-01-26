#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N];
int f[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    for (int i = 0; i < floor(n / 2); i++) {
      int pos = a[r] % a[l];
      if (f[pos]) {
        i--;
        continue;
      } else if (f[pos] == 0) {
        cout << a[r] << ' ' << a[l] << "\n";
      }
    }
  }
  return 0;
}

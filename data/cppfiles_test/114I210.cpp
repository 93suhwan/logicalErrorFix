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
    for (int i = 0; i < n / 2; i++) {
      cout << a[n - 1] << ' ' << a[i];
      cout << "\n";
    }
  }
  return 0;
}

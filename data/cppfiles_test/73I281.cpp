#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    bool checker = true;
    bool chuj = false;
    long long sol = 0;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int x = 1; x <= n; x++) {
      chuj = false;
      if (!(x & 1)) {
        for (int i = 1; i < n; i += 2) {
          if ((a[i] > a[i + 1])) {
            swap(a[i], a[i + 1]);
            chuj = true;
          }
        }
      } else {
        for (int i = 2; i < n; i += 2) {
          if ((a[i] > a[i + 1])) {
            swap(a[i], a[i + 1]);
            chuj = true;
          }
        }
      }
      if (chuj) {
        sol++;
      }
    }
    if (checker) {
      cout << sol << '\n';
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    if (n % 2 == 0) {
      cout << "YES\n";
    } else {
      int now = a[0], j = -1;
      for (int i = 1; i < n; i++) {
        if (a[i] > now) {
          j = i + 1;
          break;
        } else {
          now = a[i];
        }
      }
      if (j == -1) {
        cout << "NO\n";
      } else {
        now = a[j];
        int k = -1;
        for (int i = j; i < n; i++) {
          if (a[i] > now) {
            k = i + 1;
            break;
          } else {
            now = a[i];
          }
        }
        if (k == -1) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }
  return 0;
}

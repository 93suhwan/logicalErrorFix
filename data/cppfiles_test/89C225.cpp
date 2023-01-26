#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> arr(n + 4);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      bool tmp = false;
      for (int j = 2; j <= i + 1; j++) {
        if (arr[i] % j != 0) {
          tmp = true;
          break;
        }
      }
      if (!tmp) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

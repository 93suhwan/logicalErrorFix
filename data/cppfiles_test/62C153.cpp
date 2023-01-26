#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, num[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    int ind = -1;
    if (num[1] == 1) {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; i++) cout << i << ' ';
      cout << endl;
      continue;
    }
    if (num[n] == 0) {
      for (int i = 1; i <= n + 1; i++) cout << i << " ";
      cout << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (i + 1 <= n) {
        if (num[i] == 0 && num[i + 1] == 1) {
          ind = i;
          break;
        }
      }
    }
    if (ind == -1) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
      if (i == ind) cout << n + 1 << ' ';
    }
    cout << endl;
  }
}

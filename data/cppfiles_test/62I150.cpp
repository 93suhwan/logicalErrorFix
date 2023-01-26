#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    if (A[n - 1] == 0) {
      for (int i = 1; i <= n + 1; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      int flag = 0;
      int ans;
      for (int i = 0; i < n - 1; i++) {
        if (A[i] == 0 && A[i + 1] == 1) {
          flag = 1;
          ans = i;
          break;
        }
      }
      if (flag == 1) {
        ans++;
        for (int i = 1; i <= ans; i++) {
          cout << i << " ";
        }
        cout << n + 1 << " ";
        for (int i = ans + 1; i <= n; i++) {
          cout << i << " ";
        }
        cout << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}

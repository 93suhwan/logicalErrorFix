#include <bits/stdc++.h>
using namespace std;
int t;
int a[10050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int flag = 0;
    if (n == 1) {
      if (a[1])
        cout << 2 << " " << 1 << endl;
      else
        cout << 1 << " " << 2 << endl;
    } else if (n == 2) {
      if (!a[1] && !a[2])
        cout << 1 << " " << 2 << " " << 3 << endl;
      else if (!a[1] && a[2])
        cout << 1 << " " << 3 << " " << 2 << endl;
      else if (a[1] && !a[2])
        cout << 2 << " " << 3 << " " << 1 << endl;
      else if (a[1] && a[2])
        cout << 3 << " " << 1 << " " << 2 << endl;
    } else {
      if (!a[1] && !a[n]) {
        for (int i = 1; i <= n + 1; i++) cout << i << " ";
        cout << endl;
      } else if (!a[1] && a[n]) {
        int flag = 0;
        int p;
        for (int i = 1; i <= n - 1; i++) {
          if (a[i] == 0 && a[i + 1] == 1) {
            p = i;
            flag = 1;
            break;
          }
        }
        if (!flag)
          cout << -1 << endl;
        else {
          for (int i = 1; i <= p; i++) cout << i << " ";
          cout << n + 1 << " ";
          for (int i = p + 1; i <= n; i++) cout << i << " ";
          cout << endl;
        }
      } else if (a[1] && !a[n]) {
        for (int i = 1; i <= n + 1; i++) cout << i << " ";
        cout << endl;
      } else if (a[1] && a[n]) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
      }
    }
  }
  return 0;
}

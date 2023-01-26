#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], b[N], c[N], p[N];
void Test() {
  int n;
  cin >> n;
  int ma = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }
  if (ma % 3 == 0) {
    int flag = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] % 3 != 0) flag = 1;
    if (flag == 0)
      cout << ma / 3 << "\n";
    else
      cout << ma / 3 + 1 << "\n";
  } else if (ma % 3 == 2) {
    int flag = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] % 3 == 1) flag = 1;
    if (flag == 0)
      cout << ma / 3 + 1 << "\n";
    else
      cout << ma / 3 + 2 << "\n";
  } else {
    if (ma == 1)
      cout << 1 << "\n";
    else {
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] == 1) flag = 1;
      }
      if (flag == 1)
        cout << ma / 3 + 2;
      else
        cout << ma / 3 + 1;
      cout << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) Test();
}

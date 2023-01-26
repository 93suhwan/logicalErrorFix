#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int b[N], cnt;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) flag = 1;
    }
    if (n == 1) {
      if (a[0] == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        b[cnt++] = abs(a[i] - a[j]);
        if (b[cnt - 1] == 0) flag = 1;
      }
    }
    sort(b, b + cnt);
    for (int i = 1; i < cnt; i++) {
      if (b[i] == b[i - 1]) flag = 1;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        b[cnt++] = abs(a[i] + a[j]);
        if (b[cnt - 1] == 0) flag = 1;
      }
    }
    sort(b, b + cnt);
    for (int i = 1; i < cnt; i++) {
      if (b[i] == b[i - 1]) flag = 1;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

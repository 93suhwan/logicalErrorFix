#include <bits/stdc++.h>
using namespace std;
int ss(int l, int l_ans, int r, int r_ans, int rul, int n, int a[]) {
  if (a[l] <= n && a[r] <= n) return 3 - rul;
  if (a[l] > a[r] && l_ans % 2 == 1) return rul;
  if (a[r] > a[l] && r_ans % 2 == 1) return rul;
  if (a[r] == a[l] && (l_ans % 2 == 1 || r_ans % 2 == 1))
    return rul;
  else if (a[r] == a[l])
    return 3 - rul;
  if (a[l] < a[r])
    return ss(l + 1, l_ans - 1, r, r_ans, 3 - rul, a[l], a);
  else
    return ss(l, l_ans, r - 1, r_ans - 1, 3 - rul, a[r], a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l_ans = 0, r_ans = 0;
  cin >> n;
  int a[n];
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0)
      l_ans++;
    else if (ok)
      if (a[i] > a[i - 1])
        l_ans++;
      else
        ok = false;
  }
  ok = true;
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1)
      r_ans++;
    else if (ok)
      if (a[i] > a[i + 1])
        r_ans++;
      else
        ok = false;
  }
  int ans = ss(0, l_ans, n - 1, r_ans, 1, -10, a);
  if (ans == 1)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n + 10];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 1) {
    cout << "Alice\n";
    return 0;
  }
  int x = 2;
  if (a[1] < a[n]) reverse(a + 1, a + 1 + n);
  while (x < n && a[x] > a[x - 1]) ++x;
  if (a[x] < a[x - 1]) --x;
  if (x % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }
  int y = n - 1;
  while (y > 1 && a[y] > a[y + 1]) --y;
  if (a[y] < a[y + 1]) ++y;
  if ((n - y + 1) % 2 == 0) {
    cout << "Bob\n";
    return 0;
  }
  cout << "Alice\n";
  return 0;
}

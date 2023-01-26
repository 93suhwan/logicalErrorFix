#include <bits/stdc++.h>
using namespace std;
int n;
int out(int x) {
  int l, r;
  if (x > 0)
    l = n - x, r = n;
  else
    l = 1 - x, r = 1;
  cout << "?";
  for (int i = 1; i <= n; i++) cout << " " << (i != n ? l : r);
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}
int a[105];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  int now = n;
  for (int i = 1; i < n; i++) {
    int x = out(n - now + 1);
    if (x == 0)
      break;
    else
      a[x] = n - now + 1;
    now--;
  }
  for (int i = 1; i < now; i++) a[out(i - now)] = i - now;
  for (int i = 1; i <= n; i++) a[i] += now;
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << a[i];
  cout << endl;
  return 0;
}

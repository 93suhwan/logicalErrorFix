#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, a[1001], b[1001], s = 0;
  cin >> n;
  for (int i = 1; i <= 1666; i++) {
    if (i % 3 != 0 && i % 10 != 3) s++, b[s] = i;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cout << b[a[i]] << "\n";
}

#include <bits/stdc++.h>
using namespace std;
void ac(void) {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (m % 2 == 0) {
    if (k >= m / 2 && (k - m / 2) % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (k % 2 == 0 && k <= n * m / 2 - n / 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) ac();
  return 0;
}

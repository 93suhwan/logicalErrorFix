#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n;
  cin >> n;
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    int found = 0;
    for (int j = i + 1; j >= 2 && !found; j--)
      if (val % j > 0) found = 1;
    ok &= found;
  }
  if (ok)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) test_case();
}

#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
void test_case() {
  int l, w, k;
  cin >> l >> w >> k;
  if (l == 1) {
    if (k == w / 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (w == 1) {
    if (k == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (w % 2 == 0 && l % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (w % 2 == 0 && l % 2 == 1) {
    k -= w / 2;
    l--;
    int wanted = ((w / 2) * l) - k;
    if (k < 0)
      cout << "NO" << endl;
    else if (wanted % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (w % 2 == 1 && l % 2 == 0) {
    int max1 = ((w / 2) * l);
    if (k > max1)
      cout << "NO" << endl;
    else if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}

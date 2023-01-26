#include <bits/stdc++.h>
using namespace std;
void jai_shree_ram() {
  long long l, r, c = 0;
  cin >> l >> r;
  c = r / 2 + 1;
  if (c >= l)
    cout << r % c << "\n";
  else {
    c = l * 2 - 1;
    c <= r ? cout << l % c << "\n" : cout << r - l << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    jai_shree_ram();
  }
  return 0;
}

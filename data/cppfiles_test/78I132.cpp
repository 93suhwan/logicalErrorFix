#include <bits/stdc++.h>
using namespace std;
void jai_shree_ram() {
  long long l, r;
  cin >> l >> r;
  long long a = l;
  long long b = l - 1;
  while (a + b <= r) {
    a++;
    b++;
  }
  b--;
  cout << a << "\n";
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

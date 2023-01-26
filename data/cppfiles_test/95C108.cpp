#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long s, n;
    cin >> s >> n;
    long long ten = 1;
    while (ten <= s) ten *= 10;
    while (n > 1) {
      n--;
      while (s - ten < n) ten /= 10;
      cout << ten << " ";
      s -= ten;
    }
    if (s != 0) cout << s << '\n';
  }
  return 0;
}

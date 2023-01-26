#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int s = sqrt(k);
    if (s * s != k) s++;
    int s1 = s - 1;
    s1 = s1 * s1;
    s1 = k - s1;
    if (s1 <= s)
      cout << s1 << " " << s << "\n";
    else {
      cout << s << " " << 2 * s - s1 << "\n";
    }
  }
}

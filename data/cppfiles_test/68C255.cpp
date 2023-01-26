#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, j;
    int k;
    cin >> k;
    long s = floor(sqrt(k));
    if (k <= s * s + s + 1) {
      i = k - (s * s) - 1;
      j = s;
    } else {
      j = (s + 1) * (s + 1) - k;
      i = s;
    }
    if (i < 0)
      cout << s << " " << 1 << " ";
    else
      cout << i + 1 << " " << j + 1 << " ";
    cout << endl;
  }
}

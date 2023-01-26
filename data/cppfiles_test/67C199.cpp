#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    long long diff = abs(a - b);
    long long ele = 2 * diff;
    if (c <= ele && a <= ele && b <= ele) {
      if (diff == 1)
        cout << "-1" << endl;
      else if (c > std::max(a, b))
        cout << c - diff << endl;
      else if (c < std::max(a, b) && c > std::min(a, b)) {
        if (c + diff <= ele)
          cout << c + diff << endl;
        else
          cout << c - diff << endl;
      } else
        cout << c + diff << endl;
    } else
      cout << "-1" << endl;
  }
  return 0;
}

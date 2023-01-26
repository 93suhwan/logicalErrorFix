#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0.0);
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    set<int> s;
    int a;
    cin >> a;
    if (a == 1) {
      s.insert(1);
    } else {
      int ans = 1;
      for (int i = 2; i < a / 2; i++) {
        if (pow((i - 1), 2) <= a) {
          if (pow((i), 2) <= a) s.insert(pow((i), 2));
        } else {
          break;
        }
        if (pow((i - 1), 3) <= a) {
          if (pow((i), 3) <= a) s.insert(pow((i), 3));
        }
      }
    }
    if (s.size() > 1)
      cout << s.size() + 1 << endl;
    else
      cout << s.size() << endl;
    t--;
  }
  return 0;
}

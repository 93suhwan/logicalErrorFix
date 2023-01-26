#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool flag = false;
    int rec = INT_MAX;
    while (n--) {
      int x;
      cin >> x;
      rec = min(rec, x);
      if (false == flag and 0 == x % 2) {
        flag = true;
      }
    }
    if (true == flag)
      cout << 0 << endl;
    else
      cout << rec << endl;
  }
}

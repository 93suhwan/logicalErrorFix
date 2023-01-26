#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int l = 0, r = 0;
    int num = 1;
    while (num * num < k) {
      num++;
    }
    r = num;
    l = num - 1;
    int len = num - 1;
    if (l * l + len + 1 >= k) {
      int roww = k - l * l;
      int coll = l + 1;
      cout << roww << ' ' << coll << endl;
    } else {
      int numm = k - (l * l + len + 1);
      int roww = l + 1;
      int coll = l - numm + 1;
      cout << roww << ' ' << coll << endl;
    }
  }
  return 0;
}

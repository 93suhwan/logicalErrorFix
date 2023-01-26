#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k, i, count;
  cin >> t;
  while (t--) {
    cin >> k;
    count = 0;
    for (i = 1; i <= k; i++) {
      count++;
      if (count % 10 == 3 || count % 3 == 0) count++;
      if (count % 10 == 3 || count % 3 == 0) count++;
    }
    cout << count << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int count = 1;
    if (k == 1)
      cout << "1" << endl;
    else {
      for (int i = 0; i < k - 1; i++) {
        if ((count + 1) % 3 == 0 || (count + 1) % 10 == 3) {
          count += 2;
          while (count % 3 == 0 or count % 10 == 3) count++;
        } else
          count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}

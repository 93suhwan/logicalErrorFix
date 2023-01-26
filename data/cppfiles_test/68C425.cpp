#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int k, root;
    cin >> k;
    if (k == 1) {
      cout << "1 1" << endl;
    } else {
      root = sqrt((double)(k - 1));
      cerr << "root = " << root << endl;
      k -= root * root + 1;
      if (k <= root) {
        cout << (k + 1) << " " << (root + 1) << endl;
      } else {
        k -= root;
        cout << (root + 1) << " " << (root - k + 1) << endl;
      }
    }
  }
  return 0;
}

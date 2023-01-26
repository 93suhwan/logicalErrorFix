#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = 0;
    while (n--) {
      if (c % 10 == 3 || c % 3 == 0) {
        n++;
        c++;
      } else {
        c++;
      }
    }
    cout << c - 1 << endl;
  }
  return 0;
}

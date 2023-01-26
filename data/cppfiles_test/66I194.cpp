#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = 0;
    int i = 1;
    while (n--) {
      c++;
      if (i % 3 == 0 || i % 10 == 3) {
        c++;
      }
      i = i + 1;
    }
    cout << c;
  }
  return 0;
}

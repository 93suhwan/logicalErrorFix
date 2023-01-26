#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test > 0) {
    test--;
    int n;
    cin >> n;
    int s1, s2;
    cin >> s1;
    cin >> s2;
    bool sol = true;
    for (int i = 0; i < n; i++) {
      if (s1 % 10 == 0 || s2 % 10 == 0) {
        s1 = s1 / 10;
        s2 = s2 / 10;
        continue;
      }
      printf("NO");
      sol = false;
      break;
    }
    if (sol) cout << "YES" << endl;
  }
}

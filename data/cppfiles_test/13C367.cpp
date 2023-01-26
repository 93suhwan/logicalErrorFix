#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s.at(i) == 'A') {
        a++;
      } else if (s.at(i) == 'B') {
        b++;
      } else if (s.at(i) == 'C') {
        c++;
      }
    }
    if ((a + c) == b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int o;
  cin >> o;
  while (o--) {
    string str;
    cin >> str;
    int n = 0;
    int m = 0;
    int k = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'A') {
        n++;
      } else if (str[i] == 'B') {
        m++;
      } else
        k++;
    }
    if (m == (n + k)) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}

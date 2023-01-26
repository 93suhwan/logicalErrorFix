#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char c1[n], c2[n];
    cin >> c1 >> c2;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (c1[i] == '1' && c2[i] == '1') {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

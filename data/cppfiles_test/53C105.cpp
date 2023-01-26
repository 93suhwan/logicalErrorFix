#include <bits/stdc++.h>
using namespace std;
int main() {
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    int n;
    cin >> n;
    char p;
    cin >> p;
    string s;
    cin >> s;
    int flag = 0;
    int pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == p)
        continue;
      else if (s[i] != p and flag == 0) {
        flag = 1;
        pos = i;
      } else
        flag = 2;
    }
    if (flag == 0)
      cout << 0;
    else {
      int k = n / 2;
      for (int i = n - 1; i >= n / 2; i--) {
        if (s[i] == p) {
          cout << 1 << endl << i + 1;
          flag = 3;
          break;
        }
      }
      if (flag != 3) cout << 2 << endl << n - 1 << " " << n;
    }
    cout << endl;
  }
}

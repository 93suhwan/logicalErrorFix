#include <bits/stdc++.h>
using namespace std;
void check(string str) {
  int flag = 0;
  if (str.size() % 2 != 0) {
    cout << "NO" << endl;
  } else {
    int n = (str.size() - 1) / 2;
    for (int i = 0; i <= n; i++) {
      if (str[i] != str[n + 1 + i]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    check(str);
  }
  return 0;
}

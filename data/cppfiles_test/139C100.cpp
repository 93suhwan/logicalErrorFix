#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int flag = 0;
    if (str.size() % 2 != 0) {
      puts("NO");
      continue;
    }
    for (int i = 0, j = str.size() / 2; i < str.size() / 2; i++, j++) {
      if (str[i] != str[j]) {
        flag = 1;
        break;
      }
    }
    if (flag)
      puts("NO");
    else
      puts("YES");
  }
}

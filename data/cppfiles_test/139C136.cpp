#include <bits/stdc++.h>
using namespace std;
int t;
string str;
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> str;
    int len = str.size();
    if (len & 1) {
      printf("NO\n");
      continue;
    }
    bool flag = 1;
    for (int i = 0; i < (len >> 1); i++) {
      if (str[i] != str[i + (len >> 1)]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}

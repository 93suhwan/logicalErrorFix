#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
  scanf("%d", &t);
  while (t--) {
    int n, mind = 0x3f3f3f3f;
    cin >> n >> s;
    bool flag = false;
    for (int i = 0; i < 26; i++) {
      int cnt = 0;
      string temp1 = "", temp2 = "";
      for (int j = 0; j < n; j++) {
        if (s[j] - 'a' != i) temp1.push_back(s[j]);
        if (s[n - j - 1] - 'a' != i) temp2.push_back(s[n - 1 - j]);
      }
      if (temp1 == temp2) {
        flag = true;
        queue<char> t1, t2;
        for (int j = 0; j < n; j++) t1.push(s[j]);
        for (int j = n - 1; j > 0; j--) t2.push(s[j]);
        int i1 = 0, i2 = n - 1;
        while (i1 < i2) {
          char top1 = t1.front(), top2 = t2.front();
          if (top1 != top2) {
            if (top1 - 'a' == i)
              t1.pop(), i1++;
            else if (top2 - 'a' == i)
              t2.pop(), i2--;
            cnt++;
          } else {
            i1++;
            i2--;
            t1.pop();
            t2.pop();
          }
        }
        mind = min(mind, cnt);
      }
    }
    if (flag)
      printf("%d\n", mind);
    else
      printf("-1\n");
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int t;
int flag = 0;
char s[N];
int num[50];
int main() {
  scanf("%d", &t);
  int x;
  while (t--) {
    scanf("%s", s);
    flag = 0;
    int l = strlen(s);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < l; i++) {
      num[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (num[i] == 1) {
        if (flag)
          ans++, flag = 0;
        else
          flag = 1;
      } else if (num[i] > 1)
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

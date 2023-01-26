#include <bits/stdc++.h>
using namespace std;
char ch[114];
int main() {
  int t, sum;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", ch);
    int len = strlen(ch);
    if (ch[0] == ch[len - 1])
      printf("%s\n", ch);
    else {
      ch[0] = ch[len - 1];
      printf("%s\n", ch);
    }
  }
  return 0;
}

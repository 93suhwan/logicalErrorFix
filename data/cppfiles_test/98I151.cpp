#include <bits/stdc++.h>
using namespace std;
map<char, int> e;
int main() {
  int t;
  char b[55];
  scanf("%d", &t);
  while (t--) {
    char ch;
    int i;
    int ans = 0;
    for (i = 1; i <= 26; i++) {
      scanf("%c", &ch);
      e[ch] = i;
    }
    getchar();
    scanf("%s", b);
    for (i = 1; i < strlen(b); i++) {
      ans += abs(e[b[i]] - e[b[i - 1]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

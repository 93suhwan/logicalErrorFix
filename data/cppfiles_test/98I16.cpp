#include <bits/stdc++.h>
using namespace std;
char str[100];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unordered_map<char, int> M;
    for (int i = 1; i <= 26; i++) {
      char c;
      scanf("%c", &c);
      M[c] = i;
    }
    getchar();
    scanf("%s", str);
    int res = 0;
    for (int i = 1; i < strlen(str); i++) {
      res += abs(M[str[i]] - M[str[i - 1]]);
    }
    printf("%d\n", res);
  }
  return 0;
}

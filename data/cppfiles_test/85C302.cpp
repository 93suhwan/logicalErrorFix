#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[200200];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        one++;
      else
        zero++;
    }
    if (one == n) {
      printf("0\n");
      continue;
    }
    vector<char> temp;
    temp.push_back(s[0]);
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) temp.push_back(s[i]);
    }
    int cans = 0;
    for (char i : temp)
      if (i == '0') cans++;
    cans = min(cans, 2);
    printf("%d\n", cans);
  }
}

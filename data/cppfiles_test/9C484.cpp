#include <bits/stdc++.h>
using namespace std;
char s[100];
int q[200];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(q, 0, sizeof(q));
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      q[s[i]]++;
    }
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
      if (q[i] == 1) {
        ans++;
      }
      if (q[i] > 1) {
        ans += 2;
      }
    }
    printf("%d\n", ans / 2);
  }
}

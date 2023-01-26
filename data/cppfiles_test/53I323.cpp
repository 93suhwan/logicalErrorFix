#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    char c;
    string s;
    scanf("%d %c", &n, &c);
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != c) cnt++;
    }
    if (cnt == 0) {
      printf("0\n");
    } else {
      if (cnt == 1) {
        if (s[n - 1] != c) {
          printf("1\n");
          printf("%d\n", n - 1);
        } else {
          printf("1\n");
          printf("%d\n", n);
        }
      } else {
        if (s[n - 1] != c) {
          printf("2\n");
          printf("%d %d\n", n - 1, n);
        } else {
          printf("1\n");
          printf("%d\n", n);
        }
      }
    }
  }
  return 0;
}

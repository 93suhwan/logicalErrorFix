#include <bits/stdc++.h>
using namespace std;
void A() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    int req = floor(n / 2);
    bool found = false;
    for (int i = 0; i < n; i += 1) {
      if (str[i] == '0') {
        int left = n - i;
        int second = n - i - 1;
        if (second >= req) {
          found = true;
          printf("%d %d %d %d\n", i + 1, n, i + 2, n);
          break;
        } else if (i >= req) {
          found = true;
          printf("%d %d %d %d\n", 1, i + 1, 1, i);
          break;
        }
      }
    }
    if (!found) {
      printf("%d %d %d %d\n", 1, req, 2, req + 1);
    }
  }
}
int main() {
  A();
  return 0;
}

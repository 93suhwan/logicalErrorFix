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
        int left = n - i + 1;
        if (left >= req) {
          found = true;
          printf("%d %d %d %d\n", i + 1, n, i + 2, n);
          break;
        }
      }
    }
    if (!found) {
    }
  }
}
int main() {
  A();
  return 0;
}

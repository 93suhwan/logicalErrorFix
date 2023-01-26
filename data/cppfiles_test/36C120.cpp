#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int t;
struct TestCase {
  int n;
  char* s;
  void solve() {
    scanf("%d", &n);
    s = new char[n];
    if (n == 1)
      s[0] = 'a';
    else if (n == 2)
      s = "ab";
    else if (n == 3)
      s = "abc";
    else if (n % 2) {
      for (int i = (0); i <= (n / 2 - 1); i++) s[i] = 'a';
      s[n / 2] = 'b';
      for (int i = (n / 2 + 1); i <= (n - 2); i++) s[i] = 'a';
      s[n - 1] = 'c';
    } else {
      for (int i = (0); i <= (n / 2 - 1); i++) s[i] = 'a';
      s[n / 2] = 'b';
      for (int i = (n / 2 + 1); i <= (n - 1); i++) s[i] = 'a';
    }
    for (int i = (0); i <= (n - 1); i++) printf("%c", s[i]);
    printf("\n");
  }
};
int main() {
  scanf("%d", &t);
  while (t--) {
    TestCase nt;
    nt.solve();
  }
  return 0;
}

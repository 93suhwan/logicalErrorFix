#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (n == 1)
      printf("a\n");
    else if (n & 1) {
      string s;
      s.append((n - 1) / 2, 'a');
      s.push_back('b');
      s.append((n - 3) / 2, 'a');
      s.push_back('c');
      printf("%s\n", s.c_str());
    } else {
      string s;
      s.append(n / 2, 'a');
      s.push_back('b');
      s.append((n - 2) / 2, 'a');
      printf("%s\n", s.c_str());
    }
  }
  getchar();
  getchar();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x1, p1, x2, p2;
    scanf("%d%d%d%d", &x1, &p1, &x2, &p2);
    int t1 = 0, t2 = 0, y1 = x1, y2 = x2;
    while (y1) y1 /= 10, ++t1;
    while (y2) y2 /= 10, ++t2;
    if (t1 + p1 != t2 + p2) {
      cout << (t1 + p1 > t2 + p2 ? ">" : "<") << endl;
      continue;
    }
    x1 = x1 * pow(10, p1);
    x2 = x2 * pow(10, p2);
    if (x1 < x2)
      cout << ("<") << endl;
    else if (x1 > x2)
      cout << (">") << endl;
    else if (x1 = x2)
      cout << ("=") << endl;
  }
}

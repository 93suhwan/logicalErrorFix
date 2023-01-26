#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
int n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int jud = 0;
    for (int i = 1; i <= n; ++i)
      if (a[i] == 1) ++jud;
    if (jud & 1) {
      printf("NO\n");
      continue;
    }
    vector<int> res;
    for (int i = 1; i + 2 <= n;) {
      if (a[i] == 1) {
        int cnt = 1 + (a[i + 1] == 1) + (a[i + 2] == 1);
        if (cnt & 1) {
          if (cnt != 3) {
            res.push_back(i);
            a[i] = a[i + 1] = a[i + 2] = 1;
          }
          i = i + 2;
        } else {
          res.push_back(i);
          a[i] = a[i + 1] = a[i + 2] = 0;
          i = i + 3;
        }
      } else
        ++i;
    }
    for (int i = 1; i + 2 <= n; ++i) {
      int cnt = a[i] + a[i + 1] + a[i + 2];
      if (cnt != 0 && cnt % 2 == 0) {
        res.push_back(i);
        a[i] = a[i + 1] = a[i + 2] = 0;
      }
    }
    bool f = true;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1) {
        f = false;
        break;
      }
    }
    if (!f) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    printf("%d\n", (int)res.size());
    for (int num : res) {
      printf("%d ", num);
    }
    puts("");
  }
}

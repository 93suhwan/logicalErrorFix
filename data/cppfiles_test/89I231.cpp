#include <bits/stdc++.h>
using namespace std;
vector<int> vi;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vi.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int s;
      scanf("%d", &s);
      vi.push_back(s);
    }
    int cnt = 0;
    int l = n + 1;
    int pt = n - 1;
    for (int i = l; i > 1; i--) {
      while (vi[pt] % i) {
        pt--;
        if (pt + 2 < i) break;
        if (pt == -1) break;
      }
      if (pt == -1) break;
    }
    if (pt == -1) {
      printf("YES");
    } else
      printf("NO");
    printf("\n");
  }
  return 0;
}

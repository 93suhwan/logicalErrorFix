#include <bits/stdc++.h>
using namespace std;
int n, a[200004], cnt;
char s[200004];
vector<int> vl, vr;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1]) cnt++;
  sort(a + 1, a + n + 1);
  for (int i = n - cnt + 1; i <= n; i++) vr.push_back(a[i]);
  for (int i = 1; i <= n - cnt; i++) vl.push_back(a[i]);
  if (s[1] == 'R') vl[0] = -vl[0];
  for (int i = 1; i < vl.size(); i++) {
    if (i & 1) {
      if (vl[0] > 0) vl[i] = -vl[i];
    } else {
      if (vl[0] < 0) vl[i] = -vl[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1 || s[i] != s[i - 1])
      printf("%d %c\n", abs(a[i]), s[i]);
    else {
      if (a[i] > 0)
        printf("%d L\n", a[i]);
      else
        printf("%d R\n", -a[i]);
    }
  }
}

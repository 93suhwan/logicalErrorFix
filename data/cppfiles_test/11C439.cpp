#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e5 + 10;
struct node {
  int zms[27], maxn, len;
  char gxM;
  char mxC;
};
int nw;
bool cmp(node x, node y) {
  return 2 * x.zms[nw] - x.len > 2 * y.zms[nw] - y.len;
}
node a[2 * M + 10];
int n;
int zmM[27];
int mxS[27];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(zmM, 0, sizeof zmM);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 27; j++) a[i].zms[j] = 0;
      a[i].maxn = 0;
      a[i].gxM = '\0';
    }
    char ch[2 * M + 1];
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch + 1);
      a[i].len = strlen(ch + 1);
      for (int j = 1; j <= a[i].len; j++) {
        a[i].zms[ch[j] - 'a']++;
        if (a[i].maxn < a[i].zms[ch[j] - 'a']) {
          a[i].maxn = a[i].zms[ch[j] - 'a'];
          a[i].mxC = ch[j] - 'a';
        }
        if (a[i].zms[ch[j] - 'a'] * 2 > a[i].len) a[i].gxM = ch[j];
      }
      if (a[i].gxM != '\0') {
        zmM[a[i].gxM - 'a']++;
      }
    }
    int summ = 0;
    int ans = 0;
    int maxn = 0;
    for (nw = 0; nw < 26; nw++) {
      summ = 0;
      ans = 0;
      if (zmM[nw] == 0) continue;
      sort(a + 1, a + n + 1, cmp);
      for (int i = 1; i <= n; i++) {
        summ += (2 * a[i].zms[nw] - a[i].len);
        if (summ <= 0) break;
        ans++;
      }
      maxn = max(ans, maxn);
    }
    printf("%d\n", maxn);
  }
}

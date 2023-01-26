#include <bits/stdc++.h>
using namespace std;
struct data {
  int cnt, len;
};
int n;
struct data acnt[200001], bcnt[200001], ccnt[200001], dcnt[200001],
    ecnt[200001];
char a[400001];
bool so(struct data n1, struct data n2) {
  double t1 = n1.cnt / n1.len;
  double t2 = n2.cnt / n2.len;
  if (t1 == t2) return n1.cnt < n2.cnt;
  return t1 > t2;
}
int f(char num) {
  int sum1 = 0, sum2 = 0;
  int rsum1 = 0, rsum2 = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (num == 'a') sum1 += acnt[i].cnt, sum2 += acnt[i].len;
    if (num == 'b') sum1 += bcnt[i].cnt, sum2 += bcnt[i].len;
    if (num == 'c') sum1 += ccnt[i].cnt, sum2 += ccnt[i].len;
    if (num == 'd') sum1 += dcnt[i].cnt, sum2 += dcnt[i].len;
    if (num == 'e') sum1 += ecnt[i].cnt, sum2 += ecnt[i].len;
    if (sum1 <= sum2 - sum1) {
      sum1 = rsum1;
      sum2 = rsum2;
    } else
      cnt++;
    rsum1 = sum1, rsum2 = sum2;
  }
  return cnt;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%s", a);
      int l = strlen(a);
      acnt[i].cnt = 0;
      bcnt[i].cnt = 0;
      ccnt[i].cnt = 0;
      dcnt[i].cnt = 0;
      ecnt[i].cnt = 0;
      for (j = 0; j < l; j++) {
        if (a[j] == 'a') acnt[i].cnt++;
        if (a[j] == 'b') bcnt[i].cnt++;
        if (a[j] == 'c') ccnt[i].cnt++;
        if (a[j] == 'd') dcnt[i].cnt++;
        if (a[j] == 'e') ecnt[i].cnt++;
      }
      acnt[i].len = l;
      bcnt[i].len = l;
      ccnt[i].len = l;
      dcnt[i].len = l;
      ecnt[i].len = l;
    }
    sort(acnt, acnt + n, so);
    sort(bcnt, bcnt + n, so);
    sort(ccnt, ccnt + n, so);
    sort(dcnt, dcnt + n, so);
    sort(ecnt, ecnt + n, so);
    printf("ans : %d\n",
           max(f('a'), max(f('b'), max(f('c'), max(f('d'), f('e'))))));
  }
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int t;
int n;
char s[MAXN * 2];
struct node {
  int detea;
  int deteb;
  int detec;
  int deted;
  int detee;
} a[MAXN];
bool cmpa(node x, node y) { return x.detea > y.detea; }
bool cmpb(node x, node y) { return x.deteb > y.deteb; }
bool cmpc(node x, node y) { return x.detec > y.detec; }
bool cmpd(node x, node y) { return x.deted > y.deted; }
bool cmpe(node x, node y) { return x.detee > y.detee; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      int len = strlen(s + 1);
      int suma = 0;
      int sumb = 0;
      int sumc = 0;
      int sumd = 0;
      int sume = 0;
      for (int j = 1; j <= len; j++) {
        if (s[j] == 'a') {
          suma++;
        }
        if (s[j] == 'b') {
          sumb++;
        }
        if (s[j] == 'c') {
          sumc++;
        }
        if (s[j] == 'd') {
          sumd++;
        }
        if (s[j] == 'e') {
          sume++;
        }
      }
      a[i].detea = suma - (len - suma);
      a[i].deteb = sumb - (len - sumb);
      a[i].detec = sumc - (len - sumc);
      a[i].deted = sumd - (len - sumd);
      a[i].detee = sume - (len - sume);
    }
    int ans = 0;
    sort(a + 1, a + 1 + n, cmpa);
    int tota = 0;
    int resta = 0;
    for (int i = 1; i <= n; i++) {
      resta += a[i].detea;
      if (resta > 0) {
        tota++;
      }
    }
    ans = max(ans, tota);
    sort(a + 1, a + 1 + n, cmpb);
    int totb = 0;
    int restb = 0;
    for (int i = 1; i <= n; i++) {
      restb += a[i].deteb;
      if (restb > 0) {
        totb++;
      }
    }
    ans = max(ans, totb);
    sort(a + 1, a + 1 + n, cmpc);
    int totc = 0;
    int restc = 0;
    for (int i = 1; i <= n; i++) {
      restc += a[i].detec;
      if (restc > 0) {
        totc++;
      }
    }
    ans = max(ans, totc);
    sort(a + 1, a + 1 + n, cmpd);
    int totd = 0;
    int restd = 0;
    for (int i = 1; i <= n; i++) {
      restd += a[i].deted;
      if (restd > 0) {
        totd++;
      }
    }
    ans = max(ans, totd);
    sort(a + 1, a + 1 + n, cmpe);
    int tote = 0;
    int reste = 0;
    for (int i = 1; i <= n; i++) {
      reste += a[i].detee;
      if (reste > 0) {
        tote++;
      }
    }
    ans = max(ans, tote);
    printf("%d\n", ans);
  }
}

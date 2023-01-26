#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct node {
  int numa, numb, numc, numd, nume;
} num[MAXN];
int t, n;
bool cmpa(node x, node y) { return x.numa > y.numa; }
bool cmpb(node x, node y) { return x.numb > y.numb; }
bool cmpc(node x, node y) { return x.numc > y.numc; }
bool cmpd(node x, node y) { return x.numd > y.numd; }
bool cmpe(node x, node y) { return x.nume > y.nume; }
int chose_a() {
  sort(num + 1, num + 1 + n, cmpa);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + num[i].numa > 0) {
      tot += num[i].numa;
      ans++;
    } else
      break;
  }
  return ans;
}
int chose_b() {
  sort(num + 1, num + 1 + n, cmpb);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + num[i].numb > 0) {
      tot += num[i].numb;
      ans++;
    } else
      break;
  }
  return ans;
}
int chose_c() {
  sort(num + 1, num + 1 + n, cmpc);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + num[i].numc > 0) {
      tot += num[i].numc;
      ans++;
    } else
      break;
  }
  return ans;
}
int chose_d() {
  sort(num + 1, num + 1 + n, cmpd);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + num[i].numd > 0) {
      tot += num[i].numd;
      ans++;
    } else
      break;
  }
  return ans;
}
int chose_e() {
  sort(num + 1, num + 1 + n, cmpe);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + num[i].nume > 0) {
      tot += num[i].nume;
      ans++;
    } else
      break;
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    string p;
    for (int i = 1; i <= n; i++) {
      cin >> p;
      int len = p.size();
      int la = 0, lb = 0, lc = 0, ld = 0, le = 0;
      for (int i = 0; i < len; i++) {
        if (p[i] == 'a') la++;
        if (p[i] == 'b') lb++;
        if (p[i] == 'c') lc++;
        if (p[i] == 'd') ld++;
        if (p[i] == 'e') le++;
      }
      num[i].numa = la - lb - lc - ld - le;
      num[i].numb = lb - la - lc - ld - le;
      num[i].numc = lc - la - lb - ld - le;
      num[i].numd = ld - la - lb - lc - le;
      num[i].nume = le - la - lb - lc - ld;
    }
    int ans = chose_a();
    ans = max(ans, chose_b());
    ans = max(ans, chose_c());
    ans = max(ans, chose_c());
    ans = max(ans, chose_d());
    ans = max(ans, chose_e());
    printf("%d\n", ans);
    memset(num, 0, sizeof(num));
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
long long a, b;
int qa[N], qb[N], backup[N], tt1, tt2;
void div() {
  while (a) {
    if (a & 1)
      qa[tt1++] = 1;
    else
      qa[tt1++] = 0;
    a >>= 1;
  }
  while (b) {
    if (b & 1)
      qb[tt2++] = 1;
    else
      qb[tt2++] = 0;
    b >>= 1;
  }
}
bool can_match(int s1[], int l1, int s2[], int l2) {
  for (int i = 0; i < l2 - l1 + 1; ++i) {
    int st = true;
    for (int j = 0; j < l1; ++j)
      if (s2[i + j] != s1[j]) {
        st = false;
        break;
      }
    if (st) {
      int st2 = true;
      for (int j = i + l1; j < l2; ++j)
        if (s2[j] != 1) {
          st2 = false;
          break;
        }
      if (st2) {
        return true;
        break;
      }
    }
    if (s2[i] == 0) break;
  }
  return false;
}
int main() {
  cin >> a >> b;
  div();
  reverse(qa, qa + tt1);
  reverse(qb, qb + tt2);
  bool flag = false;
  int tt_1 = tt1;
  memcpy(backup, qa, sizeof backup);
  while (tt_1 > 0 && backup[tt_1 - 1] == 0) tt_1--;
  if (can_match(backup, tt_1, qb, tt2)) flag = true;
  memcpy(backup, qa, sizeof backup);
  tt_1 = tt1;
  backup[tt_1++] = 1;
  if (can_match(backup, tt_1, qb, tt2)) flag = true;
  if (!flag)
    puts("NO");
  else
    puts("YES");
  return 0;
}

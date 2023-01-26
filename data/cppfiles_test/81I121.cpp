#include <bits/stdc++.h>
using namespace std;
int pre1[300010], pre2[300010];
int sq;
struct str {
  int a, b, idx;
};
bool comp(str s1, str s2) {
  if (s1.a / sq != s2.a / sq) return s1.a < s2.a;
  return s1.b < s2.b;
}
str qs[300010];
int cnt1[300010][2], cnt2[300010][2];
void add(int l, int r) {
  if (l > r) swap(l, r);
  for (int i = l; i <= r; i++) {
    if (pre1[i] < pre1[i - 1])
      cnt1[pre1[i]][0]++;
    else
      cnt1[pre1[i]][1]++;
    if (pre2[i] < pre2[i - 1])
      cnt2[pre2[i]][0]++;
    else
      cnt2[pre2[i]][1]++;
  }
}
void sub(int l, int r) {
  if (l > r) swap(l, r);
  for (int i = l; i <= r; i++) {
    if (pre1[i] < pre1[i - 1])
      cnt1[pre1[i]][0]--;
    else
      cnt1[pre1[i]][1]--;
    if (pre2[i] < pre2[i - 1])
      cnt2[pre2[i]][0]--;
    else
      cnt2[pre2[i]][1]--;
  }
}
int ans[300010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, n, q, a, b, pre;
  string st;
  cin >> t;
  while (t--) {
    cin >> n >> q >> st;
    sq = sqrt(n);
    for (int i = 0; i <= n; i++)
      cnt1[i][0] = cnt1[i][1] = cnt2[i][0] = cnt2[i][1] = 0;
    pre1[0] = pre2[0] = 0;
    for (int i = 0; i < n; i++)
      pre1[i + 1] =
          pre1[i] + ((st[i] == '+') ? 1 : -1) * ((i % 2 == 0) ? 1 : -1);
    for (int i = 0; i < n; i++)
      pre2[i + 1] =
          pre2[i] + ((st[i] == '+') ? 1 : -1) * ((i % 2 == 0) ? -1 : 1);
    for (int i = 0; i < q; i++) {
      cin >> qs[i].a >> qs[i].b;
      qs[i].a--;
      qs[i].b--;
      qs[i].idx = i;
    }
    sort(qs, qs + q, comp);
    add(qs[0].a, qs[0].b);
    pre = ((qs[0].a % 2 == 0) ? pre1[qs[0].b + 1] - pre1[qs[0].a]
                              : pre2[qs[0].b + 1] - pre1[qs[0].a]);
    if (pre == 0)
      ans[qs[0].idx] = 0;
    else {
      if (qs[0].b - qs[0].a == 0 ||
          (pre % 2 &&
           (((qs[0].a % 2 == 0) ? cnt1[pre / 2][0] : cnt2[pre / 2][0]) ||
            ((qs[0].a % 2 == 0) ? cnt1[pre / 2 + 1][1]
                                : cnt2[pre / 2 + 1][1]))))
        ans[qs[0].idx] = 1;
      else
        ans[qs[0].idx] = 2;
    }
    for (int i = 1; i < q; i++) {
      if (qs[i].a != qs[i - 1].a) {
        if (qs[i].a < qs[i - 1].a)
          add(qs[i].a, qs[i - 1].a - 1);
        else
          sub(qs[i - 1].a, qs[i].a - 1);
      }
      if (qs[i].b != qs[i - 1].b) {
        if (qs[i].b < qs[i - 1].b)
          sub(qs[i].b + 1, qs[i - 1].b);
        else
          add(qs[i - 1].b + 1, qs[i].b);
      }
      pre = ((qs[i].a % 2 == 0) ? pre1[qs[i].b + 1] - pre1[qs[i].a]
                                : pre2[qs[i].b + 1] - pre1[qs[i].a]);
      if (pre == 0)
        ans[qs[i].idx] = 0;
      else {
        if (qs[i].b - qs[i].a == 0 ||
            (pre % 2 &&
             (((qs[i].a % 2 == 0) ? cnt1[pre / 2][0] : cnt2[pre / 2][0]) ||
              ((qs[i].a % 2 == 0) ? cnt1[pre / 2 + 1][1]
                                  : cnt2[pre / 2 + 1][1]))))
          ans[qs[i].idx] = 1;
        else {
          if (pre % 2 == 0)
            ans[qs[i].idx] = 2;
          else
            ans[qs[i].idx] = 3;
        }
      }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  }
}

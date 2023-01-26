#include <bits/stdc++.h>
using namespace std;
long long n, q, x, cnt, mn, a1[200200], a2[200200], a3[200200], a4[200200],
    a5[200200], a6[200200], l, r;
string s, t1, t2, t3, t4, t5, t6, tt1, tt2, tt3, tt4, tt5, tt6;
int32_t main() {
  cin >> n >> q;
  cin >> s;
  t1 = "abc";
  t2 = "acb";
  t3 = "bac";
  t4 = "bca";
  t5 = "cab";
  t6 = "cba";
  for (long long i = 0; i < n; i++) {
    tt1 += t1[i % 3];
    tt2 += t2[i % 3];
    tt3 += t3[i % 3];
    tt4 += t4[i % 3];
    tt5 += t5[i % 3];
    tt6 += t6[i % 3];
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt1[i]) cnt++;
    a1[i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt2[i]) cnt++;
    a2[i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt3[i]) cnt++;
    a3[i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt4[i]) cnt++;
    a4[i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt5[i]) cnt++;
    a5[i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != tt6[i]) cnt++;
    a6[i] = cnt;
  }
  for (long long i = 0; i < q; i++) {
    cin >> l >> r;
    l--;
    r--;
    mn = 1e9;
    if (l < 0)
      x = a1[r];
    else
      x = a1[r] - a1[l - 1];
    mn = min(mn, x);
    if (l < 0)
      x = a2[r];
    else
      x = a2[r] - a2[l - 1];
    mn = min(mn, x);
    if (l < 0)
      x = a3[r];
    else
      x = a3[r] - a3[l - 1];
    mn = min(mn, x);
    if (l < 0)
      x = a4[r];
    else
      x = a4[r] - a4[l - 1];
    mn = min(mn, x);
    if (l < 0)
      x = a5[r];
    else
      x = a5[r] - a5[l - 1];
    mn = min(mn, x);
    if (l < 0)
      x = a6[r];
    else
      x = a6[r] - a6[l - 1];
    mn = min(mn, x);
    cout << mn << endl;
  }
}

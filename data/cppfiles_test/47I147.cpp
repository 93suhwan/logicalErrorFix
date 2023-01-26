#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
const long long large = 2000000000000000000LL;
int query(int t, int i, int j) {
  if (t == 0) cout << "and ";
  if (t == 1) cout << "or ";
  cout << i + 1 << " " << j + 1 << endl;
  int x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  vector<int> anr(3, 0);
  vector<int> orr(3, 0);
  anr[0] = query(0, 0, 1);
  anr[1] = query(0, 1, 2);
  anr[2] = query(0, 0, 2);
  orr[0] = query(1, 0, 1);
  orr[1] = query(1, 1, 2);
  orr[2] = query(1, 0, 2);
  for (int j = 0; j < 30; j++) {
    int t = -1;
    for (int i = 0; i < 3; i++) {
      int ab = (anr[i] >> j) & 1;
      int ob = (orr[i] >> j) & 1;
      if (ab == ob) {
        t = i;
        break;
      }
    }
    int f = anr[t] & (1 << j);
    int of = f ^ (1 << j);
    if (t == 0) {
      a[0] ^= f;
      a[1] ^= f;
      int atb = (anr[1] >> j) & 1;
      int otb = (orr[1] >> j) & 1;
      if (atb == otb)
        a[2] ^= f;
      else
        a[2] ^= of;
    }
    if (t == 1) {
      a[1] ^= f;
      a[2] ^= f;
      int atb = (anr[0] >> j) & 1;
      int otb = (orr[0] >> j) & 1;
      if (atb == otb)
        a[0] ^= f;
      else
        a[0] ^= of;
    }
    if (t == 2) {
      a[0] ^= f;
      a[2] ^= f;
      int atb = (anr[0] >> j) & 1;
      int otb = (orr[0] >> j) & 1;
      if (atb == otb)
        a[1] ^= f;
      else
        a[1] ^= of;
    }
  }
  for (int i = 3; i < n; i++) {
    int ab = query(0, 0, i);
    int ob = query(1, 0, i);
    a[i] = ab ^ ob ^ a[0];
  }
  sort(a.begin(), a.end());
  cout << a[k - 1] << endl;
  return 0;
}

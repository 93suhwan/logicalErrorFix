#include <bits/stdc++.h>
using namespace std;
int t;
long long n, a[1000100];
long long jia[200010], jian[200010], idx1, idx2;
int ch1() {
  if (idx1 == 0) return 1;
  sort(jia + 1, jia + 1 + idx1);
  if (jia[idx1] > n) return 0;
  int now = jia[idx1], add = 0;
  for (int i = idx1; i >= 1; i--) {
    if (jia[i] == now) {
      add++;
    } else {
      if (add + now > n + 1) return 0;
      now = jia[i];
      add = 1;
    }
  }
  if (add + now > n + 1) return 0;
  return 1;
}
int ch2() {
  if (idx2 == 0) return 1;
  sort(jian + 1, jian + 1 + idx2);
  if (jian[1] < 1) return 0;
  int now = jian[1], add = 0;
  for (int i = 1; i <= idx2; i++) {
    if (jian[i] == now)
      add++;
    else {
      if (add - now >= 1) return 0;
      now = jian[i];
      add = 1;
    }
  }
  if (add - now >= 1) return 0;
  return 1;
}
int main() {
  cin >> t;
  while (t--) {
    idx1 = 0, idx2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
      if (s[i - 1] == 'R')
        jia[++idx1] = a[i];
      else
        jian[++idx2] = a[i];
    if (ch1() && ch2())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

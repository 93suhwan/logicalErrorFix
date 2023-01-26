#include <bits/stdc++.h>
using namespace std;
int t;
long long n, a[1000100];
long long jia[200010], jian[200010], idx1, idx2;
int ch1() {
  sort(jia + 1, jia + 1 + idx1);
  int now = 0;
  for (int i = idx1; i >= 1; i--) {
    now++;
    if (now + jia[i] > n + 1) return 0;
  }
  return 1;
}
int ch2() {
  sort(jian + 1, jian + 1 + idx2);
  int now = 0;
  for (int i = 1; i <= idx2; i++) {
    now++;
    if (now > jian[i]) return 0;
  }
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

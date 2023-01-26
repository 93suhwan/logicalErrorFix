#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
void solve() {
  long long n, m, k;
  string s;
  scanf("%lld %lld %lld", &n, &m, &k);
  cin >> s;
  if (m == 0) {
    for (int i = 0; s[i]; i++)
      if (s[i] == 'a') cout << s[i];
    cout << endl;
    return;
  }
  string res;
  k--;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'a') {
      res += 'a';
      continue;
    }
    int t = 1;
    while (s[i] == '*') {
      t += m;
      i--;
    }
    i++;
    for (int j = 1; j <= k % t; j++) res += 'b';
    k /= t;
  }
  for (int i = res.size() - 1; i >= 0; i--) printf("%c", res[i]);
  printf("\n");
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}

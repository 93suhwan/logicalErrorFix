#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int w[N];
int ans[N];
int n;
void solve() {
  memset(w, 0, sizeof w);
  memset(ans, 0, sizeof ans);
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
  int cnt = 0, res = 1;
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'a') continue;
    w[++cnt] = 1;
    while (s[i] == '*') {
      w[cnt] += m;
      i++;
    }
    res *= w[cnt];
  }
  if (k >= res) k = res;
  k--;
  for (int i = cnt; i >= 1; i--) {
    ans[i] = k % w[i];
    k /= w[i];
  }
  for (int i = 0, j = 1; s[i]; i++) {
    if (s[i] == 'a') {
      printf("a");
    } else {
      for (int i = 1; i <= ans[j]; i++) {
        printf("b");
      }
      while (s[i] == '*') i++;
      j++;
      i--;
    }
  }
  printf("\n");
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long tab[2005], tab2[2005];
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  long long last = -1;
  for (long long i = 0; i <= n - 1; i++) {
    if (s[i] == 'a')
      tab[i] = -1;
    else {
      if (i == 0 || s[i - 1] == 'a') {
        tab[i] = k;
        last = i;
      } else {
        tab[last] += k;
        tab[i] = 0;
      }
    }
  }
  x--;
  string s2 = "";
  memset(tab2, 0, sizeof(tab2));
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == 'a')
      s2 = 'a' + s2;
    else if (tab[i] > 0) {
      long long val = x % (tab[i] + 1);
      tab2[i] = val;
      x /= tab[i] + 1;
    }
  }
  for (long long i = 0; i <= n - 1; i++) {
    if (s[i] == 'a')
      cout << 'a';
    else {
      for (long long j = 1; j <= tab2[i]; j++) cout << 'b';
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

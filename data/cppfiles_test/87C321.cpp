#include <bits/stdc++.h>
using namespace std;
long long int power(long long int n, long long int k) {
  long long int ans = 1;
  long long int mod = 1000000007;
  while (k) {
    if (k & 1) ans = (ans * n) % mod, k--;
    n = (n * n) % mod, k >>= 2;
  }
  return ans;
}
long long int mod(long long int n, long long int k) {
  long long int ans = n % k;
  if (n < 0) ans += k;
  return ans;
}
string cins() {
  char ss[1000000];
  fgets(ss, 1000000, stdin);
  string s;
  for (int i = 0; i < strlen(ss); i++) s += ss[i];
  return s;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  cin >> tt;
  for (int T = 1; T < tt + 1; T++) solve();
  return 0;
}
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    int x;
    cin >> x;
    if (x > i + ans) ans += x - (i + ans);
  }
  {
    cout << ans << '\n';
    return;
  };
  ;
}

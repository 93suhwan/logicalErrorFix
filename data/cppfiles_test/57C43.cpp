#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solve() {
  long long int n, k, s;
  cin >> s >> n >> k;
  if (k > s) {
    cout << "NO\n";
    return;
  }
  if (k == s) {
    cout << "YES\n";
    return;
  }
  long long int l = s - n;
  long long int r = n / k * k;
  if (l >= r)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

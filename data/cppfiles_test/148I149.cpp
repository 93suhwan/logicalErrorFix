#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int nonzero(int a) {
  int num = a, ans = 0, z = 1;
  while (num) {
    int div = num % 10;
    if (div) {
      ans += z * div;
      z *= 10;
    }
    num /= 10;
  }
  return ans;
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  int a1;
  cin >> a1;
  int s1[a1];
  for (long long int i = 0; i < a1; i++) cin >> s1[i];
  int a2;
  cin >> a2;
  int s2[a2];
  for (long long int i = 0; i < a2; i++) cin >> s2[i];
  int maxiX = max(s1[a1 - 1] - s1[0], s2[a2 - 1] - s2[0]);
  int ARX = maxiX * m;
  int b1;
  cin >> b1;
  int t1[b1];
  for (long long int i = 0; i < b1; i++) cin >> t1[i];
  int b2;
  cin >> b2;
  int t2[b2];
  for (long long int i = 0; i < b2; i++) cin >> t2[i];
  int maxiY = max(t1[b1 - 1] - t1[0], t2[b2 - 1] - t2[0]);
  int ARy = maxiY * n;
  cout << max(ARy, ARX) << endl;
}
int main() {
  long long int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

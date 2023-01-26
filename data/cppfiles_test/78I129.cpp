#include <bits/stdc++.h>
using namespace std;
long long int T;
const long long int mod = 1e9 + 7;
const long long int maxn = 1e5 + 7;
void srinite() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
}
signed main() {
  srinite();
  for (long long int test = 1; test < T + 1; test++) {
    long long int l, r;
    cin >> l >> r;
    long long int a = r / 2;
    if (r % 2) a++;
    long long int val = max(a, l);
    long long int ans1 = r % val;
    long long int ans2 = (r - 1) % val;
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}

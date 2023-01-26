#include <bits/stdc++.h>
using namespace std;
long long n, ans1;
vector<long long> v;
long long take[200005];
char x[50][50];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 3; i <= 2 * n; ++i) {
      ans = ((ans % (1000000007)) * (i % (1000000007))) % (1000000007);
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 2; i <= n; i++)
    ans = (ans % 1000000007 * i % 1000000007) % 1000000007;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (n % 1000000007 * fact(2 * n - 1) % 1000000007) % 1000000007
         << endl;
  }
}

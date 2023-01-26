#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    m++;
    long long int ans = 0;
    for (long long int i = 32; i >= 0; i--) {
      long long int g1 = n >> i;
      long long int g2 = m >> i;
      if ((g1 & 1) ^ (g2 & 1) == 0)
        continue;
      else if ((g1 & 1) == 0) {
        ans += (long long int)(pow(2, i) + 0.5);
      } else
        break;
    }
    cout << ans << endl;
  }
}

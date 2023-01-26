#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = n / 3;
    long long abc = ans;
    if (n % 3 == 0)
      abc = ans;
    else
      abc++;
    cout << abc << " " << ans << "\n";
  }
  return 0;
}

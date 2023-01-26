#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = (int)sqrt(n);
    long long ans2 = (int)cbrt(n);
    long long ans3 = (int)sqrt(ans2);
    cout << ans + ans2 - ans3 << endl;
  }
}
int main() { solve(); }

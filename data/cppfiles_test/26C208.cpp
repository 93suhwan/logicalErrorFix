#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 2 * n;
    long long sum = 1;
    for (int i = ans; i > 2; i--) {
      sum *= i;
      sum %= 1000000007;
    }
    cout << sum << "\n";
  }
  return 0;
}

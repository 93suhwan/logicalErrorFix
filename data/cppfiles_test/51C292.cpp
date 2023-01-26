#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
long long int fastPow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
void solution() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (n - 1) * -1 << ' ' << n << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solution();
  return 0;
}

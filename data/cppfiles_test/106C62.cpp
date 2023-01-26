#include <bits/stdc++.h>
using namespace std;
long long int mult(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) * (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int add(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) + (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int subt(long long int a, long long int b) {
  long long int ans = ((a % int(1e9 + 7)) - (b % int(1e9 + 7))) % int(1e9 + 7);
  ans %= int(1e9 + 7);
  ans = (ans + int(1e9 + 7)) % int(1e9 + 7);
  return ans;
}
long long int exp(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    }
    po = ((po % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    b /= 2;
  }
  return ans;
}
void nitheesh() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  nitheesh();
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cout << i + 2 << " ";
    }
    cout << '\n';
  }
}

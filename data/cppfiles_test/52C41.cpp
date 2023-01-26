#include <bits/stdc++.h>
using namespace std;
void decToBinary(int n, vector<int>& vc) {
  int i = 0;
  while (n > 0) {
    vc[i] = n % 2;
    n = n / 2;
    i++;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    long long int n, k;
    cin >> n >> k;
    vector<int> vc(32, 0);
    decToBinary(k, vc);
    long long int ans = 0;
    for (int i = 0; i < 32; i++) {
      if (vc[i] == 1) {
        long long int b = 1;
        for (int j = 1; j <= i; j++) {
          b = ((b % 1000000007) * (n % 1000000007)) % 1000000007;
        }
        ans = (ans % 1000000007 + b % 1000000007) % 1000000007;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

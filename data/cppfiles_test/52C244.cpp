#include <bits/stdc++.h>
using namespace std;
long long int N = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, i;
    cin >> n >> k;
    vector<int> v;
    v.push_back(1);
    for (i = 1; i < 30; i++) {
      v.push_back(((v[i - 1] % N) * (n % N)) % N);
      if (v[i] < 0) v[i] += N;
    }
    int binaryNum[30], b[30];
    for (i = 0; i < 30; i++) binaryNum[i] = 0;
    i = 0;
    while (k > 0) {
      binaryNum[i] = k % 2;
      k = k / 2;
      i++;
    }
    int ans = 0;
    for (i = 0; i < 30; i++) {
      ans = ((ans % N) + (binaryNum[i] * v[i]) % N) % N;
      if (ans < 0) ans += N;
    }
    cout << ans << endl;
  }
}

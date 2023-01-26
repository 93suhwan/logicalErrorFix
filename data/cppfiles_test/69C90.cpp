#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int transform(long long int a, long long int b) {
  vector<int> V1, V2;
  while (a) {
    V1.push_back(a % 10);
    a /= 10;
  }
  while (b) {
    V2.push_back(b % 10);
    b /= 10;
  }
  long long int n = V1.size(), m = V2.size();
  long long int j = m - 1, i = n - 1, ans, k = 0;
  while (j > -1 && i > -1) {
    if (V1[i] == V2[j]) {
      k++;
      i--;
    }
    j--;
  }
  return n + m - 2 * k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  vector<long long int> V;
  long long int k = 1;
  V.push_back(k);
  for (long long int i = 1; i < 63; i++) {
    k *= 2;
    V.push_back(k);
  }
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 68719476736;
    for (int i = 0; i < 63; i++) {
      ans = min(ans, transform(V[i], n));
    }
    cout << ans << "\n";
  }
  return 0;
}

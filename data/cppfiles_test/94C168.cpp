#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 6;
long long int binpower(long long int a, long long int b, long long int m) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b = b >> 1;
  }
  return res;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;
    long long int sum = 0;
    sort(arr.begin(), arr.end());
    k++;
    for (int i = 0; i < n - 1; i++) {
      if (k == 0) break;
      int nextval = arr[i + 1];
      long long int poss = (binpower(10LL, nextval, 1e18) - sum - 1) /
                           binpower(10LL, arr[i], 1e18);
      poss = min(k, poss);
      k -= poss;
      sum += poss * (binpower(10, arr[i], 1e18));
    }
    if (k > 0) {
      sum += k * (binpower(10, arr[n - 1], 1e18));
    }
    cout << sum << endl;
  }
}
int32_t main(int argc, char* argv[]) { solve(); }

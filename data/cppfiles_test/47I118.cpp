#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
const long long mod = 1e10 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7;
const long long LEVEL = log2(N) + 1;
long long helper(vector<long long> arr, vector<long long>& dp, long long i,
                 long long k) {
  if (dp[i] != -1) {
    return dp[i];
  } else {
    long long ans = mod;
    for (long long j = 1; j <= k; j++) {
      if (i - j < 0) {
        break;
      } else {
        ans = min(ans, (2 * arr[i - 1]) + helper(arr, dp, i - j, k));
      }
    }
    dp[i] = ans;
  }
  return dp[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<long long> arr1, arr2;
    for (long long i = 0; i < n; i++) {
      if (arr[i] < 0) {
        arr1.push_back(-1 * arr[i]);
      } else {
        arr2.push_back(arr[i]);
      }
    }
    sort(arr1.begin(), arr1.end());
    long long n1 = arr1.size();
    long long n2 = arr2.size();
    long long maxi = -mod;
    if (n1 != 0) {
      maxi = max(maxi, arr1[n1 - 1]);
    }
    if (n2 != 0) {
      maxi = max(maxi, arr2[n2 - 1]);
    }
    vector<long long> dp1(n1 + 1, -1);
    vector<long long> dp2(n2 + 1, -1);
    dp1[0] = 0;
    dp2[0] = 0;
    long long ans1 = helper(arr1, dp1, n1, k);
    long long ans2 = helper(arr2, dp2, n2, k);
    cout << (ans1 + ans2) - maxi << endl;
  }
}

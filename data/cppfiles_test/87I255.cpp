#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  a %= 1000000007;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= 1000000007;
    }
    b /= 2;
    a *= a;
    a %= 1000000007;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n + 1, 0);
    for (long long int i = 1; i < n + 1; i++) {
      cin >> arr[i];
    }
    arr[0] = 0;
    long long int cnt = 0;
    long long int ind = 1;
    for (long long int i = 1; i < n + 1; i++) {
      if (arr[i] <= ind) {
        continue;
      } else {
        long long int cal = (arr[i] - arr[i - 1] - 1);
        cnt += cal;
        ind += cal;
      }
      ind++;
    }
    cout << cnt << endl;
  }
  return 0;
}

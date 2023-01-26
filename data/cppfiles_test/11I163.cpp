#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    string arr[n];
    for (long long i = 0; i < n; i += 1) cin >> arr[i];
    vector<long long> v;
    long long mx = 0;
    for (long long i = 0; i < 5; i += 1) {
      v.clear();
      for (long long k = 0; k < n; k += 1) {
        string str = arr[k];
        long long cnt = 0, others = 0;
        for (long long m = 0; m < (long long)str.size(); m += 1) {
          if (str[m] - '97' == i)
            cnt += 1;
          else
            others += 1;
        }
        v.push_back(cnt - others);
      }
      sort(v.begin(), v.end(), greater<long long>());
      long long sum = 0;
      long long j;
      for (j = 0; j < (long long)v.size(); j += 1) {
        sum += v[j];
        if (sum > 0)
          continue;
        else
          break;
      }
      mx = max(mx, j);
    }
    cout << mx << "\n";
  }
  return 0;
}

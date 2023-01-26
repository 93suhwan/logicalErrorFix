#include <bits/stdc++.h>
using namespace std;
const char ENDL = '\n';
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    vector<long long> ans;
    vector<long long> a;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      long long k;
      cin >> k;
      a.push_back(k);
      sum += k;
    }
    if (sum % (n * (n + 1) / 2) == 0) {
      sum /= n * (n + 1) / 2;
      bool flag = true;
      for (long long j = 0; j < n; j++) {
        if (j == 0) {
          if ((a[n - 1] - a[j] + sum) > 0 and
              (a[n - 1] - a[j] + sum) % n == 0) {
            ans.push_back((a[n - 1] - a[j] + sum) / n);
          } else {
            flag = false;
            break;
          }
        } else {
          if ((a[j - 1] - a[j] + sum) > 0 and
              (a[j - 1] - a[j] + sum) % n == 0) {
            ans.push_back((a[j - 1] - a[j] + sum) / n);
          } else {
            flag = false;
            break;
          }
        }
      }
      if (flag) {
        cout << "YES" << ENDL;
        for (long long j = 0; j < n; j++) {
          cout << ans[j] << ' ';
        }
        cout << ENDL;
      } else {
        cout << "NO" << ENDL;
      }
    } else {
      cout << "NO" << ENDL;
    }
  }
  return 0;
}

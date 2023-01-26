#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t > 0) {
    long long int n;
    cin >> n;
    long long int a[n];
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    vector<long long int> ans;
    sort(a, a + n);
    long long int c = 0;
    long long int pp = 0;
    long long int prev = 0;
    long long int flg2 = 0;
    for (long long int i = 0; i <= n; i++) {
      long long int count = 0;
      if (m[i] > 1) {
        pp = i;
      }
      if (m[i] > 0) {
        count = count + m[i];
        long long int x = i - 0;
        if (x > 0) {
          count = count + prev;
        }
        ans.push_back(count);
      } else {
        ans.push_back(0 + prev);
        long long int flg = 0;
        while (pp >= 0) {
          if (m[pp] > 1) {
            prev = prev + i - pp;
            m[pp]--;
            flg = 1;
            break;
          } else {
            pp--;
          }
        }
        if (flg == 0) {
          flg2 = 1;
          prev = -1;
          break;
        }
      }
    }
    for (long long int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    for (long long int i = 0; i < n + 1 - ans.size(); i++) {
      cout << -1 << " ";
    }
    cout << endl;
    t--;
  }
}

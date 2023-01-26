#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    vector<int> ans;
    sort(a, a + n);
    int c = 0;
    int pp = 0;
    int prev = 0;
    int flg2 = 0;
    for (int i = 0; i <= n; i++) {
      int count = 0;
      if (m[i] > 1) {
        pp = i;
      }
      if (m[i] > 0) {
        count = count + m[i];
        int x = i - 0;
        if (x > 0) {
          count = count + prev;
        }
        ans.push_back(count);
      } else {
        ans.push_back(0 + prev);
        int flg = 0;
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
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    for (int i = 0; i < n + 1 - ans.size(); i++) {
      cout << -1 << " ";
    }
    cout << endl;
    t--;
  }
}

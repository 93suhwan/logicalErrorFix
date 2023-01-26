#include <bits/stdc++.h>
using namespace std;
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const long long POW = 9973;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long second, n;
    cin >> second >> n;
    long long temp = second;
    long long rem = second;
    vector<long long> v;
    while (second) {
      v.push_back(second % 10);
      second /= 10;
    }
    vector<long long> ans;
    long long p10 = 1;
    for (long long i = 1; i < v.size(); i++) p10 *= 10;
    for (long long i = v.size() - 1; i >= 0; i--) {
      for (long long j = 10 * n; j >= 0; j--) {
        if (rem - j * p10 >= 0 && j + (rem - (j * p10)) >= n - ans.size()) {
          vector<int> cnt(n, 0);
          rem -= j * p10;
          int q = j;
          while (ans.size() < n) {
            if (q) {
              ans.push_back(p10);
              q--;
              cnt[ans.size() - 1]++;
            } else
              break;
          }
          for (int i = 0; i < ans.size(); i++) {
            if (q) {
              int ad = min(9 - cnt[i], q);
              ans[i] += ad * p10;
              q -= ad;
            }
          }
          break;
        }
      }
      p10 /= 10;
    }
    for (auto i : ans) cout << i << " ";
    ;
    cout << "\n";
  }
}

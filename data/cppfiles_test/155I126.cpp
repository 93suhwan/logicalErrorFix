#include <bits/stdc++.h>
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    vector<long long> ans;
    vector<long long> v;
    long long n, dis = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    string second;
    cin >> second;
    for (long long i = 0; i < n; i++) {
      if (second[i] == '0') {
        dis++;
      }
    }
    long long temp;
    for (long long i = 0; i < n; i++) {
      if (second[i] == '0' && v[i] > dis) {
        temp = v[i] - (v.size() - dis);
        ans.push_back(temp);
      } else if (second[i] == '1' && v[i] <= dis) {
        temp = v[i] + (v.size() - dis);
        ans.push_back(temp);
      } else {
        ans.push_back(v[i]);
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

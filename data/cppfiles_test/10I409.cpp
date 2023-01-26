#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  unordered_map<int, vector<int> > make_pair;
  unordered_map<int, int> curr;
  int ans[n], var = 0;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    int temp;
    cin >> temp;
    make_pair[temp].push_back(i);
  }
  int cnt = 1;
  for (auto i : make_pair) {
    if (i.second.size() >= k) {
      int cnt = 1;
      for (auto j : i.second) {
        if (cnt > k) {
          ans[j] = 0;
        } else {
          ans[j] = cnt;
          cnt++;
        }
        var += 1;
      }
    } else {
      for (auto j : i.second) {
        if (cnt == k + 1) cnt = 1;
        ans[j] = cnt;
        cnt++;
      }
      var += i.second.size();
    }
  }
  var = var / k;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    curr[ans[i]]++;
    if (curr[ans[i]] > var)
      cout << 0 << " ";
    else
      cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}

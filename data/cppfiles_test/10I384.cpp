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
  int ans[n];
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    int temp;
    cin >> temp;
    make_pair[temp].push_back(i);
  }
  for (auto i : make_pair) {
    if (i.second.size() > k) {
      int cnt = 1;
      for (auto j : i.second) {
        if (cnt > k) {
          ans[j] = 0;
        } else {
          ans[j] = cnt;
          cnt++;
        }
      }
    } else {
      int cnt = 1;
      for (auto j : i.second) {
        ans[j] = cnt;
        cnt++;
      }
    }
  }
  for (auto i : ans) {
    cout << i << " ";
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

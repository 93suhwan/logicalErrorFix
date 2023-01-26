#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
void solve() {
  int n;
  char c;
  cin >> n >> c;
  string str;
  cin >> str;
  int ans = 0;
  vector<int> vec;
  for (int i = 0; i < n - 1; i++) {
    if (str[i] != c) {
      ans = 1;
    }
  }
  if (ans == 1) {
    vec.push_back(n);
  }
  if (str[n - 1] != c) {
    ans++;
    vec.push_back(n - 1);
  }
  cout << ans << endl;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

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
  vector<int> vec;
  if (str[n - 1] != c) {
    vec.push_back(n - 1);
    str[n - 1] = c;
  }
  if (str[n - 2] != c) {
    vec.push_back(n);
    str[n - 2] = c;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != c) {
      cnt++;
    }
  }
  if (cnt >= 1 && vec.size() == 0) {
    vec.push_back(n);
  }
  cout << vec.size() << endl;
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

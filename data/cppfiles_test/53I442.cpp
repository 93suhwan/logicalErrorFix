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
  int ans = 0, current = 1;
  vector<int> vec;
  while (current <= str.size()) {
    int curr = 0;
    for (int i = 0; i < n; i++) {
      if ((i + 1) % current != 0 && str[i] != c) {
        str[i] = c;
        curr++;
      }
    }
    if (curr > 0) {
      ans++;
      vec.push_back(current);
    }
    current = current * 2;
  }
  if (vec.size() >= 2) {
    vec[vec.size() - 1] -= 1;
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
    if (i == vec.size() - 1) {
      cout << endl;
    }
  }
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

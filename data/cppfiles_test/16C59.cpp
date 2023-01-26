#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  string temp = str;
  sort(temp.begin(), temp.end());
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (temp[i] != str[i]) count++;
  }
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

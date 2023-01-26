#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string in;
    for (int i = 0; i < n - 2; i++) {
      string temp;
      cin >> temp;
      in += temp;
    }
    string ans = "";
    ans.push_back(in[0]);
    int l = in.length();
    for (int i = 1; i < l - 1; i = i + 2) {
      char a = in[i];
      char b = in[i + 1];
      if (a == b) {
        ans.push_back(a);
      } else {
        ans.push_back(a);
        ans.push_back(b);
      }
    }
    ans.push_back(in[l - 1]);
    if (ans.length() < n) ans.push_back('a');
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  solve();
  return 0;
}

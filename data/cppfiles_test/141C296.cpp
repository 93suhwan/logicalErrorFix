#include <bits/stdc++.h>
using namespace std;
string ans;
void solve(string& a, string& b, string temp, int i, int j) {
  if (i < 0 and j < 0) {
    ans = temp;
    return;
  }
  if (i == -1) {
    while (j >= 0) temp = b[j--] + temp;
    ans = temp;
    return;
  }
  if (i >= 0 and j >= 0) {
    string temp1 = "", temp2 = "", temp3 = "";
    temp1 += b[j];
    if (j > 0 and b[j - 1] != '0') temp2 += b[j - 1];
    temp2 += b[j];
    temp3 += a[i];
    int x, y = -1, z;
    x = stoi(temp1);
    if (temp1 != temp2) y = stoi(temp2);
    z = stoi(temp3);
    if (x >= z and x - z <= 9) {
      string w = to_string(x - z);
      solve(a, b, w + temp, i - 1, j - 1);
    }
    if (temp1 != temp2) {
      if (y >= z and y - z <= 9) {
        string w = to_string(y - z);
        solve(a, b, w + temp, i - 1, j - 2);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b, temp = "";
    cin >> a >> b;
    ans = "";
    solve(a, b, temp, (int)a.size() - 1, (int)b.size() - 1);
    reverse(ans.begin(), ans.end());
    if (ans.size() > 1) {
      while (ans.back() == '0') ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans == "")
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}

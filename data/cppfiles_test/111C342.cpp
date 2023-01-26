#include <bits/stdc++.h>
using namespace std;
void solution(int open, int close, int n, vector<string>& ans, string s) {
  if (ans.size() == n) return;
  if (open == 0 && close == 0) {
    ans.push_back(s);
    return;
  }
  if (open != 0) {
    solution(open - 1, close, n, ans, s + '(');
  }
  if (close > open) {
    solution(open, close - 1, n, ans, s + ')');
  }
  return;
}
vector<string> sol(int n) {
  vector<string> ans;
  solution(n, n, n, ans, "");
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> ans = sol(n);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
    ans.clear();
  }
  return 0;
}

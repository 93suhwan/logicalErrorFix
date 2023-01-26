#include <bits/stdc++.h>
using namespace std;
void help(int open, int close, int n, vector<string> &v, string s) {
  if (v.size() == n) return;
  if (s.size() == 2 * n) {
    v.push_back(s);
    return;
  }
  if (open < n) {
    help(open + 1, close, n, v, s + '(');
  }
  if (open > close) {
    help(open, close + 1, n, v, s + ')');
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v;
    help(0, 0, n, v, "");
    for (int i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
  }
  return 0;
}

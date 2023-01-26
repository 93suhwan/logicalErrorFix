#include <bits/stdc++.h>
using namespace std;
void solve(string s) {
  int one;
  int ans = 0;
  int c[200] = {0};
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    c[s[i]]++;
  }
  for (int i = 0; i < 200; i++) {
    if (c[i] == 1)
      one++;
    else if (c[i] > 1)
      one += 2;
  }
  cout << one / 2 << "\n";
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}

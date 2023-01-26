#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
set<int> st;
void solve() {
  string n;
  int k;
  cin >> n >> k;
  while (1) {
    set<char> s;
    for (auto c : n) s.insert(c);
    if (s.size() <= k) break;
    s.clear();
    int cnt = 0;
    while (1) {
      s.insert(n[cnt]);
      if (s.size() > k) {
        while (n[cnt] == '9') cnt--;
        n[cnt]++;
        for (int i = cnt + 1; i < n[i]; i++) n[i] = '0';
        break;
      }
      cnt++;
    }
  }
  cout << n << endl;
}
int main() {
  int t = read();
  while (t--) {
    solve();
  }
}

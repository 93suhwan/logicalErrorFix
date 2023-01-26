#include <bits/stdc++.h>
using namespace std;
void solve() {
  string n, v;
  int k;
  cin >> n >> k;
  while (true) {
    set<char> s;
    int len = n.length();
    for (int i = 0; i < len; i++) {
      s.insert(n[i]);
      if (s.size() > k) {
        while (n[i] == '9') i--;
        n[i]++;
        for (int j = i + 1; j < n.size(); j++) n[j] = '0';
        break;
      }
      if (i == len - 1) {
        cout << n << endl;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

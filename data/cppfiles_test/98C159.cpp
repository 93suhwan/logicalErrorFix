#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  string word;
  cin >> n >> word;
  int atotal = 0;
  int btotal = 0;
  for (int i = 0; i < n; i++) {
    if (word[i] == 'a') {
      atotal++;
    } else {
      btotal++;
    }
  }
  if (atotal == 0 || btotal == 0) {
    cout << "-1 -1\n";
    return;
  }
  for (int i = 1; i < n; i++) {
    if (word[i - 1] != word[i]) {
      cout << i << " " << i + 1 << "\n";
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

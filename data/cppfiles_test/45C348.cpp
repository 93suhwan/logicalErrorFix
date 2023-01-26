#include <bits/stdc++.h>
using namespace std;
void Start_Crushing() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
void solve() {
  int n;
  cin >> n;
  bool dies = false;
  int ans = 1;
  for (int i = 0, entry, prev; i < n and cin >> entry; i++) {
    ans += entry;
    if (i) {
      if (not entry and not prev)
        dies = true;
      else if (entry and prev)
        ans += 4;
    }
    prev = entry;
  }
  cout << (dies ? -1 : ans);
}
int main() {
  Start_Crushing();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    if (!t) break;
    cout << "\n";
  }
  return 0;
}

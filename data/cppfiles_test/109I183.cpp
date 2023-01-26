#include <bits/stdc++.h>
using namespace std;
void S() {
  int a, b;
  cin >> a >> b;
  vector<int> ans;
  int d = abs(a - b) / 2;
  if ((a + b) % 2 == 0) {
    for (int i = d; i <= (a + b) - d; i += 2) ans.push_back(i);
  } else {
    for (int i = d; i <= (a + b) - d; i++) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (int i : ans) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) S();
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  string n;
  cin >> n;
  string tmp1 = "", tmp2 = "";
  for (int i = 0; i < n.size(); i++) {
    if (i % 2 == 0) {
      tmp1 += n[i];
    } else {
      tmp2 += n[i];
    }
  }
  if (tmp1.empty()) {
    cout << stoi(tmp2) - 1 << endl;
    return;
  }
  if (tmp2.empty()) {
    cout << stoi(tmp1) - 1 << endl;
    return;
  }
  long long int tmp1_n = stoi(tmp1), tmp2_n = stoi(tmp2);
  cout << (tmp1_n + 1) * (tmp2_n + 1) - 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

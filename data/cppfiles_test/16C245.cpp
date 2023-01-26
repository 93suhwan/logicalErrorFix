#include <bits/stdc++.h>
using namespace std;
void find_count(string st) {
  string dup = st;
  int long long ans = 0;
  sort(st.begin(), st.end());
  for (int i = 0; i < st.size(); i++) {
    if (st[i] != dup[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ct;
    cin >> ct;
    string st;
    cin >> st;
    find_count(st);
  }
}

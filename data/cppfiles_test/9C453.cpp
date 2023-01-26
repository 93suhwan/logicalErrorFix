#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  vector<int> hash(26, 0);
  for (int i = 0; i < s.length(); i++) hash[s[i] - 97]++;
  set<char, greater<char>> st;
  for (int i = 0; i < s.length(); i++) st.insert(s[i]);
  long long ans = st.size();
  long long count1 = count(hash.begin(), hash.end(), 1);
  if (count1 % 2 != 0)
    ans = ans - count1 / 2 - 1;
  else
    ans -= count1 / 2;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

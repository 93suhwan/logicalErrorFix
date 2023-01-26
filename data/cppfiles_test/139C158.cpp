#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long int n, m, a, b, c, d, p, q, cnt = 0, ct = 0, sum = 0, ans = 0;
  string st;
  cin >> st;
  long long int sz = st.size();
  if (sz % 2 == 1)
    cout << "NO" << endl;
  else {
    string s1, s2;
    for (long long int i = 0; i < sz / 2; i++) s1 += st[i];
    for (long long int i = sz / 2; i < sz; i++) s2 += st[i];
    if (s1 == s2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}

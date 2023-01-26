#include <bits/stdc++.h>
using namespace std;
int arr[7 + 1][7 + 1];
int vis[8][8];
int ans = 0;
vector<int> v[7 + 1];
long long n, p, r, a, b, k, m, sz, q, x, d, c;
void solve() {
  string s;
  cin >> s;
  int arr[26] = {0};
  for (int i = 0; i < s.size(); i++) arr[s[i] - 'a']++;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < 26; i++) {
    if (arr[i] == 1)
      cnt1++;
    else if (arr[i] > 1)
      cnt1 += 2;
  }
  cout << cnt1 / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

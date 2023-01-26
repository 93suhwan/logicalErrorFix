#include <bits/stdc++.h>
using namespace std;
const int MX = 20, MA = 400005;
int n, mem[1 << MX], mn[MX], sum[MX], mp[MX][2 * MA];
int dp(int mk) {
  if (__builtin_popcount(mk) == n) return 0;
  int &res = mem[mk];
  if (res != -1) return res;
  res = 0;
  int s = 0;
  for (int i = 0; i < int(n); i++)
    if (mk & (1 << i)) s += sum[i];
  for (int i = 0; i < int(n); i++)
    if (~mk & (1 << i)) {
      if (s + mn[i] < 0) {
        res = max(res, mp[i][MA - s]);
      } else {
        res = max(res, dp(mk | (1 << i)) + mp[i][MA - s]);
      }
    }
  return res;
}
void main_() {
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    string s;
    cin >> s;
    for (char c : s) {
      if (c == '(')
        sum[i]++;
      else
        sum[i]--;
      if (sum[i] <= mn[i]) {
        mp[i][MA + sum[i]]++;
        mn[i] = sum[i];
      }
    }
  }
  memset(mem, -1, sizeof(mem));
  cout << dp(0) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}

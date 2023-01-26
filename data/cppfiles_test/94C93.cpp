#include <bits/stdc++.h>
using namespace std;
const int maxv = 50010;
const int maxn = 50010;
#pragma warning(disable : 4996)
int T;
string S;
void solve() {
  if (S.length() == 1) {
    cout << stoll(S) - 1 << endl;
    return;
  }
  string a = "", b = "";
  for (int i = 0; i < S.length(); i++) {
    if (i % 2)
      a += S[i];
    else
      b += S[i];
  }
  long long x = stoll(a), y = stoll(b);
  cout << (x + 1) * (y + 1) - 2 << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> S;
    solve();
  }
  return 0;
}

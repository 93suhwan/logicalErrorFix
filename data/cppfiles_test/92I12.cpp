#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
void solve() {
  string s;
  cin >> s;
  s[0] = s[s.size() - 1];
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

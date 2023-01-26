#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long bin(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * bin((a * a) % mod, b / 2)) % mod;
  return (1 * bin((a * a) % mod, b / 2)) % mod;
}
void I_m_Beast() {
  long long n, m, a;
  string s;
  cin >> s;
  vector<int> v(26);
  for (int i = 0; i < (int)s.size(); i++) {
    v[s[i] - 'a']++;
  }
  int red = 0, green = 0;
  for (int i = 0; i < 26; i++) {
    if (v[i] > 1) {
      red++;
      green++;
    } else if (v[i] == 1) {
      if (red < green)
        red++;
      else
        green++;
    }
  }
  cout << min(red, green) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    I_m_Beast();
  }
  return 0;
}

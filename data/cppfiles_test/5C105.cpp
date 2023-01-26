#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool pof2(int n) {
  if (n < 1) return false;
  double logn = log2(n);
  return floor(logn) == ceil(logn);
}
int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string e, g, s;
    e.push_back('0');
    cin >> s;
    e += s;
    e.push_back('0');
    g.push_back('0');
    cin >> s;
    g += s;
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {
      if (g[i] == '0')
        continue;
      else if (g[i] == '1' && e[i] == '0')
        cnt++;
      else if (g[i] == '1' && e[i - 1] == '1') {
        cnt++;
        e[i - 1] = '0';
      } else if (g[i] == '1' && e[i + 1] == '1') {
        cnt++;
        e[i + 1] = '0';
      }
    }
    cout << cnt << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long NEG_INF = -1e12;
long long POS_INF = 1e12;
int main() {
  ios_base::sync_with_stdio(0);
  long long n, m, a, h, w, b, q, y, c, temp, p, out, in;
  double up, lo, k, ans, r;
  string s, t, t_left, t_right, reverse_s, ts, trs;
  cin >> q;
  while (q--) {
    cin >> s >> t;
    bool flag = false;
    for (int i = 0; i <= t.length(); i++) {
      t_left = t.substr(0, i);
      t_right = t.substr(i, t.length() - i);
      if (s.find(t_left) != std::string::npos) {
        reverse_s = s.substr(0, s.find(t_left) + i - 1);
        reverse(reverse_s.begin(), reverse_s.end());
        if (reverse_s.find(t_right) != std::string::npos) {
          flag = true;
          break;
        }
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
vector<int> vec{};
int numof(string sing, char x) {
  map<char, int> nuof;
  string a = sing;
  for (char c : a) {
    nuof[c]++;
  }
  return nuof[x];
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,
      v, w, x, y, z, count, maxx, minn;
  a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = q = r = s =
      t = u = v = w = x = y = z = count = 0;
  string st;
  char ch;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l == r) {
      cout << 0 << "\n";
    } else if (r - l == 1) {
      cout << 1 << "\n";
    } else {
      if ((r % 2 == 0 ? r : r + 1) / 2 > l) {
        cout << (r % 2 == 0 ? r : r + 1) / 2 - 1 << "\n";
      } else {
        cout << r % l << "\n";
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, a, b, c, j;
  cin >> n;
  vector<pair<long long int, long long int> > v1, v2;
  vector<long long int> v3, v4;
  for (i = 0; i < n; i++) {
    cin >> a;
    v3.push_back(a);
    v1.push_back(make_pair(a, i));
  }
  for (i = 0; i < n; i++) {
    cin >> a;
    v4.push_back(a);
    v2.push_back(make_pair(a, i));
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  i = 0;
  j = 0;
  map<long long int, long long int> m1, m2;
  a = 1;
  b = 1;
  long long int d = -1;
  bool ok = false;
  string s;
  for (int l = 0; l < n; l++) {
    if (l > d) {
      m1[v3[l]] = 1;
      m2[v4[l]] = 1;
      a = 1;
      b = 1;
      while ((a > 0 || b > 0) && i < n && j < n) {
        while (a > 0 && i < n) {
          c = v1[i].first;
          d = max(d, v1[i].second);
          if (m1[c] == 1) {
            m1[c] = 0;
            a--;
          } else if (m2[c] == 0) {
            b++;
            m2[c] = 1;
          }
          i++;
        }
        while (b > 0 && j < n) {
          d = max(d, v2[j].second);
          c = v2[j].first;
          if (m2[c] == 1) {
            b--;
            m2[c] = 0;
          } else if (m1[c] == 0) {
            a++;
            m1[c] = 1;
          }
          j++;
        }
      }
      if (i == n || j == n) {
        d = n;
      }
      if (d == n) {
        ok = true;
        s.push_back('1');
      } else
        s.push_back('0');
    } else if (ok) {
      s.push_back('1');
    } else
      s.push_back('0');
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

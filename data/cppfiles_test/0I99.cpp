#include <bits/stdc++.h>
using namespace std;
struct sp {
  string s1, s2;
  int id;
};
int n, i, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  sp s[n];
  for (int k = 0; k < n; k++) {
    string s1 = "", s2 = "";
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (j % 2 == 0) {
        s1 += c;
      } else {
        s2 += c;
      }
    }
    s[k] = {s1, s2, k + 1};
  }
  stable_sort(s, s + n, [](sp A, sp B) { return A.s2 > B.s2; });
  stable_sort(s, s + n, [](sp A, sp B) { return A.s1 < B.s1; });
  for (int p = 0; p < n; p++) cout << s[p].id << " ";
  cout << "\n";
  return 0;
}

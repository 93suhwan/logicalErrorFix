#include <bits/stdc++.h>
using namespace std;
struct sp {
  string s1, s2;
  int id;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  sp a[n];
  for (int i = 0; i < n; i++) {
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
    a[i] = {s1, s2, i + 1};
  }
  sort(a, a + n,
       [](sp A, sp B) { return A.s1 == B.s1 ? A.s2 > B.s2 : A.s1 < B.s1; });
  for (int i = 0; i < n; i++) {
    cout << a[i].id << " ";
  }
  cout << "\n";
  return 0;
}

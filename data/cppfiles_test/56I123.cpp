#include <bits/stdc++.h>
using namespace std;
int lie;
string s;
inline void doit(int x, int y) {
  cout << x << " " << y << endl;
  lie = y;
  cin >> s;
}
inline bool find(int row) {
  for (int i = (lie == 1 ? 2 : 1); i <= 8; i++) {
    doit(row, i);
    if (s == "Done") return true;
    if (s == "Down") return false;
    if (s == "Up") return find(row);
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    lie = 1;
    for (int i = 1; i <= 7; i++) {
      doit(i, lie);
      if (lie != 1) {
        if (s == "Done") break;
        lie = 1;
        doit(i, lie);
      }
      if (s == "Done") break;
      if (find(i)) break;
    }
  }
  return 0;
}

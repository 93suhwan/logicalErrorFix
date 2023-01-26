#include <bits/stdc++.h>
using namespace std;
string f;
long long i, j, m, k, n;
char a, b, tmp;
bool kt;
int main() {
  cin >> n;
  for (j = 1; j <= n; j++) {
    cin >> m;
    cin >> a >> b;
    kt = false;
    f = "";
    f.push_back(a);
    f.push_back(b);
    tmp = b;
    for (i = 1; i <= m - 3; i++) {
      cin >> a >> b;
      if (a != tmp) {
        f.push_back(a);
        kt = true;
      }
      f.push_back(b);
      tmp = b;
    }
    if (kt == false) f.push_back(b);
    cout << f << '\n';
  }
}

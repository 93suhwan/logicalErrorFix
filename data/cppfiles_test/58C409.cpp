#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1e9 + 7, base = 131;
const double eps = 1e-6, PI = acos(-1);
int random(int n) { return (int)(rand() * rand()) % n; }
string a, b;
void work() {
  int n;
  cin >> n;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '1' && b[i] == '1') {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int main(void) {
  int T = 1;
  cin >> T;
  while (T--) {
    work();
  }
  return 0;
}

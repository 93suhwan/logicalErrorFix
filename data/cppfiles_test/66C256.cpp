#include <bits/stdc++.h>
using namespace std;
int T;
int k;
int now[30005], cnt;
int main() {
  cnt = 0;
  for (int i = 1; i <= 30000; i++) {
    if (i % 3 && i % 10 != 3) {
      now[++cnt] = i;
    }
  }
  cin >> T;
  while (T--) {
    cin >> k;
    cout << now[k] << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1000000, INF = 0x3f3f3f3f;
int aa[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> aa[i];
    bool yes = true;
    int a = -INF, b = -INF;
    for (int i = 0; i < n; i++)
      if (-aa[i] > a || -aa[i] > b)
        (-aa[i] > a && (-aa[i] < b || a > b) ? a : b) = -aa[i];
      else if (aa[i] > a || aa[i] > b)
        (aa[i] > a && (aa[i] < b || a > b) ? a : b) = aa[i];
      else {
        yes = false;
        break;
      }
    if (yes) {
      cout << "YES\n";
      a = b = -INF;
      for (int i = 0; i < n; i++)
        if (-aa[i] > a || -aa[i] > b) {
          cout << -aa[i] << ' ';
          (-aa[i] > a && (-aa[i] < b || a > b) ? a : b) = -aa[i];
        } else {
          cout << aa[i] << ' ';
          (aa[i] > a && (aa[i] < b || a > b) ? a : b) = aa[i];
        }
      cout << '\n';
    } else
      cout << "NO\n";
  }
  return 0;
}

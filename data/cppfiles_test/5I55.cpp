#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 0, n = 0, count = 0;
  cin >> t;
  while (t--) {
    count = 0;
    cin >> n;
    string enemy, my;
    cin >> enemy >> my;
    int used[n];
    int killed = 0;
    for (int i = 0; i < n; i++) {
      used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (my[i] == '1') {
        killed = 0;
        if (enemy[i] == '1') {
          if (i > 0 && used[i - 1] == 0 && my[i - 1] == '1') {
            count++;
            killed = 1;
            used[i - 1] = 1;
          }
          if (my[i + 1] == '1' && i < n - 1 && killed == 0) {
            count++;
            used[i + 1] = 1;
            killed = 1;
          }
        } else {
          if (used[i] == 1) continue;
          count++;
          used[i] = 1;
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], i, j;
    int h[200000 + 1] = {0}, x = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      h[a[i]]++;
    }
    stack<int> s;
    int chill = 0;
    for (i = 0; i <= n; i++) {
      if (x == -1)
        cout << -1 << " ";
      else if (h[i] > 0) {
        for (j = 0; j < h[i] - 1; j++) s.push(i);
        cout << chill + h[i] << " ";
      } else {
        cout << chill << " ";
        if (s.size() == 0)
          x = -1;
        else {
          chill += i - s.top();
          s.pop();
        }
      }
    }
    cout << endl;
  }
  return 0;
}

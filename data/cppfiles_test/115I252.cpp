#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, h;
    cin >> n >> h;
    vector<int> time;
    int a;
    int b;
    cin >> a;
    for (int i = 0; i < n - 1; i++) {
      b = a;
      cin >> a;
      time.push_back(a - b);
    }
    sort(time.begin(), time.end());
    int sol;
    for (int i = 0; i < n - 1; i++) {
      if ((double)h / (n - i) > (double)time[i]) {
        h -= time[i];
      } else {
        if (i != 0) {
          sol = max(ceil((double)h / (n - i)), (double)time[i - 1]);
        } else {
          sol = ceil((double)h / (n - i));
        }
        break;
      }
    }
    cout << sol << endl;
  }
}

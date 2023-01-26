#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, h;
    cin >> n >> h;
    vector<long int> time;
    long int a;
    long int b;
    cin >> a;
    if (n == 1) {
      cout << h << endl;
    } else {
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
          sol = ceil((double)h / (n - i));
          break;
        }
      }
      cout << sol << endl;
    }
  }
}

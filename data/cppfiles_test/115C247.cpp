#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, h;
    cin >> n >> h;
    vector<long long int> time;
    long long int a;
    long long int b;
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
      long long int sol;
      for (int i = 0; i < n - 1; i++) {
        if ((double)h / (n - i) > (double)time[i]) {
          h -= time[i];
          if (i == n - 2) {
            sol = h;
          }
        } else {
          sol = ceil((double)h / (n - i));
          break;
        }
      }
      cout << sol << endl;
    }
  }
}

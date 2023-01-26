#include <bits/stdc++.h>
using namespace std;
void setup() {}
int main() {
  setup();
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<vector<long long>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        long long x;
        cin >> x;
        a[i].push_back(x);
      }
    }
    bool pos = false;
    for (int day1 = 0; day1 < 5; day1++) {
      for (int day2 = day1 + 1; day2 < 5; day2++) {
        long long a1 = 0, a2 = 0, flex = 0;
        for (int i = 0; i < n; i++) {
          if (a[i][day1] && a[i][day2])
            flex++;
          else if (a[i][day1])
            a1++;
          else if (a[i][day2])
            a2++;
          else
            break;
        }
        if (a1 + a2 + flex == n && !(a1 > n / 2) && !(a2 > n / 2)) pos = true;
      }
    }
    if (pos)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

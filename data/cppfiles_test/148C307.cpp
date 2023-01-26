#include <bits/stdc++.h>
using namespace std;
long long t, w, h, k, xxa[2], xa[2], yya[2], ya[2], x, y, z;
string s;
vector<long long> e;
bool p[10005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  for (long long ca = 1; ca <= t; ++ca) {
    cin >> w >> h >> k;
    cin >> xa[0];
    for (int i = 1; i < k; ++i) {
      cin >> xa[1];
    }
    cin >> x;
    cin >> xxa[0];
    for (int i = 1; i < x; ++i) {
      cin >> xxa[1];
    }
    cin >> y;
    cin >> ya[0];
    for (int i = 1; i < y; ++i) {
      cin >> ya[1];
    }
    cin >> z;
    cin >> yya[0];
    for (int i = 1; i < z; ++i) {
      cin >> yya[1];
    }
    cout << max(max((xa[1] - xa[0]) * h, (xxa[1] - xxa[0]) * h),
                max((ya[1] - ya[0]) * w, (yya[1] - yya[0]) * w))
         << "\n";
  }
}

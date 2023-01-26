#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void init_code() {}
signed main() {
  startTime = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long h = 1;
    bool flag = true;
    for (long long i = 0; i < n; i++) {
      if (v[i] == 1 && v[i + 1] == 1) {
        h = h + 5;
      } else if (v[i] == 0 && v[i + 1] == 0) {
        flag = false;
        break;
      } else if (v[i] == 1)
        h = h + 1;
    }
    if (flag)
      cout << h;
    else
      cout << "-1";
    cout << "\n";
  }
}

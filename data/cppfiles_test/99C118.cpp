#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test;
  cin >> test;
  while (test--) {
    long long xx;
    cin >> xx;
    long long d;
    cin >> d;
    vector<long long> fooll;
    long long curent = xx;
    for (long long i = 0; i < 4; i++) {
      long long minn = i + 1;
      if (curent & 1) {
        curent += minn;
      } else {
        curent -= minn;
      }
      fooll.push_back(curent);
    }
    long long tep = d % 4;
    if (tep == 2 or tep == 0) {
      if (tep == 0) tep += 4;
      cout << fooll[tep - 1] << '\n';
    } else {
      if (tep == 1) {
        d--;
        long long dell = d / 4.0;
        if (xx & 1) {
          cout << fooll[tep - 1] + dell * 4 << '\n';
        } else {
          cout << fooll[tep - 1] - dell * 4 << '\n';
        }
      } else {
        d--;
        long long dell = d / 4.0;
        if (xx & 1) {
          cout << fooll[tep - 1] - dell * 4 << '\n';
        } else {
          cout << fooll[tep - 1] + dell * 4 << '\n';
        }
      }
    }
  }
}

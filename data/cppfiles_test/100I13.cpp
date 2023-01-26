#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1000;
long long p[N];
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
      cin >> p[i];
    }
    sort(p, p + a);
    long long j = 0, s = 0;
    long long max = -1e18 - 1;
    for (int i = 0; i < a; i++) {
      if (p[i] + j > max) {
        max = p[i];
        s = j;
      }
      j -= p[i] + j;
    }
    cout << max + s << endl;
  }
  return 0;
}

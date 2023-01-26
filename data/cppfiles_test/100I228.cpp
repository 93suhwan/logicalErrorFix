#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
long long p[N];
int main() {
  int n;
  cin >> n;
  while (n--) {
    memset(p, 0, sizeof p);
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
      cin >> p[i];
    }
    sort(p, p + a);
    long long j = 0, s;
    long long max = -1e9 - 1;
    for (int i = 0; i < a; i++) {
      if (p[i] + j >= max) {
        max = p[i];
        s = j;
      }
      j -= p[i] + j;
    }
    cout << max + s << endl;
  }
  return 0;
}

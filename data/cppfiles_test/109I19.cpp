#include <bits/stdc++.h>
using namespace std;
void AboTupoi() {
  long long n;
  cin >> n;
  long long cnt = 0, a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cnt += a;
  }
  cout << cnt << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    AboTupoi();
  }
}

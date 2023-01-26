#include <bits/stdc++.h>
using namespace std;
void initial_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  initial_code();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long cnt = 0;
    bool bt = 1;
    for (long long i = 0; i < n - 1; i++) {
      cnt = 0;
      if (a[i] == '1') cnt++;
      if (b[i] == '1') cnt++;
      if (cnt >= 2) {
        bt = 0;
        cout << "NO" << endl;
        break;
      }
    }
    if (bt == 1) {
      cout << "YES" << endl;
    }
  }
  return 0;
}

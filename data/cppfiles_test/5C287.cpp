#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<long long> c;
    vector<long long> d;
    c.push_back(-1);
    d.push_back(-1);
    for (int i = 0; i < n; i++) c.push_back(int(a[i]) - 48);
    for (int i = 0; i < n; i++) d.push_back(int(b[i]) - 48);
    c.push_back(-1);
    d.push_back(-1);
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i - 1] == 1 && d[i] == 1) {
        c[i - 1] = 0;
        cnt++;
      } else if ((c[i] == 0 && d[i] == 1))
        cnt++;
      else if ((c[i + 1] == 1 && d[i] == 1)) {
        c[i + 1] = 0;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

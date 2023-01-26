#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  init_code();
  long long T, i, j, l, k, n, s, val, count;
  bool flag;
  vector<long long> c, temp;
  string a, b;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> a;
    cin >> b;
    count = 0;
    for (i = 0; i < n; i++) {
      if (b[i] == '1') {
        if (i > 0 && a[i - 1] == '1')
          count++;
        else if (a[i] == '0') {
          count++;
        } else if (i < n - 1 && a[i + 1] == '1') {
          count++;
          a[i + 1] = '#';
        }
      }
    }
    cout << count << endl;
    a.clear();
    b.clear();
  }
  return 0;
}

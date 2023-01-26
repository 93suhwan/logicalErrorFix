#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
long long n, k, x;
string str;
long long a[N], b[N];
int idx;
void calc(int n, int k) {
  for (int i = n; i >= 0; i--) {
    b[i] = k % (a[i] + 1);
    k /= (a[i] + 1);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k >> x;
    cin >> str;
    idx = 0;
    memset(a, 0, sizeof 0);
    for (int i = 0; i < n; i++) {
      if (a[idx] && str[i] == 'a')
        idx++;
      else
        a[idx] += k;
    }
    calc(idx, x - 1);
    int idx2 = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == 'a') {
        if (i != 0 && str[i - 1] == '*') {
          for (int i = 0; i < b[idx2]; i++) cout << 'b';
          idx2++;
        }
        cout << 'a';
      }
    }
    if (idx2 <= idx)
      while (idx2 <= idx) {
        for (int i = 0; i < b[idx2]; i++) cout << 'b';
        idx2++;
      }
    cout << endl;
  }
  return 0;
}

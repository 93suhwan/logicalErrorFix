#include <bits/stdc++.h>
using namespace std;
const int N = 3500;
char s[N];
long long d[N];
long long id[N];
long long tx[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(tx, 0, sizeof tx);
    memset(d, 0, sizeof d);
    memset(id, 0, sizeof id);
    int n, k;
    cin >> n >> k;
    long long x;
    cin >> x;
    cin >> s;
    x--;
    bool falg = false;
    if (k == 0) {
      for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cout << s[i];
      }
      cout << endl;
      continue;
    }
    long long cnt = 0;
    int j = 0;
    for (int i = 0; i <= n - 1; i++) {
      if (s[i] == 'a' && cnt != 0) {
        id[j] = i;
        d[j++] = cnt;
        cnt = 0;
      } else if (s[i] == '*') {
        cnt += k;
      }
    }
    if (cnt) id[j] = n, d[j++] = cnt;
    long long last = 1;
    int m = 0;
    for (int i = j - 1; i >= 0; i--) {
      if (d[i] * last >= x) {
        m = i;
        tx[i] = x / last;
        x -= last * tx[i];
        break;
      } else
        last = (last) * (d[i] + 1);
    }
    for (int i = m + 1; i < j; i++) {
      last /= (d[i] + 1);
      tx[i] = x / last;
      x -= last * tx[i];
      if (!x) break;
    }
    int tt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        cout << "a";
      } else {
        for (int z = 0; z < tx[tt]; z++) cout << "b";
        i = id[tt] - 1;
        tt++;
      }
    }
    cout << endl;
  }
}

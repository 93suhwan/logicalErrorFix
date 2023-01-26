#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 55;
long long a[MAXN], mark[MAXN];
vector<long long> ans;
int main() {
  long long T, T1;
  cin >> T;
  for (T1 = 1; T1 <= T; T1++) {
    long long n, i, j, sz, st, vall, f2 = 0, lg = 0;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
      if (a[i] > n || (a[i] <= n && mark[a[i]])) {
        ans.push_back(a[i]);
        continue;
      }
      mark[a[i]] = 1;
    }
    sz = ans.size();
    st = 0;
    for (i = 1; i <= n; i++) {
      if (mark[i] == 0) {
        vall = ans[st];
        if (((i * 2) + 1) > vall) {
          f2 = 1;
          break;
        }
        st++;
        lg++;
      }
    }
    if (f2)
      cout << -1 << endl;
    else
      cout << lg << endl;
    for (i = 1; i <= n; i++) mark[i] = 0;
    ans.clear();
  }
}

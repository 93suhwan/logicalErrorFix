#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void compute() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  vector<long long> fre(n + 1, 0);
  multiset<long long> extra;
  vector<long long> ans(n + 1, -1);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    fre[v[i]]++;
    if (fre[v[i]] > 1) {
      extra.insert(v[i]);
    }
  }
  long long added = 0;
  long long indOfbreak = -1;
  if (fre[0] == 0) {
    cout << "0 ";
    for (long long i = 0; i < n; i++) cout << "-1 ";
    cout << endl;
    return;
  }
  for (long long i = 0; i < n + 1; i++) {
    ans[i] = fre[i];
    if (i != 0 and fre[i - 1] == 0) {
      multiset<long long>::iterator it;
      if (extra.size() == 0) {
        indOfbreak = i;
        break;
      }
      it = extra.lower_bound(i - 1);
      if (it == extra.begin()) {
        indOfbreak = i;
        break;
      }
      it--;
      added += i - 1 - (*it);
      extra.erase(it);
    }
    ans[i] += added;
  }
  if (indOfbreak != -1)
    for (long long i = indOfbreak; i <= n; i++) ans[i] = -1;
  for (long long i = 0; i < n + 1; i++) cout << ans[i] << " ";
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    compute();
  }
  return 0;
}

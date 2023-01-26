#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n = ({
    long long int tito;
    cin >> tito;
    tito;
  });
  vector<vector<long long int>> v;
  map<long long int, vector<long long int>> mm;
  long long int pos = 0;
  for (long long int i = 0; i < n; i++) {
    long long int a = ({
      long long int tito;
      cin >> tito;
      tito;
    });
    long long int b, c;
    if (a == 1) {
      b = ({
        long long int tito;
        cin >> tito;
        tito;
      });
      c = 0;
    } else {
      b = ({
        long long int tito;
        cin >> tito;
        tito;
      });
      c = ({
        long long int tito;
        cin >> tito;
        tito;
      });
    }
    vector<long long int> vv;
    vv.push_back(a);
    vv.push_back(b);
    vv.push_back(c);
    v.push_back(vv);
  }
  vector<long long int> ans;
  vector<long long int> aa;
  for (long long int i = 0; i < 5 * 1e5 + 5; i++) {
    aa.push_back(i);
  }
  for (long long int i = 0; i < n; i++) {
    vector<long long int> vv = v[n - 1 - i];
    long long int a = vv[0];
    long long int b = vv[1];
    long long int c = vv[2];
    if (a == 1) {
      ans.push_back(aa[b]);
    } else {
      aa[b] = aa[c];
    }
  }
  long long int nn = ans.size();
  for (long long int i = 0; i < nn; i++) {
    cout << ans[nn - 1 - i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) solve();
  return 0;
}

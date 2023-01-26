#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> in(n);
  for (auto& it : in) cin >> it;
  vector<long long> l(n, 1), r(n, 1);
  for (int i = 1; i < n; i++) {
    if (in[i] < in[i - 1]) {
      r[i] += r[i - 1];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (in[i] < in[i + 1]) {
      l[i] += l[i + 1];
    }
  }
  int il = 0, ir = n - 1;
  bool al = true;
  long long last = -1;
  while (il <= ir) {
    long long mx = ir - il + 1;
    int cntleft = min(l[il], mx);
    int cntright = min(r[ir], mx);
    if (in[il] > in[ir]) {
      if (cntleft % 2 == 1) {
        cout << (al ? "Alice" : "Bob") << endl;
        return;
      }
      if (last < in[ir]) {
        last = in[ir];
        ir--;
      } else {
        last = in[il];
        il++;
      }
    } else if (in[ir] > in[il]) {
      if (cntright % 2 == 1) {
        cout << (al ? "Alice" : "Bob") << endl;
        return;
      }
      if (last < in[il]) {
        last = in[il];
        il++;
      } else {
        last = in[ir];
        ir--;
      }
    } else {
      if (cntleft % 2 == 1 || cntright % 2 == 1) {
        cout << (al ? "Alice" : "Bob") << endl;
      } else {
        cout << (al ? "Bob" : "Alice") << endl;
      }
      return;
    }
    al = !al;
  }
  cout << (al ? "Bob" : "Alice") << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}

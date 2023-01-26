#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N), b, r;
    for (int i = 0; i < N; i++) cin >> a[i];
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
      if (s[i] == 'B')
        b.push_back(a[i]);
      else
        r.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(r.rbegin(), r.rend());
    int B = b.size(), R = r.size();
    bool ok = true;
    for (int i = 0; i < B; i++) {
      if (b[i] <= i) ok = false;
    }
    for (int i = 0; i < R; i++) {
      if (r[i] > N - i) ok = false;
    }
    cout << (ok ? "YES" : "NO") << nl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<int> blu, red;
    for (int i = 0; i < N; i++) {
      if (s[i] == 'R')
        red.push_back(a[i]);
      else
        blu.push_back(a[i]);
    }
    sort(red.begin(), red.end());
    sort(blu.begin(), blu.end());
    vector<int> ord(N + 1, 0);
    iota(ord.begin(), ord.end(), 0);
    bool ok = true;
    int cur = 1;
    for (int i = 0; i < blu.size(); i++) {
      if (blu[i] >= cur) ord[cur] = 1, cur++;
    }
    for (int i = 0; i < red.size(); i++) {
      if (red[i] <= cur) ord[cur] = 1, cur++;
    }
    for (int i = 1; i <= N; i++) ok &= ord[i];
    cout << (ok ? "YES" : "NO") << nl;
  }
}

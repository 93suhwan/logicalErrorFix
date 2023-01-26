#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int A[N];
int side[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; ++i) {
    char ch;
    cin >> ch;
    if (ch == 'L')
      side[i] = 0;
    else
      side[i] = 1;
  }
  pair<int, int> last = {-1, -1};
  vector<pair<int, int>> ans;
  int ptr = 1;
  if (side[1] != side[n]) last = {A[1], side[n]}, ++ptr;
  for (int i = 1; i <= n; ++i) {
    int r = i;
    while (r + 1 <= n && side[r + 1] == side[i]) ++r;
    vector<int> V1, V2;
    int flag = 0, len = r - i + 1;
    if (!((r - i + 1) & 1)) {
      if (last.first != -1) {
        if (last.second == side[i])
          V1.push_back(last.first);
        else
          V2.push_back(last.first);
        last = {-1, -1};
        flag = 1;
        --len;
      }
    } else
      flag = 1;
    if (!flag) {
      last = {A[ptr++], side[i]};
      int cnt = len;
      while (cnt) {
        V1.push_back(A[ptr + 1]);
        V2.push_back(A[ptr]);
        ptr += 2;
        cnt -= 2;
      }
    } else {
      V1.push_back(A[ptr++]);
      int cnt = len - 1;
      while (cnt) {
        V1.push_back(A[ptr + 1]);
        V2.push_back(A[ptr]);
        ptr += 2;
        cnt -= 2;
      }
    }
    sort(V1.begin(), V1.end(), greater<int>());
    sort(V2.begin(), V2.end(), greater<int>());
    for (int to : V1) {
      ans.push_back({to, side[i]});
    }
    for (int to : V2) {
      ans.push_back({to, side[i] ^ 1});
    }
    i = r;
  }
  if (last.first != -1) ans.push_back(last);
  for (auto [val, sd] : ans) {
    cout << val << ' ' << (sd == 0 ? 'L' : 'R') << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}

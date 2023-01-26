#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], cnt;
void solve() {
  bool flag = false;
  cnt = 0;
  cin >> n;
  vector<int> ones, ans;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i]) {
      ones.push_back(i);
      cnt++;
    }
  }
  if (cnt & 1) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 1; i < cnt; i += 2) {
    int firstIndex = ones[i - 1], secondIndex = ones[i];
    vector<int> curr;
    for (int j = firstIndex; j < secondIndex; j += 2) {
      if (j + 2 <= secondIndex) {
        int x = a[j] ^ a[j + 1] ^ a[j + 2];
        a[j] = x, a[j + 1] = x, a[j + 2] = x;
        curr.push_back(j);
        ans.push_back(j);
      }
    }
    if ((secondIndex - firstIndex - 1) & 1) {
      flag = true;
      for (int j = (int)curr.size() - 2; j >= 0; j--) {
        ans.push_back(curr[j]);
        int x = a[curr[j]] ^ a[curr[j] + 1] ^ a[curr[j] + 2];
        a[curr[j]] = x, a[curr[j] + 1] = x, a[curr[j] + 2] = x;
      }
    }
  }
  if (!flag) {
    for (int i = 1; i <= n; i++) {
      if (!a[i]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    int firstIndex = i, secondIndex = i;
    while (secondIndex + 1 <= n && a[secondIndex + 1] == 1) {
      secondIndex++;
    }
    if (firstIndex == secondIndex) {
      continue;
    }
    if (firstIndex == 1) {
      for (int j = secondIndex - 1; j >= firstIndex; j -= 2) {
        ans.push_back(j);
      }
    } else {
      for (int j = firstIndex + 1; j < secondIndex; j += 2) {
        ans.push_back(j);
      }
    }
    i = secondIndex;
  }
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

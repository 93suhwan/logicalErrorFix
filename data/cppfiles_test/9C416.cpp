#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int t;
int sum[N];
string str;
int main() {
  cin >> t;
  while (t--) {
    memset(sum, 0, sizeof(sum));
    cin >> str;
    for (auto ch : str) sum[ch - 'a']++;
    int ans = 0, cnt = 0;
    for (int i = 0; i < 26; i++) {
      if (sum[i] == 0) continue;
      if (sum[i] >= 2)
        ans++;
      else
        cnt++;
    }
    cout << ans + cnt / 2 << endl;
  }
  return 0;
}

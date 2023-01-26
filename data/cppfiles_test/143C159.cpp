#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a;
  long long c = 0;
  cin >> n;
  vector<long long> cou(n + 1, 0), last;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    cou[a]++;
  }
  for (int i = 0; i <= n; i++) {
    cout << (long long)c + cou[i] << ' ';
    for (int j = 1; j <= cou[i]; j++) last.push_back(i);
    if (last.empty()) {
      for (int j = i + 1; j <= n; j++) cout << "-1 ";
      break;
    } else {
      c = c + i - last.back();
      last.pop_back();
    }
  }
  cout << '\n';
}
short test;
int main() {
  cin >> test;
  for (short i = 1; i <= test; i++) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
bool gone[M];
void solve() {
  long long pl;
  cin >> pl;
  long long race[5][pl];
  for (long long i = 0; i < pl; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> race[j][i];
    }
  }
  bool judge[pl];
  for (long long i = 0; i < pl; i++) {
    judge[i] = true;
  }
  for (long long i = 0; i < pl - 1; i++) {
    for (long long j = i + 1; j < pl; j++) {
      long long cnt1 = 0;
      if (judge[i] == false && judge[j] == false) continue;
      for (long long k = 0; k < 5; k++) {
        if (race[k][i] < race[k][j]) cnt1 += 1;
      }
      if (cnt1 >= 3) {
        judge[j] = false;
      } else {
        judge[i] = false;
        break;
      }
    }
    if (judge[i] == true) break;
  }
  long long ans = -1;
  for (long long i = 0; i < pl; i++) {
    if (judge[i] == true) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long freq = 1;
  cin >> freq;
  while (freq--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
bool gone[M];
void solve() {
  long long p2;
  cin >> p2;
  long long race[5][p2];
  for (long long i = 0; i < p2; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> race[j][i];
    }
  }
  long long len2 = p2;
  bool judge[p2];
  long long len1 = p2;
  for (long long i = 0; i < p2; i++) {
    judge[i] = true;
  }
  long long pos = 0;
  long long pos1 = 0;
  bool fjudge = true;
  while (true) {
    pos1 = pos;
    for (long long i = pos + 1; i < p2; i++) {
      long long cnt1 = 0;
      for (long long k = 0; k < 5; k++) {
        if (race[k][pos] < race[k][i]) cnt1 += 1;
      }
      if (cnt1 >= 3) {
        judge[i] = false;
        if (i == (p2 - 1)) {
          fjudge = false;
          break;
        }
      } else {
        judge[pos] = false;
        pos = i;
        break;
      }
    }
    if (fjudge == false || pos == (p2 - 1)) break;
    if (judge[pos1] == true) break;
  }
  bool result = true;
  for (long long i = 0; i < p2; i++) {
    if (i == pos) continue;
    long long cnt1 = 0;
    for (long long k = 0; k < 5; k++) {
      if (race[k][pos] < race[k][i]) cnt1 += 1;
    }
    if (cnt1 < 3) {
      result = false;
      break;
    }
  }
  if (result == false) {
    cout << -1 << "\n";
  } else {
    cout << (pos + 1) << "\n";
  }
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

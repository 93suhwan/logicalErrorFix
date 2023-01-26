#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int xyz = 1;
const int N = 2e1 + 6;
const int M = 1e6 + 0;
const int inf = 9e17;
const int mod = 998244353;
int n;
int arr[N][N];
int cnt[(1 << 23)][N];
void run() {
  cin >> n;
  vector<string> inp(n);
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
    for (char c : inp[i]) {
      arr[i][c - 'a']++;
    }
  }
}
signed main() {
  setIO();
  while (xyz--) run();
  return 0;
}

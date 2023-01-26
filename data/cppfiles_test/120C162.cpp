#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
vector<long long> ans;
bool gone[M];
int pre1[300000][32];
void pre() {
  for (long long i = 1; i <= 200000; i++) {
    long long num1 = i;
    long long pos1 = 0;
    while (num1 != 0) {
      pre1[i][pos1] = num1 % 2 + pre1[i - 1][pos1];
      pos1++;
      num1 = num1 / 2;
    }
  }
}
void solve() {
  long long num1, num2;
  cin >> num1 >> num2;
  int max1 = INT_MIN;
  for (long long i = 0; i < 32; i++) {
    max1 = max(pre1[num2][i] - pre1[num1 - 1][i], max1);
  }
  cout << num2 - num1 + 1 - max1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  long long freq = 1;
  cin >> freq;
  while (freq--) {
    solve();
  }
}

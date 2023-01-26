#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
vector<long long> ans;
bool gone[M];
void solve() {
  long long num1, num2;
  cin >> num1 >> num2;
  long long num3 = num2 - num1 + 1;
  long long cnt1 = 0;
  for (long long i = num2; i != 0; i = i / 2) {
    cnt1 += 1;
  }
  long long val1 = pow(2, cnt1 - 1);
  long long val2 = pow(2, cnt1 - 2);
  cnt1 = num2 - val1 + 1;
  cnt1 = max(cnt1, (num3 + 1) / 2);
  cout << num3 - cnt1 << "\n";
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

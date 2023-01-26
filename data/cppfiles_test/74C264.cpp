#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
bool gone[M];
long long dp[M];
int decimalToBinary(int N) {
  unsigned long long B_Number = 0;
  int cnt = 0;
  while (N != 0) {
    int rem = N % 2;
    unsigned long long c = pow(10, cnt);
    B_Number += rem * c;
    N /= 2;
    cnt++;
  }
  return B_Number;
}
void solve() {
  set<long long> s1;
  long long p1, p2;
  cin >> p1 >> p2;
  long long sum = p1 + p2;
  long long val1 = sum / 2;
  long long val2 = sum - val1;
  for (long long i = 0; i <= min(p1, val2); i++) {
    if (p1 - i <= val1) {
      s1.insert(p1 - i + val2 - i);
    }
  }
  for (long long i = 0; i <= min(p1, val1); i++) {
    if (p1 - i <= val2) {
      s1.insert(p1 - i + val1 - i);
    }
  }
  cout << s1.size() << "\n";
  for (auto e : s1) {
    cout << e << " ";
  }
  cout << "\n";
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

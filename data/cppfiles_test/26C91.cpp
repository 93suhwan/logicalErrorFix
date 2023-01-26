#include <bits/stdc++.h>
using namespace std;
const int N = 200023;
long long int fact[N];
bool mysort(const pair<long long int, long long int> &a,
            const pair<long long int, long long int> &b) {
  if (a.second < b.second)
    return 1;
  else if (a.second == b.second)
    return (a.first < b.first);
  else
    return 0;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2) return (a * power(a, b - 1)) % 1000000007;
  long long int x = power(a, b / 2);
  return (x * x) % 1000000007;
}
long long int modInverse(long long int a) { return power(a, 1000000007 - 2); }
void calc() {
  fact[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
void solve() {
  long long int n;
  cin >> n;
  cout << (fact[2 * n] * modInverse(2)) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int Test;
  Test = 1;
  calc();
  cin >> Test;
  long long int t = 0;
  while (t++ < Test) {
    solve();
    cout << endl;
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}

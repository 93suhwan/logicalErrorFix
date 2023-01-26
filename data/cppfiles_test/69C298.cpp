#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void read_input() {}
const long long int N = 1e18;
long long int helper(string a, string b) {
  long long int n = b.size();
  int j = 0;
  for (int i = 0; i < n && j < a.size(); i++) {
    if (a[j] == b[i]) {
      j++;
    }
  }
  return b.size() - j + (a.size() - j);
}
void solving() {
  long long int n;
  cin >> n;
  string second = to_string(n);
  long long int v = 1;
  long long int ans = 1e18;
  while (v <= N) {
    string str = to_string(v);
    ans = min(ans, helper(str, second));
    v *= 2;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solving();
  }
  return 0;
}

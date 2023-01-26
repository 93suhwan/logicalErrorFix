#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 200005, mod = pow(10, 9) + 7;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void create_array(vector<long long int>& a) {
  for (long long int i = 1;; i++) {
    if (i % 3 != 0 and i % 10 != 3) {
      a.push_back(i);
    }
    if (a.size() == 1000) break;
  }
}
void solve(vector<long long int>& a) {
  long long int k;
  cin >> k;
  cout << a[k - 1] << endl;
}
int main() {
  fast();
  long long int t = 1;
  vector<long long int> a;
  create_array(a);
  cin >> t;
  while (t--) {
    solve(a);
  }
  return 0;
}

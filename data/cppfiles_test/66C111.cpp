#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
vector<int> A(1005);
int intial = 0;
int i = 1;
void pre() {
  while (intial < 1000) {
    if (i % 3 != 0 && i % 10 != 3) {
      A[intial] = i;
      intial++;
    }
    i++;
  }
}
void solve() {
  int k;
  cin >> k;
  cout << A[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

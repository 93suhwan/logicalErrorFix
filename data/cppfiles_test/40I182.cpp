#include <bits/stdc++.h>
using namespace std;
int mina = 0x3f3f3f3f;
long long int MINI = 1e9 + 1;
int c1[10000000];
int c2[10000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n), v2(n);
    for (auto &i : v) cin >> i;
    for (auto &i : v2) cin >> i;
    for (long long int i = 0; i < n; i++) {
      c1[i + 1] = v[i] + c1[i];
    }
    for (long long int i = 0; i < n; i++) {
      c2[i + 1] = v2[i] + c2[i];
    }
    long long int m = 0;
    vector<long long int> k;
    for (long long int i = 0; i < n; i++) {
      long long int alice = c1[i + 1] + (c2[n] - c2[i]);
      long long int b1 = c1[n] - c1[i + 1];
      long long int b2 = c2[i];
      long long int fbob = max(b1, b2);
      if (fbob < alice) k.push_back(fbob);
    }
    sort(k.begin(), k.end());
    if (k.size() == 1)
      cout << k[0];
    else
      cout << k[0] << endl;
  }
  return 0;
}

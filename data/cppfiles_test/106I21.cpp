#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cin.tie(NULL);
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fastio();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    if (n == 1)
      cout << 1 << endl;
    else {
      long long int start = 111;
      v.push_back(start);
      for (long long int i = 1; i < n; i++) {
        v.push_back(v[i - 1] * 10 + 1);
      }
      for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
      cout << endl;
    }
  }
  return 0;
}

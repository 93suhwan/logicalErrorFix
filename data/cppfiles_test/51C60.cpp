#include <bits/stdc++.h>
using namespace std;
vector<long long> c;
vector<long long> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long l, r;
    l = n - 1;
    r = n;
    l = l * -1;
    cout << l << " " << r << endl;
  }
  return 0;
}

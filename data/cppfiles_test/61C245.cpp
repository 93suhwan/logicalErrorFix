#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int long long t;
  cin >> t;
  int long long n;
  while (t--) {
    cin >> n;
    int long long a[n], b[n];
    map<int long long, int long long> first;
    map<int long long, int long long> second;
    for (int long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      first[a[i]]++;
      second[b[i]]++;
    }
    int long long finans = n * (n - 1) * (n - 2) / 6;
    for (int long long i = 0; i < n; i++) {
      finans -= (first[a[i]] - 1) * (second[b[i]] - 1);
    }
    cout << finans << endl;
  }
  return 0;
}

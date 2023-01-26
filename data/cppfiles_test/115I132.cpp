#include <bits/stdc++.h>
const int MAXN = 1e6;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unsigned long long n, h;
    cin >> n >> h;
    unsigned long long arr[n];
    set<unsigned long long, greater<unsigned long long>> s;
    vector<unsigned long long> v(n - 1);
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      if (j > 0) {
        s.insert(arr[j] - arr[j - 1]);
      }
    }
    v.assign(s.begin(), s.end());
    unsigned long long min = ceil((float)h / n);
    int temp = n;
    for (int j = n - 2; j >= 0; j--) {
      if (v[j] < min) {
        h -= v[j];
        temp--;
        min = ceil((float)h / temp);
      }
    }
    cout << min << endl;
  }
}

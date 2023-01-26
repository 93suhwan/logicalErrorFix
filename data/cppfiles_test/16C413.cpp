#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int NINF = -1e18;
using pii = pair<long long int, long long int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string second;
    cin >> second;
    string s1 = second;
    sort(second.begin(), second.end());
    long long int m = 0;
    for (int i = 0; i < s1.length(); i++) {
      if (second[i] != s1[i]) m++;
    }
    cout << m << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int k;
    cin >> n >> k;
    vector<int> vect;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      vect.push_back(a);
    }
    sort(vect.begin(), vect.end());
    unsigned long long int score = 0;
    int begin, end;
    int maxn[k];
    for (int i = 0; i < k; i++) {
      score += ((vect[vect.size() - 1 - i - k]) / vect[vect.size() - 1 - i]);
    }
    for (int i = vect.size() - 1 - (2 * k); i >= 0; i--) {
      score += vect[i];
    }
    cout << score << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    set<long long> need;
    for (int i = 1; i <= n; i++) need.insert(i);
    vector<long long> rem;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (need.find(x) != need.end())
        need.erase(x);
      else
        rem.push_back(x);
    }
    sort(rem.begin(), rem.end());
    int fl = 0;
    long long count = 0;
    for (int i = 0; i < rem.size(); i++) {
      long long curr = rem[i];
      long long maxP = (curr - 1) / 2;
      auto it = need.begin();
      long long currNeed = *it;
      if (currNeed > maxP) {
        fl = 1;
        break;
      } else {
        need.erase(currNeed);
        count++;
      }
    }
    if (fl == 1)
      cout << "-1\n";
    else
      cout << count << "\n";
  }
  return 0;
}

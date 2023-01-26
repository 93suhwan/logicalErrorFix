#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n], x = 0, y = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<pair<long long, long long> > disliked;
    vector<pair<long long, long long> > liked;
    for (i = 0; i < n; i++) {
      if (s[i] == '1')
        liked.push_back(make_pair(a[i], i));
      else
        disliked.push_back(make_pair(a[i], i));
    }
    sort(liked.begin(), liked.end());
    sort(disliked.begin(), disliked.end());
    for (i = 0; i < n; i++)
      if (s[i] == '0') disliked[x].first = (x++) + 1;
    for (i = 0; i < n; i++)
      if (s[i] == '1') liked[y].first = 1 + (y++) + x;
    sort(disliked.begin(), disliked.end(), sortbysec);
    sort(liked.begin(), liked.end(), sortbysec);
    x = 0, y = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '1')
        cout << liked[x++].first << " ";
      else
        cout << disliked[y++].first << " ";
    }
    std::cout << endl;
  }
}

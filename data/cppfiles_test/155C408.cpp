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
    long long a[n], x, y;
    for (i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<pair<long long, long long> > disliked;
    vector<pair<long long, long long> > liked;
    for (i = 0; i < n; i++) {
      if (s[i] == '0')
        disliked.push_back(make_pair(a[i], i));
      else
        liked.push_back(make_pair(a[i], i));
    }
    sort(liked.begin(), liked.end());
    sort(disliked.begin(), disliked.end());
    x = 0, y = 1;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        disliked[x].first = y;
        x++;
        y++;
      }
    }
    x = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        liked[x].first = y;
        y++;
        x++;
      }
    }
    sort(disliked.begin(), disliked.end(), sortbysec);
    sort(liked.begin(), liked.end(), sortbysec);
    x = 0, y = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        cout << disliked[x].first << " ";
        x++;
      } else if (s[i] == '1') {
        cout << liked[y].first << " ";
        y++;
      }
    }
    std::cout << endl;
  }
  return 0;
}

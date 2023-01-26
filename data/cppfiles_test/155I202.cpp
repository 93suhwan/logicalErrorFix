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
    long long a[n], rating[n], x, y;
    for (i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    long long q = stoi(s);
    for (i = n - 1; i >= 0; i--) {
      rating[i] = q % 10;
      q = q / 10;
    }
    vector<pair<long long, long long> > disliked;
    vector<pair<long long, long long> > liked;
    for (i = 0; i < n; i++) {
      if (rating[i] == 0)
        disliked.push_back(make_pair(a[i], i));
      else
        liked.push_back(make_pair(a[i], i));
    }
    sort(liked.begin(), liked.end());
    sort(disliked.begin(), disliked.end());
    x = 0, y = 0;
    for (i = 0; i < n; i++)
      if (rating[i] == 0) disliked[x].first = (x++) + 1;
    for (i = 0; i < n; i++)
      if (rating[i] == 1) liked[y].first = 1 + (y++) + x;
    sort(disliked.begin(), disliked.end(), sortbysec);
    sort(liked.begin(), liked.end(), sortbysec);
    x = 0, y = 0;
    for (i = 0; i < n; i++) {
      if (rating[i] == 0)
        cout << disliked[x++].first << " ";
      else if (rating[i] == 1)
        cout << liked[y++].first << " ";
    }
    std::cout << endl;
  }
}

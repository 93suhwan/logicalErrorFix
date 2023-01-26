#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#ifdef ROHIT_SYS
#include "headers/debug.hpp"
#endif

 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  #ifdef ROHIT_SYS
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  int t;
  cin >> t;
  while(t--) {
    int n, k, ai;
    cin >> n;

    vector<pair<int, int>> cave(n);
    vector<int> v;
    for(auto &x:cave) {
      cin >> k;
      int req=INT_MIN;
      for(int i=1; i<=k; i++) {
        cin >> ai;
        req=max(req, ai-i+2);
      }
      x.first=req;
      x.second=k;
    }

    sort(cave.begin(), cave.end(), [](const auto &a, const auto &b) {
      // if(a.first==b.first)
      //   return a.second>b.second;
      // return a.first<b.first;
      return a.first+a.second<b.first+b.second;
    });

    int ans=cave[0].first;
    int cur=cave[0].first+cave[0].second;
    for(int i=1; i<n; i++) {
      ans+=max(0LL, cave[i].first-cur);
      cur=cave[i].first+cave[i].second;
    }
    cout << ans << endl;
  }
 
  return 0;
}


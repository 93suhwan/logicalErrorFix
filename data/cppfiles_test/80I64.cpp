#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orset;

const int N = 1e6 + 10;

int a[N], b[N], p[N], pref[N], suff[N];

void solve(int al, int ar, int bl, int br){
      if(bl > br)
            return;
      int mid = (bl + br) / 2;
      for(int i = al; i <= ar; i ++){
            pref[i] = 0;
            if(i > al)
                  pref[i] = pref[i - 1] + (a[i - 1] > b[mid]);
      }
      for(int i = ar; i >= al; i --){
            suff[i] = (a[i] < b[mid]);
            if(i + 1 <= ar)
                  suff[i] += suff[i + 1];
      }
      int best = al;
      for(int i = al; i <= ar; i ++){
            if(pref[best] + suff[best] > pref[i] + suff[i])
                  best = i;
      }
      p[mid] = best;
      solve(al, best, bl, mid - 1);
      solve(best, ar, mid + 1, br);
}

int main(){
      ios_base :: sync_with_stdio(0);
      cin.tie(0); cout.tie(0);
      int t; cin >> t;
      while(t --){
            int n, m;
            cin >> n >> m;
            for(int i = 1; i <= n; i ++)
                  cin >> a[i];
            for(int i = 1; i <= m; i ++)
                  cin >> b[i];
            a[n + 1] = INT_MAX;
            sort(b + 1, b + m + 1);
            solve(1, n + 1, 1, m);
            vector<int> c;
            int pt = 1;
            for(int i = 1; i <= n + 1; i ++){
                  while(pt <= m && p[pt] <= i){
                        c.push_back(b[pt]);
                        ++ pt;
                  }
                  if(i <= n)
                        c.push_back(a[i]);
            }
            orset s;
            reverse(c.begin(), c.end());
            ll result = 0;
            for(int x : c){
                  result += s.order_of_key(x);
                  s.insert(x);
            }
            cout << result << "\n";
      }
}

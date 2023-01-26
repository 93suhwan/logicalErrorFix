#include<bits/stdc++.h>
using namespace std;
// #define int int
// when you got tle but tc is right do this and make as global as possible
#define endl "\n"   
// const int MAX =1000000000000000000;
int mod= 1000000000;
long double pi=3.141592653589793238;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
}
/*   DON'T STUCK ON SINGLE APPROACH AND ALWAYS STUCK ON QUESTION :)*/
/*
dfs+ query at same time
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> os;
/*
  like the set(unique and sorted value)
  os.insert()

    // value at 3rd index in sorted array.
    
    *p.find_by_order(3);  (index start from 0 so 3rd mean 4th element)
  
    // index of number 6 (which exist in set currently)

    p.order_of_key(6)
  
    // number 7 not in the set but it wiint show the 
    // index number if it was there in sorted array.
    
    p.order_of_key(7)

*/
const int N=1e6+2;
os st;
unordered_map<int,int> cnt;
int val[N];
int ans[N];
vector<pair<pair<int,int>,int>> mp[N];
vector<int> g[N];
void dfs(int ix)
{
      if(cnt.find(val[ix])==cnt.end())
      {
          cnt[val[ix]]++;
          st.insert({1,val[ix]});
      }
      else
      {
          st.erase({cnt[val[ix]],val[ix]});
          cnt[val[ix]]++;
          st.insert({cnt[val[ix]],val[ix]});
      }

      for(auto &x: mp[ix])
      {
          int ixx=x.second;
          int l=x.first.first;
          int k=x.first.second;

          int startpoint=st.order_of_key({l,-1});
          if(startpoint==st.size())
          {
             ans[ixx]=-1;
          }
          else
          {
             int ix2=startpoint+k-1;
             if(ix2>=st.size())
             {
                ans[ixx]=-1;
             }
             else
             {
                ans[ixx]=(*st.find_by_order(ix2)).second;
                // cout<<ix<<" "<< (*st.find_by_order(ix2)).first<<" "<<(*st.find_by_order(ix2)).second<<endl;
             }
          }
      }

      for(auto x: g[ix])
      {
          dfs(x);
      }

      pair<int,int> cur={cnt[val[ix]],val[ix]};
      cnt[val[ix]]--;
      if(cnt[val[ix]]==0)
      {
         cnt.erase(val[ix]);
         st.erase(cur);
      }
      else
      {
         st.erase(cur);
         st.insert({cnt[val[ix]],val[ix]});
      }
}
void solve()
{  
   int t;cin>>t;while(t--)
   {
          int n,q; cin>>n>>q;
          st.clear();
          cnt.clear();
          
          for(int i=0;i<n;i++)
          {
            cin>>val[i];
            g[i].clear();
          }
          for(int i=0;i<q;i++)
          {
             mp[i].clear();
          }
          
          for(int i=0;i<n-1;i++)
          {
             int p;cin>>p;p--;
             g[p].push_back(i+1);
          }
          
          for(int i=0;i<q;i++)
          {
               int v,l,k; cin>>v>>l>>k;
               v--;
               mp[v].push_back({{l,k},i});
          }
          
          dfs(0);
          for(int i=0;i<q;i++)
          {
            cout<<ans[i]<<" ";
          }
          cout<<endl;
   }
}
int main(){pls(); solve(); return 0;}
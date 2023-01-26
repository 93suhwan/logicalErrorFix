#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll                      long long
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define afo(i,x)                for(auto &i:x)
#define vi                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvi                    vector<vi>
#define mod                     1000000009
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve(){ 
  int n,k;
  cin>>n>>k;

  int a[n];
  unordered_map<int,int>x;
  fo(i,0,n-1)
  {
    cin>>a[i];
    x[a[i]]++;
  }

  int ans[n];
  // set<int>z;
  unordered_map<int,int>col;
  unordered_map<int,int>go,comp;
  // vi remcol;
  int rem=0;
  afo(i,x)
  {
    if(i.second>=k)
      col[i.first]=1;
    else if (i.second>1)
    {
      go[i.first]=i.second;
      comp[i.first]=1;
      rem+=i.second;
    }  
    else
      rem++;
  }

  vi b;
  b.resize(n,-1);

  set<int>s,notfull;
  int remcolor=1;

  // afo(i,go)
  // {
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  fo(i,0,n-1)
  {
    if(col[a[i]]>0 and col[a[i]]<=k)
    {
      b[i]=col[a[i]];
      col[a[i]]++;
    }
    else if(col[a[i]]>0)
    {
      b[i]=0;
    }
    else if(go[a[i]]>0 and s.find(a[i])==s.end())
    {
      if((remcolor==1 and (rem)>=k) or (remcolor!=1 and remcolor>0))
      {
        int diff=remcolor+x[a[i]]-1;
        if(diff>k)
          diff-=k;
        
        if(rem-x[a[i]]+diff>=k)
        {
          go[a[i]]=remcolor;
          b[i]=go[a[i]];
          go[a[i]]++;
          remcolor=remcolor+x[a[i]];
          
          if(remcolor>k)
            remcolor-=k;

          if(go[a[i]]>k)
            go[a[i]]=1;
        }
        
        else
        {
          // cout<<rem;
          // cout<<rem-x[a[i]]+diff;
          go[a[i]]=remcolor;
          b[i]=go[a[i]];
          go[a[i]]++;
          notfull.insert(a[i]);
          remcolor=-1;
          // cout<<a[i]<<0<<endl;
        }
      
      }

      else if(rem<k)
      {
        go[a[i]]=0;
        b[i]=go[a[i]];
        remcolor=-1;
        // cout<<1<<endl;
      }

      rem-=x[a[i]];
      s.insert(a[i]);
    }
    else if(s.find(a[i])!=s.end())
    {
      if(go[a[i]]>0)
      {
        b[i]=go[a[i]];
        go[a[i]]++;
        if(go[a[i]]>k and notfull.find(a[i])==notfull.end())
          go[a[i]]-=k;
        else if(go[a[i]]>k)
          go[a[i]]=0;
      }
      else
      {
        b[i]=0;
      }
    }

  }

  // cout<<remcolor<<endl;
  if(rem>0)
  {
    fo(i,0,n-1)
    {
      if(b[i]==-1 and remcolor>0 and remcolor+rem-1>=k)
      {
        b[i]=remcolor;
        remcolor++;
        rem--;
        if(remcolor>k and rem>=k)
        {
          remcolor=1;
        }
        else if(remcolor>k)
        {
          remcolor=-1;
        }
      }
      else if(b[i]==-1)
      {
        b[i]=0;
      }
    }
  }
  fo(i,0,n-1)
  {
    cout<<b[i]<<" ";
  }

  cout<<endl;

}

signed main() {
 
  FIO
  INPUT();
  int t;
   t = 1;
  cin >> t;
  fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}
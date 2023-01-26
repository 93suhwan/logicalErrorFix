#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
  int n,m;
  cin>>n>>m;
  int a[n*m];
  map<int,vector<int>> mp;
  for(int i=0;i<n*m;i++)
    cin>>a[i],mp[a[i]].push_back(i);
  int row=0,col=0,arr[n][m];
  while(!mp.empty()){
    vector<int> v=(*mp.begin()).second;
    vector<bool> vis(v.size(),false);
    int done=0;
    mp.erase(mp.begin());
    while(done<v.size()){
      int nxt=min(m,col+(int)v.size()-done)-col;
      int x=row,y=col,temp=done+nxt;
      col+=nxt;
      while(nxt)arr[x][y++]=v[done+ --nxt];
      done=temp;
      if(col==m)col=0,row++;
    }
  } 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); //freopen("op.txt", "w", stdout);
#endif
  int t=1;
  cin>>t;
  while(t--)solve(),cout<<"\n";
  //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
} 
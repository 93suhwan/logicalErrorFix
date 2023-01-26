#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int N=2e5+7;
const int MOD=1e9+7;
int n,a[N],ans;
pair<int,int> res;
map<int,pair<int,int>> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        set<int> se;
        int t=a[i],d=0;
        do{
            if(mp.count(t)){
                if(!se.count(mp[t].second)&&ans<mp[t].first+d){
                    ans=mp[t].first+d;
                    res={mp[t].second,i};
                }
                se.insert(mp[t].second);
                if(mp[t].first<=d){
                    mp[t]={d,i};
                }
            }else mp[t]={d,i};
            if(t==0)break;
            d++;
            if(t==1)t=0;
            else t=(1<<__lg(t-1)+1)-t;
        }while(t>=0);
    }
    cout<<res.first<<" "<<res.second<<" "<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
/*
3
939 683 854
*/
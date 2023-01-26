#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef  long double  ld;
ll inf = 1e19, mod=998244353;

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif

        ll t;cin>>t;
        while(t--){
            ll n,k;cin>>n>>k;
            k=n-k;
            ll arr[n];
            vector<vector<ll>>ans;
            vector<ll> tem;
            for(auto &it:arr)
            cin>>it;

            ll vis[n]={0},flg=0;
            for(ll i=0;i<n;i++){
                if(vis[i])
                continue;
                tem.clear();
                flg=0;
                for(ll j=i;;j=(j+k)%n){
                    if(tem.empty())
                    tem.push_back(j),vis[j]=1;
                    else{
                        if(tem[0]==j){
                        break;}
                        else
                        tem.push_back(j),vis[j]=1;
                    }
                }
                tem.insert(tem.end(), tem.begin(), tem.end());
                // for(auto it1:tem)
                // cout<<it1<<" ";
                ans.push_back(tem);
            }
            ll sum=0,flg1=0,temp=0;


            flg=0;

            // for(auto it:ans){
            //     for(auto it1:it)
            //     cout<<it1<<" ";
            //     cout<<endl;
            // }

            for(auto it:ans){
                flg1=0;
                for(auto it1:it){
                    if(it1==0)
                    {
                        flg1=1;break;
                    }
                }
                if(!flg1){
                flg=1;break;}
                temp=0;
                for(auto it1:it){
                    if(arr[it1]==0)
                    {
                        sum=max(sum,temp);
                        temp=0;
                    }
                    else
                    temp++;
                }
            }

            if(flg)
            cout<<"-1"<<endl;
            else
            cout<<sum<<endl;


        }

        return 0;



}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define inf 1e18
#define mod 1000000007
#include <string.h>

int main()
{
    FIO;
    ll t, n,k,m,cnt;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n][5];
        ll b[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll res1=0;
                ll res2=0;
                for(int k=0;k<5;k++){
                    if(a[i][k]<a[j][k]){
                        res1++;
                    }
                    if(a[i][k]>a[j][k]){
                        res2--;
                    }
                }
                if(res1>=3){
                    b[i]++;
                }
                if(res2<=3){
                    b[j]++;
                }
            }
        }
        bool ok=false;
        for(int i=0;i<n;i++){
            if(b[i]==n-1){
                cout<<i+1<<endl;
                ok=true;
                break;
            }
        }
        if(ok==false){
            cout<<-1<<endl;
        }


    }

    return 0;
}

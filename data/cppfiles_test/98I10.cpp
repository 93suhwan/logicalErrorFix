#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define mod 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll binpow(ll a,ll b){ll result=1;
    while(b){if(b%2==1) result=result*a%mod; a=a*a%mod; b/=2;} return result;}
int main() {
    IOS
    ll t; cin>>t; while(t--)
    {
        string temp;
        getline(cin,temp);
        ll cnt=0;
        string str,s;
        cin>>str;
        cin>>s;
        for(ll i=1;i<s.length();i++)
        {
                ll f;
                f=str.find(s[i])-str.find(s[i-1]);
                if(f<0 && f<=26)
                cnt-=f;
                else if(f>=0 && f<=26) cnt+=f;
            //cout<<cnt<<' ';
        }
        cout<<cnt<<'\n';
    }
    /*ll t; cin>>t;
    for(ll z=1;z<=t;z++){

       cout<<"Case #"<<z<<": ";
    }*/
}
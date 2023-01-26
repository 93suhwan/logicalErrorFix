#include<bits/stdc++.h>
using namespace std;
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define int long long
#define endl '\n'
#define pi 3.141592653589793
#define all(s) s.begin(),s.end()
const int imax=2147483647;
const int imin=-2147483648;
const int mod=1e9+7;
const int N=1e5+10;
bool prime[N];
int factorials[N];
/*-------------------------------------------------------------------------------------------------------------------------------------*/
void IO(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("uttar.txt", "w", stdout);
    #endif
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/
void seive(){memset(prime,true,sizeof(prime));for(int p=2;p*p<=N;p++){if (prime[p] == true){for(int j=p*p;j<=N;j+=p){prime[j]=false;}}}}
void factorial(){factorials[0]=factorials[1]=1;for(int i=2;i<N;i++){factorials[i]=factorials[i-1]*i;}}
int set_bits(int n){if(n==0){return 0;}return (n&1) + set_bits(n>>1);}
void swap(auto &a, auto &b){a^=b;b^=a;a^=b;}
/*-------------------------------------------------------------------------------------------------------------------------------------*/

void kabraji_ka_totka(){
    // totka hai dosto !
    int n;
    cin>>n;
    vector<int> arr(n);
    multimap<int,int> index;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]){
            index.insert({arr[i], i});
        }
    }
    vector<pair<int,int>> mp;
    for(int i=1;i<n;i++){
        mp.push_back({i,i+1});
    }
    cout<<mp.size()<<endl;
    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<endl;
        cout<<it.first<<" "<<it.second<<endl;
    }
}
    
int32_t main(){
    IO();
    int t;t=1;
    cin>>t;
    while(t--){
        kabraji_ka_totka();
    }
    return 0;
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/
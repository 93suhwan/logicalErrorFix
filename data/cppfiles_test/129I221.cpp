#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define rrep(i,st,en) for(ll i=en-1;i>=st;i--)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define debug(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define ff first
#define ss second
#define sz size
#define pb push_back
#define np next_permutation
#define inf 1e18
#define Mod 1000000007
#define set_bits __builtin_popcountll
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
#define nline '\n'
#define endl '\n'
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

void solve(){
    int n;
    cin>>n;

    int a[n];
        
    vector<int> temp;
    int b[n]{0};
    rep(i,0,n){
        cin>>a[i];

        if(b[i]==-1 && a[i]<=n){
            b[i]=a[i];
        }else{
            temp.pb(a[i]);
        }
    }



    sort(all(temp));

    int p1=0;
    rep(i,0,n){
        if(b[i]==0){
            b[i]=temp[p1];
            p1++;
        }
    
    }

    rep(i,0,n){
        a[i]=b[i];
    }
    
    int ans =0;


    rep(i,0,n){
        if(a[i]==i+1){
            continue;
        }

        if((a[i]%(a[i]-(i+1))==i+1)){
            ans++;
        }else{
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t t1=clock();
    int t=1;
    cin>>t;  

    while(t--){ 
        solve();
    }
    cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}

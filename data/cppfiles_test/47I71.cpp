#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define D double
#define mod 1000000007
#define P(t1,t2) pair<t1,t2>
#define pi 3.14159265358979323846
#define ss stringstream
#define V(t) vector<t>
#define VP(t1,t2) vector<pair<t1,t2>>
#define PQ(t) priority_queue<t>
#define PQP(t1,t2) priority_queue<pair<t1,t2>>
#define pb push_back
#define pob pop_back
#define bs binary_search
#define mp make_pair
#define lb lower_bound 
#define ub upper_bound 
#define F first 
#define S second 
#define M(t1,t2) unordered_map<t1,t2>
#define SE(t) set<t>
#define in insert
#define er erase
#define mem(i,n) memset(i,n,sizeof(i))
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORK(i,a,b,k) for(int i=a;i<b;i+=k)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define prec(n) fixed<<setprecision(n) 
#define len(v) v.size() 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define mini(x) *min_element(all(x))
#define maxi(x) *max_element(all(x))
#define LL_MIN 1e12;
using namespace std;

ll lcm(ll x,ll y){
    return x/__gcd(x,y)*y;
}
ll gcd(ll x,ll y){
    return __gcd(x,y);
}  

/* Prime numbers b/w 1 to N*/
// V(ll) primes;
// bool prime[1000001];
// memset(prime,true,sizeof(prime));
// for (int p=2;p*p<=1000000;p++){
//     if (prime[p]==true){
//         for (int i=p*p;i<=1000000;i+=p){
//             prime[i]=false;
//         }
//     }
// }
// for (int p=2;p<=1000000;p++){
//     if (prime[p]){
//         primes.pb(p);
//     }
// }

// ll DigitSum(ll n){
//     ll sum=0;
//     while(n>0){
//         sum+=n%10;
//         n/=10;
//     }
//     return sum;
// }

/*Binary Search*/
// ll BS(ll a[],ll n,ll k){
//     ll s=0,e=n-1;
//     while (s<=e){
//         ll m=s+((e-s)/2);
//         if (k==a[m]){
//             return m;
//         }
//         else if (k<a[m]){
//             e=m-1;
//         }
//         else{
//             s=m+1;
//         }
//     }
//     return -1;
// }

// bool IsPowOfTwo(ll x) {
//     return x && (!(x & (x-1)));
// }

/*To find (a^b)%m*/
// int modularexp(ll a,unsigned ll b,int m){
//     int r=1;
//     a=a%m;
//     if (a==0){
//         return 0; 
//     } 
//     while (b>0){
//         if (b&1){
//             r=(r*a)%m;
//         }
//         b=b>>1;
//         a=(a*a)%m;
//     }
//     return r;
// }

// bool isDigPre(ll x,ll d){
//     while (x>0){
//         if (x%10==d){
//             break;
//         }
// 	    x/=10;
//     }
//     return (x>0);
// }

// V(int) FindDiv;
// void FindDiv(ll n){
//     for (int i=1;i*i<n;i++) {
//         if (n%i==0){
//             FindDiv.pb(i);
//         }
//     }
//     for (int i=sqrt(n);i>=1;i--){
//         if (n%i==0){
//             FindDiv.pb(n/i);
//         }
//     }
// }
// rep(i,n+1){
//     if (i==d || isDigPre(i,d)){
//         cout<<i<<" ";
//     }
// }

/* Depth First Search */
// void DFS(ll u, V(V(ll)) &G, V(ll) &vn){
//     vn[u]=1;
//     for (auto x:G[u]){
//         if (!vn[x]){
//             DFS(x,G,vn);
//         }
//     }
// }

void Solve(){
    ll n,k,ans=0,x,y;
    cin>>n>>k;
    V(ll) pos,neg;
    ll a[n];
    rep(i,n){
        cin>>a[i];
        if (a[i]>0){
            pos.pb(a[i]);
        }
        else{
            neg.pb((-1)*a[i]);
        }
    }
    sort(all(pos));
    sort(all(neg));
    if (len(pos)!=0){
        if (len(pos)<k){
            ans+=pos[len(pos)-1];
        }
        else{
            x=pos[len(pos)-1];
            rep(i,len(pos)){
                if (i==len(pos)-1){
                    ans+=pos[i];
                }
                else if ((len(pos)-i-1)%k==0){
                    ans+=pos[i]*2;
                }
            }
        }
    }
    if (len(neg)!=0){
        if (len(neg)<k){
            ans+=neg[len(neg)-1];
        }
        else{
            y=neg[len(neg)-1];
            rep(i,len(neg)){
                if (i==len(neg)-1){
                    ans+=neg[i];
                }
                else if ((len(neg)-i-1)%k==0){
                    ans+=neg[i]*2;
                }
            }
        }
    }
    ans+=min(x,y);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout); 
    #endif 
    int t=1;
    cin>>t;
    FOR(T,1,t+1){
        Solve();
    }
    return 0;
}
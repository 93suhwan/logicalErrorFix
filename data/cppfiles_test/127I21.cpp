/*Abhilash Datta*/
#include<bits/stdc++.h>

#define all(x)      x.begin(),x.end()
#define trav(x)     for(auto& i:x)
#define ll          long long
#define endl        '\n'
#define sp          <<" "<<
#define INF         0x3f3f3f3f
#define sum(a)      accumulate(a,a+n,0)
#define forn(i,n)   for(ll i=0;i<n;i++)   //iterate n times with iterator i (variable)
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
order_of_key(k);
find_by_order(k);
*/

inline ll start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
ll static r = start_up();
 
template<typename T> inline void rsort(T& v){ sort(all(v),greater<ll>()); }

template<typename T> void print(T& v, string end = "\n"){
    trav(v) cout<<i<<" ";
    cout<<end;
} 

inline ll gcd( ll a, ll b){
    return __gcd(a,b);
}

bool is_prime(ll n){
    if(n==1) return false;
    else if(n==2 || n==3) return true;
    else if(n%2==0 || n%3==0) return false;
    else {
        for(ll i=5;i*i<=n;i=i+6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
    }
    return true;
}

inline void swap(ll& a, ll& b){
    ll x = a;
    a = b;
    b = x;
}

inline ll count_setbits(ll n){ return __builtin_popcountll(n); }

inline ll count_trailing_zeros(ll n){ return __builtin_ctzll(n); }

string lltos(ll n){
    stringstream sstr;
    sstr<<n;
    return sstr.str();
}

inline ll lcm(ll a, ll b){ return a*b/__gcd(a,b); }

// ll X = 1e9+7;
ll Pow(ll a,ll b, ll X){
    if(b==1) return a%X;
    ll v = Pow(a,b/2,X)%X;

    if(b%2==0){
        return (v*v)%X;
    }
    else{
        return (((v*v)%X)*a)%X;
    }
}

//Graph
// const ll M = 4e5+1;
// vector<ll> adj[M];
// bool visited[M];

// void dfs(ll v){
//     visited[v] = true;
//     for(auto i:adj[v]) if(!visited[i]) dfs(i);
// }

// void bfs(ll v){
//     stack<ll> stk;
//     stk.push(v);

//     while(!stk.empty()){
//         ll cur = stk.top();
//         stk.pop();
//         visited[cur] = true;

//         for(auto neighbor:adj[cur]){
//             stk.push(neighbor);
//         }
//     }
// }


const ll N = 1e7+1;

bool isPrime[N];
vector<ll> primes;

void prime_calc(){
    fill(isPrime+2, isPrime+N, true);
    for(ll i=2;i*i<N;i++){
        for(ll j =i*i; j<N;j+=i ){
            isPrime[j] = false;
        }
    }
    for(ll i=2;i<N;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

// ll count_digits(ll n){
//     ll count = 0;
//     while(n>0){
//         n = n/10;
//         count++;
//     }
//     return count;
// }

// ll count_pf(ll n){
//     set<ll> pfs;
//     map<ll,ll> exp;
//     for(auto i:primes){
//         while(n%i==0 && i!=1){
//             n /=i;
//             pfs.insert(i);
//             exp[i]++;
//         }
//         if(n==1) break;
//     }
//     ll count = 0;
//     for(auto i:pfs){
//         count += count_digits(i);
//         if(exp[i]>1) count += count_digits(exp[i]);
//     }
//     return count;
// }

// ll MEX(ll a[], ll n){
//     sort(a,a+n);
//     set<ll> s;
//     forn(i,n){
//         s.insert(a[i]);
//     }
//     forn(i,n+1){
//         if(s.find(i)==s.end()){
//             return i;
//         }
//     }
//     return 0;
// }
ll fact(ll n){
    ll f = n;
    while(n--){
        f *= n;
        if(n==1) break;
    }
    return f;
}


int main(int argc, char* argv[]){
    ll t=1;
    cin>>t;  
    
    while(t--){
        string s,t;
        cin>>s>>t;
        map<char,ll> m;
        forn(i,s.size()) m[s[i]]++;

        ll g = 0;
        forn(i,s.size()){
            if(s[i]==t[g]){
                g++;
            }
            if(g>=3) break;
        }
        if(g<3){
            for(auto i:m){
                forn(k,i.second){
                    cout<<i.first;
                }
            }
            cout<<endl;
            continue;
        }

        if(t=="abc"){
            forn(i,m['a']){
                cout<<'a';
            }
            forn(i,m['c']){
                cout<<'c';
            }
            forn(i,m['b']){
                cout<<'b';
            }
            m.erase('a');
            m.erase('b');
            m.erase('c');
            for(auto i:m){
                forn(k,i.second){
                    cout<<i.first;
                }
            }
            cout<<endl;
        }
        else{
            for(auto i:m){
                forn(k,i.second){
                    cout<<i.first;
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}   
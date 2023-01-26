    
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace std;
    using namespace __gnu_pbds; 

    template <typename num_t>
    using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

    #define ll long long
    #define dd long double
    #define scf(n) scanf("%d",&n)
    #define lscf(n) scanf("%lld",&n)
    #define lpri(n) printf("%lld ",n)
    #define pri(n) printf("%d ",(int)n)
    #define prin(n) printf("%d\n",(int)n)
    #define lprin(n) printf("%lld\n",n)
    #define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
    #define show(a) for(auto xy: a) pri(xy); 
 
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define all(x)     x.begin(),x.end()
    #define tc   int tt; scf(tt); while(tt--)
 
    #define inf INT_MAX
    #define ninf INT_MIN
    #define gcd __gcd
    #define bitcount(n) __builtin_popcount(n)
 
    const int M=1e9+7;
    const int N = 2e5+7;
        
    void my_dbg() { cout << endl; }
    template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
    { cout << ' ' << A; my_dbg(B...); }
    #define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)


    int main()
{

    tc{
        int n;
        scf(n);

        vector<int>a(n+1);
        vector<int>t;

        int mx = 0;

        map<int,int>m;        

        rep(i,1,n+1)
        {

            scf(a[i]);

            m[a[i]] = i;

            t.pb(a[i]);
            mx = max(mx,a[i]);
        }

        sort(all(t));

        if(a[n] == mx)
        {
            prin(0);

            continue;
        }

        int ans = inf;

        ans = min(ans, n - m[mx]);

        ans = min(ans,n-m[t[n-2]]+1);

        prin(ans);







    }

   
       

}


   
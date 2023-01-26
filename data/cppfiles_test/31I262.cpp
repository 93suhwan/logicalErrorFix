#include <bits/stdc++.h>
    using namespace std;
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl "\n"
    #define int long long
    #define fore(i, l, r) for(int i = l; i < r; i++)
    #define sz(a) a.size()
    #define x first
    #define y second
    #define rev(s) reverse(s.begin(),s.end())
    #define all(a) (a).begin(), (a).end()
    #define pb push_back
    #define mp make_pair
    #define rloop(n,i) for(int i=n-1;i>=0;i--)
    #define loop1(i,n) for(int i=1;i<=n;i++)
    #define pv(v) for(auto x:v) cout<<x<<" ";
    #define pi pair<int,int>
    #define vi vector<int>
    #define vpi vector<pi>
    #define inf 1e18
    typedef long double ld;
    //const int N=998244353;
    const int N=1e9+7;
    /*----------------------Graph Moves----------------*/
    //const int fx[]={+1,-1,+0,+0};
    //const int fy[]={+0,+0,+1,-1};
    //const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
    //const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
    //const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
    //const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
    /*------------------------------------------------*/
    #define gcd(a, b) __gcd(a, b)
    #define lcm(a, b) ((a)*((b)/gcd(a,b)))


    //fast Expo
    int fastExpo(int aa,int bb) // aa^bb
    {
        int res=1;
        while(bb>0)
        {
            if(bb&1)
            {
                res=(res*aa)%N;
            }
            aa=(aa*aa)%N;
            bb=bb>>1;
        }
        return res;
    }
    // modular multiplicative inverse
    int mmi(int nn)
    {
        return fastExpo(nn,N-2);
    }
    //calculating factorial up to 1e6
    const int ramramaramnamshamnam=1e6+1;
    int facti[ramramaramnamshamnam];
    void facto()
    {
        facti[0]=1;
        fore(i,1,1e6+1)
        {
            facti[i]=(facti[i-1]*i)%N;
        }
    }
    //sieve section
    const int maxii=1e7+1;
    int spf[maxii];
    int prime[maxii];
    //calculating the smallest prime factor
    void sieve()
    {
        //1->prime
        //0->non prime
        prime[2]=1;
        //marking all odd nos since they are potential primes
        for(int i=3;i<=maxii;i+=2) prime[i]=1;
        //time complexity of sieve is n(log(log(n))
        for(int i=3;i*i<=maxii;i+=2)
        {
            //if a prime no is encountered mark all its multiple as zero/non prime
            // if they are already marked as primes
            if(prime[i]==1)
            {
                for(int j=i*i;j<=maxii;j+=i)
                {
                    if(prime[j]==1) prime[j]=0;
                }
            }
        }
    }
    //calculating the smallest prime factors using prime sieve
    void spfac()
    {
        //all even nos have smallest prime factor as 2
        for(int i=2;i<=maxii;i+=2) spf[i]=2;

        for(int i=3;i*i<=maxii;i+=2)
        {
            if(spf[i]==0)
            {
                for(int j=i*i;j<=maxii;j+=i)
                {
                    if(spf[j]==0) spf[j]=i;
                }
            }
        }
        //all primes have itself as the smallest prime factor
        for(int i=2;i<=maxii;i++){
            if(spf[i]==0) spf[i]=i;
        }
    }
    //factorizing using sieve
    //n log(n)

    void fatorSieve(int *arr,int n)
    {
        //FIRST CALL THE SPFAC() FUNCTION IN THE MAIN FN

        for(int i=0;i<n;i++)
        {
            int temp=arr[i];
            //map stores exponents of all prime factors of the number
            map<int,int>mpf;
            while(temp>1)
            {
                int f=spf[temp];
                mpf[f]++;
                temp=temp/f;
            }
        }
    }


    //graph/trees
    vector<int>adj[100001];
    int vis[100001];
    void dfs(int node)
    {
        vis[node]=1;
        for(auto child:adj[node])
        {
            if(vis[child]==0) dfs(child);
        }
    }

    //solve
    void solve() {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int brr[n];

        for(int i=1;i<n;i+=2)
        {
            int a = abs(arr[i-1]);
            int b = abs(arr[i]);

            if(n&1 && i==n-2){
                int c = abs(arr[n-1]);
                b=b+c;
                int l = (a*b)/__gcd(a,b);
                int temp = l/b;
                brr[i-1]=(l/a);
                if(arr[i-1]<0) brr[i-1]*=-1;
                brr[i]=temp;
                if(brr[i]>0) brr[i]*=-1;
                brr[i+1]=temp;
                if(brr[i+1]>0) brr[i+1]*=-1;
            }
            else{
                int l = (a*b)/__gcd(a,b);

                if((arr[i]>0 && arr[i-1]>0) || (arr[i]<0 && arr[i-1]<0)){
                    brr[i]=l/arr[i] , brr[i-1]=l/arr[i-1];
                    if(brr[i-1]<0) brr[i-1]*=-1;
                    if(brr[i]>0)   brr[i]*=-1;

                }else{
                    brr[i]=l/b;
                    brr[i-1]=l/a;
                }
            }

        }
        for(int i=0;i<n;i++) cout<<brr[i]<<" ";
        cout<<endl;
    }
    int32_t main()
    {
        IOS;
        cout << fixed << setprecision(15);
        int T=1;
        cin>>T;
        while(T--) solve();
    }
    //corner cases
    //clear vis or adj
    //overflow
    //empty vector


// //JAI SHREE RAM// //
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
map<int,set<int>> mp;

typedef pair<int, int> pi;

bool is_prime(int n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}



void solve(long long tz)
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		int sum=0;
		vector<int> arr;
		for(int j=i;j<n;j++){
			sum+=a[j];
			arr.push_back(a[j]);
			if(!is_prime(sum))
			{
				if(arr.size()>ans.size())
				{
					ans = arr;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	

}

int  main()
{
    
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input4.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
    long long t;
	t = 1;
    cin>>t;
	long long z = 0;
	while (t--)
	{
	 	z++;
		solve(z);
	}
}


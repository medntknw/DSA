#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int k = 0; k<n-1; k++){
        // (n-k-1) because in each loop we will be placing the elements in order from largest to smallest
        for(int i=0;i<n-k-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("/Users/morph/Desktop/DSA/c++/input.txt", "r", stdin);
        freopen("/Users/morph/Desktop/DSA/c++/output.txt", "w", stdout);
    #endif
    fast_cin();
    solve();
    return 0;
}
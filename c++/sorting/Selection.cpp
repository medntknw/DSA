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
 
int minimum_idx(int *arr, int start, int end){
    int mn = start;
    for(int i = start+1; i<end;i++){
        if (arr[i]<arr[mn]){
            mn = i;
        }
    }
    return mn;
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int mn = minimum_idx(arr, i, n);
        swap(arr[mn], arr[i]);
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
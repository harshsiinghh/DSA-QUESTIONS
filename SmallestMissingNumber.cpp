//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
    const int N = 1e6 + 2;
    bool idx[n];
    for(int i=0;i<n;i++){
        idx[i]=false;
        idx[0]=true;
    }
    for(int i=0;i<n;i++){
        if(array[i]>0){
            idx[array[i]]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(idx[i]==false){
            return i;
            break;
        }
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends

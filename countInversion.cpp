//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
     long long int merge(long long arr[], long long int temp[], long long int left, long long int right, long long int mid)

    {

        int i,j,k; // declared variables for performing merging.

        long long int inversion = 0; // to store the final answer;

        i=left;

        j=mid;

        k=left;



        while(i<=mid-1 && j<=right)

        {

            if(arr[i]<=arr[j])

            temp[k++] = arr[i++]; //simply append arr[i];



            else

            {

                temp[k++] = arr[j++];// append arr[j] and increase the inversions count;

                inversion += (mid-i);

            }

        }



        // check for any residual array



        while(i<=mid-1)

        temp[k++] = arr[i++];



        while(j<=right)

        temp[k++] = arr[j++];



        // store the temp array in the new array

        for(int i=left;i<=right;i++)

        {

            arr[i] = temp[i];

        }



        return inversion;

    }



    long long int mergeSort(long long arr[], long long int temp[], long long int  left, long long int right)

    {

       // declare a variable to store final answer

       long long int inversions = 0;

       long long int mid;

       // now split until right>left, cuz then we have reached the bottom of the tree

       if(right>left)

       {

           mid = (right+left)/2; //split the array from middle

           inversions += mergeSort(arr,temp,left,mid); // perform merge sort for the array from left to mid

           inversions += mergeSort(arr,temp,mid+1,right); // perform merge sort for the array from mid+1 to right

           inversions += merge(arr,temp,left,right,mid+1); // to perform merge operations

       }



       return inversions;



    }



    long long int inversionCount(long long arr[], long long N)

    {
        long long int temp[N];

        long long int high = N-1;

        long long int low = 0;

        long long int ans = mergeSort(arr,temp,low,high);

        return ans;

    }



};




//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}

// } Driver Code Ends

//leet code questions
//problem-1281
// subtract product and sum of digits of number
// Input: n = 234
// Output: 15 
// Explanation: 
// Product of digits = 2 * 3 * 4 = 24 
// Sum of digits = 2 + 3 + 4 = 9 
// Result = 24 - 9 = 15
class Solution {
public:
    int subtractProductAndSum(int n) {
     int sum = 0;
int prod = 1;
while(n>0)
{
    sum += (n % 10);
    prod *= (n % 10);
    n /= 10;
}
        return prod-sum;
        
    }
};


//problem 191
// Number of bits 1
// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
// Input: n = 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n!=0){
            if(n&1){
            ans++;
            }
           n= n>>1;
        }
        return ans;
        
    }
};

// 1009.Compliment of base 10 integer
// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
        int mask=0;
        if (n==0)
            return 1;
        while(m!=0){
            mask=(mask<<1) |1;
                m=m>>1;
            
        }
        int a = (~n)&mask;
        return a;
    }
};




//231. power of two
// Input: n = 16
// Output: true
// Explanation: 24 = 16

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
for(int i=0;i<=30;i++){
    int num=pow(2,i);
    // cout<<num <<endl;
    if(n==num){
        return true;
    }

}
return false;
        
    }
};

//Given an integer n, return true if it is a power of three. Otherwise, return false.

//An integer n is a power of three, if there exists an integer x such that n == 3x.
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod((log10(n) / log10(3)), 1) == 0;

        
    }
};




//7. Reverse Integer
// Input: x = 123
// Output: 321

class Solution {
public:
    int reverse(int x) {
    int a  = 0;
        while( x != 0) {
            
            int digit = x % 10;
            
            if( (a > INT_MAX/10) || (a < INT_MIN/10)) {
                return 0;
            }


            
            a = (a * 10) + digit;
            x = x / 10;
            
        }
        return a;
        
    }
}


// Find Unique element in an array
public class Solution{  

    public static int findUnique(int[] arr){
	    int ans=0;
            for(int i=0,i<size,i++){
                ans=ans^arr[i];
            }
           return ans;
    }
}


//1207. Unique Number of Occurrences
//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.
//Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int size = arr.size();
        int i = 0;
        sort(arr.begin(),arr.end());
        while(i<size){
            int count = 1;
            for(int j =i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(count);
            i = i+count;
        }
        size = ans.size();
        sort(ans.begin(),ans.end());
        for(int i = 0;i<size-1;i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;   
            
    }
};



/*
find first and last position of an element in sorted array
2
6 3
0 5 5 6 6 6
8 2
0 0 1 1 2 2 2 2
*/
#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {
            //Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            //left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
}


/*Peak Index in a Mountain Array
arr[]={0,1,2,1,0}
ans=1


*/

#include<vector>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};




// Book Alloocation problem  //
/*
Given an array arr of integer numbers, where arr[i] represents the number of pages in the ith book.
there are m students and task is to allocate the books to their students in such a way that
1.each student gets atleast one book.
2.each book should be allocated to a student
3.book allocation manner should be contiguous
you have to allocate the book to m students suvh that max number of pages assigned ta a student is minimum. 
Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students)
‘arr = { 12, 34, 67, 90 }’. And ‘m= 2’.
All possible way to allocate the ‘4’ books in ‘2’ number of students is-

12 | 34, 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’ so maximum is ‘max(12, 191)= 191’.
12, 34 | 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’ so maximum is ‘max(46, 157)= 157’.
12, 34, 67 | 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’ so maximum is ‘max(113, 90)= 113’.

So possible maximum number of pages which allocated to a single student is { 191, 157, 113 } 
But you have to return a minimum of this so return ‘min(191,157, 113) =113’.

Hence answer is ‘113’.

*/
bool isPossible(vector<int> arr,int n/*size*/,int m/*number of students*/,int mid){
    int studentcount=1;
    int pagesum=0;

    for (int i = 0; i < n; i++)
    {
        if (pagesum+arr[i]<=mid)    
        {
            pagesum+=arr[i];
        }
        else{
            studentcount++;
            if (studentcount>m || arr[i]>mid)
            {
                return false;
            }
            pagesum=arr[i];
            if (studentcount>m)
            {
                return false;
            }
        }
        return true;
            
            
        }
        
    }
    

int allocatebooks(vector<int> arr,int n/*size*/,int m/*number of students*/){
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(s-e)/2;
    while (s<=e)
    {
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(s-e)/2;
    }
    return ans;
}


////  AGGRESIVE COWS //////
/*
arr[]={4,2,1,3,6}     k=2{no of aggressive cows}
to prevent cow from hurting each other assign such stalls such that minimum distance between any two of them is as large as possible.
Return the largest minimum distance.

*/
bool isPossible(vector<int>&stalls,int k,int mid){
    int cowcount=1;
    int lasspos=stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i]-lasspos>=mid) 
        {
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lasspos=stalls[i];
            
        }
        
    }
    
    return true;
}
int aggresivecoes(vector<int> &stalls,int k){
    sort{stalls.begin(),stalls.end()};
    int s=0;
    int maxi=-1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi=max{maxi,stalls[i]};
    }
    int e=maxi;
    int ans=-1;
    int mid=s+(s-e)/2;
    while (s<=e)
    {
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(s-e)/2;
    }
    return ans;
}





/// Reversing Array ///
/// Reversing Array ///
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> k){
    for (int i = 0; i < k.size() ; i++)
    {
        cout<<k[i] <<" ";
    }
    cout<<endl;
}

vector<int>   reversearray(vector<int> v){
    int s=0,e=v.size()-1;
    while (s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;       

}


int main()
{
    vector<int> v;

    v.push_back(3);   
    v.push_back(30);   
    v.push_back(300);   
    v.push_back(3000);   
    v.push_back(30000);   
    v.push_back(300000); 
   cout<<"array is->";
   print(v);
    cout <<endl;
    vector<int> ans=reversearray(v);
    print(ans);

}

//// merge array ///

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void mergesortedarray(int a[],int n , int b[],int m,int c[]){
    int i=0;int j=0;int k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;

        }else{
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n){
        c[k]=a[i];
            k++;
            i++;
   
    }
    while(j<m){
        c[k]=b[j];
            k++;
            j++;
    }

    }


void print(int ans[], int n) {
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }
    cout << endl;
}


int main()
{
    int a[5]={34,45,51,65,77};
    int b[6]={4,43,53,75,84,93};
    int c[11]={0};
    mergesortedarray(a,5,b,6,c);
    print(c,11);


}   


///// Mpves Zeros ////
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[nonzero]);
                nonzero++;
            }
        }
        
    }
};

///////// ROTATE ARRAYS ????
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
            
        }
        nums=temp;
    }

};




////valid palindrome...
/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.*/

class Solution {
private:
    bool isvalid(char ch){
        if((ch>='a' && ch <='z')||(ch>='A' && ch <='Z')||(ch>='0' && ch <='9')){
            return 1;
        }
        return 0;
    }
    
    char tolowercase(char ch){
        if((ch>='a' && ch <='z')||(ch>='0' && ch <='9')){
            return ch;
        }
        else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }
    
    bool checkpalindrome(string a){
        int s=0;
        int e=a.length()-1;
        while(s<=e){
            if(a[s]!=a[e]){
                return 0;
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
    }
    
    
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int j=0;j<s.length();j++){
            if(isvalid(s[j])){
                temp.push_back(s[j]);
            }
        }
        for(int j=0;j<temp.length();j++){
            temp[j]=tolowercase(temp[j]);
    }
        
        return checkpalindrome(temp);
    }
};


/// romove substring from a string??
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
    return s;      
    }
  
};




// print the matrix element in spiral way

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:  

vector<int> spiralprint(vector<vector<int> > &matrix){

    vector<int> ans;
    int row=matrix.size();
    int col=matrix[0].size();

    int srow=0;
    int scol=0;
    int erow=row-1;
    int ecol=col-1;

    int count=0;
    int total=row*col;

    while(count<total){

    for(int i=scol;count<total && i<=ecol;i++){
    ans.push_back(matrix[srow][i]);
    count++;
    }
    srow++;
    for(int i=srow;count<total && i<=erow;i++){
    ans.push_back(matrix[i][ecol]);
    count++;
    }
    ecol--;
    for(int i=ecol;count<total && i>=scol;i--){
    ans.push_back(matrix[erow][i]);
   count++;
    }
    erow--;
    for(int i=erow;count<total && i>=srow;i--){
    ans.push_back(matrix[i][scol]);
    count++;
    }
    scol++;

    }

    return ans;

}

};



// count number of primes using sieve of Eratosthenes 
class Solution {
public:
    int countPrimes(int n) {
    
        vector<bool> prime(n+1,true);
        
        prime[0]=prime[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
              count++;  
            }
            
            for(int j=2*i;j<n;j+=i){
                prime[j]=0;
                
            }
        }
    return count;
    }
};
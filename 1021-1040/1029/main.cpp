//
// Created by eason on 8/11/17.
//

#include <iostream>

using namespace std;

long int s1[1000010],s2[1000010];

int getIndex(long int* s,int n,long int e){
    int start = 0,end = n;
    if(e<s[start]) return start;
    while(start<end){
        int mid = (start+end)/2;
        if(s[mid]==e) return mid;
        else if(s[mid]<e) start = mid+1;
        else end = mid-1;
    }
    return end;
}

long int getMedian(long int* ss1,long int* ss2,int n,int m){
    int i=0,j=0;
    long int result;
    while(true){
        if(i<n&&ss1[i]<=ss2[j]){
            result = ss1[i];
            i++;
        }else{
            result = ss2[j];
            j++;
        }

        if(i+j>=m) return result;
    }
}

int main(){
    int n,m;
    int midIndex1,midIndex2,midIndex;

    cin >> n;
    midIndex1 = (n+1)/2-1;
    for(int i=0;i<n;i++){
        cin >> s1[i];
    }

    cin >> m;
    midIndex2 = (m+1)/2-1;
    midIndex = (m+n+1)/2-1;
    for(int i=0;i<m;i++){
        cin >> s2[i];
    }

    if(s1[midIndex1]>s2[midIndex2]){
        int index = getIndex(s1,midIndex1,s2[midIndex2]);
        long int median = getMedian(&s2[midIndex2],&s1[index],m-midIndex2,midIndex-midIndex2-index+1);
        cout << median;
    }else if(s1[midIndex1]<s2[midIndex2]){
        int index = getIndex(s2,midIndex2,s1[midIndex1]);
        long int median = getMedian(&s1[midIndex1],&s2[index],n-midIndex1,midIndex-midIndex1-index+1);
        cout << median;
    }else cout << s1[midIndex1] << endl;

    return 0;
}
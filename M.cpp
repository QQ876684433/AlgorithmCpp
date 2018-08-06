//
// Created by steve on 18-8-1.
//

//#include <iostream>
//
//using namespace std;
//
//void quickSort(int s[], int l, int r);
//void printArr(int *arr,int len);
//
//int main() {
//    int N, M;
//    while (cin >> N >> M) {
//        int *nums = new int[N];
//        for (int i = 0; i < N; ++i) {
//            cin >> nums[i];
//        }
//        int n = 1;
//        for (int j = 1; j <= N; ++j) {
//            if (0.5 * j * (j - 1) >= M) {
//                n = j;
//                break;
//            }
//        }
//        quickSort(nums, 0, N - 1);
//        int *output = new int[M];
//        int i = 0;
//        for (int k = N - 1; k > N - 1 - n; k--) {
//            for (int j = k - 1; j > N - 1 - n; j--) {
//                if (i < M) {
//                    output[i] = nums[k] + nums[j];
//                    i++;
//                }
//            }
//        }
//        quickSort(output, 0, M - 1);
//        for (int l = M - 1; l >= 0; l--) {
//            cout << output[l];
//            if (l != 0) cout << " ";
//            else cout << endl;
//        }
//    }
//    return 0;
//}
//
//void quickSort(int s[], int l, int r) {
//    if (l < r) {
//        int i = l, j = r, x = s[l];
//        while (i < j) {
//            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
//                j--;
//            if (i < j)
//                s[i++] = s[j];
//            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
//                i++;
//            if (i < j)
//                s[j--] = s[i];
//        }
//        s[i] = x;
//        quickSort(s, l, i - 1); // 递归调用
//        quickSort(s, i + 1, r);
//    }
//}
//
//void printArr(int *arr,int len){
//    for (int i = 0; i < len; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const int a,const int b){
    return a>b;
}
int a[3010],b[3000*3000/2];
int main(){
    int n,m,i,j,t;
    while(cin>>n>>m){
        for(i=0; i<n; i++)
            cin>>a[i];
        t = 0;
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                b[t++] = a[i]+a[j];

        sort(b,b+n*(n-1)/2,cmp);

        for(i=0; i<m; i++){
            if(!i)
                cout<<b[i];
            else
                cout<<" "<<b[i];
        }
        cout<<endl;
    }
    return 0;
}
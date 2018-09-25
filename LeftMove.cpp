//
// Created by steve on 18-9-24.
//

#include <iostream>
#define SIZE 1000000
using namespace std;

void reverse(int *arr , int begin , int end)
{
    for(int i = begin , j = end ; i < j ; i++ , j--)
    {
        int t;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void function(int *arr , int n , int p)
{
    reverse(arr,0,p-1);
    reverse(arr,p,n-1);
    reverse(arr,0,n-1);
}


void display(int *arr , int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[SIZE];
//    display(arr, SIZE);

    long    i = 10000000L;
    clock_t start, finish;
    double  duration;
    /* 测量一个事件持续的时间*/
    printf( "Time to do %ld empty loops is ", i );
    start = clock();


    function(arr, SIZE, 7);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );

//    display(arr, SIZE);
    return 0;
}



//
//  main.c
//  排序
//
//  Created by pc on 18/3/16.
//  Copyright (c) 2018年 com.aprss.learne. All rights reserved.
//

#include <stdio.h>

int a[100],n;

//插入排序(非降序）
void Insertion_sort1()
{
    for(int i = 1;i < n;i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
    }
}
//插入排序（非升序）
void Insertion_sort2()
{
    for(int i = 1;i < n;i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] < key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
    }
}
//线性查找
void Linear_search()
{
    int t,k = 1;
    printf("Which number is your search?\n");
    scanf("%d",&t);
    for(int i = 0;i < n;i++)
    {
        if (a[i] == t)
        {
            printf("%d\n",i);
            k = 0;
            break;
        }
    }
    if(k)
        printf("NIL\n");
    
}
//选择排序
void Select_sort()
{
    for(int i = 0; i < n-1; i++)
    {
        int min = a[i],min_i = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                min_i = j;
            }
        }
        a[min_i] = a[i];
        a[i] = min;
    }
    
}

//归并排序

void Merge(int a[],int start,int mid,int end)
{
    
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1],right[n2];
    for (int i = 0; i < n1;i++)
        left[i] = a[start + i];
    for (int i = 0; i < n2;i++)
        right[i] = a[mid + i + 1];
    int i = 0,j = 0;
    int k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)                      /* left[] is not exhausted */
        a[k++] = left[i++];
    while (j < n2)                      /* right[] is not exhausted */
        a[k++] = right[j++];
}

void Merge_sort(int a[],int p,int r)
{
    if(p < r)
    {
        int q =(r + p)/2;
        Merge_sort(a,p,q);
        Merge_sort(a,q+1,r);
        Merge(a,p,q,r);
    }
}

//二分查找
void Binary_Search(int a[],int p,int r,int t)
{
    if(a[r] == t)
        printf("%d\n",r);
    else
    {
    if(p<r)
    {
        int q = (r+p)/2;
        if (t > a[q])
        {
            Binary_Search(a,q+1,r,t);
        }
        else if(t < a[q])
        {
            Binary_Search(a,0,q,t);
        }
        else
        {
            printf("%d\n",q);
        }
    }
    }
    
}
//冒泡排序
void  Bubble_sort()
{
    for(int i = 0; i < n; i++)
        for(int j = n-1;j > i;j--)
        {
            if(a[j] < a[j-1])
            {
                int b = a[j];
                a[j] = a[j - 1];
                a[j - 1] = b;
            }
        }
}


int main(int argc, const char * argv[])
{
    
    scanf("%d",&n);
    for(int i = 0; i < n;i++)
    {
        scanf("%d",&a[i]);
    }
//    Insertion_sort1();    //插入排序（非升序）
//    Insertion_sort2();    //插入排序（非降序）
//    Linear_search();          //线性查找
//    Select_sort();          //选择排序
//    Merge_sort(a,0,n-1);    //归并排序
//    int t;
//    printf("Which number is your search?\n");
//    scanf("%d",&t);
//    Binary_Search(a,0,n-1,t);  //二分查找
    Bubble_sort();
    for(int i = 0; i < n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

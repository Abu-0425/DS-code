#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <windows.h>

void PrintArray(int *arr, int n);//打印数组

void TestSort(int *arr, int n);//测试排序
void TestQuickSort(int *arr, int left, int right);//测试快排
void TestSortEfficiency();//测试排序算法的效率

#endif

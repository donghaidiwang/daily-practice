#define _CRT_SECURE_NO_WARNINGS 1
#define N 1000000
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
void InsertSort(int* a, int n);//��������
void ShellSort(int* a, int n);//ϣ������
void SelectSort(int* a, int n);//ѡ������
void HeapSort(int* a, int n);//������
void BubbleSort(int* a, int n);//ð������
void QuickSort(int* a,int begin,int end);//��������
void QuickSortNonR(int* a, int begin, int end);//�ǵݹ����
void MergeSort(int* a, int n);//�鲢����
void MergeSortNonR(int* a, int n);//�ǵݹ�鲢����
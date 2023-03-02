 ///
 /// @file    mergesort.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-22 21:33:47
 ///
#include<algorithm> 
#include <iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::sort;

class MergeSort
{
public:	
	//分而治之
	static void mergeSort(int numbers[], int  left, int  right)
	{ 
		//int vector_size = numbers.size();
		while(left < right)
		{
			//cout << "111" << endl;
			int mid = (left + right)/2;
			//cout << mid << "  " ;
			mergeSort(numbers, left , mid);
			mergeSort(numbers,mid+1, right);
			merge(numbers, left, mid, right);
			return ;
		}	
	}

	//合并函数
	static void merge(int numbers[], int  left, int  mid, int  right)
	{
		//cout << "222" << endl;
		int * temp = new int[right-left+1]();
		//cout << "333" << endl;
		int i = left;
		int j = mid + 1;
		int n = 0;
		while(i <= mid && j <= right )
		{
			//cout << "444" << endl;
			if(numbers[i] < numbers[j])
			{
				temp[n++] = numbers[i++];
				cout << "left = " << left << endl;
			}
			else
				temp[n++] = numbers[j++];
			//int m = n - 1 ;
			//cout << "temp[n] = " << temp[m] << " ";
		}
		//cout << "555" << endl;
		//将剩余的加入temp
		while(i<= mid)
		{
			temp[n++] = numbers[i++];
		}
		while(j <= right)
		{
			temp[n++] = numbers[j++];
		}

		int index1 = 0;
		int index2 = left;
		//将temp中有序序列添加到numbers中，之前发生了段错误
		while(index1 <= (right - left))
		{
			numbers[index2++] = temp[index1++];
		}
        delete [] temp;
		//cout << "666" << endl;
	}

};
 
int main(void)
{
	int* numbers = new int[20]{3,1,56,4,8,20,12,125,13,5,6,9,7,14,11,8,4,1,12,10};
	//numbers[] = {4,53,6,2,3,7,5,8,9,10,21,13,20,1,15};
    //	cout << numbers.size() << endl;
	//int size = numbers.size();
	MergeSort::mergeSort(numbers, 0, 19);
	for(int index = 0 ;index < 20; ++index)
	{
		cout << numbers[index] << " ";
	}
	cout << endl;
	return 0; 
}

 ///
 /// @file    HeapSort.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-23 19:55:48
 ///
 
#include <iostream>
#include<array>
using std::cout;
using std::endl;
using std::array;
class HeapSort
{
public:
	//堆排序
	static void heapSort(int numbers[] , int last)
	{ 
		buildHeap(numbers, last); //建大顶堆
		for(int index_last = last ; index_last >= 1; --index_last)
		{
			swap(numbers[0],numbers[index_last]);
			//cout << " index_last" << index_last << endl;
			adjustHeap(numbers, index_last - 1, 0);//出堆后。向下调整
		}
	}
	// swap();
	static void swap(int & x, int & y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	//建大顶堆
	static void buildHeap(int numbers[], int last)
	{
		for(int i = (last-1)/2; i >= 0; --i)
		{
			adjustHeap(numbers, last, i);
		}
	}
	//调整
	static void adjustHeap(int numbers[], int last, int index)
	{
		int maxidx = index; //存放父节点，左右孩子节点三者最大的下标值
		int index_lchild = index*2 + 1;
		int index_rchild = index*2 + 2;  //从零开始的规律,与二叉树从1开始有所区别

		if(index_lchild <= last && numbers[index_lchild] > numbers[maxidx]) maxidx = index_lchild;
		if(index_rchild <= last && numbers[index_rchild] > numbers[maxidx]) maxidx = index_rchild; //得到最大值的下标
		if(maxidx != index) 
		{
			swap(numbers[index], numbers[maxidx]);
			adjustHeap(numbers, last, maxidx); //往下继续调整成大顶堆
		}
	}
//		if(index_rchild <= last)
//		{
//			if(numbers[index_lchild] > numbers[index_rchild] && numbers[index_lchild] > numbers[i])
//			{
//				swap(numbers[i], numbers[index_lchild]);
//				
//			}
//			else if(numbers[index_rchild] >= numbers[index_lchild] && numbers[index_rchild] > numbers[i])
//				swap(numbers[i], numbers[index_rchild]);
//		}
//		else if(numbers[index_lchild] > numbers[i] && index_lchild <= last && index_rchild > last)
//				swap(numbers[i], numbers[index_lchild]);
	
};
int main(void)
{
	int array[15] = {5,2,8,12,6,9,8,3,1,15,10,11,7,14,13};
	HeapSort::heapSort(array, 14);

	for(int index = 0 ; index < 15; ++index)
		cout << array[index] << " " ;
	cout << endl;
	return 0;
}

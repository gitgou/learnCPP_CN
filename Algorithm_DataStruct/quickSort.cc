 ///
 /// @file    QuickSort.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-23 17:06:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class QuickSort
{
public:
	static void quickSort(int array[],int low, int high)
	{
		
		while(low < high)
		{
			int part = partition(array, low, high);	
			quickSort(array, low, part-1);
			//cout << "111" << endl;
			quickSort(array, part+1, high);
			//cout << "222" << endl;
			return;
		}
	}

	static int partition(int array[], int low, int high)
	{
		int parter = array[low];
		while(low < high)
		{
			while((low < high) && (parter <= array[high])) 
				--high;
			array[low] = array[high];
		//	cout << "high = " << high << " " ;
			while((low < high && parter >= array[low])) 
				++low;
			array[high] = array[low];
		}
		array[low] = parter;
		cout << low << endl;
		return low;
	}

};
int main(void)
{
    int *array = new int[15]{5,2,5,1,7,9,35,21,4,6,9,7,10,12,11};
	//cout <<"111" << endl;
	QuickSort::quickSort(array, 0, 14);
	//cout << "222" << endl;
	for(int i = 0; i < 15; ++i)
		cout << array[i] << " " ;
	cout << endl;
}

#include<iostream>
using namespace std;
#define TT_ERROR -1
int binary_search(const int *const arr, const int array_size, const int key)
{
	if ((arr == nullptr) || (array_size == 0))
	{
		return TT_ERROR;
	}
	int left(0);   //数组的首位置，即data[0]处
	int right = array_size - 1;   //数组的最后一个位置，即data[n-1],数组大小为array_size
	while (left <= right)
	{
		//int mid = (left + right) / 2;//array_size为偶数，取靠左的那个(当left和right比较大时，二者之和可能会溢出)  
		int mid = left + ((right - left) >> 1);/*此处的mid的计算一定要放在while循环内部，
											   否则mid无法正确更新;并且此处用移位代替除以2可以提高效率，
											   而且可以防止溢出。*/
		if (arr[mid] > key)
		{
			right = mid - 1;   // 赋值给right， 是因为能够把mid右边的数给排除，然后最后一个数字是mid前一个数字
		}
		else if (arr[mid] < key)  
		{
			left = mid + 1;  //  赋值给left， 是因为能够把mid左边的数给排除，然后第一个数字是mid的后一个
		}
		else
		{
			return mid;

		}

	}
	return TT_ERROR;
}

void print_Array(const int *const arr, const int count)
{
	cout << "\n输出查找前的数据元素：\n";
	for (int j = 0; j < count; ++j)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************欢迎来到来到二分查找的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行二分查找！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "\n请输入你的选择：";
		int choice(0);
		cin >> choice;
		if (choice == 0)
		{
			cout << "程序已退出！" << endl;
			break;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "请输入你想要查找元素列表数组的长度：";
			int list_Length(0);
			cin >> list_Length;
			if (cin >> list_Length && list_Length <= 0)
			{
				cout << "输入错误，请输入正确的数组个数(至少大于0)，否则无法进行排序,请重新输入！" << endl;
				continue;
			}
			int *array = new int[list_Length];
			if (!array)
			{
				cout << "错误，分配数组内存时失败，请重新运行程序！" << endl;
				system("pause");
				exit(0);
			}

			cout << "请分别输入你想要进行查找的" << list_Length << "个元素，分别用回车键分开即可：\n";
			for (int i = 0; i < list_Length; ++i)
			{
				cin >> array[i];
			}
			
			print_Array(array, list_Length);

			int element(0), locate(0);
			cout << "请输入你想要在数组中查找的元素是：";
			cin >> element;
			if ((locate = binary_search(array, list_Length, element)) >= 0)
			{
				cout << "找到元素" << element << ",它在数组中的位置为：" << locate << endl;
			}
			else
				cout << "没有找到你想要查找的元素" << element << "!" << endl;

			delete[]array;
			array = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "屏幕已清屏，可以重新输入！" << endl;
			break;
		default:
			cout << "序号输入错误，请重新输入！" << endl;
		}
	}
	system("pause");
	return 0;
}

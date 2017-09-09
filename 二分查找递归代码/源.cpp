#include<iostream>
using namespace std;
#define TT_ERROR -1
int binary_search(const int *const arr, const int left, const int right, const int key)
{
	if (left <= right)
	{
		int mid = left + ((right - left) >> 1);

		if (arr[mid] > key)
		{
			return binary_search(arr, left, mid - 1, key);  //舍弃右侧
		}
		else if (arr[mid] < key)
		{
			return binary_search(arr, mid + 1, right, key);//舍弃左侧
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
			cout << "\n************************欢迎来到来到二分查找(递归)的世界！**********************\n" << endl
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
			cout << "请输入你想要查找元素列表的长度：";
			int list_Length(0);
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
			if ((locate = binary_search(array, 0, list_Length - 1, element)) >= 0)
			{
				cout << "找到元素" << element << ",它在数组中的位置为：" << locate << endl;
			}
			else
			{
				cout << "没有找到你想要查找的元素" << element << "!" << endl;
			}
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

#include<iostream>
#include<cassert>
using namespace std;
void printElem(const int arr[], const int count)
{
	cout << "输出排序前的元素：\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
}
void swapElem(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int *const arr, const int length)
{
	assert((length > 0));
	int  count = 0;
	for (int i = 1; i < length; ++i)   //length个数排序，只用进行length-1趟,也可以写成int i=0;i<length-1
	{
		for (int j = 0; j < length - i; ++j)  //从第1位开始比较直到最后一个尚未归位的数
		{
			if (arr[j] > arr[j + 1])  //只要改成“<"号，就可以实现降序排序，现在是升序
			{
				swapElem(arr[j], arr[j + 1]);
			}
		}
		++count;
	}
	cout << "普通冒泡花了" << count << "次完成了排序！" << endl;
	/*for (int i = 1; i < length; ++i)   //length个数排序，只用进行length-1趟,也可以写成int i=0;i<length-1
	{
	for (int j = length - 1; 1 <= j; --j) //这里是从后面开始比较元素，每次比较中，将最大的数放到最后
	{
	if (arr[j] < arr[j - 1]) //换成“>" 号，就可以实现降序，现在是升序
	{
	swapElem(arr[j - 1], arr[j]);  //其实这里的实参的顺序可以不用改， 但是改了，可以增强可读性
	}
	}
	}*/
}
int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到冒泡排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行冒泡排序！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "************************* 请输入你想要使用的功能的序号 **********************" << endl;
		int select(0);
		cout << "请输入你的选择：";
		cin >> select;
		if (select == 0)
		{
			cout << "程序已退出，感谢你的使用！" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "请输入你想排序数组元素的个数：";
			int arraySize(0);
			cin >> arraySize;
			if (arraySize <= 0)
			{
				cout << "输入错误，请输入正确的数组个数(至少大于0)，否则无法进行排序！" << endl;
				system("pause");
				exit(0);
			}
			int *assignCapacity = new int[arraySize];
			if (!assignCapacity)
			{
				cout << "错误，分配数组内存时失败，请重新运行程序！" << endl;
				system("pause");
				exit(0);
			}
			cout << "请分别输入你想排序的这" << arraySize << "个元素，中间以回车键隔开：\n";
			for (int i = 0; i < arraySize; ++i)
			{
				cin >> assignCapacity[i];
			}
			printElem(assignCapacity, arraySize);
			bubbleSort(assignCapacity, arraySize);
			cout << "\n输出排序后的元素顺序：";
			for (int k = 0; k < arraySize; ++k)
			{
				cout << assignCapacity[k] << " ";
			}
			cout << endl;
			delete[]assignCapacity;
			assignCapacity = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "程序已清屏！可以重新输入！" << endl;
			break;
		default:
			cout << "输入的序号不正确，请重新输入！" << endl;
		}
	}
	system("pause");
	return 0;
}
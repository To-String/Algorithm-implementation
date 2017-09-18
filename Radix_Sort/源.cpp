#include<iostream>
using namespace std;

/*
* 获取数组arr中最大值
*
* 参数说明：
*     arr -- 数组
*     length -- 数组长度
*/
int getMax(int arr[], int length)
{

	int max = arr[0];
	for (int i = 1; i < length; ++i)
	{
		if (arr[i] > max)
		{
		  max = arr[i];
		}
	}
	return max;
}

/*
* 对数组按照"某个位数"进行排序(桶排序)
*
* 参数说明：
*     arr -- 数组
*     length -- 数组长度
*     exp -- 指数。对数组a按照该指数进行排序。
*
* 例如，对于数组arr={50, 3, 542, 745, 2014, 154, 63, 616}；
*    (01) 当exp=1表示按照"个位"对数组a进行排序
*    (02) 当exp=10表示按照"十位"对数组a进行排序
*    (03) 当exp=100表示按照"百位"对数组a进行排序
*    ...
*/
void countSort(int arr[],   int length, int exp)
{
	
	  int *output=new int [length];             // 存储"被排序数据"的临时数组
	int  buckets[10] = { 0 };

	// 将数据出现的次数存储在buckets[]中
	for (int i = 0; i < length; ++i)
	{
		buckets[(arr[i] / exp) % 10]++;
	}

	// 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
	for (int j = 1; j < 10; ++j)
	{
		buckets[j] += buckets[j - 1];
	}

	// 将数据存储到临时数组output[]中
	for (int k = length - 1; k >= 0; --k)
	{
		output[buckets[(arr[k] / exp) % 10] - 1] = arr[k];
		buckets[(arr[k] / exp) % 10]--;
	}

	// 将排序好的数据赋值给arr[]
	for (int m = 0; m < length; ++m)
	{
		arr[m] = output[m];
	}
	delete[]output;
	output = nullptr;
}

/*
* 基数排序
*
* 参数说明：
*     arr -- 数组
*     n -- 数组长度
*/
void radixSort(int arr[],  int size)
{
	   
	int max = getMax(arr, size);    // 数组a中的最大值
							   // exp指数。当对数组按各位进行排序时，exp=1；按十位进行排序时，exp=10；...
							   // 从个位开始，对数组a按"指数"进行排序
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(arr, size, exp);
	}
	
}
void printElem(const int *arr, const int count)
{
	cout << "\n输出排序前的元素：\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到基数排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行基数排序！" << endl
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
			if (cin >> arraySize &&  arraySize <= 0)
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
			radixSort(assignCapacity, arraySize);
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

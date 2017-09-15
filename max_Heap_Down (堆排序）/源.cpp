#include<iostream>
using namespace std;


/*
* (最大)堆的向下调整算法，创建初始堆（一般升序采用大顶堆，降序采用小顶堆），此代码是大顶堆
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
*     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
*
* 参数说明：
*     arr -- 待排序的数组
*     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
*     end   -- 截至范围(一般为数组中最后一个元素的索引)
*/

void maxHeapDown(int *const arr, const int start, const int end)
{
	int c = start;            // 当前(current)节点的位置,第一次首先从该完全二叉树中的第一个非叶子结点开始调整
	int left = 2 * c + 1;        // 左(left)孩子的位置序号
	int tmp = arr[c];            // 当前(current)节点的大小
	for (; left <= end; c = left, left = 2 * left + 1)
	{
		// "left"是左孩子，"left+1"是右孩子，先左右孩子先比较，比较完后那个大的数在跟当前根结点比较
		if (left < end && arr[left] < arr[left + 1])                           //如果根结点比那个数大，则结束此次循环，否则这两个数进行交换
		{
			++left;        // 左右两孩子中选择较大者，即m_heap[left+1]
		}
		if (arr[left] <= tmp)  //然后在判断根结点是否大于左右孩子中，那个大的数
		{
			break;        // 调整结束
		}
		else            // 交换值
		{
			arr[c] = arr[left];
			arr[left] = tmp;
		}
	}
}


/*
* 堆排序(从小到大)
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void heapSortAsc(int *const arr, const int size)
{
	// 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		maxHeapDown(arr, i, size - 1);
	}
	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (int j = size - 1; j > 0; --j)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。    
		int tmp = arr[0];
		arr[0] = arr[j];
		arr[j] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
		// 即，保证a[i-1]是a[0...i-1]中的最大值。
		maxHeapDown(arr, 0, j - 1);
	}
}

void printElem(const int *arr, const int count)
{
	cout << "\n输出排序前的元素序列：";
	for (auto it = 0; it < count; ++it)
	{
		cout << arr[it] << " ";
	}
	cout << endl;
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到堆排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行堆排序算法！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "************************* 请输入你想要使用的功能的序号 **********************" << endl;
		int select(0);
		cout << "请输入你的选择：";
		cin >> select;
		if (select == 0)
		{
			cout << "程序已退出，感谢你的使用!" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "请输入你想进行排序元素的个数：";
			int arraySize;
			if (cin >> arraySize && arraySize <= 0)
			{
				cout << "输入错误，请输入正确的数组个数(至少大于0)，否则无法进行排序！" << endl;
				system("pause");
				continue;
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
			heapSortAsc(assignCapacity, arraySize);

			cout << "\n输出排序后的元素序列：\n";
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
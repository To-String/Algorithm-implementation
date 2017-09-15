#include<iostream>
using namespace std;


/*
* (���)�ѵ����µ����㷨��������ʼ�ѣ�һ��������ô󶥶ѣ��������С���ѣ����˴����Ǵ󶥶�
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*     ���У�NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0��
*
* ����˵����
*     arr -- �����������
*     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
*     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
*/

void maxHeapDown(int *const arr, const int start, const int end)
{
	int c = start;            // ��ǰ(current)�ڵ��λ��,��һ�����ȴӸ���ȫ�������еĵ�һ����Ҷ�ӽ�㿪ʼ����
	int left = 2 * c + 1;        // ��(left)���ӵ�λ�����
	int tmp = arr[c];            // ��ǰ(current)�ڵ�Ĵ�С
	for (; left <= end; c = left, left = 2 * left + 1)
	{
		// "left"�����ӣ�"left+1"���Һ��ӣ������Һ����ȱȽϣ��Ƚ�����Ǹ�������ڸ���ǰ�����Ƚ�
		if (left < end && arr[left] < arr[left + 1])                           //����������Ǹ�����������˴�ѭ�������������������н���
		{
			++left;        // ������������ѡ��ϴ��ߣ���m_heap[left+1]
		}
		if (arr[left] <= tmp)  //Ȼ�����жϸ�����Ƿ�������Һ����У��Ǹ������
		{
			break;        // ��������
		}
		else            // ����ֵ
		{
			arr[c] = arr[left];
			arr[left] = tmp;
		}
	}
}


/*
* ������(��С����)
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void heapSortAsc(int *const arr, const int size)
{
	// ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		maxHeapDown(arr, i, size - 1);
	}
	// �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (int j = size - 1; j > 0; --j)
	{
		// ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�    
		int tmp = arr[0];
		arr[0] = arr[j];
		arr[j] = tmp;
		// ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�
		// ������֤a[i-1]��a[0...i-1]�е����ֵ��
		maxHeapDown(arr, 0, j - 1);
	}
}

void printElem(const int *arr, const int count)
{
	cout << "\n�������ǰ��Ԫ�����У�";
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
			cout << "\n************************ ��ӭ������������������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�����ж������㷨��" << endl
				<< "����2��������" << endl;
		}
		cout << "************************* ����������Ҫʹ�õĹ��ܵ���� **********************" << endl;
		int select(0);
		cout << "���������ѡ��";
		cin >> select;
		if (select == 0)
		{
			cout << "�������˳�����л���ʹ��!" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "�����������������Ԫ�صĸ�����";
			int arraySize;
			if (cin >> arraySize && arraySize <= 0)
			{
				cout << "���������������ȷ���������(���ٴ���0)�������޷���������" << endl;
				system("pause");
				continue;
			}

			int *assignCapacity = new int[arraySize];
			if (!assignCapacity)
			{
				cout << "���󣬷��������ڴ�ʱʧ�ܣ����������г���" << endl;
				system("pause");
				exit(0);
			}
			cout << "��ֱ����������������" << arraySize << "��Ԫ�أ��м��Իس���������\n";
			for (int i = 0; i < arraySize; ++i)
			{
				cin >> assignCapacity[i];

			}

			printElem(assignCapacity, arraySize);
			heapSortAsc(assignCapacity, arraySize);

			cout << "\n���������Ԫ�����У�\n";
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
			cout << "�����������������������룡" << endl;
			break;
		default:
			cout << "�������Ų���ȷ�����������룡" << endl;
		}
	}
	system("pause");
	return 0;
}
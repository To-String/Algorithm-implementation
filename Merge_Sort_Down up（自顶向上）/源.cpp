#include<iostream>
using namespace std;

/*
* �������ܣ���һ�������е�����������������ϲ���һ��
*
* ����˵����
*     arr -- ���������������������
*     start -- ��1�������������ʼ��ַ��
*     mid   -- ��1����������Ľ�����ַ��Ҳ�ǵ�2�������������ʼ��ַ��
*     end   -- ��2����������Ľ�����ַ��
*/
void merge(int *const arr, const int start, const int mid, const int end)
{
	int *tmp = new int[end - start + 1];    // tmp�ǻ���2������������ʱ����
	int i = start;            // ��1��������������
	int j = mid + 1;        // ��2��������������
	int k = 0;               // k����ʱ��źϲ����е��±�

							 // ɨ���һ�κ͵ڶ������У�ֱ����һ��ɨ�����
	while (i <= mid && j <= end)
	{
		// �жϵ�һ�κ͵ڶ���ȡ�������ĸ���С���������ϲ����У�����������ɨ��
		if (arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
			//i++
			//k++
		}
		else
		{
			tmp[k++] = arr[j++];
			//j++
			//k++
		}
	}

	// ����һ�����л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (i <= mid)  //�����ʣ��Ԫ������tmp��
	{
		tmp[k++] = arr[i++];
	}

	// ���ڶ������л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (j <= end) //��������ʣ��Ԫ������tmp��
	{
		tmp[k++] = arr[j++];
	}

	// ��������Ԫ�أ�ȫ�������ϵ�����arr�С�
	for (i = 0; i < k; ++i)
	{
		arr[start + i] = tmp[i];
	}

	delete[] tmp;
	tmp = nullptr;
}



/*
* ������a�����ɴκϲ�������a���ܳ���Ϊlen��������Ϊ���ɸ�����Ϊgap�������飻
*             ��"ÿ2�����ڵ�������" ���кϲ�����
*
* ����˵����
*     a -- �����������
*     len -- ����ĳ���
*     gap -- ������ĳ���
*/
void merge_Groups(int *arr, const int len, const int gap)
{
	int i;
	int twolen = 2 * gap;    // �������ڵ�������ĳ���

							 // ��"ÿ2�����ڵ�������" ���кϲ�����
	for (i = 0; i + 2 * gap - 1 < len; i += (2 * gap))
	{
		merge(arr, i, i + gap - 1, i + 2 * gap - 1);
	}

	// �� i+gap-1 < len-1����ʣ��һ��������û����ԡ�
	// ����������ϲ���������������С�
	if (i + gap - 1 < len - 1)
	{
		merge(arr, i, i + gap - 1, len - 1);
	}  
}

/*
* �鲢����(��������)
*
* ����˵����
*     a -- �����������
*     len -- ����ĳ���
*/
void merge_Sort_Down2up(int *const arr, const int len)
{
	
	if (arr == NULL || len <= 0)
		return;

	for (int n = 1; n < len; n *= 2)
	{
		merge_Groups(arr, len, n);
	}
}

void printElem(const int *const arr, const int count)
{
	cout << "\n�������ǰ��Ԫ�����У�\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ���������Զ����Ϲ鲢��������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�������Զ����Ϲ鲢����" << endl
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
			merge_Sort_Down2up(assignCapacity, arraySize);

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
#include<iostream>
using namespace std;

/*
* ��ȡ����arr�����ֵ
*
* ����˵����
*     arr -- ����
*     length -- ���鳤��
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
* �����鰴��"ĳ��λ��"��������(Ͱ����)
*
* ����˵����
*     arr -- ����
*     length -- ���鳤��
*     exp -- ָ����������a���ո�ָ����������
*
* ���磬��������arr={50, 3, 542, 745, 2014, 154, 63, 616}��
*    (01) ��exp=1��ʾ����"��λ"������a��������
*    (02) ��exp=10��ʾ����"ʮλ"������a��������
*    (03) ��exp=100��ʾ����"��λ"������a��������
*    ...
*/
void countSort(int arr[],   int length, int exp)
{
	
	  int *output=new int [length];             // �洢"����������"����ʱ����
	int  buckets[10] = { 0 };

	// �����ݳ��ֵĴ����洢��buckets[]��
	for (int i = 0; i < length; ++i)
	{
		buckets[(arr[i] / exp) % 10]++;
	}

	// ����buckets[i]��Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ�á�
	for (int j = 1; j < 10; ++j)
	{
		buckets[j] += buckets[j - 1];
	}

	// �����ݴ洢����ʱ����output[]��
	for (int k = length - 1; k >= 0; --k)
	{
		output[buckets[(arr[k] / exp) % 10] - 1] = arr[k];
		buckets[(arr[k] / exp) % 10]--;
	}

	// ������õ����ݸ�ֵ��arr[]
	for (int m = 0; m < length; ++m)
	{
		arr[m] = output[m];
	}
	delete[]output;
	output = nullptr;
}

/*
* ��������
*
* ����˵����
*     arr -- ����
*     n -- ���鳤��
*/
void radixSort(int arr[],  int size)
{
	   
	int max = getMax(arr, size);    // ����a�е����ֵ
							   // expָ�����������鰴��λ��������ʱ��exp=1����ʮλ��������ʱ��exp=10��...
							   // �Ӹ�λ��ʼ��������a��"ָ��"��������
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(arr, size, exp);
	}
	
}
void printElem(const int *arr, const int count)
{
	cout << "\n�������ǰ��Ԫ�أ�\n";
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
			cout << "\n************************ ��ӭ��������������������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�����л�������" << endl
				<< "����2��������" << endl;
		}
		cout << "************************* ����������Ҫʹ�õĹ��ܵ���� **********************" << endl;
		int select(0);
		cout << "���������ѡ��";
		cin >> select;
		if (select == 0)
		{
			cout << "�������˳�����л���ʹ�ã�" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "������������������Ԫ�صĸ�����";
			int arraySize(0);
			if (cin >> arraySize &&  arraySize <= 0)
			{
				cout << "���������������ȷ���������(���ٴ���0)�������޷���������" << endl;
				system("pause");
				exit(0);
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
			radixSort(assignCapacity, arraySize);
			cout << "\n���������Ԫ��˳��";
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

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
			return binary_search(arr, left, mid - 1, key);  //�����Ҳ�
		}
		else if (arr[mid] < key)
		{
			return binary_search(arr, mid + 1, right, key);//�������
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
	cout << "\n�������ǰ������Ԫ�أ�\n";
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
			cout << "\n************************��ӭ�����������ֲ���(�ݹ�)�����磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�����ж��ֲ��ң�" << endl
				<< "����2��������" << endl;
		}
		cout << "\n���������ѡ��";
		int choice(0);
		cin >> choice;
		if (choice == 0)
		{
			cout << "�������˳���" << endl;
			break;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "����������Ҫ����Ԫ���б�ĳ��ȣ�";
			int list_Length(0);
			if (cin >> list_Length && list_Length <= 0)
			{
				cout << "���������������ȷ���������(���ٴ���0)�������޷���������,���������룡" << endl;
				continue;
			}

			int *array = new int[list_Length];
			if (!array)
			{
				cout << "���󣬷��������ڴ�ʱʧ�ܣ����������г���" << endl;
				system("pause");
				exit(0);
			}
			cout << "��ֱ���������Ҫ���в��ҵ�" << list_Length << "��Ԫ�أ��ֱ��ûس����ֿ����ɣ�\n";
			for (int i = 0; i < list_Length; ++i)
			{
				cin >> array[i];
			}
			print_Array(array, list_Length);
			
			int element(0), locate(0);
			cout << "����������Ҫ�������в��ҵ�Ԫ���ǣ�";
			cin >> element;
			if ((locate = binary_search(array, 0, list_Length - 1, element)) >= 0)
			{
				cout << "�ҵ�Ԫ��" << element << ",���������е�λ��Ϊ��" << locate << endl;
			}
			else
			{
				cout << "û���ҵ�����Ҫ���ҵ�Ԫ��" << element << "!" << endl;
			}
			delete[]array;
			array = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "��Ļ�������������������룡" << endl;
			break;
		default:
			cout << "�������������������룡" << endl;
		}
	}
	system("pause");
	return 0;
}

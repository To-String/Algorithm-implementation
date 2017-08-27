#include<iostream>
using namespace std;

void printElem(const int *arr, const int count)
{
	cout << "\n�������ǰ��Ԫ�����У�";
	for (auto it = 0; it < count; ++it)
	{
		cout << arr[it] << " ";
	}
	cout << endl;
}

void Shell_Sord(int *const arr, const int length)
{

	for (int gap = length / 2; gap > 0; gap /= 2) //����  
	{
		for (int i = 0; i < gap; ++i)         // ��gap���飬��ÿһ�鶼ִ��  ֱ�Ӳ�������
		{
			for (int j = i + gap; j < length; j += gap)
			{
				if (arr[j] < arr[j - gap])   // ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
				{
					int temp = arr[j];  //��¼a[j]��ֵ���Ҷ�λ�ú���в���
					int k = j - gap;
					while ((k >= 0) && (temp < arr[k])) // �Ƚ����С������֣���arr[k] ����temp�������������ֵ�λ��
					{
						arr[k + gap] = arr[k]; // ���н���
						k -= gap;
					}
					arr[k + gap] = temp;  //��arr[j]  ��¼�����ֲ�����ʵ�λ��
				}
			}
		}
	}
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ��������ϣ����������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1������ϣ������" << endl
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
			if ((cin >> arraySize) && (arraySize <= 0))
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
			Shell_Sord(assignCapacity, arraySize);

			cout << "\n���������Ԫ�����У�";
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
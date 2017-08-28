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

void Shell_Sord2(int *const arr, const int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < length; ++j)//�������gap��Ԫ�ؿ�ʼ  
		{
			if (arr[j] < arr[j - gap])//ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������  
			{
				int temp = arr[j];
				int k = j - gap;
				while ((k >= 0) && (temp < arr[k]))
				{
					arr[k + gap] = arr[k];
					k -= gap;
				}
				arr[k + gap] = temp;
			}
		}
	}

	/*������������n=10��һ������49, 38, 65, 97, 26, 13, 27, 49, 55, 4Ϊ��

	��һ�� gap = 10 / 2 = 5

49   38   65   97   26   13   27   49   55   4

1A                       1B

	2A                       2B

		3A                       3B

			 4A                       4B

                   5A                       5B

	�ڶ��� gap = 5 / 2 = 2

	�����	13   27   49   55   4    49   38   65   97   26

			 1A        1B        1C        1D        1E

				  2A        2B        2C        2D        2E

	*/

	/*�Ե�һ��ϣ����������Ż����Եڶ�������Ϊ����ԭ����ÿ�δ�1A��1E����2A��2E�����Ըĳɴ�1B��ʼ��
	�Ⱥ�1A�Ƚϣ�Ȼ��ȡ2B��2A�Ƚϣ���ȡ1C��ǰ���Լ����ڵ����ݱȽϡ���.��*/

	/*����ÿ�δ������gap��Ԫ�ؿ�ʼ��ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ���������ȻҲ����ȷ�ġ�*/

	
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ��������ϣ������2�����磡**********************\n" << endl
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
			Shell_Sord2(assignCapacity, arraySize);

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
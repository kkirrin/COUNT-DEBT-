#include <iostream>
#include <string>
#include "Source1.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	double sum, amount_of_mounth, IntRate;
	string choice;

	cout << "������� ����� �������: " << endl;
	cin >> sum;
	cout << "�� ������� ������� �� ������ ������? ";
	cin >> amount_of_mounth;
	cout << "���������� ������ �� �������? % ";
	cin >> IntRate;
	cout << "����� ��� ��������� ��� ����������? ����������� ��� ������������������? (1 ��� 2)";
	cin >> choice;
	if (choice == "1") //�����������, ����� ������� ���������� �� ���������� ���������
		{
		double persent_at_sum = (IntRate / 100) * sum;
		double amount_of_payments = amount_of_mounth;
		double IntRate_of_mounth = IntRate / 12 / 100;
		cout << "���� ����������� ���������� ������: " << IntRate_of_mounth << endl;
		double koef_of_annuita = (IntRate_of_mounth * pow(1 + IntRate_of_mounth, amount_of_payments)) / (pow(1 + IntRate_of_mounth, amount_of_payments) - 1);

		cout << "����������� ������ ��������: " << sum * koef_of_annuita << " ������" << endl;
		}
	if ( choice == "2")// ������������������
		//{
		//cout << "������� ����� ���� � ������, � ������� ����� ����������� ������� ���������" << endl;
		//float n, y;
		//cin >> n;

		//cout << "� ����� �������, � ���� ���� 365 � 364 ���?" << endl;
		//cin >> y;

		//float s = n / y;
		//cout << s << endl;

		//long double part_of_debt = sum / amount_of_mounth;
		//cout << "����� ��������� �����: " << part_of_debt << " ������" << endl; //��� ����� ��������� �����, 
		////������� ����� ������� �� ������� � ������ ����������� ��� ������������������ ������� ������ �����.
		////����� ��������� ������������� ����������. ���� ����� ����� ���������� ������� � ���������� �����������
	 //   //���������:

		//long double  count_of_persent = sum * IntRate / 100 * double(s);
		//cout << "����� ��������� �� ����� ����������: " << count_of_persent << endl;


		//cout << "������������������ ������ �������� � ���� ������: " << part_of_debt + count_of_persent << " ������" << endl;
		//}

		{
		double count_of_persent, part_of_debt = sum / amount_of_mounth, sum_persent = 0, sum_debt = 0;

		for (int i = 0, x = 1; x <= amount_of_mounth; i++, x++)
		{
			count_of_persent = (((sum - (part_of_debt * i)) * IntRate) / 12) / 100;
			cout << x << " ����� �������� ����:" << part_of_debt << " �������: " << count_of_persent << " �����: " << part_of_debt + count_of_persent << endl;
			sum_persent = count_of_persent + sum_persent;
			sum_debt = sum_debt + part_of_debt;
		}
		cout << "����� ��������: �������� ����� - " << sum_debt << " �������� - " << sum_persent << endl;

	}
	


	return 0;
}

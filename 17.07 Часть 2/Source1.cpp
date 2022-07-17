#include <iostream>
#include <string>
#include "Source1.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	double sum, amount_of_mounth, IntRate;
	string choice;

	cout << "Введите сумму кредита: " << endl;
	cin >> sum;
	cout << "На сколько месяцев вы берете кредит? ";
	cin >> amount_of_mounth;
	cout << "Процентная ставка по кредиту? % ";
	cin >> IntRate;
	cout << "Какой вид погашения вас устраивает? Аннуитетный или дифференцированный? (1 или 2)";
	cin >> choice;
	if (choice == "1") //Аннуитетный, сумма кредита умножается на коэффицент аннуитета
		{
		double persent_at_sum = (IntRate / 100) * sum;
		double amount_of_payments = amount_of_mounth;
		double IntRate_of_mounth = IntRate / 12 / 100;
		cout << "Ваша ежемесячная процентная ставка: " << IntRate_of_mounth << endl;
		double koef_of_annuita = (IntRate_of_mounth * pow(1 + IntRate_of_mounth, amount_of_payments)) / (pow(1 + IntRate_of_mounth, amount_of_payments) - 1);

		cout << "Ежемесячный платеж составит: " << sum * koef_of_annuita << " рублей" << endl;
		}
	if ( choice == "2")// Дифференцированный
		//{
		//cout << "Введите число дней в месяце, в котором будет происходить выплата процентов" << endl;
		//float n, y;
		//cin >> n;

		//cout << "А также укажите, в этом году 365 и 364 дня?" << endl;
		//cin >> y;

		//float s = n / y;
		//cout << s << endl;

		//long double part_of_debt = sum / amount_of_mounth;
		//cout << "Часть основного долга: " << part_of_debt << " рублей" << endl; //Это часть основного долга, 
		////которую нужно платить по кредиту с нашими параметрами при дифференцированном платеже каждый месяц.
		////Сумма процентов пересчитывает ежемесячно. Чаще всего банки используют формулу с ежедневным начислением
	 //   //процентов:

		//long double  count_of_persent = sum * IntRate / 100 * double(s);
		//cout << "Сумма процентов на месяц составляет: " << count_of_persent << endl;


		//cout << "Дифференцированный платеж составит в этом месяце: " << part_of_debt + count_of_persent << " рублей" << endl;
		//}

		{
		double count_of_persent, part_of_debt = sum / amount_of_mounth, sum_persent = 0, sum_debt = 0;

		for (int i = 0, x = 1; x <= amount_of_mounth; i++, x++)
		{
			count_of_persent = (((sum - (part_of_debt * i)) * IntRate) / 12) / 100;
			cout << x << " месяц Основной долг:" << part_of_debt << " Процент: " << count_of_persent << " Всего: " << part_of_debt + count_of_persent << endl;
			sum_persent = count_of_persent + sum_persent;
			sum_debt = sum_debt + part_of_debt;
		}
		cout << "Всего уплачено: основная сумма - " << sum_debt << " проценты - " << sum_persent << endl;

	}
	


	return 0;
}

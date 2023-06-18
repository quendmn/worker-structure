#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

struct Worker
{
	
	std::string surname;
	int exp;
	int zp;
	int hours;
	int salary_w_rew;

	void Info_input()
	{
		std::cout << "============================\n";
		std::cout << "Введите фамилию работника: ";
		std::cin >> surname;

		std::cout << "Введите стаж работника: ";
		std::cin >> exp;

		std::cout << "Введите часовую зп работника: ";
		std::cin >> zp;

		std::cout << "Введите кол-во отработанных часов: ";
		std::cin >> hours;

	}

	void Salary()
	{
		float reward_percent;
		
		if (exp < 1)
		{
			salary_w_rew = zp * hours;
		}

		if (exp > 1 && exp <= 3)
		{
			reward_percent = 0.05;
			salary_w_rew = zp * hours + (zp * hours) * reward_percent;

		}

		if (exp > 3 && exp <= 5)
		{
			reward_percent = 0.08;
			salary_w_rew = zp * hours + (zp * hours) * reward_percent;
		}

		if (exp > 5)
		{
			reward_percent = 0.15;
			salary_w_rew = zp * hours + (zp * hours) * reward_percent;
		}

	}

	void Print()
	{
		std::cout << "============================\n";
		std::cout << "Фамилия работника: " << surname << "\n";
		std::cout << "Стаж: " << exp << "\n";
		std::cout << "Часовая зп: " << zp << "\n";
		std::cout << "Кол-во отработанных часов: " << hours << "\n";
		std::cout << "Зарплата: " << salary_w_rew << "\n";
	}

	void File()
	{
		std::fstream Worker_file;
		Worker_file.open("worker.txt", std::ios::app);
		if (!Worker_file.is_open())
		{
			std::cerr << "Error!";
		}
		else
		{
			std::cout << "============================\n";
			
			Worker_file << "\n============================\n";
			Worker_file << "КАРТОЧКА СОТРУДНИКА\n";
			Worker_file << "============================\n";
			Worker_file << "Фамилия работника: " << surname << "\n";
			Worker_file << "Стаж: " << exp << "\n";
			Worker_file << "Часовая зп: " << zp << "\n";
			Worker_file << "Кол-во отработанных часов: " << hours << "\n";
			Worker_file << "Зарплата: " << salary_w_rew << " Руб";

			std::cout << "\nЗапись данных в файл worker.txt завершена!";
		}
		Worker_file.close();
	}


};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker obj;
	obj.Info_input();
	obj.Salary();
	obj.Print();
	obj.File();
	
	return 0;
}
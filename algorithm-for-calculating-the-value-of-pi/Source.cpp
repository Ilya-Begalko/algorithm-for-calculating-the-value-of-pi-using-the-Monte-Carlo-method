#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <glut.h>
#include <cmath>
#include "Myclass.h"

#define PI 3.14159265

using namespace std;
void myDisplay(void);
void myInit(void);
void drawCircle(float x, float y, float r, int amountSegments);

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void information()
{
	cout << "\n";
	cout << "         ---------------------------------------------------------\n";
	cout << "                Курсовой проект по дисцеплине программирование\n";
	cout << "          ---------------------------------------------------------\n";
	cout << "\n";
	cout << "   Выполнил студент Факультета информационных технологий и компьютерных систем\n";
	cout << "\n";
	cout << "           Кафедры Фундаментальной информатики и информационных технологий\n";
	cout << "\n";
	cout << "                               Группы ФИТ-181\n";
	cout << "\n";
	cout << "                           Бегалко Илья Алексеевич\n";
	cout << "\n";
	cout << "                                  2019 год" << endl;
	cout << "                                 Город Омск";
	cout << "\n";
	cout << "          ---------------------------------------------------------\n" << endl;
	system("pause");
}

void info()
{
	cout << "\n";
	cout << "         ---------------------------------------------------------\n";
	cout << "                      Тема данного курсового проекта\n";
	cout << "         ----------------------------------------------------------\n";
	cout << "\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 3) | 0));
	cout << "                  Разработать и реализовать алгоритм вычисления               \n";
	cout << "                     значения числа  методом Монте-Карло.                     \n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "         ----------------------------------------------------------\n" << endl;
	system("pause");
}

void algoritm()
{
	int Nincircle = 0; // Кол-во точек в кругу
	srand(time(0));
	int Npoints; //Кол-во точек
	cout << "Введите колличество точек для вычисления числа PI:" << endl;
	while (!(cin >> Npoints) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введенное значение не является цифрой, введите новое: \n";
	}
	Myclass obj;
	for (int i = 0; i < Npoints; i++)
	{
		double x = (rand() % (4 * Npoints) - 2 * Npoints) / (2.0 * Npoints);
		double y = (rand() % (4 * Npoints) - 2 * Npoints) / (2.0 * Npoints);
		if (obj.IsPointInCircle(1.0, x, y)) { Nincircle++; }
		glPointSize(2);
		glBegin(GL_POINTS);
		glVertex2f(x * 100, y * 100);
		glEnd();
	}
	double Pi, Pogr;
	Pi = Nincircle * 4.0 / Npoints;
	Pogr = abs(PI - Pi);
	cout << "Число PI по методу Монте-Карло: " << setprecision(5) << Pi << endl;
	cout << "Таблчное значение числа PI : " << setprecision(5) << PI << endl;
	cout << "Погрешность измерения : " << setprecision(5) << Pogr << endl;
}

void menu()
{
	int Num;
	system("cls");
	for (int i = 1; i < 21; i++)
	{
		gotoxy(22, i);
		cout << "|";
		gotoxy(52, i);
		cout << "|" << endl;
	}

	for (int i = 1; i < 30; i++)
	{
		gotoxy(22 + i, 1);
		cout << "=";
		gotoxy(35, 2);
		cout << "МЕНЮ";
		gotoxy(22 + i, 3);
		cout << "_";
		gotoxy(22 + i, 20);
		cout << "=" << endl;
	}

	{
		gotoxy(24, 5); cout << "1) Информация об авторе";
		gotoxy(24, 7); cout << "2) Тема КП";
		gotoxy(24, 9); cout << "3) Алгоритм";
		gotoxy(24, 11); cout << "4) Графическое представление";
		gotoxy(24, 12); cout << "   алгоритма";
		gotoxy(24, 17); cout << "5)  ВЫХОД";
		gotoxy(24, 19); cout << "ВВЕДИ НОМЕР ПУНКТА: ";

		cin >> Num;
		if (1 > Num || Num > 5)
		{
			cout << "\n";
			cout << "Введенно некорректное значение, введите другое:";
			cin >> Num;
		}

		switch (Num)
		{
		case 1:
		{
			system("cls");
			information();
			break;
		}
		case 2:
		{
			system("cls");
			info();
			break;
		}
		case 3:
		{
			system("cls");
			algoritm(Npoints);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(640, 480);
			glutInitWindowPosition(800, 0);
			glutCreateWindow("PI");
			myInit();
			glutDisplayFunc(myDisplay);
			glutMainLoop();
			break;
		}
		case 5:
		{
			system("cls");
			exit(1);
			break;
		}
		}
		menu();
		system("pause");
	}
}

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640, -480, 480);
}
void drawCircle(float x, float y, float r, int amountSegments)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, -480.0);
	glVertex2f(0.0, 480.0);
	glVertex2f(-640.0, 0.0);
	glVertex2f(640.0, 0.0);
	glEnd();
	glLineWidth(2);
	const double R = 100;
	drawCircle(0, 0, R, 60);
	drawCircle(0, 0, 2 * R, 4);
	algoritm();
	glFlush();
	system("pause");
	menu();
}

int main(int argc, char** argv)
{
	system("chcp 1251>nul");
	system("mode con cols=80 lines=25");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	menu();
	system("pause");
}
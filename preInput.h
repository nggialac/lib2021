#include "prototype.h"

char *toCharArray(string str)
{
	char *c = new char(str.size() + 1);
	for (int i = 0; i < str.size() + 1; i++)
		c[i] = str[i];
	return c;
}

string chuanHoaChuoi(string result)
{
	for (size_t i = 1; i < result.length(); i++)
	{
		if (result[0] == ' ')
		{
			result.erase(0, 1);
			i--;
		}
		else if (result[i - 1] == ' ' && result[i] == ' ')
		{
			result.erase(i - 1, 1);
			i--;
		}
		else if (result[result.length() - 1] == ' ')
		{
			result.erase(result.length() - 1, 1);
		}
	}
	return result;
}

void Nhap(int &result, int choice, int &tienTrinh, bool &isSave, bool &isEscape)
{
	//cout << result;
	int count = 0;
	// giu lai vi tri ban dau
	int x = wherex() - 1, y = wherey() - 1;
	if (choice == 1 && result == 3)
	{
		result = 1;
		gotoxy(x, y);
		cout << result << ":  Hoat dong ";
	}
	while (true)
	{
		while (_kbhit())
		{
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 49) && count < 1) //0 || 1
			{
				count++;
				result = kb_hit - 48;
				if (choice == 0)
				{
					gotoxy(x_Note + 15, y_Note);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  Nam" : cout << result << ":  Nu    ";
				}
				else if (choice == 1)
				{
					// xoa dong thong bao
					gotoxy(x_Note + 15, y_Note);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  Khoa      " : cout << result << ":  Hoat dong ";
				}
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (choice == 0)
				{
					if (kb_hit == KEY_UP)
					{
						tienTrinh = 1;
						return;
					}
					else
					{
						tienTrinh = 3;
						return;
					}
				}
				else if (choice == 1)
				{
					if (kb_hit == KEY_UP)
					{
						tienTrinh = 2;
						return;
					}
					else
					{
						tienTrinh = 0;
						return;
					}
				}
			}
			else if (kb_hit == ENTER)
			{
				if (choice == 0)
				{
					tienTrinh = 3;
					return;
				}
				else if (choice == 1)
				{
					tienTrinh = 0;
					return;
				}
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				gotoxy(x, y);
				result = 3;
				cout << " " << setw(15) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == F5)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else
			{
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Nhap 0 hoac 1, Backspace de xoa !";
				SetColor(WHITE);
				gotoxy(x, y);
			}
		}
	}
}

void NhapTen(string &result, int &ordinal, bool &isSave, bool &isEscape)
{
	cout << result;
	int count = (int)result.length();
	int x, y;
	while (true)
	{
		x = wherex() - 1;
		y = wherey() - 1;

		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa.
			// chi nhap ten toi da 7 ky tu, vi tu dai nhat tieng viet chi la 7.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_TEN)
			{
				count++;
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 0;
					return;
				}
				else
				{
					ordinal = 2;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 2;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b"
					 << " "
					 << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == F5)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else
			{
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 7 ky tu chu !";
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(x, y);
			}
		}
	}
}

void NhapHo(string &result, int &ordinal, bool &isSave, bool &isEscape)
{
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			// chi nhap ho toi da 15 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
			        && count < MAX_HO && count >= 0) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (nSpace == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					ordinal = 3;
					return;
				} else {
					ordinal = 1;
					return;
				}
			} else if (kb_hit == ENTER) {
				ordinal = 1;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 16 ky tu chu !!!";
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(x, y);
			}
		}
	}
}

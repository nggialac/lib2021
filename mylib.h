#include "initial.h"

char *Pwd()
{
    char S[40];
    int i = 0;
    while ((S[i] = getch()) != Enter)
    {
        printf("%c", '*');
        i++;
    }
    S[i] = '\0';
    return S;
}

int CheckPwd()
{
    int dem = 0;
    for (dem = 1; dem <= 3; dem++)
    {
        printf("Password :");
        if (strcmp(Pwd(), PASSWORD) == 0)
            return 1;
        else
            printf("\nPassword sai. Hay nhap lai\n");
    }
    return 0;
}

void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol()
{
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
                               info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
    gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

void cls(HANDLE hConsole)
{
    COORD coordScreen = {0, 0}; // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ',
                                    dwConSize, coordScreen, &cCharsWritten))
        return;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;
    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
                                    dwConSize, coordScreen, &cCharsWritten))
        return;
    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void clrscr()
{
    // system("cls");
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hCon);
}

void setWindowSize()
{
        // HWND hWnd = GetConsoleWindow();
    // ShowWindow(hWnd, SW_SHOWMAXIMIZED);
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 1200, 800, TRUE); // 800 width, 100 height
}

void XoaMotDong(int width) {
	SetBGColor(BLACK);
	cout << " " << setw(width) << setfill(' ') << " ";
}

void XoaMotVung(int x, int y, int ndoc, int width) {
	for (int i = 0; i < ndoc; i++) {
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}
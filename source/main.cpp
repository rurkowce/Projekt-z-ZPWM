#include <Windows.h>
#include "res.h"
#include <stdio.h>
#include "player.h"


#define KEYLEFT 0x25
#define KEYUP 0x26
#define KEYRIGHT 0x27
#define KEYDOWN 0x28
#define KEYA 0x41
#define KEYW 0x57
#define KEYD 0x44
#define KEYS 0x53
#define KEYENTER 0x0D
#define KEYESCAPE 0x1B
#define STARTX 585
#define STARTYMIN 290
#define STARTYMAX 390
#define ENDX 580

CHAR szText[200];
HBITMAP hBitmapMenu;
HBITMAP hBitmapMenuPlayer;
HBITMAP hBitmapBoard;
HBITMAP hBitmapControls;
HBITMAP hBitmapPlayer1;
HBITMAP hBitmapPlayer2;
HINSTANCE hInst;
bool is_game_on = false;
bool is_controls_window_open = false;
bool is_player_window_open = false;
bool is_multiplayer = false;
bool key_tab[10] = { false }; //0-3 arrows 4-7 wsad 8-9 enter escape to start and pause game
Player* player_one = new Player(STARTX, (STARTYMIN + 10));
Player* player_two = new Player(STARTX, (STARTYMAX - 10));

void DrawMenu(HDC x);
void DrawMenuPlayer(HDC x);
void DrawGameBoard(HDC x);
void DrawGameControls(HDC x);
void DrawPlayer1(HDC hdc, int x, int y);
void DrawPlayer2(HDC hdc, int x, int y);
void DrawPlayers(HDC hdc);


INT_PTR CALLBACK DialogControl(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  //HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {

      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapControls = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CONTROLS));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawGameControls(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_controls_window_open = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogGame(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  //HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED://Zdarzenie klikniecia 
      switch (LOWORD(wParam))
      {
      case ID_OGRZE_AUTORZY:
        {
        MessageBox(0, "Super ludzie to zrobili", "Autorzy", MB_OK);
        return TRUE;
        }
      case ID_OGRZE_TUTAJ:
        {
        MessageBox(0, "Super informacje o grze", "O grze", MB_OK);
        return TRUE;
        }
      case ID_ROZGRYWKA_ROZPOCZNIJ:
        {
        MessageBox(0, "HEHE JESZCZE NIE TERAZ", " ", MB_OK);
        return TRUE;
        }
      case ID_ROZGRYWKA_ZAKONCZ:
        {
        MessageBox(0, "Najpierw trzeba zacz1a hehe", " ", MB_OK);
        return TRUE;
        }
      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_KEYDOWN:
  {
    if ((wParam == KEYLEFT) && (key_tab[0] == false))
    {
      key_tab[0] = true;
      //while (key_tab[0] == true)
      //{
        DrawGameBoard(GetDC(hwndDlg));
        player_one->move_left();
        DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYUP) && (key_tab[1] == false))
    {
      key_tab[1] = true;
      //while (key_tab[1] == true)
      //{
        DrawGameBoard(GetDC(hwndDlg));
        player_one->move_up();
        DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == false))
    {
      key_tab[2] = true;
      //while (key_tab[2] == true)
      //{
        DrawGameBoard(GetDC(hwndDlg));
        player_one->move_right();
        DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == false))
    {
      key_tab[3] = true;
      //while (key_tab[3] == true)
      //{
        DrawGameBoard(GetDC(hwndDlg));
        player_one->move_down();
        DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYA) && (key_tab[4] == false) && (is_multiplayer == true))
    {
      key_tab[4] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_left();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYW) && (key_tab[5] == false) && (is_multiplayer == true))
    {
      key_tab[5] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_up();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYD) && (key_tab[6] == false) && (is_multiplayer == true))
    {
      key_tab[6] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_right();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYS) && (key_tab[7] == false) && (is_multiplayer == true))
    {
      key_tab[7] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_down();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYENTER) && (key_tab[8] == false))
    {
      DrawPlayers(GetDC(hwndDlg));
      key_tab[8] = true;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == false))
    {
      MessageBox(nullptr, "Nacisnales escape, zatrzymalbys gre, gdyby dzialala", "temp", MB_OK);
      key_tab[9] = true;
    }

    return TRUE;
  }
  case WM_KEYUP:
  {
    if ((wParam == KEYLEFT) && (key_tab[0] == true))
    {
      key_tab[0] = false;
    }
    if ((wParam == KEYUP) && (key_tab[1] == true))
    {
      key_tab[1] = false;
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == true))
    {
      key_tab[2] = false;
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == true))
    {
      key_tab[3] = false;
    }
    if ((wParam == KEYA) && (key_tab[4] == true))
    {
      key_tab[4] = false;
    }
    if ((wParam == KEYW) && (key_tab[5] == true))
    {
      key_tab[5] = false;
    }
    if ((wParam == KEYD) && (key_tab[6] == true))
    {
      key_tab[6] = false;
    }
    if ((wParam == KEYS) && (key_tab[7] == true))
    {
      key_tab[7] = false;
    }
    if ((wParam == KEYENTER) && (key_tab[8] == true))
    {
      key_tab[8] = false;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == true))
    {
      MessageBox(nullptr, "Pusciles escape", "temp", MB_OK);
      key_tab[9] = false;
    }
    return TRUE;
  }
  case WM_INITDIALOG:
  {
    hBitmapBoard = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_BOARD));
    hBitmapPlayer1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1));
    hBitmapPlayer2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawGameBoard(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_game_on = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); // zniszczenie okna
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogPlayer(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  HWND hwndPlayerview = GetDlgItem(hwndDlg, IDD_PLAYERVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_PLAYER_SINGLE:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
          MessageBox(hwndGameWindow, "Enter rozpoczyna gre", " ", MB_OK);
          is_game_on = true;
          is_multiplayer = false;
        }
        return TRUE;
      }

      case IDC_BUTTON_PLAYER_MULTI:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
          MessageBox(hwndGameWindow, "Enter rozpoczyna gre", " ", MB_OK);
          is_game_on = true;
          is_multiplayer = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_GOBACK:
        is_player_window_open = false;
      {
        EndDialog(hwndDlg, 0);
        DestroyWindow(hwndDlg); 
        return TRUE;
      }
      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapMenuPlayer = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MENUPLAYER));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawMenuPlayer(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_player_window_open = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs3ugi komunikatów
{
  HWND hwndMainview = GetDlgItem(hwndDlg, IDD_MAINVIEW);
  
  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_NEW_GAME:
      {
        if(is_player_window_open==false){
          HWND hwndPlayerWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_PLAYERVIEW), NULL, DialogPlayer);
          ShowWindow(hwndPlayerWindow, SW_SHOW);
          is_player_window_open = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_CONTROL:
      {
        if (is_controls_window_open == false) 
        {
          HWND hwndControlWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_CONTROLVIEW), NULL, DialogControl);
          ShowWindow(hwndControlWindow, SW_SHOW);
          is_controls_window_open = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_END_GAME:
      {
        DestroyWindow(hwndMainview); 
        PostQuitMessage(0);
        return TRUE;
      }
      default:;
      }
    default:;
    }
  }
    return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapMenu = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MENU));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawMenu(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    DestroyWindow(hwndMainview); 
    PostQuitMessage(0); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{


  hInst = hInstance;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogMain);
  ShowWindow(hwndMainWindow, iCmdShow);



  MSG msg = {};
  while (GetMessage(&msg, nullptr, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);

  }

}

void DrawMenu(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenu);
  BitBlt(x, 0, 0, 280, 220, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

void DrawMenuPlayer(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenuPlayer);
  BitBlt(x, 0, 0, 280, 180, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
  
}

void DrawGameBoard(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapBoard);
  BitBlt(x, 0, 0, 1250, 600, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);  
}

void DrawGameControls(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapControls);
  BitBlt(x, 0, 0, 288, 162, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}
void DrawPlayer1(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

void DrawPlayer2(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

void DrawPlayers(HDC hdc)
{
  if (is_multiplayer == false)
  {
    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
  }
  else
  {
    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
    DrawPlayer2(hdc, player_two->return_position_x(), player_two->return_position_y());
  }
  
}
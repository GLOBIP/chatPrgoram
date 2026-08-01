
#include "comunicator.h"
#include <iostream>
#include <ncurses.h>
#include <string>
WINDOW *createWin(int height, int width, int starty, int startx) {

  WINDOW *local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0); /* 0, 0 gives default characters
                         * for the vertical and horizontal
                         * lines			*/

  return local_win;
}
void printOnScreen(WINDOW *win, const char *msg) {
  mvwprintw(win, 3, 3, msg);
  refresh();
  wrefresh(win);
  wrefresh(win);
}
void checkInput(int &what) {
  int letter;
  letter = getch();
  if (letter == 49) {
    what = 1;
  }
  if (letter == 50) {
    what = 2;
  }
  clrtoeol();
  std::string option = std::to_string(what);
  refresh();
}
void destroyWindow(WINDOW *win) {
  wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(win);
  delwin(win);
}
int main() {

  initscr();
  start_color();
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  bkgd(COLOR_PAIR(2));
  int height = 10;
  int width = 30;
  int starty = LINES / 2 - 5;
  int startx = COLS / 2;
  keypad(stdscr, TRUE);
  WINDOW *win1 = createWin(height, width, starty, startx - 45);
  WINDOW *win2 = createWin(height, width, starty, startx + 30);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);
  wbkgd(win1, COLOR_PAIR(4));
  wbkgd(win2, COLOR_PAIR(4));
  keypad(win1, TRUE);
  keypad(win2, TRUE);
  printOnScreen(win1, "1-Client");
  printOnScreen(win2, "2-Server");
  int what{};
  checkInput(what);
  MainWindow ChooseWhatToDo;
  bkgd(COLOR_PAIR(0));
  wbkgd(win1, COLOR_PAIR(0));
  wbkgd(win2, COLOR_PAIR(0));
  destroyWindow(win1);
  destroyWindow(win2);
  endwin();
  if (what == 1) {
    ChooseWhatToDo.callClientSide();

  } else if (what == 2) {
    ChooseWhatToDo.callServerSide();
  }

  return 0;
}

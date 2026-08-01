
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
void printOnScreen(WINDOW *win) {
  mvwprintw(win, 3, 3, "1 for Client");
  mvwprintw(win, 3, 3, "2 for Server");
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
  std::string option = std::to_string(letter);
  mvprintw(40, 5, option.c_str());
  refresh();
}
int main() {
  int height = 10;
  int width = 30;
  int starty = COLS / 2;
  int startx = LINES / 2;
  initscr();
  keypad(stdscr, TRUE);
  WINDOW *win1 = createWin(height, width, starty, startx);
  WINDOW *win2 = createWin(height, width, starty, startx + 30);
  keypad(win1, TRUE);
  keypad(win2, TRUE);
  printOnScreen(win1);
  printOnScreen(win2);
  int what{};
  checkInput(what);
  MainWindow ChooseWhatToDo;
  endwin();
  if (what == 1) {
    ChooseWhatToDo.callClientSide();

  } else if (what == 2) {
    ChooseWhatToDo.callServerSide();
  }

  return 0;
}

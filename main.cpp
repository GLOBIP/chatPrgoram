
#include "comunicator.h"
#include <iostream>
int main() {
  std::cout << "Give 1-Client , 2-Server";
  int what{};
  std::cin >> what;
  // MainWindow ChooseWhatToDo;
  if (what == 1) {
    // ChooseWhatToDo.callClientSide();

  } else if (what == 2) {
    // ChooseWhatToDo.callServerSide();
  }

  return 0;
}

#include "InterfaceManager.h"
#ifdef _windows_
#include <Windows.h>
#include <conio.h>
#endif
#ifdef __linux__
    #include <unistd.h>
    #include <ncurses.h>

void prepareNcurses();
int kbhit(void);

    #include <chrono>
    #include <cstdio>

    #define BUTTON_1       68  // left
    #define BUTTON_2       67  // right
    #define BUTTON_3       66  // down
    #define SPECIAL_BUTTON 91

#else
    #define BUTTON_1       75  // left
    #define BUTTON_2       77  // right
    #define BUTTON_3       80  // down
    #define SPECIAL_BUTTON 224

#endif

#define INTERVAL 0.1

InterfaceManager::InterfaceManager() {
#ifdef __linux__
    prepareNcurses();  //PREPARE LIB FOR READ LINUX KEYBOARD EVENTS
#endif
    interfaceLocal = new Interface;

    display();
      while (true) {
#ifdef _windows_
        if (_kbhit()) {  //Check if button was pressed
            if (_getch() == SPECIAL_BUTTON) {
#else
        if (kbhit()) {  //Check if button was pressed
              if (getch() == SPECIAL_BUTTON) {
#endif
                  interfaceLocal->setInputEvent(readKey());  //Check if button was pressed
              }
            
        } else {
            usleep(100000);
            display();
        }
     }
}

InterfaceInput::Button InterfaceManager::readKey() {
#ifdef _windows_
    switch (_getch()) {
#else
    switch (getch()) {
#endif
        case BUTTON_1:
            return InterfaceInput::LEFT_BUTTON;
        case BUTTON_2:
            return InterfaceInput::RIGHT_BUTTON;
        case BUTTON_3:
            return InterfaceInput::ENTER_BUTTON;
            break;
    }
    return InterfaceInput::OTHER_BUTTON;
}
void InterfaceManager::display() {
#ifdef __linux__
    //system("clear");
    clear();
#else
    //system("cls");
#endif
    MenuItem *currentItem = interfaceLocal->getCurrentMenuItem();
    currentItem->display();
    // printw("%s\n", currentItem->subMenuItems[currentItem->currentMainMenuItem]->getName().c_str());
    // if (interface->getCurrentMenuItem()->type == MenuItem::BACK_EVENT_ITEM) {
    //     printw("BACK ITEM\n");
    // }

    // if (Ssd_1306->isNoChangeableErrorCounting()) {
    //     cout << "No change" << endl;
    //     cout << "possible";
    // } else if (Ssd_1306->isSaveParameterValueMode()) {
    //     cout << "SAVE" << endl;
    //     cout << "to flash" << endl;
    // } else {
    //     cout << Ssd_1306->getParameterHeadline() << endl;
    //     if (!(Ssd_1306->hasSubList())) {
    //         if (Ssd_1306->isVisibleValue())
    //             cout << Ssd_1306->getParameterValue() << " "
    //                  << Ssd_1306->getParameterUnit();

    //         else {
    //             for (uint16_t i = (Ssd_1306->getParameterValue()) * 10; i > 0;
    //                  i /= 10)
    //                 cout << " ";
    //             cout << Ssd_1306->getParameterUnit();
    //         }
    //     }
    // }
    // cout << endl;
#ifdef __linux__
    refresh();
    #endif
}

#ifdef __linux__
int kbhit(void) {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void prepareNcurses() {
    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
}

#endif

#ifdef _windows_
void InterfaceManager::usleep(__int64 usec)
{
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}
#endif
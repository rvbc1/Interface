#include "InterfaceManager.h"

Interface* InterfaceManager::interfaceLocal = nullptr;

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #include <conio.h>
#endif

#ifdef __linux__
    #include <ncurses.h>
    #include <unistd.h>

void prepareNcurses();
int kbhit(void);

    #include <chrono>
    #include <cstdio>

    #define BUTTON_1       68  // left
    #define BUTTON_2       67  // right
    #define BUTTON_3       66  // down
    #define SPECIAL_BUTTON 91

#elif defined(_WIN32) || defined(_WIN64)
    #define BUTTON_1       75  // left
    #define BUTTON_2       77  // right
    #define BUTTON_3       80  // down
    #define SPECIAL_BUTTON 224

#endif

#define INTERVAL 0.1

void InterfaceManager::saveInterface() {
    interfaceLocal->save();
}

InterfaceManager::InterfaceManager() {
#ifdef __linux__
    prepareNcurses();
#endif
    interfaceLocal = new Interface("InterfaceFile.json");

    Action* saveAction = interfaceLocal->getActionByName("Save");
    if (saveAction != nullptr) {
        saveAction->setFunction(&(this->saveInterface));
    }

    display();
    while (true) {
#ifdef __linux__
        if (kbhit()) {
            if (getch() == SPECIAL_BUTTON) {
#elif defined(_WIN32) || defined(_WIN64)
        if (_kbhit()) {
            if (_getch() == SPECIAL_BUTTON) {
#endif
                interfaceLocal->setInputEvent(readKey());
            }

        } else {
            usleep(100000);
            display();
        }
    }
}

InterfaceInput::Button InterfaceManager::readKey() {
#ifdef __linux__
    switch (getch()) {
#elif defined(_WIN32) || defined(_WIN64)
    switch (_getch()) {
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
    clear();
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif

    MenuItem* currentItem = interfaceLocal->getCurrentMenuItem();
    InterfaceDisplayManager::displayManuItem(currentItem);
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

#if defined(_WIN32) || defined(_WIN64)
void InterfaceManager::usleep(__int64 usec) {
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10 * usec);  // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}
#endif
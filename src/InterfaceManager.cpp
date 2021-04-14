#include "InterfaceManager.h"
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
    interface = new Interface;

    // auto start = std::chrono::system_clock::now();
    // std::chrono::duration<double> elapsed_seconds;
    // double time;
    display();
    refresh();
    while (true) {
        if (kbhit()) {  //Check if button was pressed
            if (getch() == SPECIAL_BUTTON) {
                interface->setInputEvent(readKey());  //Check if button was pressed
                //display();
            }
            display();
            refresh();
        } else {
            usleep(100000);
            //display();
            refresh();
        }

        // auto end = std::chrono::system_clock::now();
        // elapsed_seconds = end - start;
        // if (time < elapsed_seconds.count() +
        //                INTERVAL) {  // double fmod( double x, double y );
        //     time += INTERVAL;
        //     //Ssd_1306->refresh();
        //     //display();
        // }
    }
}

InterfaceInput::Button InterfaceManager::readKey() {
    switch (getch()) {
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
    system("cls");
#endif
    printw("%s\n", interface->getCurrentMenuItem()->getName().c_str());
    if (interface->getCurrentMenuItem()->type == MenuItem::BACK_EVENT_ITEM) {
        printw("BACK ITEM\n");
    }

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

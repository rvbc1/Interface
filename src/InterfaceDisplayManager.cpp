#include "InterfaceDisplayManager.h"

void InterfaceDisplayManager::displayMenuItemList(MenuItemsList* item) {
#ifdef __linux__
    printw("%s\n  > %s\n", item->getName().c_str(), item->getSelectedMenuItem()->getName().c_str());

    // if (subMenuItems[currentMainMenuItem]->type == MenuItem::BACK_EVENT_ITEM) {
    //     printw("BACK ITEM\n");
    // }
#elif defined(_WIN32) || defined(_WIN64)
    std::cout << getName() << std::endl
              << subMenuItems[currentMainMenuItem]->getName().c_str();
#endif
}

void InterfaceDisplayManager::displayParameter(Parameter* item) {
#ifdef __linux__
    printw("%s\n", item->getName().c_str());
    //printw("%d %s\n", value, name.c_str());
    std::string displayFormat = "-   %." + std::to_string(item->getAmountOfDigits()) + "f %s   +%s\n";
    printw(displayFormat.c_str(), item->getValue(), item->getUnit().c_str(), " | editing");
#elif defined(_WIN32) || defined(_WIN64)
    std::cout << name << std::endl
              << "   " << value << "   " << unit << "| editing" << std::endl;
#endif
}

void InterfaceDisplayManager::displayAction(Action* item) {
#ifdef __linux__
    printw("%s\n", item->getName().c_str());
    if (item->getValue()) {
        printw(" NO    [YES]   +%s\n", " | editing");
    } else {
        printw("[NO]    YES    +%s\n", " | editing");
    }
#elif defined(_WIN32) || defined(_WIN64)

#endif
}

void InterfaceDisplayManager::displaySwitch(Switch* item) {
#ifdef __linux__
    printw("%s\n", item->getName().c_str());
    if (item->getValue()) {
        printw(" OFF    [ON]   +%s\n", " | editing");
    } else {
        printw("[OFF]    ON    +%s\n", " | editing");
    }
#elif defined(_WIN32) || defined(_WIN64)
    std::cout << name << std::endl;
    if (value) {
        std::cout << " OFF    [ON]   + | editing" << std::endl;
    } else {
        std::cout << "[OFF]    ON    + | editing" << std::endl;
    }
#endif
}
void InterfaceDisplayManager::displayValue(Value* item) {
#ifdef __linux__
    printw("%s\n", item->getName().c_str());
    //printw("%d %s\n", value, name.c_str());
    std::string displayFormat = "   %." + std::to_string(item->getAmountOfDigits()) + "f %s   %s\n";
    printw(displayFormat.c_str(), item->getValue(), item->getUnit().c_str(), " | not editable");
#elif defined(_WIN32) || defined(_WIN64)
    std::cout << name << std::endl
              << "   " << value << "   " << unit << "| not editable" << std::endl;
#endif
}
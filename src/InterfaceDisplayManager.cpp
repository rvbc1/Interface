#include "InterfaceDisplayManager.h"

void InterfaceDisplayManager::showItem(std::string itemText) {
#ifdef __linux__
    printw("%s", itemText.c_str());
#elif defined(_WIN32) || defined(_WIN64)
    std::cout << itemText;
#endif
}

void InterfaceDisplayManager::displayMenuItemList(MenuItemsList* item) {
    std::ostringstream stringStream;
    stringStream << item->getName() << std::endl;
    stringStream << "  > " << item->getSelectedMenuItem()->getName();
    showItem(stringStream.str());
}

void InterfaceDisplayManager::displayParameter(Parameter* item) {
    std::ostringstream stringStream;
    stringStream << item->getName() << std::endl;
    stringStream << "-   " << std::fixed << std::setprecision(item->getAmountOfDigits()) << item->getValue() << " " << item->getUnit() << "   +" << std::endl;
    showItem(stringStream.str());
}

void InterfaceDisplayManager::displayAction(Action* item) {
    std::ostringstream stringStream;
    stringStream << item->getName() << std::endl;
    if (item->getValue()) {
        stringStream << " NO    [YES]    | editing" << std::endl;
    } else {
        stringStream << "[NO]    YES     | editing" << std::endl;
    }
    showItem(stringStream.str());
}

void InterfaceDisplayManager::displaySwitch(Switch* item) {
    std::ostringstream stringStream;
    stringStream << item->getName() << std::endl;
    if (item->getValue()) {
        stringStream << " OFF    [ON]    | editing" << std::endl;
    } else {
        stringStream << "[OFF]    ON     | editing" << std::endl;
    }
    showItem(stringStream.str());
}
void InterfaceDisplayManager::displayValue(Value* item) {
    std::ostringstream stringStream;
    stringStream << item->getName() << std::endl;
    stringStream << "   " << std::fixed << std::setprecision(item->getAmountOfDigits()) << item->getValue() << " " << item->getUnit() << "   " << std::endl;
    showItem(stringStream.str());
}
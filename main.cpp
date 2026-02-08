#include <iostream>
#include <string>
#include <limits>

struct Sleep_Interval
{
    std::string sleepDate;
    std::string sleepTime;
    std::string wakeDate;
    std::string wakeTime;
    std::string notes;
};

struct Sleep_Record
{
    std::string date;
    bool didSleep;
    std::string notes;
};

void ShowMainMenu();
void PrintSleepIntervalRecord(const Sleep_Interval& sleepInvervalRecord);
void PrintSleepRecord(const Sleep_Record& sleepRecord);

int main()
{
    int choice = 0;
    std::string sleepDate = "";
    std::string sleepTime = "";
    std::string wakeDate = "";
    std::string wakeTime = "";
    std::string notes_1 = "";

    std::string date = "";
    bool didSleep = true;
    std::string notes_2 = "";

    do
    {
        ShowMainMenu();    
        std::cout << "Enter your choice (1, 2, 3, 0): ";
        std::cin >> choice;

        if (choice == 1)
        {
            // Clean the buffer before switching to getline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter Sleep Interval Data\n";
            std::cout << "Sleep Date: ";
            std::getline(std::cin, sleepDate, '\n');
            std::cout << "Sleep Time: ";
            std::getline(std::cin, sleepTime, '\n');
            std::cout << "Wake Date: ";
            std::getline(std::cin, wakeDate, '\n');
            std::cout << "Wake Time: ";
            std::getline(std::cin, wakeTime, '\n');

            char tempChoice = 'n';
            while(true)
            {
                std::cout << "Do you want to enter some notes? (y/n): ";
                std::cin >> tempChoice;
                if (tempChoice == 'y' || tempChoice == 'Y')
                {
                    std::cout << "Notes: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, notes_1, '\n');
                    break;
                }
                else if (tempChoice == 'n' || tempChoice == 'N')
                {
                    break;
                }
                else
                {
                    std::cout << "Please enter only valid options.\n";
                }
            }

            struct Sleep_Interval newSleepInterval;
            newSleepInterval.sleepDate = sleepDate;
            newSleepInterval.sleepTime = sleepTime;
            newSleepInterval.wakeDate = wakeDate;
            newSleepInterval.wakeTime = wakeTime;
            newSleepInterval.notes = notes_1;

            std::cout << "Enter Sleep Data\n";
            std::cout << "Date: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, date, '\n');
            std::cout << "Did you sleep? (1 = y/0 = n): ";
            std::cin >> didSleep;

            while(true)
            {
                std::cout << "Do you want to enter some notes? (y/n): ";
                std::cin >> tempChoice;
                if (tempChoice == 'y' || tempChoice == 'Y')
                {
                    std::cout << "Notes: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, notes_2, '\n');
                    break;
                }
                else if (tempChoice == 'n' || tempChoice == 'N')
                {
                    break;
                }
                else
                {
                    std::cout << "Please enter only valid options.\n";
                }
            }

            struct Sleep_Record newSleepRecord;
            newSleepRecord.date = date;
            newSleepRecord.didSleep = didSleep;
            newSleepRecord.notes = notes_2;

            PrintSleepIntervalRecord(newSleepInterval);

            PrintSleepRecord(newSleepRecord);
        }
        else if (choice == 2)
        {
            std::cout << "YET TO IMPLEMENT\n";
        }
        else if (choice == 3)
        {
            std::cout << "YET TO IMPLEMENT\n";
        }
    }
    while (choice != 0);
    return 0;
}

void ShowMainMenu()
{
    std::cout<< "====MAIN MENU====\n";
    std::cout<< "1. Enter Data\n";
    std::cout<< "2. Show Database In Browser\n";
    std::cout<< "3. Show Record Count\n";
    std::cout<< "0. Exit\n";
}

void PrintSleepIntervalRecord(const Sleep_Interval& sleepInvervalRecord)
{
    std::cout << "=== Sleep Interval Record ===\n";
    std::cout << sleepInvervalRecord.sleepDate << std::endl;
    std::cout << sleepInvervalRecord.sleepTime << std::endl;
    std::cout << sleepInvervalRecord.wakeDate << std::endl;
    std::cout << sleepInvervalRecord.wakeTime << std::endl;
    std::cout << sleepInvervalRecord.notes << std::endl;
}

void PrintSleepRecord(const Sleep_Record& sleepRecord)
{
    std::cout << "=== Sleep Record ===\n";
    std::cout << sleepRecord.date << std::endl;
    std::cout << sleepRecord.didSleep << std::endl;
    std::cout << sleepRecord.notes << std::endl;
}
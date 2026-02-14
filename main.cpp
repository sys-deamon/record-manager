#include <iostream>
#include <string>
#include <limits>

enum class DateError
{
    Success,
    InvalidDay,
    InvalidMonth,
    InvalidYear,
    InvalidChar,
    InvalidLength
};

enum class TimeError
{
    Success,
    InvalidHour,
    InvalidMinutes,
    InvalidChar,
    InvalidSeparator,
    InvalidLength,
};

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
DateError IsValidDate(const std::string& date);
TimeError IsValidTime(const std::string& time);
std::string GetDateErrorMessage(const DateError& error);
std::string GetTimeErrorMessage(const TimeError& error);

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

            DateError dateValidationResult = IsValidDate(sleepDate);
            if (dateValidationResult != DateError::Success)
            {
                std::cout << GetDateErrorMessage(dateValidationResult) << std::endl;
                return EXIT_FAILURE; // for now
            }

            std::cout << "Sleep Time: ";
            std::getline(std::cin, sleepTime, '\n');

            TimeError timeValidationResult = IsValidTime(sleepTime);
            if (timeValidationResult != TimeError::Success)
            {
                std::cout << GetTimeErrorMessage(timeValidationResult) << std::endl;
                return EXIT_FAILURE; // for now :)
            }

            std::cout << "Wake Date: ";
            std::getline(std::cin, wakeDate, '\n');

            std::cout << "Wake Time: ";
            std::getline(std::cin, wakeTime, '\n');

            timeValidationResult = IsValidTime(wakeTime);
            if (timeValidationResult != TimeError::Success)
            {
                std::cout << GetTimeErrorMessage(timeValidationResult) << std::endl;
                return EXIT_FAILURE; // for now :)
            }

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

            PrintSleepIntervalRecord(newSleepInterval);
        }
        else if (choice == 2)
        {
            std::cout << "Enter Sleep Data\n";
            std::cout << "Date: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, date, '\n');
            std::cout << "Did you sleep? (1 = y/0 = n): ";
            std::cin >> didSleep;

            char tempChoice = 'n';
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

            PrintSleepRecord(newSleepRecord);
        }
        else if (choice == 3)
        {
            std::cout << "YET TO IMPLEMENT\n";
        }
        else if (choice == 4)
        {
            std::cout << "YET TO IMPLEMENT\n";
        }
    }
    while (choice != 0);
    return EXIT_SUCCESS;
}

void ShowMainMenu()
{
    std::cout<< "====MAIN MENU====\n";
    std::cout<< "1. Enter Sleep Interval Data\n";
    std::cout<< "2. Enter Sleep Log Data\n";
    std::cout<< "3. Show Database In Browser\n";
    std::cout<< "4. Show Record Count\n";
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

DateError IsValidDate(const std::string& date)
{
    // I need to verify if the input date matches DD-MM-YYYY format
    // which is two numbers - two numbers - four numbers

    // If string is too short or long, reject immediately.
    if (date.length() != 10) 
    {
        return DateError::InvalidLength;
    }

    if (date[0] >= '0' && date[0] <= '9' )
    {
        if (date[1] >= '0' && date[1] <= '9' )
        {
            // checking if the day is valid
            int day = ((date[0] - '0') * 10) + (date[1] - '0');
            if (day > 31 || day < 1) return DateError::InvalidDay;

            if (date[2] == '-')
            {
                if (date[3] >= '0' && date[3] <= '9' )
                {
                    if (date[4] >= '0' && date[4] <= '9' )
                    {
                        // checking if the month is valid
                        int month = ((date[3] - '0') * 10) + (date[4] - '0');
                        if (month > 12 || month < 1) return DateError::InvalidMonth;

                        if (date[5] == '-')
                        {
                            if (date[6] >= '0' && date[6] <= '9' )
                            {
                                if (date[7] >= '0' && date[7] <= '9' )
                                {
                                    if (date[8] >= '0' && date[8] <= '9' )
                                    {
                                        if (date[9] >= '0' && date[9] <= '9' )
                                        {
                                            // checking if the year is valid
                                            int year = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0');
                                            if (year < 1) return DateError::InvalidYear;

                                            return DateError::Success; // date is valid
                                        }
                                        return DateError::InvalidYear;
                                    }
                                    return DateError::InvalidYear;
                                }
                                return DateError::InvalidYear;
                            }
                            return DateError::InvalidChar;
                        }
                        return DateError::InvalidMonth;
                    }
                    return DateError::InvalidMonth;
                }
                return DateError::InvalidChar;
            }
            return DateError::InvalidDay;
        }
        return DateError::InvalidDay;
    }
    return DateError::InvalidChar;
}

TimeError IsValidTime(const std::string& time)
{
    // Validating the length of the input
    if (time.length() != 5)
    {
        return TimeError::InvalidLength;
    }

    // Validating the time
    if (time[0] >= '0' && time[0] <= '2')
    {
        if (time[1] >= '0' && time[1] <= '9')
        {
            // Checking if the hour stays under 24
            int hour = ((time[0] - '0') * 10) + (time[1] - '0');
            if (hour > 23 || hour < 0) return TimeError::InvalidHour;

            if (time[2] == ':')
            {
                if (time[3] >= '0' && time[3] <= '6')
                {
                    if (time[4] >= '0' && time[4] <= '9')
                    {
                        // Making sure that minutes stay under 60
                        int min = ((time[3] - '0') * 10) + (time[4] - '0');
                        if (min < 0 || min > 59) return TimeError::InvalidMinutes;

                        return TimeError::Success;
                    }
                    return TimeError::InvalidMinutes;
                }
                return TimeError::InvalidMinutes;
            }
            return TimeError::InvalidSeparator;
        }
        return TimeError::InvalidHour;
    }
    return TimeError::InvalidChar;
}

std::string GetDateErrorMessage(const DateError& error)
{
    switch (error)
    {
        case DateError::Success:
            return "Success.";
        case DateError::InvalidDay:
            return "Error: Day must be two digits (e.g., 01-31).";
        case DateError::InvalidMonth:
            return "Error: Month must be two digits (e.g., 01-12).";
        case DateError::InvalidYear:
            return "Error: Year must be four digits (e.g., 2026).";
        case DateError::InvalidChar:
            return "Error: Date contains invalid characters or missing separators (-).";
        case DateError::InvalidLength:
            return "Error: Date length is short or too long (it must be like 01-01-2026).";
        default:
            return "Error: Unknown Date error occurred.";
    }
}

std::string GetTimeErrorMessage(const TimeError& error)
{
    switch (error)
    {
        case TimeError::Success:
            return "Success.";
        case TimeError::InvalidHour:
            return "Error: Invalid Hour. Hour should be in 24 hour format (e.g., 00 to 23).";
        case TimeError::InvalidMinutes:
            return "Error: Invalid Minutes. Minutes should from 0 - 59.";
        case TimeError::InvalidChar:
            return "Error: Time contains invalid characters.";
        case TimeError::InvalidSeparator:
            return "Error: Invalid or missing time separator (:).";
        case TimeError::InvalidLength:
            return "Error: Time entered is too short or long (it must me like 23:55).";
        default:
            return "ErrorL Unknown Time error occurred.";
    }
}
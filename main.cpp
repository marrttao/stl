#include <iostream>
#include <vector>
#include <algorithm>
#include "entities/train.h"
using namespace std;

void FindByTrainName(vector<Train<string>>& TrainsList, string name) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [name](const Train<string>& train) {
		return train.trainName == name;
		});

	if (it != TrainsList.end()) {
		cout << "Train found: " << it->trainName << " " << it->trainNumber << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}
void FindByTrainNumber(vector<Train<string>>& TrainsList, int number) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [number](const Train<string>& train) {
		return train.trainNumber == number;
		});

	if (it != TrainsList.end()) {
		cout << "Train found: " << it->trainName << " " << it->trainNumber << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}
void FindByTrainArriveTime(vector<Train<string>>& TrainsList, int hour, int minute) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [hour, minute](const Train<string>& train) {
		return train.ArriveTime.hour == hour && train.ArriveTime.minute == minute;
		});

	if (it != TrainsList.end()) {
		cout << "Train found: " << it->trainName << " " << it->trainNumber << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}
void FindByTrainDepartTime(vector<Train<string>>& TrainsList, int hour, int minute) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [hour, minute](const Train<string>& train) {
		return train.DepartTime.hour == hour && train.DepartTime.minute == minute;
		});

	if (it != TrainsList.end()) {
		cout << "Train found: " << it->trainName << " " << it->trainNumber << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}
void FindByTrainIsArrived(vector<Train<string>>& TrainsList, bool isArrived) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [isArrived](const Train<string>& train) {
		return train.isArrived == isArrived;
		});

	if (it != TrainsList.end()) {
		cout << "Train found: " << it->trainName << " " << it->trainNumber << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}

void AddTrain(vector<Train<string>>& TrainsList) {
	TrainsList.emplace_back(Train<string>());
}
void DelTrain(vector<Train<string>>& TrainsList, string name) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [name](const Train<string>& train) {
		return train.trainName == name;
		});

	if (it != TrainsList.end()) {
		TrainsList.erase(it);
		cout << "Train deleted" << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}

void OutputInfo(const vector<Train<string>>& TrainsList) {
	for (const auto& train : TrainsList) {
		train.GetTrainInfo("Sample Info");
	}
}

void changeIsArrived(vector<Train<string>>& TrainsList, string name, bool isArrived) {
	auto it = find_if(TrainsList.begin(), TrainsList.end(), [name](const Train<string>& train) {
		return train.trainName == name;
		});

	if (it != TrainsList.end()) {
		it->setIsArrived(isArrived);
		cout << "Train status changed" << endl;
	}
	else {
		cout << "Train not found" << endl;
	}
}


void DisplayMenu() {
	cout << "Menu:" << endl;
	cout << "1. Add Train" << endl;
	cout << "2. Delete Train" << endl;
	cout << "3. Find Train by Name" << endl;
	cout << "4. Find Train by Number" << endl;
	cout << "5. Find Train by Arrival Time" << endl;
	cout << "6. Find Train by Departure Time" << endl;
	cout << "7. Find Train by Arrival Status" << endl;
	cout << "8. Output Train Info" << endl;
	cout << "9. Change Train Status" << endl;
	cout << "10. Exit" << endl;
}

int main() {
    std::vector<Train<std::string>> TrainsList;
	int choice;
	string name;
	int number, hour, minute;
	bool isArrived;

	do {
		DisplayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			AddTrain(TrainsList);
			break;
		case 2:
			cout << "Enter train name to delete: ";
			cin >> name;
			DelTrain(TrainsList, name);
			break;
		case 3:
			cout << "Enter train name to find: ";
			cin >> name;
			FindByTrainName(TrainsList, name);
			break;
		case 4:
			cout << "Enter train number to find: ";
			cin >> number;
			FindByTrainNumber(TrainsList, number);
			break;
		case 5:
			cout << "Enter arrival hour and minute to find: ";
			cin >> hour >> minute;
			FindByTrainArriveTime(TrainsList, hour, minute);
			break;
		case 6:
			cout << "Enter departure hour and minute to find: ";
			cin >> hour >> minute;
			FindByTrainDepartTime(TrainsList, hour, minute);
			break;
		case 7:
			cout << "Enter arrival status (1 for arrived, 0 for not arrived): ";
			cin >> isArrived;
			FindByTrainIsArrived(TrainsList, isArrived);
			break;
		case 8:
			OutputInfo(TrainsList);
			break;
		case 9:
			cout << "Enter train name to change status: ";
			cin >> name;
			cout << "Enter new status (1 for arrived, 0 for not arrived): ";
			cin >> isArrived;
			changeIsArrived(TrainsList, name, isArrived);
			break;
		case 10:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 10);
	return 0;
}

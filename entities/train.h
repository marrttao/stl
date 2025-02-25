#pragma once
#ifndef TRAIN
#define TRAIN
#include "abstraction/ABSTrain.h"
#include <string>
#include <iostream>

template <typename T>
class Train : public AbstractTrain<T>
{
public:
    std::string trainName;
    int trainNumber;

    // Constructor
    Train() {
        // cin for each member
        std::cout << "Enter train name: ";
        std::cin >> trainName;
        std::cout << "Enter train number: ";
        std::cin >> trainNumber;
        std::cout << "Enter arrive time: ";
        std::cin >> this->ArriveTime.hour >> this->ArriveTime.minute;
        std::cout << "Enter depart time: ";
        std::cin >> this->DepartTime.hour >> this->DepartTime.minute;
        std::cout << "Enter is arrived (1 for true, 0 for false): ";
        std::cin >> this->isArrived;
    }

    Train(std::string name, int number) {
        trainName = name;
        trainNumber = number;
    }

    Train(std::string name, int number, typename AbstractTrain<T>::Time Arrive, typename AbstractTrain<T>::Time Depart, bool isArrive) {
        trainName = name;
        trainNumber = number;
        this->ArriveTime = Arrive;
        this->DepartTime = Depart;
        this->isArrived = isArrive;
    }

    void GetTrainInfo(T) const override {
        std::cout << "Train: " << trainName << " " << trainNumber
            << "\t Arrive time: " << this->ArriveTime.hour << ":" << this->ArriveTime.minute
            << "\t Depart time: " << this->DepartTime.hour << ":" << this->DepartTime.minute
            << "\t Is arrived: " << (this->isArrived ? "Yes" : "No") << std::endl;
    }

    void GetTrainInfo(T, T) const override {
        std::cout << "Train: " << trainName << " " << trainNumber
            << "\t Arrive time: " << this->ArriveTime.hour << ":" << this->ArriveTime.minute
            << "\t Depart time: " << this->DepartTime.hour << ":" << this->DepartTime.minute
            << "\t Is arrived: " << (this->isArrived ? "Yes" : "No") << std::endl;
    }

    void GetTrainInfo(T, T, T) const override {
        std::cout << "Train: " << trainName << " " << trainNumber
            << "\t Arrive time: " << this->ArriveTime.hour << ":" << this->ArriveTime.minute
            << "\t Depart time: " << this->DepartTime.hour << ":" << this->DepartTime.minute
            << "\t Is arrived: " << (this->isArrived ? "Yes" : "No") << std::endl;
    }
	void setIsArrived(bool isArrived) {
		this->isArrived = isArrived;
	}
};

#endif // !TRAIN

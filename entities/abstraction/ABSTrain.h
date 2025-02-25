#pragma once
#ifndef ABSTRAIN_H
#define ABSTRAIN_H

#include "../interface/ITrain.h"
#include <string>

template <typename T>
class AbstractTrain : public ITrain<T> {
public:
    struct Time {
        int hour;
        int minute;
    };

    Time ArriveTime;
    Time DepartTime;
    bool isArrived;

    virtual void GetTrainInfo(T) const override = 0;
    virtual void GetTrainInfo(T, T) const override = 0;
    virtual void GetTrainInfo(T, T, T) const override = 0;
    virtual ~AbstractTrain() = default;
};

#endif // ABSTRAIN_H

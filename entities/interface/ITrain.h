#pragma once
#ifndef ITRAIN_H
#define ITRAIN_H

template <typename T>
class ITrain {
public:
    virtual void GetTrainInfo(T) const = 0;
    virtual void GetTrainInfo(T, T) const = 0;
    virtual void GetTrainInfo(T, T, T) const = 0;
    virtual ~ITrain() = default;
};

#endif // ITRAIN_H

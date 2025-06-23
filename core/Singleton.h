//
// Created by avoro on 6/23/2025.
//

#ifndef SINGLETON_H
#define SINGLETON_H


template <typename T>
class Singleton {
protected:
    Singleton() = default;
    ~Singleton() = default;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T& getInstance() {
        static T instance;
        return instance;
    }
};




#endif //SINGLETON_H

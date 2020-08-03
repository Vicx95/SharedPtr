#pragma once

class RefCounter {
public:
    RefCounter();
    ~RefCounter();

    unsigned int getCounter();
    void reset();

    RefCounter& operator++();
    RefCounter& operator--();

    RefCounter(const RefCounter& refCounter) = delete;
    RefCounter& operator=(const RefCounter& refCounter) = delete;

private:
    unsigned int counter_;
};

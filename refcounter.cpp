#include "refcounter.hpp"

RefCounter::RefCounter()
    : counter_(0) {
}

RefCounter::~RefCounter() {
}

unsigned int RefCounter::getCounter() {
    return counter_;
}

void RefCounter::reset() {
    counter_ = 0;
}

RefCounter& RefCounter::operator++() {
    ++counter_;
    return *this;
}

RefCounter& RefCounter::operator--() {
    --counter_;
    return *this;
}

//
// Created by yahya on 5/19/2024.
//

#include <sstream>
#include "Assets.h"
#include "string"

Assets::Assets() {
    _numberOfTags = 0;
    _tags = nullptr;
}

Assets::Assets(const std::string& name) {
    _name = name;
    _numberOfTags = 0;
    _tags = nullptr;
}

Assets::~Assets() {
    delete[] _tags;
}

Assets::Assets(const Assets& other) {
    _name = other._name;
    _numberOfTags = other._numberOfTags;
    if (_numberOfTags > 0) {
        _tags = new std::string[_numberOfTags];
        for (size_t i = 0; i < _numberOfTags; i ++) {
            _tags[i] = other._tags[i];
        }
    }
    else {
        _tags = nullptr;
    }
}

const Assets& Assets::operator=(const Assets& rhs) {
    if (this != &rhs) {
// Destruction
        delete[] _tags;
// Construction
        _name = rhs._name;
        _numberOfTags = rhs._numberOfTags;
        if (_numberOfTags > 0) {
            _tags = new std::string[_numberOfTags];
            for (size_t i = 0; i < _numberOfTags; i ++) {
                _tags[i] = rhs._tags[i];
            }
        }
        else {
            _tags = nullptr;
        }
    }
    return *this;
}

void Assets::AddTag(const std::string& tag) {
    std::string* oldTags = _tags;
// Copy tags into a slightly larger block
    _tags = new std::string[_numberOfTags+1];
    for (size_t i = 0; i < _numberOfTags; i ++) {
        _tags[i] = oldTags[i];
    }
// Add the new tag and increment count
    _tags[_numberOfTags++] = tag;
// Deallocate the old block
    delete[] oldTags;
}

std::string Assets::ToString() {
    std::stringstream oss;
    oss << "{\"name\":\"" << _name << "\", \"numberofTags\":" << std::to_string(_numberOfTags) << ", \"Tags\":\"";
    for (int i = 0; i < _numberOfTags; ++i) {
        if (i > 0) oss << ";";
        oss << _tags[i];
    }
    oss << "\"}";

    return oss.str();
}
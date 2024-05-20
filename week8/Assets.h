//
// Created by yahya on 5/19/2024.
//

#ifndef WEEK8_ASSETS_H
#define WEEK8_ASSETS_H
#include "string";
#include "vector";

class Assets {
private:
    std::string _name;
    std::string* _tags;
    int _numberOfTags;

public:
    Assets();
    Assets(const std::string& name);
    Assets(const Assets& other);
    ~Assets();
    std::string ToString();

    const Assets& operator=(const Assets& rhs);

    void AddTag(const std::string& tag);



};


#endif //WEEK8_ASSETS_H

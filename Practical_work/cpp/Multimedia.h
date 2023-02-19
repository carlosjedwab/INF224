/**
 * @file Multimedia.h
 * @author Carlos Jedwab
 * @brief Multimedia class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <iostream>
using namespace std;

/**
 * @brief The Multimedia class
 * 
 */
class Multimedia
{
private:
    std::string name; /*< Name of the multimedia */
    std::string fileName; /*< Name of the file */

public:  
    Multimedia();
    Multimedia(std::string name, std::string fileName);
    ~Multimedia();
    void setName(std::string name);
    void setFileName(std::string fileName);
    const std::string getName();
    const std::string getFileName();
    virtual void display(std::ostream& os);
    virtual void play();
};
#endif

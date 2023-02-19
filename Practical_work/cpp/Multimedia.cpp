/**
 * @file Multimedia.cpp
 * @author Carlos Jedwab
 * @brief Multimedia class source file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Multimedia.h"
using namespace std;

/**
 * @brief Construct a new Multimedia:: Multimedia object
 * 
 */
Multimedia::Multimedia() {
    this->name = "Multimedia";
    this->fileName = "Multimedia.cpp";
}

/**
 * @brief Construct a new Multimedia:: Multimedia object
 * 
 * @param name 
 * @param fileName 
 */
Multimedia::Multimedia(std::string name, std::string fileName) {
    this->name = name;
    this->fileName = fileName;
}

/**
 * @brief Destroy the Multimedia:: Multimedia object
 * 
 */
Multimedia::~Multimedia() {
}

/**
 * @brief Set the Name object
 * 
 * @param name 
 */
void Multimedia::setName(std::string name) {
    this->name = name;
}

/**
 * @brief Set the File Name object
 * 
 * @param fileName 
 */
void Multimedia::setFileName(std::string fileName) {
    this->fileName = fileName;
}

/**
 * @brief Get the Name object
 * 
 * @return std::string 
 */
const std::string Multimedia::getName() {
    return name;
}

/**
 * @brief Get the File Name object
 * 
 * @return std::string 
 */
const std::string Multimedia::getFileName() {
    return fileName;
}

/**
 * @brief Display the multimedia object
 * 
 * @return int 
 */
void Multimedia::display(std::ostream& os) {
    os << "Nom: " << this->getName() << ";";
    os << "Nom du fichier: " << this->getFileName() << ";";
}

/**
 * @brief Play the multimedia object
 * 
 * @return int 
 */
void Multimedia::play() {}

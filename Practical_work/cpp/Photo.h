/**
 * @file Photo.h
 * @author Carlos Jedwab
 * @brief Photo class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PHOTO_H
#define PHOTO_H
#include "Multimedia.h"

/**
 * @brief The Photo class
 * 
 */
class Photo : public Multimedia
{
private:
    int latitude; /*< Latitude of the photo */
    int longitude; /*< Longitude of the photo */

public:
    /**
     * @brief Construct a new Photo object
     * 
     */
    Photo() : Multimedia() {
        this->latitude = 0;
        this->longitude = 0;
    }

    /**
     * @brief Construct a new Photo object
     * 
     * @param name 
     * @param fileName 
     * @param latitude 
     * @param longitude 
     */
    Photo(std::string name, std::string fileName, int latitude, int longitude) : Multimedia(name, fileName) {
        this->latitude = latitude;
        this->longitude = longitude;
    }

    /**
     * @brief Destroy the Photo object
     * 
     */
    ~Photo() {}

    /**
     * @brief Set the Latitude object
     * 
     * @param latitude 
     */
    void setLatitude(int latitude) {
        this->latitude = latitude;
    }

    /**
     * @brief Set the Longitude object
     * 
     * @param longitude 
     */
    void setLongitude(int longitude) {
        this->longitude = longitude;
    }

    /**
     * @brief Get the Latitude value
     * 
     * @return int 
     */
    int getLatitude() {
        return latitude;
    }

    /**
     * @brief Get the Longitude value
     * 
     * @return int 
     */
    int getLongitude() {
        return longitude;
    }

    /**
     * @brief Display the Photo object
     * 
     */
    void display(std::ostream& os) override {
        Multimedia::display(os);
        os << "Latitude: " << this->getLatitude() << ";";
        os << "Longitude: " << this->getLongitude() << ";";
    }

    /**
     * @brief Play the Photo object
     * 
     */
    void play() override {
        std::string command = "imagej " + this->getFileName() + " &";
        system(command.c_str());
    }
};
#endif

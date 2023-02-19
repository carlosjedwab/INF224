/**
 * @file Video.h
 * @author Carlos Jedwab
 * @brief Video class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VIDEO_H
#define VIDEO_H
#include "Multimedia.h"

/**
 * @brief The Video class
 * 
 */
class Video : public Multimedia
{
private:
    float duration; /*< Duration of the video */

public:
    /**
     * @brief Construct a new Video object
     * 
     */
    Video() : Multimedia() {
        this->duration = 0;
    }

    /**
     * @brief Construct a new Video object
     * 
     * @param name 
     * @param fileName 
     * @param duration 
     */
    Video(std::string name, std::string fileName, float duration) : Multimedia(name, fileName) {
        this->duration = duration;
    }

    /**
     * @brief Destroy the Video object
     * 
     */
    ~Video() {}

    /**
     * @brief Set the Duration value
     * 
     * @param duration 
     */
    void setDuration(int duration) {
        this->duration = duration;
    }

    /**
     * @brief Get the Duration value
     * 
     * @return float 
     */
    float getDuration() {
        return duration;
    }

    /**
     * @brief Display the Video object
     * 
     * @param os 
     */
    void display(std::ostream& os) override {
        Multimedia::display(os);
        os << "Durée: " << this->getDuration() << ";";
    }

    /**
     * @brief Play the Video object
     * 
     */
    void play() override {
        std::string command = "mpv " + this->getFileName() + " &";
        system(command.c_str());
    }
};
#endif

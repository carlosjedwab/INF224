/**
 * @file Movie.h
 * @author Carlos Jedwab
 * @brief Movie class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MOVIE_H
#define MOVIE_H
#include <vector>
#include "Video.h"

/**
 * @brief The Movie class
 * 
 */
class Movie : public Video
{
private:
    std::vector<int>* chapters; /*< Vector of chapters durations */

public:
    /**
     * @brief Construct a new Movie object
     * 
     */
    Movie() : Video() {
        this->chapters = new std::vector<int>();
    }

    /**
     * @brief Construct a new Movie object
     * 
     * @param name 
     * @param fileName 
     * @param duration 
     * @param chapters 
     */
    Movie(std::string name, std::string fileName, float duration, std::vector<int>* chapters) : Video(name, fileName, duration) {
        this->setChapters(chapters);
    }

    /**
     * @brief Destroy the Movie object
     * 
     */
    ~Movie() {
        delete this->chapters;
    }

    /**
     * @brief Set the Chapters object
     * 
     * @param chapters 
     */
    void setChapters(std::vector<int>* chapters) {
        delete this->chapters;
        this->chapters = new std::vector<int>(*chapters);
    }

    /**
     * @brief Get the Chapters object
     * 
     * @return std::vector<int> 
     */
    std::vector<int> getChapters() {
        return std::vector<int>(*this->chapters);
    }

    /**
     * @brief Get the Chapters size
     * 
     * @return int 
     */
    int getChaptersCount() {
        return (int)(*this->chapters).size();
    }

    /**
     * @brief Display the Movie object
     * 
     * @param os 
     */
    void display(std::ostream& os) override {
        Video::display(os);
        os << "Chapitres " << this->getChaptersCount() << ": " << ";";
        for (int i = 0; i < this->getChaptersCount(); i++) {
            os << "Chapitre " << i << ": " << (*this->chapters)[i] << ";";
        } 
    }
};

#endif
/**
 * @file Encapsulator.h
 * @author Carlos Jedwab
 * @brief Encapsulator class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ENCAPSULATOR_H
#define ENCAPSULATOR_H
#include <memory>
#include <map>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Movie.h"
#include "Group.h"

/**
 * @brief The encapsulator class
 * 
 */
class Encapsulator
{
private:
    typedef std::shared_ptr<Multimedia> MultimediaPtr; /*< Shared pointer to a Multimedia object */
    typedef std::shared_ptr<Group<MultimediaPtr>> GroupPtr; /*< Shared pointer to a Group object */
    typedef std::shared_ptr<Photo> PhotoPtr; /*< Shared pointer to a Photo object */
    typedef std::shared_ptr<Video> VideoPtr; /*< Shared pointer to a Video object */
    typedef std::shared_ptr<Movie> MoviePtr; /*< Shared pointer to a Movie object */

    std::map<std::string, MultimediaPtr> mediaMap; /*< Map of medias inside the encapsulator */
    std::map<std::string, GroupPtr> groupMap; /*< Map of groups inside the encapsulator */
    
public:
    Encapsulator() {}
    
    ~Encapsulator() {
        this->mediaMap.clear();
        this->groupMap.clear();
    }
    
    /**
     * @brief Create a Photo object
     * 
     * @param name 
     * @param fileName 
     * @param latitude 
     * @param longitude 
     * @return PhotoPtr 
     */
    PhotoPtr createPhoto(std::string name, std::string fileName, int latitude, int longitude) {
        PhotoPtr photo = std::make_shared<Photo>(name, fileName, latitude, longitude);
        this->mediaMap.insert(std::pair<std::string, MultimediaPtr>(name, photo));
        return photo;
    }

    /**
     * @brief Create a Video object
     * 
     * @param name 
     * @param fileName 
     * @param duration 
     * @return VideoPtr 
     */
    VideoPtr createVideo(std::string name, std::string fileName, int duration) {
        VideoPtr video = std::make_shared<Video>(name, fileName, duration);
        this->mediaMap.insert(std::pair<std::string, MultimediaPtr>(name, video));
        return video;
    
    }

    /**
     * @brief Create a Movie object
     * 
     * @param name 
     * @param fileName 
     * @param duration 
     * @param chapters 
     * @return MoviePtr 
     */
    MoviePtr createMovie(std::string name, std::string fileName, int duration, std::vector<int>* chapters) {
        MoviePtr movie = std::make_shared<Movie>(name, fileName, duration, chapters);
        this->mediaMap.insert(std::pair<std::string, MultimediaPtr>(name, movie));
        return movie;
    }

    /**
     * @brief Create a Group object
     * 
     * @param name 
     * @return GroupPtr 
     */
    GroupPtr createGroup(std::string name) {
        GroupPtr group = std::make_shared<Group<MultimediaPtr>>(name);
        this->groupMap.insert(std::pair<std::string, GroupPtr>(name, group));
        return group;
    }

    /**
     * @brief Check if a media exists
     * 
     * @param name 
     * @return true 
     * @return false 
     */
    bool hasMedia(std::string name) {
        return this->mediaMap.find(name) != this->mediaMap.end();
    }

    /**
     * @brief Check if a group exists
     * 
     * @param name 
     * @return true 
     * @return false 
     */
    bool hasGroup(std::string name) {
        return this->groupMap.find(name) != this->groupMap.end();
    }

    /**
     * @brief Add a media to a group
     * 
     * @param groupName 
     * @param mediaName 
     * @return true if the media was added to the group
     * @return false if the media or group was not found
     */
    bool addMediaToGroup(std::string groupName, std::string mediaName) {
        if (this->hasGroup(groupName) && this->hasMedia(mediaName)) {
            GroupPtr group = this->groupMap.find(groupName)->second;
            MultimediaPtr multimedia = this->mediaMap.find(mediaName)->second;
            group->push_back(multimedia);
            return true;
        } else {
            std::cout << "Le groupe ou le média n'existe pas." << " ";
            return false;
        }
    }

    /**
     * @brief Delete a media
     * 
     * @param name 
     * @return true if the media was deleted
     * @return false if the media was not found
     */
    bool deleteMedia(std::string name) {
        if (this->hasMedia(name)) {
            this->mediaMap.erase(name);
            return true;
        }
        return false;
    }

    /**
     * @brief Delete a group
     * 
     * @param name 
     * @return true if the group was deleted
     * @return false if the group was not found
     */
    bool deleteGroup(std::string name) {
        if (this->hasGroup(name)) {
            this->groupMap.erase(name);
            return true;
        }
        return false;
    }

    /**
     * @brief Display a media or a group
     * 
     * @param name 
     * @param os 
     * @return true if the media or group was found
     * @return false if the media or group was not found
     */
    bool findAndDisplay(std::string name, std::ostream& os) {
        if (this->hasMedia(name)) {
            this->mediaMap.find(name)->second->display(os);
            return true;
        } else if (this->hasGroup(name)) {
            this->groupMap.find(name)->second->display(os);
            return true;
        } else {
            os << "Aucun média ou groupe de ce nom n'existe." << std::endl;
            return false;
        }
    }

    /**
     * @brief Play a media
     * 
     * @param name 
     * @return true if the media did play
     * @return false if the media was not found
     */
    bool findAndPlay(std::string name) {
        if (this->mediaMap.find(name) != this->mediaMap.end()) {
            this->mediaMap.find(name)->second->play();
            return true;
        }
        return false;
    }
};
#endif
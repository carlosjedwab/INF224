/**
 * @file server.cpp
 * @author Carlos Jedwab
 * @brief Funtion to handle the request by running the corresponding action and returning the response
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TRUC_VERSION
#define TRUC_VERSION

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Encapsulator.h"

/**
 * @brief Handle the request of form "{action} {params_for_action}"
 * 
 * @param request 
 * @param encapsulator 
 * @return std::string for the response
 */
std::string handle_request(std::string request, Encapsulator* encapsulator)
{
  std::vector<std::string> requestVector; /* vector of words in the request */
  std::stringstream ss(request);
  std::string item;
  while (std::getline(ss, item, ' ')) {
    requestVector.push_back(item);
  }
  
  if (requestVector[0] == "create" && requestVector.size() > 1) {
    if (requestVector[1] == "photo" && requestVector.size() == 6) {
      std::string name = requestVector[2];
      std::string fileName = requestVector[3];
      int latitude = std::stoi(requestVector[4]);
      int longitude = std::stoi(requestVector[5]);
      if (encapsulator->createPhoto(name, fileName, latitude, longitude)) {
        return "Photo created";
      }
      else {
        return "Error: Photo not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "video" && requestVector.size() == 5) {
      std::string name = requestVector[2];
      std::string fileName = requestVector[3];
      int duration = std::stoi(requestVector[4]);
      if (encapsulator->createVideo(name, fileName, duration)) {
        return "Video created";
      }
      else {
        return "Error: Video not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "movie" && requestVector.size() >= 5) {
      std::string name = requestVector[2];
      std::string fileName = requestVector[3];
      int duration = std::stoi(requestVector[4]);
      std::vector<int> *chapters = new std::vector<int>();
      for (int i = 5; i < (int)requestVector.size(); i++) {
        chapters->push_back(std::stoi(requestVector[i]));
      }
      if (encapsulator->createMovie(name, fileName, duration, chapters)) {
        return "Movie created";
      }
      else {
        return "Error: Movie not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "group" && requestVector.size() == 3) {
      std::string name = requestVector[2];
      if (encapsulator->createGroup(name)) {
        return "Group created";
      }
      else {
        return "Error: Group not created (might be missing parameters)";
      }
    }
  }
  else if (requestVector[0] == "add" && requestVector.size() == 3) {
    std::string groupName = requestVector[1];
    std::string mediaName = requestVector[2];
    if (encapsulator->addMediaToGroup(groupName, mediaName)) {
      return "Media added";
    }
    else {
      return "Error: Media not added (media or group might not exist)";
    }
  }
  else if (requestVector[0] == "delete" && requestVector.size() == 3) {
    if (requestVector[1] == "group") {
      std::string name = requestVector[2];
      if (encapsulator->deleteGroup(name)) {
        return "Group deleted";
      }
      else {
        return "Error: Group not deleted (group might not exist)";
      }
    }
    else if (requestVector[1] == "media") {
      std::string name = requestVector[2];
      if (encapsulator->deleteMedia(name)) {
        return "Media deleted";
      }
      else {
        return "Error: Media not deleted (media might not exist)";
      }
    }
  }
  else if (requestVector[0] == "display" && requestVector.size() == 2) {
    std::string mediaName = requestVector[1];
    std::stringstream ss;
    encapsulator->findAndDisplay(mediaName, ss);
    return ss.str();
  }
  else if (requestVector[0] == "play" && requestVector.size() == 2) {
    std::string mediaName = requestVector[1];
    if (encapsulator->findAndPlay(mediaName)) {
      return "Media played";
    }
    else {
      return "Error: Media not played (media might not exist)";
    }
  }
  return "Error: Invalid request format (missing parameters or wrong action)";
};

#endif


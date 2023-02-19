/**
 * @file Group.h
 * @author Carlos Jedwab
 * @brief Group class header file
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GROUP_H
#define GROUP_H
#include <list>

/**
 * @brief The Group class
 * 
 * @tparam T 
 */
template <typename T>
class Group : public std::list<T>
{
private:
    std::string name; /*< Name of the group */
    
public:
    Group(std::string name) {
        this->name = name;
    }
    
    ~Group() {
        this->clear();
    }
    
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(std::string name) {
        this->name = name;
    }
    
    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName() {
        return name;
    }
    
    /**
     * @brief Display all the elements of the group
     * 
     * @return int 
     */
    void display(std::ostream& os) {
        os << "Nom: " << this->getName() << std::endl;
        os << "Nombre d'éléments: " << this->size() << std::endl;
        for (typename std::list<T>::iterator it = this->begin(); it != this->end(); it++) {
            os << " " << std::endl;
            (*it)->display(os);
        }
    }
};
#endif
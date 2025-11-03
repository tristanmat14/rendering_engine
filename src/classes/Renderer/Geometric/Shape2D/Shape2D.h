#pragma once
#include "Geometric.h"
#include "glm/glm.hpp"
#include <stdexcept>

class Shape2D : public Geometric {
private:
    glm::vec3 normal = glm::vec3{0.0f, 0.0f, 1.0f};

public:
    /**
     * sets the normal vector of the Shape2D object. The normal vector must have
     * a unit length.
     * @param newNormal - the new normal vector
     * @throws 
     */
    void setNormal(glm::vec3& newNormal) {
        if (std::abs(glm::length(newNormal) - 1.0f) > 1e-6f) {
            throw std::runtime_error("Provided normal vector not unit length");
        }
        normal = glm::vec3(newNormal);
    }
    
    glm::vec3 getNormal() const { return normal; }
};

#pragma once
#include <array>
#include "glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shape2D.h"

class Triangle : public Shape2D {
private:
    std::array<glm::vec3, 3> _vertices;
    GLuint vao, vbo;

    void updateVertexBuffers() {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(glm::vec3), _vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
public:
    explicit Triangle(std::array<glm::vec3, 3> vertices, glm::vec3 normal) : Triangle(vertices) {
        setNormal(normal);
    }

    explicit Triangle(std::array<glm::vec3, 3> vertices) : _vertices(vertices) {
        updateVertexBuffers();
    }

    void rotateAroundNormal(float angleDeg) {
        float angle = glm::radians(angleDeg);

        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), angle, getNormal());

        for (auto& v : _vertices) {
            v = glm::vec3(rotation * glm::vec4(v, 1.0f));
        }

        updateVertexBuffers();
    }

    // TODO: add virtual function overrides

    ~Triangle() {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
    }
};

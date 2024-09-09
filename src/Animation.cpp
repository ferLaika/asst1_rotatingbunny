#include "Animation.h"

Animation::Animation() {
	this->m_model_mat = glm::mat4(1.0f);
}

Animation::~Animation() {
}

void Animation::init() {
	reset();
}

void Animation::reset() {
    m_model_mat = glm::mat4(1.0f);
    m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0, 0.0, 0.0)); // Initial position
    m_rotate_angle_x = 0.0f;
    m_rotate_angle_y = 0.0f;
}

void Animation::update(float delta_time) {
    // Apply rotations
    m_model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, 0.0f)); // Translate to initial position
    m_model_mat = glm::rotate(m_model_mat, glm::radians(m_rotate_angle_y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate around global y-axis
    m_model_mat = glm::rotate(m_model_mat, glm::radians(m_rotate_angle_x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotate around local x-axis
}

void Animation::rotate_x(float angle) {
    m_rotate_angle_x += angle;
}

void Animation::rotate_y(float angle) {
    m_rotate_angle_y += angle;
}


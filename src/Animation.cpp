#include "Animation.h"
//Fernando de Salvidea FXD210003

Animation::Animation() {
	this->m_model_mat = glm::mat4(1.0f);
}

Animation::~Animation() {
}

void Animation::init() {
	reset();
}

void Animation::update(float delta_time) {
    glm::mat4 model_mat = glm::mat4(1.0f);

    // global y rotation
    model_mat = glm::rotate(model_mat, glm::radians(m_rotate_angle_y), glm::vec3(0.0f, 1.0f, 0.0f));

    // translate to the right
    model_mat = glm::translate(model_mat, glm::vec3(5.0f, 0.0f, 0.0f));

    // note: local x rotation
    model_mat = glm::rotate(model_mat, glm::radians(m_rotate_angle_x), glm::vec3(1.0f, 0.0f, 0.0f));
    m_model_mat = model_mat;
}

void Animation::reset() {
    m_model_mat = glm::mat4(1.0f);
    m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0f, 0.0f, 0.0f)); // Initial position
    m_rotate_angle_x = 0.0f;
    m_rotate_angle_y = 0.0f;
}

void Animation::rotate_x(float angle) {
    m_rotate_angle_x += angle;
    if (m_rotate_angle_x > 360.0f) m_rotate_angle_x -= 360.0f;
    else if (m_rotate_angle_x < 0.0f) m_rotate_angle_x += 360.0f;
}

void Animation::rotate_y(float angle) {
    m_rotate_angle_y += angle;
    if (m_rotate_angle_y > 360.0f) m_rotate_angle_y -= 360.0f;
    else if (m_rotate_angle_y < 0.0f) m_rotate_angle_y += 360.0f;
}


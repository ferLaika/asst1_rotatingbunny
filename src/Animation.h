#pragma once
//Fernando de Salvidea FXD210003
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Animation {
public:
	Animation();
	~Animation();

	void init();
	void update(float delta_time);
	void reset();
	glm::mat4 get_model_mat() { return m_model_mat; };

	// Task 3: define rotation variables/functions here
	void rotate_x(float angle);
    void rotate_y(float angle);

private:
	float m_rotate_angle_x; // x rotation local
    float m_rotate_angle_y; // y rotation global
	glm::mat4 m_model_mat;

};


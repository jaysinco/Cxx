#include "camera.h"

namespace cxx {

namespace gl {

    Camera::Camera(
        const std::string& id,
        float fov_in_degree,
        float aspect,
        float near,
        float far)
        : Base(Base::CAMERA, id)
    {
        projectionVec = glm::perspective(
            glm::radians(fov_in_degree),
            aspect, near, far);
    }

    void Camera::move(MOVE direction, float distance)
    {
        switch (direction) {
        case FORWARD:
            posVec += frontVec * distance;
            break;
        case BACKWARD:
            posVec -= frontVec * distance;
            break;
        case LEFT:
            posVec += rightVec * distance;
            break;
        case RIGHT:
            posVec += rightVec * distance;
            break;
        }
    }

    void Camera::moveTo(float x, float y, float z)
    {
        posVec = glm::vec3(x, y, z);
    }

    void Camera::shake(float degree)
    {
        yawDegree += degree;
    }

    void Camera::shakeTo(float degree)
    {
        shake(degree - yawDegree);
    }

    void Camera::nod(float degree)
    {
        pitchDegree += degree;
        if (pitchDegree > 89.0f)
            pitchDegree = 89.0f;
        if (pitchDegree < -89.0f)
            pitchDegree = -89.0f;
    }

    void Camera::nodTo(float degree)
    {
        nod(degree - pitchDegree);
    }

    glm::mat4 Camera::getViewMatrix()
    {
        updateVec();
        return glm::lookAt(posVec, posVec + frontVec, upVec);
    }

    glm::vec3 Camera::front() const
    {
        return frontVec;
    }

    glm::vec3 Camera::pos() const
    {
        return posVec;
    }

    glm::mat4 Camera::getProjectionMatrix() const
    {
        return projectionVec;
    }

    void Camera::updateVec()
    {
        glm::vec3 front;
        front.x = cos(glm::radians(yawDegree)) * cos(glm::radians(pitchDegree));
        front.y = sin(glm::radians(pitchDegree));
        front.z = sin(glm::radians(yawDegree)) * cos(glm::radians(pitchDegree));
        frontVec = glm::normalize(front);
        rightVec = glm::normalize(glm::cross(frontVec, worldUpVec));
        upVec = glm::normalize(glm::cross(rightVec, frontVec));
    }

} // namespace gl

} // namespace cxx
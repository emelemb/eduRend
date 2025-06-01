#include "Camera.h"

using namespace linalg;


void Camera::MoveTo(const vec3f& position) noexcept
{
    m_position = position;
}

void Camera::Move(const vec3f& direction) noexcept
{

    // local axises 
    vec3f Zaxis = { sin(m_yaw), 0, cos(m_yaw) };
    vec3f Yaxis = { 0, 1, 0 };
    vec3f Xaxis = { cos(m_yaw), 0 , -sin(m_yaw) };

    // fixing it in veiwSpace 
    vec3f movement = Zaxis * direction.z + Xaxis * direction.x + Yaxis * direction.y;
    m_position += movement;

}

void Camera::rotation(float dx, float dy) noexcept
{
    m_yaw -= dx * sensitivity;
    m_pitch -= dy * sensitivity;

    const float clamp = 1.55334f;  // pi/2

    if (m_pitch > clamp) m_pitch = clamp;
    if (m_pitch < -clamp) m_pitch = -clamp;
}

mat4f Camera::WorldToViewMatrix() const noexcept
{

    // Assuming a camera's position and rotation is defined by matrices T(p) and R,
    // the View-to-World transform is T(p)*R (for a first-person style camera).
    //
    // World-to-View then is the inverse of T(p)*R;
    //        inverse(T(p)*R) = inverse(R)*inverse(T(p)) = transpose(R)*T(-p)
    // Since now there is no rotation, this matrix is simply T(-p)

    mat4f translationMatrix = mat4f::translation(-m_position);
    mat4f rotationMatrix = mat4f::rotation(0, m_yaw, m_pitch);
    rotationMatrix.transpose();
    return rotationMatrix * translationMatrix;
}

const linalg::vec3f& Camera::GetPosition() const noexcept
{
    // TODO: insert return statement here
    return m_position;
}

mat4f Camera::ProjectionMatrix() const noexcept
{
    return mat4f::projection(m_vertical_fov, m_aspect_ratio, m_near_plane, m_far_plane);
}
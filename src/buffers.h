/**
 * @file buffers.h
 * @brief Contains constant buffers
*/

#pragma once

#include "vec/mat.h"

/**
 * @brief Contains transformation matrices.
*/
struct TransformationBuffer
{
	linalg::mat4f ModelToWorldMatrix; //!< Matrix for converting from object space to world space.
	linalg::mat4f WorldToViewMatrix; //!< Matrix for converting from world space to view space.
	linalg::mat4f ProjectionMatrix; //!< Matrix for converting from view space to clip cpace.
};


struct LightCameraBuffer
{
    vec4f cameraPos;
    vec4f lightPos;
};

struct MaterialBuffer
{
    vec4f ambientColor;  
    vec4f diffuseColor;
    vec4f specularColor;
    float shinyness;
    vec3f Padding;
};


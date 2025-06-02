/**
 * @file model.h
 * @brief Contains model definitions
 * @author Carl Johan Gribel 2016, cjgribel@gmail.com
*/

#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "stdafx.h"
#include <vector>
#include "vec\vec.h"
#include "vec\mat.h"
#include "Drawcall.h"
#include "OBJLoader.h"
#include "Texture.h"
#include "buffers.h"

using namespace linalg;

/**
 * @brief Abstract class. Defines the Render method and contains mesh data needed for a model.
*/
class Model
{
protected:
	// Pointers to the current device and device context
	ID3D11Device* const			m_dxdevice; //!< Graphics device, use for creating resources.
	ID3D11DeviceContext* const	m_dxdevice_context; //!< Graphics context, use for binding resources and draw commands.

	// Pointers to the class' vertex & index arrays
	ID3D11Buffer* m_vertex_buffer = nullptr; //!< Pointer to gpu side vertex buffer
	ID3D11Buffer* m_index_buffer = nullptr; //!< Pointer to gpu side index buffer
	ID3D11Buffer* m_material_buffer = nullptr;

	Material material;

	Texture m_diffuseTexture;

public:

	/**
	 * @brief Sets the protected member variables to the input params.
	 * @param dxdevice ID3D11Device to be used in the model.
	 * @param dxdevice_context ID3D11DeviceContext to be used in the model.
	*/
	Model(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context) 
		:	m_dxdevice(dxdevice), m_dxdevice_context(dxdevice_context) 
	{ 
		D3D11_BUFFER_DESC materialBufferDesc = {};
		materialBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		materialBufferDesc.ByteWidth = sizeof(MaterialBuffer);
		materialBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		materialBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		HRESULT hr = m_dxdevice->CreateBuffer(&materialBufferDesc, nullptr, &m_material_buffer);
		ASSERT(SUCCEEDED(hr));
	}
	
	void SetDiffuseTexture(const std::string& textureFilename)
	{
		HRESULT hr = LoadTextureFromFile(m_dxdevice, textureFilename.c_str(), &m_diffuseTexture);
		if (FAILED(hr)) {
			std::cerr << "ERROR: Failed to load texture: " << textureFilename << std::endl;
		}
		else {
			std::cout << "Successfully loaded texture: " << textureFilename << std::endl;
		}


	}


	/**
	 * @brief Abstract render method: must be implemented by derived classes
	*/
	virtual void Render() const = 0;
	void SetMaterial(const Material& m_material) { material = m_material; };



	/**
	 * @brief Destructor.
	 * @details Releases the vertex and index buffers of the Model.
	*/
	virtual ~Model()
	{ 
		SAFE_RELEASE(m_vertex_buffer);
		SAFE_RELEASE(m_index_buffer);
	}
};

#endif
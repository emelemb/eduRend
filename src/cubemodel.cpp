#include "Cubemodel.h"

CubeModel::CubeModel(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context) : Model(dxdevice, dxdevice_context) {

	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;

	// Populate the vertex array with 4 Vertices
	Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23;

	// Test for Rend 4
	// Front face (normal: 0,0,1)
	v0.Position = { -0.5f, -0.5f, 0.5f };
	v0.Normal = { 0, 0, 1 };
	v0.TexCoord = { 0, 0 };
	v0.Tangent = { 1, 0, 0 };
	v0.Binormal = { 0, 1, 0 };

	v1.Position = { 0.5f, -0.5f, 0.5f };
	v1.Normal = { 0, 0, 1 };
	v1.TexCoord = { 1, 0 };
	v1.Tangent = { 1, 0, 0 };
	v1.Binormal = { 0, 1, 0 };

	v2.Position = { 0.5f, 0.5f, 0.5f };
	v2.Normal = { 0, 0, 1 };
	v2.TexCoord = { 1, 1 };
	v2.Tangent = { 1, 0, 0 };
	v2.Binormal = { 0, 1, 0 };

	v3.Position = { -0.5f, 0.5f, 0.5f };
	v3.Normal = { 0, 0, 1 };
	v3.TexCoord = { 0, 1 };
	v3.Tangent = { 1, 0, 0 };
	v3.Binormal = { 0, 1, 0 };

	// Back face (normal: 0,0,-1)
	v4.Position = { -0.5f, -0.5f, -0.5f };
	v4.Normal = { 0, 0, -1 };
	v4.TexCoord = { 1, 0 };
	v4.Tangent = { -1, 0, 0 };
	v4.Binormal = { 0, 1, 0 };

	v5.Position = { -0.5f, 0.5f, -0.5f };
	v5.Normal = { 0, 0, -1 };
	v5.TexCoord = { 1, 1 };
	v5.Tangent = { -1, 0, 0 };
	v5.Binormal = { 0, 1, 0 };

	v6.Position = { 0.5f, 0.5f, -0.5f };
	v6.Normal = { 0, 0, -1 };
	v6.TexCoord = { 0, 1 };
	v6.Tangent = { -1, 0, 0 };
	v6.Binormal = { 0, 1, 0 };

	v7.Position = { 0.5f, -0.5f, -0.5f };
	v7.Normal = { 0, 0, -1 };
	v7.TexCoord = { 0, 0 };
	v7.Tangent = { -1, 0, 0 };
	v7.Binormal = { 0, 1, 0 };

	// Top face (normal: 0,1,0)
	v8.Position = { -0.5f, 0.5f, 0.5f };
	v8.Normal = { 0, 1, 0 };
	v8.TexCoord = { 0, 0 };
	v8.Tangent = { 1, 0, 0 };
	v8.Binormal = { 0, 0, -1 };

	v9.Position = { 0.5f, 0.5f, 0.5f };
	v9.Normal = { 0, 1, 0 };
	v9.TexCoord = { 1, 0 };
	v9.Tangent = { 1, 0, 0 };
	v9.Binormal = { 0, 0, -1 };

	v10.Position = { 0.5f, 0.5f, -0.5f };
	v10.Normal = { 0, 1, 0 };
	v10.TexCoord = { 1, 1 };
	v10.Tangent = { 1, 0, 0 };
	v10.Binormal = { 0, 0, -1 };

	v11.Position = { -0.5f, 0.5f, -0.5f };
	v11.Normal = { 0, 1, 0 };
	v11.TexCoord = { 0, 1 };
	v11.Tangent = { 1, 0, 0 };
	v11.Binormal = { 0, 0, -1 };

	// Bottom face (normal: 0,-1,0)
	v12.Position = { -0.5f, -0.5f, -0.5f };
	v12.Normal = { 0, -1, 0 };
	v12.TexCoord = { 0, 1 };
	v12.Tangent = { 1, 0, 0 };
	v12.Binormal = { 0, 0, 1 };

	v13.Position = { 0.5f, -0.5f, -0.5f };
	v13.Normal = { 0, -1, 0 };
	v13.TexCoord = { 1, 1 };
	v13.Tangent = { 1, 0, 0 };
	v13.Binormal = { 0, 0, 1 };

	v14.Position = { 0.5f, -0.5f, 0.5f };
	v14.Normal = { 0, -1, 0 };
	v14.TexCoord = { 1, 0 };
	v14.Tangent = { 1, 0, 0 };
	v14.Binormal = { 0, 0, 1 };

	v15.Position = { -0.5f, -0.5f, 0.5f };
	v15.Normal = { 0, -1, 0 };
	v15.TexCoord = { 0, 0 };
	v15.Tangent = { 1, 0, 0 };
	v15.Binormal = { 0, 0, 1 };

	// Right face (normal: 1,0,0)
	v16.Position = { 0.5f, -0.5f, -0.5f };
	v16.Normal = { 1, 0, 0 };
	v16.TexCoord = { 0, 0 };
	v16.Tangent = { 0, 1, 0 };
	v16.Binormal = { 0, 0, 1 };

	v17.Position = { 0.5f, 0.5f, -0.5f };
	v17.Normal = { 1, 0, 0 };
	v17.TexCoord = { 1, 0 };
	v17.Tangent = { 0, 1, 0 };
	v17.Binormal = { 0, 0, 1 };

	v18.Position = { 0.5f, 0.5f, 0.5f };
	v18.Normal = { 1, 0, 0 };
	v18.TexCoord = { 1, 1 };
	v18.Tangent = { 0, 1, 0 };
	v18.Binormal = { 0, 0, 1 };

	v19.Position = { 0.5f, -0.5f, 0.5f };
	v19.Normal = { 1, 0, 0 };
	v19.TexCoord = { 0, 1 };
	v19.Tangent = { 0, 1, 0 };
	v19.Binormal = { 0, 0, 1 };

	// Left face (normal: -1,0,0)
	v20.Position = { -0.5f, -0.5f, 0.5f };
	v20.Normal = { -1, 0, 0 };
	v20.TexCoord = { 1, 0 };
	v20.Tangent = { 0, 0, 1 };
	v20.Binormal = { 0, 1, 0 };

	v21.Position = { -0.5f, 0.5f, 0.5f };
	v21.Normal = { -1, 0, 0 };
	v21.TexCoord = { 1, 1 };
	v21.Tangent = { 0, 0, 1 };
	v21.Binormal = { 0, 1, 0 };

	v22.Position = { -0.5f, 0.5f, -0.5f };
	v22.Normal = { -1, 0, 0 };
	v22.TexCoord = { 0, 1 };
	v22.Tangent = { 0, 0, 1 };
	v22.Binormal = { 0, 1, 0 };

	v23.Position = { -0.5f, -0.5f, -0.5f };
	v23.Normal = { -1, 0, 0 };
	v23.TexCoord = { 0, 0 };
	v23.Tangent = { 0, 0, 1 };
	v23.Binormal = { 0, 1, 0 };

	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);
	vertices.push_back(v8);
	vertices.push_back(v9);
	vertices.push_back(v10);
	vertices.push_back(v11);
	vertices.push_back(v12);
	vertices.push_back(v13);
	vertices.push_back(v14);
	vertices.push_back(v15);
	vertices.push_back(v16);
	vertices.push_back(v17);
	vertices.push_back(v18);
	vertices.push_back(v19);
	vertices.push_back(v20);
	vertices.push_back(v21);
	vertices.push_back(v22);
	vertices.push_back(v23);

	for (size_t i = 0; i < 6; i++)
	{
		int temp = i * 4;

		// Triangle #1
		indices.push_back(temp + 0);
		indices.push_back(temp + 1);
		indices.push_back(temp + 3);
		// Triangle #2
		indices.push_back(temp + 1);
		indices.push_back(temp + 2);
		indices.push_back(temp + 3);
	}

	// Vertex Buffer
	D3D11_BUFFER_DESC vertexbufferDesc{ 0 };
	vertexbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexbufferDesc.CPUAccessFlags = 0;
	vertexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexbufferDesc.MiscFlags = 0;
	vertexbufferDesc.ByteWidth = (UINT)(vertices.size() * sizeof(Vertex));
	// Data resource
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = &vertices[0];
	// Create vertex buffer on device using descriptor & data
	dxdevice->CreateBuffer(&vertexbufferDesc, &vertexData, &m_vertex_buffer);
	SETNAME(m_vertex_buffer, "VertexBuffer");

	//  Index array descriptor
	D3D11_BUFFER_DESC indexbufferDesc = { 0 };
	indexbufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexbufferDesc.CPUAccessFlags = 0;
	indexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexbufferDesc.MiscFlags = 0;
	indexbufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));
	// Data resource
	D3D11_SUBRESOURCE_DATA indexData{ 0 };
	indexData.pSysMem = &indices[0];
	// Create index buffer on device using descriptor & data
	dxdevice->CreateBuffer(&indexbufferDesc, &indexData, &m_index_buffer);
	SETNAME(m_index_buffer, "IndexBuffer");

	m_number_of_indices = (unsigned int)indices.size();
}

void CubeModel::SetShininess(float shininess) {
	m_material_Shininess = shininess;
}


void CubeModel::Render()const
{
	//Update
	MaterialBuffer materialBufferData;
	materialBufferData.ambientColor = vec4f(material.AmbientColour, 1.0f);
	materialBufferData.diffuseColor = vec4f(material.DiffuseColour, 1.0f);
	materialBufferData.specularColor = vec4f(material.SpecularColour, m_material_Shininess);

	// Map and copy data to GPU buffer
	D3D11_MAPPED_SUBRESOURCE mapped;
	m_dxdevice_context->Map(m_material_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
	memcpy(mapped.pData, &materialBufferData, sizeof(MaterialBuffer));
	m_dxdevice_context->Unmap(m_material_buffer, 0);

	// Bind vertex and index buffers
	const UINT stride = sizeof(Vertex);
	const UINT offset = 0;
	m_dxdevice_context->IASetVertexBuffers(0, 1, &m_vertex_buffer, &stride, &offset);
	m_dxdevice_context->IASetIndexBuffer(m_index_buffer, DXGI_FORMAT_R32_UINT, 0);

	// Set primitive topology to triangles
	m_dxdevice_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Bind material_buffer to slot b1 of the PS
	m_dxdevice_context->PSSetConstantBuffers(1, 1, &m_material_buffer);

	// Diffuse 
	m_dxdevice_context->PSSetShaderResources(0, 1, &m_diffuseTexture.TextureView);

	// Normal
	m_dxdevice_context->PSSetShaderResources(1, 1, &material.NormalTexture.TextureView);

	// Render the cube (draw indices)
	m_dxdevice_context->DrawIndexed(m_number_of_indices, 0, 0);
}
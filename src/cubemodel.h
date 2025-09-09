#pragma once
#include "Model.h"

class CubeModel : public Model
{
private:
    //struct  Vertex
    //{
    //    float x, y, z; // Pos
    //    float nx, ny, nz; // Normal vec
    //    float u, v; // Texture coord
    //};

    unsigned m_number_of_indices = 0;
    //std::vector<Vertex> m_vertices;
/*  std::vector<uint32_t> m_indices;
    std::vector<Material> m_materials*/;

public: CubeModel(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context);

      virtual void Render() const;
};
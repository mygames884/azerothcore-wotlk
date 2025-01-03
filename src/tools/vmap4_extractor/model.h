/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MODEL_H
#define MODEL_H

#include "loadlib/loadlib.h"
#include "modelheaders.h"
#include "vec3d.h"

class MPQFile;
struct WMODoodadData;
namespace ADT { struct MDDF; struct MODF; }

Vec3D fixCoordSystem(Vec3D const& v);

class Model
{
private:
    void _unload()
    {
        delete[] vertices;
        delete[] indices;
        vertices = nullptr;
        indices = nullptr;
    }
    std::string filename;
public:
    ModelHeader header;
    Vec3D* vertices;
    uint16* indices;

    bool open();
    bool ConvertToVMAPModel(char const* outfilename);

    Model(std::string& filename);
    ~Model() { _unload(); }
};

namespace Doodad
{
    void Extract(ADT::MDDF const& doodadDef, char const* ModelInstName, uint32 mapID, uint32 tileX, uint32 tileY, FILE* pDirfile);

    void ExtractSet(WMODoodadData const& doodadData, ADT::MODF const& wmo, uint32 mapID, uint32 tileX, uint32 tileY, FILE* pDirfile);
}

#endif

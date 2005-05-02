// Copyright (C) 2005 Dave Griffiths
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#include "Renderer.h"
#include "Primitive.h"

#ifndef N_POLYPRIM
#define N_POLYPRIM

namespace fluxus
{

class PolyPrimitive : public Primitive
{
public:
	enum Type{TRISTRIP,QUADS,TRILIST,TRIFAN};
	
	PolyPrimitive(Type t=TRISTRIP);
	virtual  ~PolyPrimitive();
	
	virtual void AddVertex(const dVertex &Vert) { m_VertVec.push_back(Vert); }	
	virtual void Render();
	virtual void Finalise();
	virtual dBoundingBox GetBoundingBox();
	virtual void ApplyTransform(bool ScaleRotOnly=false);
	virtual string GetTypeName() { return "PolyPrimitive"; }
	virtual void SetData(char t, unsigned int i, dVector v);
	virtual dVector GetData(char t, unsigned int i);

	void VertColours(bool s) { m_VertColours=s; }
	
protected:
	
	Type m_Type;
	bool m_VertColours;
	float *m_VertData;
	float *m_NormData;
	float *m_ColData;
	float *m_TexData;
	int m_NumVerts;
	vector<dVertex> m_VertVec;
	
	friend istream &operator>>(istream &s, PolyPrimitive &o);
	friend ostream &operator<<(ostream &s, PolyPrimitive &o);
};

istream &operator>>(istream &s, PolyPrimitive &o);
ostream &operator<<(ostream &s, PolyPrimitive &o);

};

#endif

#pragma once


namespace rs3  {

enum EMITTER_TYPE 
{
	EMITTER_SPHERE = 0,
	EMITTER_BOX,
	EMITTER_RING,
	EMITTERTYPE_END
};

enum BILLBOARD_TYPE
{
	BILLBOARD_XYZ = 0,
	BILLBOARD_XZ,
	PLANE_XY,
	PLANE_YZ,
	PLANE_ZX,
	LINE_SPREAD,
	LINE_SPREAD_XY,
	LINE_SPREAD_YZ,
	LINE_SPREAD_ZX,
	EMITTER_ALIGN,
	BILLBOARDTYPE_END
};

enum EMITTER_UVMOD_TYPE
{
	EMITTER_UVMOD_DEFAULT,
	EMITTER_UVMOD_ANIMATION,
	EMITTER_UVMOD_TYPE_END
};

};
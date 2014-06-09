#ifndef _RTOKEN_H
#define _RTOKEN_H

//#pragma once

namespace rs3 {

#define RTOK_NAME			"name"
#define RTOK_SHADERNAME		"shadername"
#define RTOK_FILENAME		"filename"
#define RTOK_COUNT 			"count"
#define RTOK_INDEX 			"index"
#define RTOK_MAP_CHANNEL	"mapchannel"
#define RTOK_UNREDUCIBLE	"unreducible"

#define RTOK_MATERIALLIST	"MATERIALLIST"
#define RTOK_SUBMATERIALLIST "SUBMATERIALLIST"
#define RTOK_MATERIAL		"MATERIAL"
#define RTOK_SUBMATERIAL	"SUBMATERIAL"
#define RTOK_AMBIENT		"AMBIENT"
#define RTOK_DIFFUSE		"DIFFUSE"
#define RTOK_SPECULAR		"SPECULAR"
#define RTOK_SPECULAR_LEVEL	"SPECULAR_LEVEL"
#define RTOK_GLOSSINESS		"GLOSSINESS"
#define RTOK_POWER			"POWER"
#define RTOK_DIFFUSEMAP		"DIFFUSEMAP"
#define RTOK_SPECULARMAP	"SPECULARMAP"
#define RTOK_OPACITYMAP		"OPACITYMAP"
#define RTOK_NORMALMAP		"NORMALMAP"
#define RTOK_SELFILLUSIONSCALE		"SELFILLUSIONSCALE"
#define RTOK_SELFILLUMINATIONMAP	"SELFILLUMINATIONMAP"
#define RTOK_ADDITIVE		"ADDITIVE"
#define RTOK_TWOSIDED		"TWOSIDED"
#define RTOK_USEOPACITY		"USEOPACITY"
#define RTOK_USEALPHATEST	"USEALPHATEST"
#define RTOK_ALPHATESTVALUE	"ALPHATESTVALUE"
#define RTOK_ALPHATESTFUNC	"ALPHATESTFUNC"
#define RTOK_USEPARTSCOLOR	"USEPARTSCOLOR"
#define RTOK_REFLECTIONMAP	"REFLECTMAP"

// RCMPFUNC 에 대응
const char* const RTOK_COMPARE_FUNCTION[] = 
	{ "NEVER", "LESS", "EQUAL", "LESSEQUAL", "GREATER", "NOTEQUAL", "GREATEREQUAL", "ALWAYS" };

#define RTOK_BLEND_OP		"BLEND_OP"
#define RTOK_BLEND_SRC		"BLEND_SRC"
#define RTOK_BLEND_DEST		"BLEND_DEST"

#define RTOK_TFACTOR_COLOR	"TFACTOR_COLOR"

#define RTOK_ZENABLE		"ZENABLE"

#define RTOK_TEXTURE_LIST	"TEXTURELIST"
#define RTOK_TEXTURE_LAYER	"TEXTURELAYER"

#define RTOK_TEX_FILTER_MIN "TEX_FILTER_MIN"
#define RTOK_TEX_FILTER_MAX "TEX_FILTER_MAX"
#define RTOK_TEX_FILTER_MIP "TEX_FILTER_MIP"

#define RTOK_TEX_ADDRESS_U	"TEX_ADDRESS_U"
#define RTOK_TEX_ADDRESS_V	"TEX_ADDRESS_V"
#define RTOK_TEX_ADDRESS_W	"TEX_ADDRESS_W"

static const char*	RTOK_TEX_ADDRESS_MIRROR	= "MIRROR";
static const char*	RTOK_TEX_ADDRESS_BORDER	= "BORDER";

#define RTOK_TEX_COLOR_OP	"TEX_COLOR_OP"
#define RTOK_TEX_COLOR_ARG0	"TEX_COLOR_ARG0"
#define RTOK_TEX_COLOR_ARG1	"TEX_COLOR_ARG1"
#define RTOK_TEX_COLOR_ARG2	"TEX_COLOR_ARG2"

#define RTOK_TEX_ALPHA_OP	"TEX_ALPHA_OP"
#define RTOK_TEX_ALPHA_ARG0	"TEX_ALPHA_ARG0"
#define RTOK_TEX_ALPHA_ARG1	"TEX_ALPHA_ARG1"
#define RTOK_TEX_ALPHA_ARG2	"TEX_ALPHA_ARG2"

#define RTOK_TEX_ANI_COUNT	"TEX_ANI_COUNT"
#define RTOK_TEX_ANI_SPEED	"TEX_ANI_SPEED"
#define RTOK_TEX_ANIMATION	"TEX_ANIMATION"

#define RTOK_TEX_OFFSET		"TEX_OFFSET"
#define RTOK_TEX_SCALE		"TEX_SCALE"
#define RTOK_TEX_ROTATE		"TEX_ROTATE"

#define RTOK_LIGHTLIST		"LIGHTLIST"
#define RTOK_LIGHT			"LIGHT"
#define RTOK_POSITION		"POSITION"
#define RTOK_DIRECTION		"DIRECTION"
#define RTOK_MATRIX0		"MATRIX0"
#define RTOK_MATRIX1		"MATRIX1"
#define RTOK_MATRIX2		"MATRIX2"
#define RTOK_MATRIX3		"MATRIX3"

#define RTOK_COLOR			"COLOR"
#define RTOK_INTENSITY		"INTENSITY"
#define RTOK_ATTNSTART		"ATTENUATIONSTART"
#define RTOK_ATTNEND		"ATTENUATIONEND"
#define RTOK_CASTSHADOW		"CASTSHADOW"
#define RTOK_RECEIVESHADOW	"RECEIVESHADOW"
#define RTOK_VISIBLE_LAYER01	"VISIBLE_LAYER01"

#define RTOK_OBJECTLIST		"OBJECTLIST"
#define RTOK_OBJECT			"OBJECT"

#define RTOK_SPAWNPOSITIONLIST	"SPAWNPOSITIONLIST"
#define RTOK_SPAWNPOSITION		"SPAWNPOSITION"

#define RTOK_OCCLUSIONLIST	"OCCLUSIONLIST"
#define RTOK_OCCLUSION		"OCCLUSION"

#define RTOK_DUMMYLIST		"DUMMYLIST"
#define RTOK_DUMMY			"DUMMY"

#define RTOK_FLAG					"FLAG"
#define RTOK_FLAG_NAME				"NAME"
#define RTOK_FLAG_DIRECTION			"DIRECTION"		
#define RTOK_FLAG_POWER				"POWER"
#define RTOK_RESTRICTION			"RESTRICTION"
#define RTOK_RESTRICTION_AXIS		"AXIS"
#define RTOK_RESTRICTION_POSITION	"POSITION"
#define RTOK_RESTRICTION_COMPARE	"COMPARE"
#define RTOK_WINDTYPE				"TYPE"
#define RTOK_WINDDELAY				"DELAY"

#define RTOK_SMOKE					"SMOKE"
#define RTOK_SMOKE_NAME				"NAME"
#define RTOK_SMOKE_DIRECTION		"DIRECTION"
#define RTOK_SMOKE_POWER			"POWER"
#define RTOK_SMOKE_DELAY			"DELAY"
#define RTOK_SMOKE_SIZE				"SIZE"
#define RTOK_SMOKE_COLOR			"COLOR"
#define RTOK_SMOKE_LIFE				"LIFE"
#define RTOK_SMOKE_TOGMINTIME		"TOGGLEMINTIME"

#define RTOK_FOG		"FOG"
#define RTOK_GLOBAL		"GLOBAL"

#define RTOK_SHADEREFFECTS		"SHADEREFFECTS"
#define RTOK_SHADEREFFECT		"SHADEREFFECT"

//////////////// 맵 디자인 규칙

#define RTOK_MAX_OBJLIGHT		"obj_"			// object 에만 영향을 주는 광원의 이름은 이렇게 시작한다.
#define RTOK_MAX_NOPATH			"nopath_"		// 갈수없는 곳은 이렇게 시작한다.
#define RTOK_MAX_EXPORTOBJ		"obj_"			// elu 로 export 하는 오브젝트들은 이렇게 이름이 시작한다.. (애니메이션이 있으면 자동)
#define RTOK_MAX_SPAWNPOINT		"spawn_"		// spawn position 임을 나타낸다. ( dummy object 로 놓아야 한다 )
#define RTOK_MAX_PASSTHROUGH	"pass_"			// 충돌체크를 통과한다.
#define RTOK_MAX_HIDE			"hide_"			// 이런 이름을 가진 오브젝트는 렌더링되지 않는다.
#define RTOK_MAX_OCCLUSION		"wall_"			// 벽.. (culling을 위한 추가정보)
#define RTOK_MAX_PASSBULLET		"passb_"		// 총알통과
#define RTOK_MAX_PASSROCKET		"passr_"		// 로켓및 수류탄 통과
#define RTOK_MAX_OCCLUSION		"wall_"			// 벽.. (culling을 위한 추가정보)
#define RTOK_MAX_PARTITION		"partition_"	// 공간 분할을 위한 평면 partition_0 partition_1 ... 이런 식으로 쓴다
#define RTOK_MAX_NAVIGATION		"hnav_"			// 인공지능 길찾기 정보 메쉬 - hide와 마찬가지로 렌더링되지 않는다.
#define RTOK_MAX_SMOKE_SS		"smk_ss_"		// 굴뚝의 연기 더미..
#define RTOK_MAX_CELL			"cell_"			// 공간 분할 : 셀
#define RTOK_MAX_PORTAL			"portal_"		// 공간 분할 : 포탈

}

#endif

// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#pragma warning ( disable : 4996)

#ifndef _WIN32_WINNT		// Windows XP 이상에서만 기능을 사용할 수 있습니다.                   
#define _WIN32_WINNT 0x0501	// 다른 버전의 Windows에 맞도록 적합한 값으로 변경해 주십시오.
#endif						

#define WIN32_LEAN_AND_MEAN		// 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.

#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <tchar.h>
#include <atlconv.h>
#include <atlexcept.h>

#include <Winsock2.h>
#include <mswsock.h>
#include <crtdbg.h>
#include <windows.h>

// C의 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

#include "MXml.h"
#include "MFileSystem.h"
#include "MDebug.h"

#include "RTypes.h"

using namespace rs3;

#include "VDef.h"
#include "VGlobal.h"
#include "VErrorMsg.h"

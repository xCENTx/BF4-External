#pragma once
#define _USE_MATH_DEFINES
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <cmath>
#include <string>

namespace BF4
{
	__int64 GetGame();
	__int64 GetPlayerManager();
	__int64 GetLocalClient();
	__int32 GetClientTeamID(__int64 pClient);
	bool IsFriendly(__int64 pClient, __int32 localTeam = 0);
	std::string GetClientName(__int64 pClient);
	__int64 GetClientByIndex(__int8 index);
	bool GetClientArray(std::vector<__int64>* outClients);
	__int64 GetClientSoldier(__int64 pClient);
	struct Vector3 GetSoldierPos(__int64 pSoldier);
	bool IsVisible(__int64 pSoldier);
	bool IsAlive(__int64 pSoldier);
	float GetHealthPercent(__int64 pSoldier);
	bool WorldToScreen(struct Vector3 origin, struct Vector2* screen);
	bool GetBoneByIndex(__int64 pSoldier, __int32 boneIndex, struct Vector3* origin);
}

#include "BF4_Classes.h"
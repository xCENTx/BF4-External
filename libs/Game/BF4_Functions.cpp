#include "BF4_Functions.h"
#include "Memory.h"

namespace BF4
{
	__int64 GetGame()
	{
		auto pMain = g_Memory->Read<long long>(0x142364b78);
		if (!Memory::IsValidPtr(pMain))
			return 0;

		auto pClient = g_Memory->Read<long long>(pMain + BF4::Offsets::oCLIENT);
		if (!Memory::IsValidPtr(pClient))
			return 0;

		return g_Memory->Read<long long>(pClient + BF4::Offsets::oGAMECTX);
	}

	__int64 GetPlayerManager()
	{
		auto pGame = GetGame();
		if (!Memory::IsValidPtr(pGame))
			return 0;

		return g_Memory->Read<long long>(pGame + BF4::Offsets::oPLAYERMANAGER);
	}

	__int64 GetLocalClient()
	{
		auto pPlayerMan = GetPlayerManager();
		if (!Memory::IsValidPtr(pPlayerMan))
			return 0;

		return g_Memory->Read<long long>(pPlayerMan + BF4::Offsets::oLocalPlayer);
	}

	std::string GetClientName(__int64 pClient)
	{
		return std::string();
	}

	__int32 GetClientTeamID(__int64 pClient)
	{
		return g_Memory->Read<__int32>(pClient + BF4::Offsets::oTeamId);
	}

	bool IsFriendly(__int64 pClient , __int32 teamID )
	{
		if (!teamID)
			teamID = GetClientTeamID(GetLocalClient());
		__int32 cTeam = GetClientTeamID(pClient);
		return cTeam == teamID;
	}
	
	__int64 GetClientByIndex(__int8 index)
	{
		std::vector<__int64> clients;
		if (!GetClientArray(&clients))
			return 0;
		
		return clients.at(index);
	}
	
	bool GetClientArray(std::vector<__int64>* outSoldiers)
	{
		long long pPlayerMan = GetPlayerManager();
		if (!Memory::IsValidPtr(pPlayerMan))
			return false;

		auto pPlayerArray = g_Memory->Read<long long>(pPlayerMan + BF4::Offsets::oPlayerArray);
		if (!Memory::IsValidPtr(pPlayerArray))
			return false;

		std::vector<__int64> result;
		for (int i = 0; i < 70; i++)
		{

			auto ent = g_Memory->Read<long long>(pPlayerArray + (i * 0x8));
			if (!Memory::IsValidPtr(ent))
				continue;

			result.push_back(ent);
		}

		*outSoldiers = result;

		return result.size() > 0;
	}
	
	__int64 GetClientSoldier(__int64 pSoldier)
	{
		return g_Memory->Read<long long>(pSoldier + BF4::Offsets::oSOLDIER);
	}
	
	Vector3 GetSoldierPos(__int64 pSoldier)
	{
		auto pEntTransforms = g_Memory->Read<long long>(pSoldier + BF4::Offsets::oTRANSFORMS);
		if (!Memory::IsValidPtr(pEntTransforms))
			return Vector3();

		return g_Memory->Read<BF4::Vector3>(pEntTransforms + BF4::Offsets::oPosition);
	}

	bool IsAlive(__int64 pSoldier)
	{
		auto pEntHealth = g_Memory->Read<long long>(pSoldier + BF4::Offsets::oHEALTH);
		if (!Memory::IsValidPtr(pEntHealth))
			return false;

		return g_Memory->Read<float>(pEntHealth + BF4::Offsets::oHP) > 0.0f;
	}
	
	float GetHealthPercent(__int64 pSoldier)
	{
		auto pEntHealth = g_Memory->Read<long long>(pSoldier + BF4::Offsets::oHEALTH);
		if (!Memory::IsValidPtr(pEntHealth))
			return false;

		return g_Memory->Read<float>(pEntHealth + BF4::Offsets::oHP) / 100.f;
	}

	bool IsVisible(__int64 pSoldier)
	{
		auto pEntTransforms = g_Memory->Read<long long>(pSoldier + BF4::Offsets::oTRANSFORMS);
		if (!Memory::IsValidPtr(pEntTransforms))
			return false;

		return g_Memory->Read<bool>(pSoldier + BF4::Offsets::oOccluded) == false;
	}
	
	bool WorldToScreen(Vector3 origin, Vector2* out)
	{
		Vector3 result;

		auto pRenderer = g_Memory->Read<long long>(Offsets::pGameRenderer);
		if (!g_Memory->IsValidPtr(pRenderer))
			return false;

		auto pRenderView = g_Memory->Read<long long>(pRenderer + Offsets::oRENDERERVIEW);
		if (!g_Memory->IsValidPtr(pRenderView))
			return false;

		auto view_x_projection = g_Memory->Read<Matrix4x4>(pRenderView + Offsets::oViewMatrix);

		auto pDxRenderer = g_Memory->Read<long long>(Offsets::pDxRenderer);
		if (!g_Memory->IsValidPtr(pDxRenderer))
			return false;

		auto m_pScreen = g_Memory->Read<long long>(pDxRenderer + 0x38);
		if (!g_Memory->IsValidPtr(m_pScreen))
			return false;

		int ScreenWidth, ScreenHeight;
		ScreenWidth = g_Memory->Read<int>(m_pScreen + 0x58);
		ScreenHeight = g_Memory->Read<int>(m_pScreen + 0x5C);

		float cX = ScreenWidth * 0.5f;
		float cY = ScreenHeight * 0.5f;

		auto x = view_x_projection.x.x * origin.x + view_x_projection.y.x * origin.y + view_x_projection.z.x * origin.z + view_x_projection.w.x;
		auto y = view_x_projection.x.y * origin.x + view_x_projection.y.y * origin.y + view_x_projection.z.y * origin.z + view_x_projection.w.y;
		auto z = view_x_projection.x.z * origin.x + view_x_projection.y.z * origin.y + view_x_projection.z.z * origin.z + view_x_projection.w.z;
		auto w = view_x_projection.x.w * origin.x + view_x_projection.y.w * origin.y + view_x_projection.z.w * origin.z + view_x_projection.w.w;

		if (w < 0.0001f)
		{
			result.z = w;
			return false;
		}

		result.x = cX * (1 + x / w);
		result.y = cY * (1 - y / w);
		result.z = w;

		*out = { result.x, result.y };

		return true;
	}

	bool GetBoneByIndex(__int64 pSoldier, __int32 boneIndex, Vector3* out)
	{
		Vector3 tmp;
		
		auto pRagdoll = g_Memory->Read<long long>(pSoldier + Offsets::oRagdoll);
		if (!Memory::IsValidPtr(pRagdoll))
			false;

		auto quat = g_Memory->Read<long long>(pRagdoll + 0xB0);
		if (!Memory::IsValidPtr(quat))
			false;

		tmp = g_Memory->Read<Vector3>(quat + (boneIndex * 0x20));

		*out = tmp;

		return true;
	}
}
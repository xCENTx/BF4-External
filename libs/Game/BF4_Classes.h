#pragma once
namespace BF4
{
	enum Bones
	{
		Reference = 0,
		AITrajectory = 1,
		Trajectory = 2,
		TrajectoryEnd = 3,
		Hips = 4,
		Spine = 5,
		Spine1 = 6,
		Spine2 = 7,
		LeftShoulder = 8,
		LeftArm = 9,
		LeftArmRoll = 10,
		LeftForeArm = 11,
		LeftForeArmRoll = 12,
		LeftForeArmRoll1 = 13,
		LeftHand = 14,
		LeftHandMiddle0 = 15,
		LeftHandMiddle1 = 16,
		LeftHandMiddle2 = 17,
		LeftHandMiddle3 = 18,
		LeftHandMiddle4 = 19,
		LeftHandRing0 = 20,
		LeftHandRing1 = 21,
		LeftHandRing2 = 22,
		LeftHandRing3 = 23,
		LeftHandRing4 = 24,
		LeftHandPinky0 = 25,
		LeftHandPinky1 = 26,
		LeftHandPinky2 = 27,
		LeftHandPinky3 = 28,
		LeftHandPinky4 = 29,
		LeftHandIndex0 = 30,
		LeftHandIndex1 = 31,
		LeftHandIndex2 = 32,
		LeftHandIndex3 = 33,
		LeftHandIndex4 = 34,
		LeftHandThumb1 = 35,
		LeftHandThumb2 = 36,
		LeftHandThumb3 = 37,
		LeftHandThumb4 = 38,
		LeftHandProp1 = 39,
		LeftElbowRoll = 40,
		LeftArmCloth = 41,
		LeftShoulderPhys1 = 42,
		Neck = 43,
		Neck1 = 44,
		Head = 45,
		HeadEnd = 46,
		Face = 47,
		Jaw = 48,
		LeftLowerLip = 49,
		LeftLowerInnerLip = 50,
		LowerLip = 51,
		LowerInnerLip = 52,
		RightLowerLip = 53,
		RightLowerInnerLip = 54,
		Tongue = 55,
		TongueTip = 56,
		Chin = 57,
		LeftLowCheek = 58,
		RightLowCheek = 59,
		LeftEye = 60,
		LeftIris = 61,
		RightEye = 62,
		RightIris = 63,
		LeftUpCheek = 64,
		LeftUpInnerCheek = 65,
		RightUpInnerCheek = 66,
		RightUpCheek = 67,
		LeftCheek = 68,
		RightCheek = 69,
		LeftMouth = 70,
		LeftInnerMouth = 71,
		LeftMiddleCrease = 72,
		LeftUpperLip = 73,
		LeftUpperInnerLip = 74,
		UpperLip = 75,
		UpperInnerLip = 76,
		RightUpperLip = 77,
		RightUpperInnerLip = 78,
		RightMouth = 79,
		RightInnerMouth = 80,
		RightMiddleCrease = 81,
		LeftUpEyelid = 82,
		RightUpEyelid = 83,
		LeftLowEyelid = 84,
		RightLowEyelid = 85,
		LeftInnerEyebrow = 86,
		LeftOuterEyebrow = 87,
		RightInnerEyebrow = 88,
		RightOuterEyebrow = 89,
		LeftNose = 90,
		RightNose = 91,
		LeftCrease = 92,
		RightCrease = 93,
		LeftLowMiddleEyebrow = 94,
		RightMiddleEyebrow = 95,
		LeftLowEyelidCrease = 96,
		LeftLowOuterEyebrow = 97,
		NoseTip = 98,
		RightLowOuterEyebrow = 99,
		LeftMiddleEyebrow = 100,
		RightLowMiddleEyebrow = 101,
		RightLowEyelidCrease = 102,
		LowNose = 103,
		HeadCloth = 104,
		Throat = 105,
		Spine2Phys1 = 106,
		Spine2Prop1 = 107,
		RightShoulder = 108,
		RightArm = 109,
		RightArmRoll = 110,
		RightForeArm = 111,
		RightForeArmRoll = 112,
		RightForeArmRoll1 = 113,
		RightHand = 114,
		RightHandMiddle0 = 115,
		RightHandMiddle1 = 116,
		RightHandMiddle2 = 117,
		RightHandMiddle3 = 118,
		RightHandMiddle4 = 119,
		RightHandRing0 = 120,
		RightHandRing1 = 121,
		RightHandRing2 = 122,
		RightHandRing3 = 123,
		RightHandRing4 = 124,
		RightHandPinky0 = 125,
		RightHandPinky1 = 126,
		RightHandPinky2 = 127,
		RightHandPinky3 = 128,
		RightHandPinky4 = 129,
		RightHandIndex0 = 130,
		RightHandIndex1 = 131,
		RightHandIndex2 = 132,
		RightHandIndex3 = 133,
		RightHandIndex4 = 134,
		RightHandThumb1 = 135,
		RightHandThumb2 = 136,
		RightHandThumb3 = 137,
		RightHandThumb4 = 138,
		RightHandProp1 = 139,
		RightElbowRoll = 140,
		RightArmCloth = 141,
		RightShoulderPhys1 = 142,
		Wep_Root = 143,
		Wep_Trigger = 144,
		Wep_Slide = 145,
		Wep_Grenade1 = 146,
		Wep_Grenade2 = 147,
		Wep_Mag = 148,
		Wep_Mag_Ammo = 149,
		Wep_Mag_Extra1 = 150,
		Wep_Scope1 = 151,
		Wep_Scope2 = 152,
		Wep_Belt1 = 153,
		Wep_Belt2 = 154,
		Wep_Belt3 = 155,
		Wep_Belt4 = 156,
		Wep_Belt5 = 157,
		Wep_Belt6 = 158,
		Wep_Belt7 = 159,
		Wep_Belt8 = 160,
		Wep_Belt9 = 161,
		Wep_Belt10 = 162,
		Wep_Bipod1 = 163,
		Wep_Bipod2 = 164,
		Wep_Bipod3 = 165,
		IK_Joint_LeftHand = 166,
		IK_Joint_RightHand = 167,
		Wep_Physic1 = 168,
		Wep_Physic2 = 169,
		Wep_Physic3 = 170,
		Wep_Physic4 = 171,
		Wep_Physic5 = 172,
		Wep_Extra1 = 173,
		Wep_Extra2 = 174,
		Wep_Extra3 = 175,
		Wep_Extra4 = 176,
		Wep_Extra5 = 177,
		Wep_Aim = 178,
		LeftSpine1Phys1 = 179,
		RightSpine1Phys1 = 180,
		LeftUpLeg = 181,
		LeftUpLegRoll = 182,
		LeftLeg = 183,
		LeftFoot = 184,
		LeftToeBase = 185,
		LeftToe = 186,
		LeftLegCloth = 187,
		LeftKneeRoll = 188,
		LeftHipsRoll = 189,
		LeftUpLegCloth = 190,
		HipsCloth = 191,
		LeftHipsFrontPhys = 192,
		LeftHipsBackPhys = 193,
		LeftHipsSidePhys = 194,
		RightUpLeg = 195,
		RightUpLegRoll = 196,
		RightLeg = 197,
		RightFoot = 198,
		RightToeBase = 199,
		RightToe = 200,
		RightLegCloth = 201,
		RightKneeRoll = 202,
		RightHipsRoll = 203,
		RightUpLegCloth = 204,
		RightHipsFrontPhys = 205,
		RightHipsBackPhys = 206,
		RightHipsSidePhys = 207,
		CameraBase = 208,
		CameraJoint = 209,
		Connect = 210,
		ConnectEnd = 211,
		FacePosesAnimation = 212
	};

	static std::vector<std::vector<int>> BoneVector
	{
		{ Bones::LeftHand, Bones::LeftForeArm, Bones::LeftArm, Bones::Neck },            // Left hand -> neck
		{ Bones::RightHand, Bones::RightForeArm, Bones::RightArm, Bones::Neck },            // Right hand -> neck
		{ Bones::LeftToe, Bones::LeftFoot, Bones::LeftLeg, Bones::LeftUpLegRoll, Bones::LeftUpLeg, Bones::Spine },   // Left foot -> bottom spine
		{ Bones::RightToe, Bones::RightFoot, Bones::RightLeg, Bones::RightUpLegRoll, Bones::RightUpLeg, Bones::Spine },   // Right foot -> bottom spine
		{ Bones::Spine, Bones::Spine1, Bones::Spine2, Bones::Neck, Bones::Neck1 }											// Bottom spine -> head
	};

	static std::vector<int> SkeletonBoundsVector
	{
		Bones::LeftHand,	Bones::LeftArm,
		Bones::RightHand,	Bones::RightArm,
		Bones::LeftToe,		Bones::LeftUpLegRoll,	Bones::LeftUpLeg,
		Bones::RightToe,	Bones::RightUpLegRoll,	Bones::RightUpLeg,
		Bones::Spine, Bones::Spine1,		Bones::Spine2,			Bones::Neck,		Bones::Neck1,	Bones::Head, Bones::HeadEnd
	};

	//	-

	struct Offsets
	{
		//	Static Class Pointers
		static constexpr auto pClientGameCTX = 0x142670d80;
		static constexpr auto pDxRenderer = 0x142738080;
		static constexpr auto pGameRenderer = 0x142672378;
		static constexpr auto pAngles = 0x1423b2ec0;
		static constexpr auto pWorldRenderSettings = 0x1426724a0;

		//  Class Offsets
		static constexpr auto oRENDERERVIEW		= 0x0060;	   //  GameRenderer->m_pRenderView
		static constexpr auto oViewMatrix		= 0x0420;	   //  RenderView->m_ViewProjection
		static constexpr auto oCLIENT			= 0x0050;      //  Main->m_pClient
		static constexpr auto oGAMECTX			= 0x0028;      //  Client->m_pGameContext
		static constexpr auto oPLAYERMANAGER	= 0x0060;      //  ClientGameContext->m_pPlayerMan
		static constexpr auto oLocalPlayer		= 0x0540;      //  PlayerManager->m_pLocalPlayer
		static constexpr auto oPlayerArray		= 0x0548;      //  PlayerManager->m_pPlayerArray
		static constexpr auto oTeamId			= 0x13CC;      //  ClientPlayer->TeamID
		static constexpr auto oSOLDIER			= 0x14D0;      //  ClientPlayer->m_pClientSoldier
		static constexpr auto oHEALTH			= 0x0140;      //  ClientSoldier->m_pHealthComponent
		static constexpr auto oTRANSFORMS		= 0x0490;      //  ClientSoldier->m_pSoldierTransforms
		static constexpr auto oRagdoll			= 0x0580;      //  ClientSoldier->m_pRagdollComponent
		static constexpr auto oOccluded			= 0x05B1;      //  ClientSoldier->m_bOccluded
		static constexpr auto oPosition			= 0x0030;      //  SoldierTransforms->origin
		static constexpr auto oHP				= 0x0020;      //  HealthComponent->Health
		static constexpr auto oHPmax			= 0x0024;      //  HealthComponent->MaxHealth
	};

	struct Vector2
	{
		float x, y;
		Vector2() : x(0), y(0) {}
		Vector2(float x, float y) : x(x), y(y) {}

		Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
		Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
		Vector2 operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
		Vector2 operator/(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }
		Vector2& operator=(const Vector2& other) { x = other.x; y = other.y; return *this; }

		bool IsValid() { return x == 0.f && y == 0.f; }
		float DotProduct(const Vector2& other) { return (x + other.x) + (y * other.y); }
		float MagnitudeSqr() { return DotProduct(*this); }
		float Magnitude() { return sqrt(DotProduct(*this)); }
		float Distance(const Vector2& other) { return powf(other.x - x, 2.f) + powf(other.y - y, 2.f); }
		float DistanceM(const Vector2& other) { return Distance(other) * .01f; }
	};

	struct Vector3
	{
		float x, y, z;
		Vector3() : x(0), y(0), z(0) {}
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

		Vector3 operator+(const float scalar) const { return Vector3(x + scalar, y + scalar, z + scalar); }
		Vector3 operator+(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
		Vector3 operator-(const float scalar) const { return Vector3(x - scalar, y - scalar, z - scalar); }
		Vector3 operator-(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
		Vector3 operator*(const float scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
		Vector3 operator*(const Vector3& other) const { return Vector3(x * other.x, y * other.y, z * other.z); }
		Vector3 operator/(const float scalar) const { return Vector3(x / scalar, y / scalar, z / scalar); }
		Vector3 operator/(const Vector3& other) const { return Vector3(x / other.x, y / other.y, z / other.z); }
		Vector3& operator=(const Vector3& other) { x = other.x; y = other.y; z = other.z; return *this; }

		Vector3& operator+=(const float scalar) { x += scalar; y += scalar; z += scalar; return *this; }
		Vector3& operator+=(const Vector3& other) { x += other.x; y += other.y; z += other.z; return *this; }
		Vector3& operator-=(const float scalar) { x -= scalar; y -= scalar; z -= scalar; return *this; }
		Vector3& operator-=(const Vector3& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
		Vector3& operator*=(const float scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }
		Vector3& operator*=(const Vector3& other) { x *= other.x; y *= other.y; z *= other.z; return *this; }
		Vector3& operator/=(const float scalar) { x /= scalar; y /= scalar; z /= scalar; return *this; }
		Vector3& operator/=(const Vector3& other) { x /= other.x; y /= other.y; z /= other.z; return *this; }


		bool IsValid() { return x == 0.f && y == 0.f && z == 0.f; }
		float DotProduct(const Vector3& other) { return (x * other.x) + (y * other.y) + (z * other.z); }
		float MagnitudeSqr() { return DotProduct(*this); }
		float Magnitude() { return sqrt(DotProduct(*this)); }
		float Distance(const Vector3& other) { return sqrt(powf(other.x - x, 2.f) + powf(other.y - y, 2.f) + powf(z - other.z, 2.f)); }
		float DistanceM(const Vector3& other) { return Distance(other) * .01f; }
	};

	struct Vector4
	{
		float x, y, z, w;
		Vector4() : x(0), y(0), z(0) {}
		Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

		Vector4 operator+(const Vector4& other) const { return Vector4(x + other.x, y + other.y, z + other.z, w + other.w); }
		Vector4 operator-(const Vector4& other) const { return Vector4(x - other.x, y - other.y, z - other.z, w - other.w); }
		Vector4 operator*(const Vector4& other) const { return Vector4(x * other.x, y * other.y, z * other.z, w * other.w); }
		Vector4 operator/(const Vector4& other) const { return Vector4(x / other.x, y / other.y, z / other.z, w / other.w); }
		Vector4& operator=(const Vector4& other) { x = other.x; y = other.y; z = other.z; w = other.w; }

		bool IsValid() { return x == 0.f && y == 0.f && z == 0.f && w == 0.f; }
	};

	struct AABB
	{
		Vector3 mmin;
		Vector3 mmax;

		AABB() : mmin(Vector3()), mmax(Vector3()) {}
		AABB(Vector3 min, Vector3 max) : mmin(min), mmax(max){}


		Vector3 Center() const { return (mmin + mmax) / 2; }
		Vector3 Size() const { mmax - mmin; }
		Vector3 Extents() const { return Size() * .5f; }
	};

	struct Matrix4x4
	{
		Vector4 x, y, z, w;
		Matrix4x4() : x(Vector4()), y(Vector4()), z(Vector4()), w(Vector4()) {}
		Matrix4x4(Vector4 x, Vector4 y, Vector4 z, Vector4 w) : x(x), y(y), z(z), w(w) {}
	};

	//	-

	class Main
	{
	public:
		char pad_0000[32]; //0x0000
		bool m_IsDedicatedServer; //0x0020
		bool m_IsDedicatedServerData; //0x0021
		bool m_IsPaused; //0x0022
		char pad_0023[37]; //0x0023
		class Server* p_Server; //0x0048
		class Client* m_pClient; //0x0050
		char pad_0058[192]; //0x0058
	}; //Size: 0x0118

	class DxDisplaySettings
	{
	public:
		char pad_0000[40]; //0x0000
		__int32 m_FullscreenHeight; //0x0028
		__int32 m_FullscreenWidth; //0x002C
		float m_RefreshRate; //0x0030
		__int32 m_FullscreenOutputIndex; //0x0034
		__int32 m_PresentInterval; //0x0038
		__int32 m_PresentImmediateThreshold; //0x003C
		__int32 m_RenderAheadLimit; //0x0040
		float m_StereoDepth; //0x0044
		float m_StereoConvergeanceScale; //0x0048
		float m_StereoSeparationScale; //0x004C
		float m_StereoSoldierZoomConvergeanceScale; //0x0050
		__int32 m_NVIDIAMinDriverVersion; //0x0054
		char* m_AMDMinDriverVersion; //0x0058
		float m_LowResDisplayPlaneScale; //0x0060
		char pad_0064[52]; //0x0064
	}; //Size: 0x0098

	class GameRenderer
	{
	public:
		char _0x0000[72];
		class GameRenderSettings* m_RenderSettings; //0x0048 
		char _0x0050[16];
		class RenderView* m_pRenderView; //0x0060 
	};//Size=0x0068

	class GameRenderSettings
	{
	public:
		char _0x0000[16];
		__int32 m_InactiveSkipFrameCount; //0x0010 
		float m_ResolutionScale; //0x0014 
		__int32 m_XenonRingBufferSize; //0x0018 
		char _0x001C[36];
	};//Size=0x0040

	class RenderView
	{
	public:
		char _0x0000[64];
		Matrix4x4 m_Transform; //0x0040 
		char _0x0080[52];
		float m_FovY; //0x00B4 
		float m_DefaultFovY; //0x00B8 
		float m_NearPlane; //0x00BC 
		float m_FarPlane; //0x00C0 
		float m_AspectRatio; //0x00C4 
		float m_OrthoWidth; //0x00C8 
		float m_OrthoHeight; //0x00CC 
		char _0x00D0[384];
		float m_FovX; //0x0250 
		float m_DepthHeightRatio; //0x0254 
		float m_FovScale; //0x0258 
		float m_FovScaleSquared; //0x025C 
		Matrix4x4 m_View; //0x0260 
		Matrix4x4 m_ViewTranspose; //0x02A0 
		Matrix4x4 m_ViewInverse; //0x02E0 
		Matrix4x4 m_Projection; //0x0320 
		Matrix4x4 m_ViewAtOrigin; //0x0360 
		Matrix4x4 m_ProjectionTranspose; //0x03A0 
		Matrix4x4 m_ProjectionInverse; //0x03E0 
		Matrix4x4 m_ViewProjection; //0x0420 
		Matrix4x4 m_ViewProjectionTranspose; //0x0460 
		Matrix4x4 m_ViewProjectionInverse; //0x04A0 

	};//Size=0x04E0

	class Client
	{
	public:
		char pad_0000[8]; //0x0000
		class GameSettings* m_pGameSettings; //0x0008
		char pad_0010[24]; //0x0010
		class ClientGameContext* m_pGameContext; //0x0028
		class ClientSettings* m_pClientSettings; //0x0030
		char pad_0038[80]; //0x0038
	}; //Size: 0x0088

	class ClientGameContext
	{
	public:
		char pad_0000[40]; //0x0000
		class Level* m_pLevel; //0x0028
		char pad_0030[48]; //0x0030
		class PlayerManager* m_pPlayerMan; //0x0060
		char pad_0068[32]; //0x0068
	}; //Size: 0x0088

	class PlayerManager
	{
	public:
		char pad_0008[1336]; //0x0008
		class ClientPlayer* m_pLocalPlayer; //0x0540
		__int64 m_ppPlayers; //0x0548
	}; //Size: 0x0550

	class ClientPlayer
	{
	public:
		char pad_0000[64]; //0x0000
		char m_name[16]; //0x0040
		char pad_0050[4988]; //0x0050
		__int32 m_TeamID; //0x13CC
		char pad_13D0[256]; //0x13D0
		class ClientSoldierEntity* m_pClientSoldier; //0x14D0
		char pad_14D8[184]; //0x14D8
	}; //Size: 0x1590

	class ClientControllableEntity
	{
	public:
		char pad_0008[248]; //0x0008
		float m_Velocity; //0x0100
		char pad_0104[60]; //0x0104
		class HealthComponent* m_pHealthComponent; //0x0140
	}; //Size: 0x0148

	class ClientSoldierEntity : public ClientControllableEntity
	{
	public:
		char pad_0148[840]; //0x0148
		class SoldierTransforms* m_pSoldierTransforms; //0x0490
		char pad_0498[216]; //0x0498
		class SoldierWeaponsComponent* m_pWeaponComponent; //0x0570
		class ClientSoldierBodyComponent* m_pBodyComponent; //0x0578
		class RagdollComponent* m_pRagdollComponent; //0x0580
		char pad_0588[40]; //0x0588
		bool m_bSprinting; //0x05B0
		bool m_bOccluded; //0x05B1
		char pad_05B2[14]; //0x05B2
	}; //Size: 0x05C0

	class HealthComponent
	{
	public:
		char pad_0000[32]; //0x0000
		float m_Health; //0x0020
		float m_MaxHealth; //0x0024
		char pad_0028[16]; //0x0028
		float m_VehicleHealth; //0x0038
	}; //Size: 0x003C

	class SoldierTransforms
	{
	public:
		char pad_0000[48]; //0x0000
		Vector3 origin; //0x0030
		char pad_003C[80]; //0x003C
	}; //Size: 0x008C
}
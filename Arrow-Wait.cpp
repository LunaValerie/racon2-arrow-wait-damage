DWORD CPythonNetworkStream_c = 0x6F136C; 
DWORD SendAddFlyTargetingPacket_c = 0x004A6150;

typedef D3DXVECTOR3 Arrow_Position;

typedef bool(__thiscall* tSendAddFlyTargeting)(DWORD CPythonNetworkStream, DWORD dwTargetVID, const Arrow_Position& kPPosTarget);
tSendAddFlyTargeting SendAddFlyTargeting = (tSendAddFlyTargeting)SendAddFlyTargetingPacket_c;

bool m_iArrowWait = false; float m_iArrow_Speed = 100.0f;

DWORD WINAPI Arrow_Wait(LPVOID lpParam)
{
	while (true)
	{
		if (m_iArrowWait)
		{
			DWORD GetTargetVID = *reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(0x006F4FB8) + (0x00012E28)); Arrow_Position Wait;
			Wait.x = 0.0f; Wait.y = 0.0f; Wait.z = 0.0f;
			SendAddFlyTargeting(*reinterpret_cast<DWORD*>(CPythonNetworkStream_c), GetTargetVID, Wait);
		}
		Sleep(m_iArrow_Speed);
	}
}
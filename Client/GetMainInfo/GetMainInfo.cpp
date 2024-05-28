#include "stdafx.h"
#include "CCRC32.H"
#include "MapManager.h"
#include "CustomGlow.h"
#include "CustomItem.h"
#include "ItemOption.h"

struct MAIN_FILE_INFO
{
	BYTE LauncherType;
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char PluginName[32];
	DWORD ClientCRC32;
	DWORD PluginCRC32;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD ReconnectTime;
	BYTE HealthBarType;
	BYTE EnableSky;
	BYTE EnableMinimap;
	BYTE EnableMoveList;
	MAP_MANAGER_INFO MapManager[MAX_MAPS];
	CUSTOM_GLOW_INFO CustomGlowInfo[MAX_ITEM];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_ITEM];
	ITEM_OPTION_INFO ItemOptionInfo[MAX_ITEM_OPTION_INFO];
};

int main()
{
	MAIN_FILE_INFO info;

	memset(&info, 0, sizeof(info));

	info.LauncherType = GetPrivateProfileInt("MainInfo", "LauncherType", 0, ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "LauncherName", "XTLauncherExecutable", info.LauncherName, sizeof(info.LauncherName), ".\\MainInfo.ini");

	info.IpAddressPort = GetPrivateProfileInt("MainInfo", "IpAddressPort", 44405, ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "CustomerName", "", info.CustomerName, sizeof(info.CustomerName), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "IpAddress", "", info.IpAddress, sizeof(info.IpAddress), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "ClientVersion", "", info.ClientVersion, sizeof(info.ClientVersion), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "ClientSerial", "", info.ClientSerial, sizeof(info.ClientSerial), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "WindowName", "", info.WindowName, sizeof(info.WindowName), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "ScreenShotPath", "", info.ScreenShotPath, sizeof(info.ScreenShotPath), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "ClientName", "", info.ClientName, sizeof(info.ClientName), ".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo", "PluginName", "", info.PluginName, sizeof(info.PluginName), ".\\MainInfo.ini");

	info.DWMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo", "DWMaxAttackSpeed", 65535, ".\\MainInfo.ini");

	info.DKMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo", "DKMaxAttackSpeed", 65535, ".\\MainInfo.ini");

	info.FEMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo", "FEMaxAttackSpeed", 65535, ".\\MainInfo.ini");

	info.MGMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo", "MGMaxAttackSpeed", 65535, ".\\MainInfo.ini");

	info.ReconnectTime = GetPrivateProfileInt("ReconnectInfo", "ReconnectTime", 0, ".\\MainInfo.ini");

	/*=================================================================
				CUSTOM
	==================================================================*/

	info.HealthBarType = GetPrivateProfileInt("Systems", "HealthBarType", 0, ".\\MainInfo.ini");

	info.EnableSky = GetPrivateProfileInt("Systems", "EnableSky", 0, ".\\MainInfo.ini");

	info.EnableMinimap = GetPrivateProfileInt("Systems", "EnableMinimap", 0, ".\\MainInfo.ini");

	info.EnableMoveList = GetPrivateProfileInt("Systems", "EnableMoveList", 0, ".\\MainInfo.ini");

	gMapManager.Load("MapManager.txt");

	gCustomGlow.Load("CustomGlow.txt");

	gCustomItem.Load("CustomItem.txt");

	gItemOption.Load("ItemOption.txt");

	/*================================================================*/

	memcpy(info.MapManager, gMapManager.m_MapManager, sizeof(info.MapManager));

	memcpy(info.CustomGlowInfo, gCustomGlow.m_CustomGlowInfo, sizeof(info.CustomGlowInfo));

	memcpy(info.CustomItemInfo, gCustomItem.m_CustomItemInfo, sizeof(info.CustomItemInfo));

	memcpy(info.ItemOptionInfo, gItemOption.m_ItemOptionInfo, sizeof(info.ItemOptionInfo));

	/*=================================================================*/

	CCRC32 CRC32;

	if (CRC32.FileCRC(info.ClientName, &info.ClientCRC32, 1024) == 0)
	{
		info.ClientCRC32 = 0;
	}

	if (CRC32.FileCRC(info.PluginName, &info.PluginCRC32, 1024) == 0)
	{
		info.PluginCRC32 = 0;
	}

	BYTE XorKey[20] = { 0x9E, 0x98, 0x12, 0x2B, 0xB6, 0x76, 0xF6, 0x5B, 0x76, 0x4D, 0x08, 0xF2, 0xAB, 0xDF, 0x91, 0xB6, 0x4C, 0x1C, 0x93, 0x2F };

	for (int n = 0; n < sizeof(MAIN_FILE_INFO); n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(XorKey[n % 20] ^ LOBYTE(n));

		((BYTE*)&info)[n] -= (BYTE)(XorKey[n % 20] ^ HIBYTE(n));

		((BYTE*)&info)[n] += (BYTE)(XorKey[n % 20] ^ HIBYTE(n));
	}

	HANDLE file = CreateFile(".\\Data\\Local\\ClientInfo.bmd", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);

	if (file == INVALID_HANDLE_VALUE)
	{
		std::cout << "ERROR: Couldn't create the file." << std::endl;

		system("pause");

		return 1;
	}

	DWORD OutSize = 0;

	if (WriteFile(file, &info, sizeof(MAIN_FILE_INFO), &OutSize, 0) == 0)
	{
		CloseHandle(file);

		std::cout << "ERROR: Couldn't create the file." << std::endl;

		system("pause");

		return 1;
	}

	CloseHandle(file);

	std::cout << "SUCCESS: File created." << std::endl;

	system("pause");

	return 0;
}
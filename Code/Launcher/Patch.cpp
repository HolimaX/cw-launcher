/**
 * @file
 * @brief Implementation of functions for patching Crysis code.
 */

#include "Patch.h"
#include "Util.h"

using Util::RVA;
using Util::FillNOP;
using Util::FillMem;

/**
 * @brief Allows connecting to DX10 servers with game running in DX9 mode.
 * @param pCryAction CryAction DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::AllowDX9ImmersiveMultiplayer(void *pCryAction, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCryAction, 0x2AF92D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B24DD), 0x1A))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryAction, 0x2AF6ED), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B239D), 0x1A))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B349D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B6361), 0x1A))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B394D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B6860), 0x1A))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B06AD), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B3EAA), 0x16))

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B529D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B7F7A), 0x16))

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B39FD), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B66DA), 0x16))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B6F6D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B9C21), 0x16))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryAction, 0x2B6F3D), 0x1E)
			 || !FillNOP(RVA(pCryAction, 0x2B9BF1), 0x16))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D4ADA), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1D6B03), 0x15))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D4B0A), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1D6B33), 0x15))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D6EDA), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1D8F32), 0x15))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D698A), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1D89FC), 0x15))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D854A), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1DA5BC), 0x15))

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryAction, 0x1F09AA), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1F2DEC), 0x15))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D81DA), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1DA1CC), 0x15))

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D826A), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1DA25C), 0x15))

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D9FCA), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1DBFBC), 0x15))

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryAction, 0x1D9F6A), 0x1A)
			 || !FillNOP(RVA(pCryAction, 0x1DBF5C), 0x15))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Disables startup videos.
 * @param pCryGame CryGame DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::DisableIntros(void *pCryGame, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCryGame, 0x2EDF9D), 0x10))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryGame, 0x2ED05D), 0x10))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryGame, 0x2F695D), 0x10))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryGame, 0x2F6F4D), 0x10))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryGame, 0x336402), 0x10))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryGame, 0x3274E2), 0x10))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryGame, 0x3275B2), 0x10))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryGame, 0x327CC2), 0x10))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryGame, 0x3291A2), 0x10))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCryGame, 0x21A91D), 0xD)
			 || !FillNOP(RVA(pCryGame, 0x21A92B), 0x2))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryGame, 0x21ACDD), 0xD)
			 || !FillNOP(RVA(pCryGame, 0x21ACEB), 0x2))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryGame, 0x220CAD), 0xD)
			 || !FillNOP(RVA(pCryGame, 0x220CBB), 0x2))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryGame, 0x220BFD), 0xD)
			 || !FillNOP(RVA(pCryGame, 0x220C0B), 0x2))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCryGame, 0x23C9F0), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x23C9FF), 0x2))

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryGame, 0x24D101), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x24D110), 0x2))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryGame, 0x23D650), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x23D65F), 0x2))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryGame, 0x23D250), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x23D25F), 0x2))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryGame, 0x23D760), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x23D76F), 0x2))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryGame, 0x23EEE0), 0xC)
			 || !FillNOP(RVA(pCryGame, 0x23EEEF), 0x2))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Prevents DX10 servers from being grayed-out in server list when game is running in DX9 mode.
 * This patch makes sense only if connecting to DX10 servers with DX9 game is possible (see AllowDX9ImmersiveMultiplayer).
 * @param pCryGame CryGame DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::CanJoinDX10Servers(void *pCryGame, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCryGame, 0x327B3C), 0xF))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryGame, 0x32689C), 0xF))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryGame, 0x3343C1), 0x18))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryGame, 0x334791), 0x18))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryGame, 0x35BC57), 0x18))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryGame, 0x34B4F7), 0x18))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryGame, 0x34B097), 0x18))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryGame, 0x34B9A7), 0x18))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryGame, 0x34D047), 0x18))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCryGame, 0x23A4BC), 0xA))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryGame, 0x23AB5C), 0xA))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryGame, 0x242CAC), 0xF))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryGame, 0x242F1C), 0xF))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCryGame, 0x250E10), 0xF))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryGame, 0x262D50), 0xF))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryGame, 0x2514D0), 0xF))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCryGame, 0x2510D0), 0xF))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCryGame, 0x251960), 0xF))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryGame, 0x252E10), 0xF))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Forces true value for DX10 flag in Flash UI scripts (ActionScript).
 * This patch unlocks DX10 features in "CREATE GAME" menu in DX9 game. It makes sense only if connecting to DX10 servers
 * with DX9 game is possible (see AllowDX9ImmersiveMultiplayer).
 * @param pCryGame CryGame DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::EnableDX10Menu(void *pCryGame, int gameVersion)
{
	const unsigned char code[] = {
		0xB0, 0x01,  // mov al, 0x1
		0x90         // nop
	};

	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillMem(RVA(pCryGame, 0x2ECE24), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2ED3FE), code, sizeof code))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillMem(RVA(pCryGame, 0x2EBEE4), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2EC4BE), code, sizeof code))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCryGame, 0x2F5792), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2F5DBC), code, sizeof code))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCryGame, 0x2F5D7D), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2F63B7), code, sizeof code))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillMem(RVA(pCryGame, 0x3150C1), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x3156F7), code, sizeof code))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillMem(RVA(pCryGame, 0x30AED1), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x30B507), code, sizeof code))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillMem(RVA(pCryGame, 0x30AF91), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x30B5C7), code, sizeof code))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillMem(RVA(pCryGame, 0x30B6A1), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x30BCD7), code, sizeof code))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillMem(RVA(pCryGame, 0x30CBA1), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x30D1D7), code, sizeof code))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillMem(RVA(pCryGame, 0x21A00E), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x21A401), code, sizeof code))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillMem(RVA(pCryGame, 0x21A3CE), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x21A7C1), code, sizeof code))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCryGame, 0x22034F), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x220789), code, sizeof code))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCryGame, 0x22029A), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2206E2), code, sizeof code))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillMem(RVA(pCryGame, 0x22C35E), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x22C7A2), code, sizeof code))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillMem(RVA(pCryGame, 0x23936E), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x2397B2), code, sizeof code))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillMem(RVA(pCryGame, 0x22CEAE), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x22D2F2), code, sizeof code))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillMem(RVA(pCryGame, 0x22C9CE), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x22CE12), code, sizeof code))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillMem(RVA(pCryGame, 0x22CDCE), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x22D212), code, sizeof code))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillMem(RVA(pCryGame, 0x22E64E), code, sizeof code)
			 || !FillMem(RVA(pCryGame, 0x22EA92), code, sizeof code))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Unlocks advantages of pre-ordered version for everyone.
 * This is both server-side and client-side patch.
 * @param pCryNetwork CryNetwork DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::EnablePreordered(void *pCryNetwork, int gameVersion)
{
	unsigned char code[] = {
	#ifdef BUILD_64BIT
		0xC6, 0x83, 0x70, 0xFA, 0x00, 0x00, 0x01  // mov byte ptr ds:[rbx+0xFA70], 0x1
	#else
		0xC6, 0x83, 0xC8, 0xF3, 0x00, 0x00, 0x01  // mov byte ptr ds:[ebx+0xF3C8], 0x1
	#endif
	};

	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillMem(RVA(pCryNetwork, 0x17F0C7), code, sizeof code))
				return false;

			break;
		}
		case 5879:
		{
			code[2] = 0x68;  // 0xFA68 instead of 0xFA70

			if (!FillMem(RVA(pCryNetwork, 0x1765F0), code, sizeof code))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCryNetwork, 0x17C077), code, sizeof code))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCryNetwork, 0x17C377), code, sizeof code))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillMem(RVA(pCryNetwork, 0x42C10), code, sizeof code))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillMem(RVA(pCryNetwork, 0x412FD), code, sizeof code))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCryNetwork, 0x430A8), code, sizeof code))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCryNetwork, 0x43188), code, sizeof code))
				return false;

			break;
		}
	#endif
		case 6527:
		case 6566:
		case 6586:
		case 6627:
		case 6670:
		case 6729:
		{
			// Crysis Wars doesn't have pre-ordered version
			break;
		}
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Prevents server from kicking players with the same CD key.
 * This is server-side patch.
 * @param pCryNetwork CryNetwork DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::AllowSameCDKeys(void *pCryNetwork, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE4858), 0x47))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE5628), 0x47))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE0188), 0x47))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE0328), 0x47))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE9034), 0x6B))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xE0838), 0x47))
				return false;

			break;
		}
		case 6627:
		case 6670:
		case 6729:
		{
			if (!FillNOP(RVA(pCryNetwork, 0xDFE48), 0x47))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x608CE), 0x4))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x5DE79), 0x4))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x60EF2), 0x4))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x606A5), 0x4))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x60768), 0x4))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x73F90), 0x4))
				return false;

			break;
		}
		case 6586:
		case 6627:
		case 6670:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x60CFE), 0x4))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCryNetwork, 0x60CF9), 0x4))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Replace gamespy.com with g.jedi95.us
 * @param pCryNetwork CryNetwork DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::PatchGamespy(void* pCryNetwork, int gameVersion)
{
	unsigned int targets[] = {
#ifdef BUILD_64BIT
		0x1AA765, 0x1AB840, 0x1AB858, 0x1AB870,
		0x1ABBD0, 0x1ABEFA, 0x1AC879, 0x1ADF0F,
		0x1AE67C, 0x1AE6FC, 0x1AEBB6, 0x1AEFB7,
		0x1EA315, 0x1EA465, 0x1EA51A
#else
		0xC5595, 0xC6558, 0xC656C, 0xC6580,
		0xC68A8, 0xC68E6, 0xC730D, 0xC887F,
		0xC8F0C, 0xC8F74, 0xC93B6, 0xC968F,
		0xD05B2, 0xD0645, 0xD078D
#endif
	};
	//Same string for both
	unsigned char code[] = {
		0x67, 0x2e, 0x6a, 0x65, 0x64, 0x69, 0x39, 0x35, 0x2e, 0x75, 0x73
	};

	switch (gameVersion)
	{
#ifdef BUILD_64BIT
	case 5767: {}
	case 5879: {}
	case 6115: {}
	case 6156:
	{
		//Crysis 1 not supported
		break;
	}
	case 6729:
	{
		for (int i = 0; i < 15; i++) {
			if (!FillMem(RVA(pCryNetwork, targets[i]), code, sizeof code))
				return false;
		}
		break;
	}
#else
	case 5767: {}
	case 5879: {}
	case 6115: {}
	case 6156:
	{
		//Crysis 1 not supported
		break;
	}
	case 6729:
	{
		for (int i = 0; i < 15; i++) {
			if (!FillMem(RVA(pCryNetwork, targets[i]), code, sizeof code))
				return false;
		}
		break;
	}
#endif
	default:
	{
		return false;
	}
	}

	return true;
}

/**
 * @brief Disables the SecuROM crap in 64-bit CrySystem.
 * It does nothing in 32-bit build.
 * @param pCrySystem CrySystem DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::RemoveSecuROM(void *pCrySystem, int gameVersion)
{
#ifdef BUILD_64BIT
	switch (gameVersion)
	{
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x4659E), 0x16))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x47B6E), 0x16))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x46FFD), 0x16))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x470B9), 0x16))
				return false;

			break;
		}
		case 6566:
		case 6586:
		case 6627:
		case 6670:
		case 6729:
		{
			// CrySystem in Crysis Wars doesn't contain any SecuROM crap
			break;
		}
		default:
		{
			return false;
		}
	}
#endif

	return true;
}

/**
 * @brief Allows Very High settings in DX9 mode.
 * @param pCrySystem CrySystem DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::AllowDX9VeryHighSpec(void *pCrySystem, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x45C31), 0x54))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x47201), 0x54))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x46690), 0x54))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x4674C), 0x54))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x4D7B5), 0x54))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x47DBB), 0x54))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x4A90B), 0x54))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x59F08), 0x4B))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5A488), 0x4B))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5A268), 0x4B))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x59DA8), 0x4B))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5A778), 0x4B))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5D1A9), 0x4B))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5A659), 0x4B))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5B5E9), 0x4B))
				return false;

			break;
		}
	#endif
		case 6670:
		case 6729:
		{
			// Crysis Wars since 1.4 allows Very High settings in DX9 mode
			break;
		}
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Allows running multiple instances of Crysis at once.
 * Note that the first check if any instance is already running is normally done in launcher.
 * @param pCrySystem CrySystem DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::AllowMultipleInstances(void *pCrySystem, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x420DF), 0x68))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x436AF), 0x68))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x42B5F), 0x68))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x42BFF), 0x68))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x49D1F), 0x68))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x4420F), 0x68))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x46D5F), 0x68))
				return false;

			break;
		}
		case 6670:
		case 6729:
		{
			if (!FillNOP(RVA(pCrySystem, 0x46EEF), 0x68))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x57ABF), 0x58))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5802F), 0x58))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x57E1F), 0x58))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5794F), 0x58))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5831F), 0x58))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5AC4F), 0x58))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x5834F), 0x58))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x592DF), 0x58))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCrySystem, 0x595CF), 0x58))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCrySystem, 0x595DF), 0x58))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Prevents the engine from installing its own broken unhandled exceptions handler.
 * @param pCrySystem CrySystem DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::UnhandledExceptions(void *pCrySystem, int gameVersion)
{
	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x22986), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x22992), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x45C8A), 0x16))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x232C6), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x232D2), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x4725A), 0x16))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x22966), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x22972), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x466E9), 0x16))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x22946), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x22952), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x467A5), 0x16))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x298AE), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x298BA), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x4D80E), 0x16))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x24026), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x24032), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x47E14), 0x16))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x25183), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x2518F), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x4A964), 0x16))
				return false;

			break;
		}
		case 6670:
		case 6729:
		{
			if (!FillNOP(RVA(pCrySystem, 0x253B3), 0x6)
			 || !FillNOP(RVA(pCrySystem, 0x253BF), 0x7)
			 || !FillNOP(RVA(pCrySystem, 0x4AAA0), 0x16))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillNOP(RVA(pCrySystem, 0x182B7), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x182C2), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x59F58), 0x13))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillNOP(RVA(pCrySystem, 0x18437), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x18442), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5A4D8), 0x13))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillNOP(RVA(pCrySystem, 0x18217), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x18222), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5A2B8), 0x13))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillNOP(RVA(pCrySystem, 0x17D67), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x17D72), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x59DF8), 0x13))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillNOP(RVA(pCrySystem, 0x18767), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x18772), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5A7C8), 0x13))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillNOP(RVA(pCrySystem, 0x1AD57), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x1AD62), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5D1F9), 0x13))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillNOP(RVA(pCrySystem, 0x18A27), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x18A32), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5A6A9), 0x13))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillNOP(RVA(pCrySystem, 0x19327), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x19332), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5B639), 0x13))
				return false;

			break;
		}
		case 6670:
		{
			if (!FillNOP(RVA(pCrySystem, 0x19607), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x19612), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5B8DC), 0x13))
				return false;

			break;
		}
		case 6729:
		{
			if (!FillNOP(RVA(pCrySystem, 0x19617), 0x5)
			 || !FillNOP(RVA(pCrySystem, 0x19622), 0xC)
			 || !FillNOP(RVA(pCrySystem, 0x5B8EC), 0x13))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief Disables use of 3DNow! instructions.
 * This patch correctly fixes the well known crash of 32-bit Crysis on modern AMD processors.
 * @param pCrySystem CrySystem DLL handle.
 * @param gameVersion Game build number.
 * @return True if no error occurred, otherwise false.
 */
bool Patch::Disable3DNow(void *pCrySystem, int gameVersion)
{
	const unsigned char flags = 0x18;  // default processor feature flags without CPUF_3DNOW flag

	switch (gameVersion)
	{
	#ifdef BUILD_64BIT
		case 5767:
		{
			if (!FillMem(RVA(pCrySystem, 0xA1AF), &flags, sizeof flags))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillMem(RVA(pCrySystem, 0xA0FF), &flags, sizeof flags))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCrySystem, 0xA0BF), &flags, sizeof flags))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCrySystem, 0xA0FF), &flags, sizeof flags))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillMem(RVA(pCrySystem, 0xAD3F), &flags, sizeof flags))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillMem(RVA(pCrySystem, 0xA32F), &flags, sizeof flags))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillMem(RVA(pCrySystem, 0xA26F), &flags, sizeof flags))
				return false;

			break;
		}
		case 6670:
		case 6729:
		{
			if (!FillMem(RVA(pCrySystem, 0xA32F), &flags, sizeof flags))
				return false;

			break;
		}
	#else
		case 5767:
		{
			if (!FillMem(RVA(pCrySystem, 0x9432), &flags, sizeof flags))
				return false;

			break;
		}
		case 5879:
		{
			if (!FillMem(RVA(pCrySystem, 0x9472), &flags, sizeof flags))
				return false;

			break;
		}
		case 6115:
		{
			if (!FillMem(RVA(pCrySystem, 0x9412), &flags, sizeof flags))
				return false;

			break;
		}
		case 6156:
		{
			if (!FillMem(RVA(pCrySystem, 0x93E2), &flags, sizeof flags))
				return false;

			break;
		}
		case 6527:
		{
			if (!FillMem(RVA(pCrySystem, 0x9472), &flags, sizeof flags))
				return false;

			break;
		}
		case 6566:
		{
			if (!FillMem(RVA(pCrySystem, 0x9942), &flags, sizeof flags))
				return false;

			break;
		}
		case 6586:
		{
			if (!FillMem(RVA(pCrySystem, 0x93D2), &flags, sizeof flags))
				return false;

			break;
		}
		case 6627:
		{
			if (!FillMem(RVA(pCrySystem, 0x9402), &flags, sizeof flags))
				return false;

			break;
		}
		case 6670:
		case 6729:
		{
			if (!FillMem(RVA(pCrySystem, 0x9412), &flags, sizeof flags))
				return false;

			break;
		}
	#endif
		default:
		{
			return false;
		}
	}

	return true;
}
